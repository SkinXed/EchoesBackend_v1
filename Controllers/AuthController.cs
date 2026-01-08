using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Echoes.API.Data;
using Echoes.API.Models.DTOs;
using Echoes.API.Models.Entities.Character;
using System.Security.Cryptography;
using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;
using Microsoft.IdentityModel.Tokens;
using System.Text;

namespace Echoes.API.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class AuthController : ControllerBase
    {
        private readonly DatabaseContext _context;
        private readonly IConfiguration _configuration;
        private readonly ILogger<AuthController> _logger;

        public AuthController(DatabaseContext context, IConfiguration configuration, ILogger<AuthController> logger)
        {
            _context = context;
            _configuration = configuration;
            _logger = logger;
        }

        // POST: api/auth/register
        [HttpPost("register")]
        public async Task<ActionResult<AuthResponseDto>> Register([FromBody] RegisterRequestDto request)
        {
            try
            {
                // Валидация
                if (string.IsNullOrWhiteSpace(request.Username) ||
                    string.IsNullOrWhiteSpace(request.Email) ||
                    string.IsNullOrWhiteSpace(request.Password))
                    return BadRequest(new { error = "Все поля обязательны" });

                // Проверка уникальности
                if (await _context.Accounts.AnyAsync(a => a.Username == request.Username))
                    return Conflict(new { error = "Имя пользователя уже занято" });

                if (await _context.Accounts.AnyAsync(a => a.Email == request.Email))
                    return Conflict(new { error = "Email уже зарегистрирован" });

                // Создание аккаунта
                var account = new Account
                {
                    Id = Guid.NewGuid(),
                    Username = request.Username,
                    Email = request.Email,
                    //CreatedAt = DateTime.UtcNow,
                    IsActive = true
                };

                // Хэширование пароля
                CreatePasswordHash(request.Password, out byte[] passwordHash, out byte[] passwordSalt);
                account.PasswordHash = passwordHash;
                account.PasswordSalt = passwordSalt;

                // Создание персонажа
                var character = new Character
                {
                    Id = Guid.NewGuid(),
                    AccountId = account.Id,
                    Name = $"{request.Username}'s Pilot",
                    IsMain = true,
                    WalletBalance = 1000000,
                    SecurityStatus = 0.0f,
                    CloneExpiration = DateTime.UtcNow.AddDays(30)
                };

                // Сохранение
                _context.Accounts.Add(account);
                _context.Characters.Add(character);
                await _context.SaveChangesAsync();

                // Создание сессии
                var session = new AccountSession
                {
                    Id = Guid.NewGuid(),
                    AccountId = account.Id,
                    CharacterId = character.Id,
                    SessionToken = GenerateRandomToken(),
                    RefreshToken = GenerateRandomToken(),
                    CreatedAt = DateTime.UtcNow,
                    ExpiresAt = DateTime.UtcNow.AddDays(7),
                    RefreshTokenExpiresAt = DateTime.UtcNow.AddDays(30),
                    IPAddress = HttpContext.Connection.RemoteIpAddress?.ToString() ?? "Unknown",
                    UserAgent = Request.Headers.UserAgent.ToString(),
                    IsActive = true,
                    LastActivity = DateTime.UtcNow
                };

                _context.AccountSessions.Add(session);
                await _context.SaveChangesAsync();

                // Генерация JWT токена
                var token = GenerateJwtToken(account, character, session);

                return Ok(new AuthResponseDto
                {
                    Success = true,
                    Token = token,
                    CharacterId = character.Id,
                    CharacterName = character.Name,
                    SessionId = session.Id,
                    ExpiresAt = session.ExpiresAt
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка регистрации");
                return StatusCode(500, new { error = "Внутренняя ошибка сервера" });
            }
        }

        // POST: api/auth/login
        [HttpPost("login")]
        public async Task<ActionResult<AuthResponseDto>> Login([FromBody] LoginRequestDto request)
        {
            try
            {
                // Поиск аккаунта
                var account = await _context.Accounts
                    .FirstOrDefaultAsync(a => a.Email == request.EmailOrUsername ||
                                             a.Username == request.EmailOrUsername);

                if (account == null || !VerifyPasswordHash(request.Password, account.PasswordHash, account.PasswordSalt))
                    return Unauthorized(new { error = "Неверные учетные данные" });

                if (!account.IsActive)
                    return Unauthorized(new { error = "Аккаунт деактивирован" });

                // Получение персонажа
                var character = await _context.Characters
                    .FirstOrDefaultAsync(c => c.AccountId == account.Id && c.IsMain);

                if (character == null)
                    return NotFound(new { error = "Персонаж не найден" });

                // Обновление времени последнего входа
                account.LastLogin = DateTime.UtcNow;

                // Создание новой сессии
                var session = new AccountSession
                {
                    Id = Guid.NewGuid(),
                    AccountId = account.Id,
                    CharacterId = character.Id,
                    SessionToken = GenerateRandomToken(),
                    RefreshToken = GenerateRandomToken(),
                    CreatedAt = DateTime.UtcNow,
                    ExpiresAt = DateTime.UtcNow.AddDays(7),
                    RefreshTokenExpiresAt = DateTime.UtcNow.AddDays(30),
                    IPAddress = HttpContext.Connection.RemoteIpAddress?.ToString() ?? "Unknown",
                    UserAgent = Request.Headers.UserAgent.ToString(),
                    IsActive = true,
                    LastActivity = DateTime.UtcNow
                };

                // Деактивация старых сессий
                var oldSessions = await _context.AccountSessions
                    .Where(s => s.AccountId == account.Id && s.IsActive)
                    .ToListAsync();

                foreach (var oldSession in oldSessions)
                {
                    oldSession.IsActive = false;
                }

                _context.AccountSessions.Add(session);
                await _context.SaveChangesAsync();

                // Генерация JWT
                var token = GenerateJwtToken(account, character, session);

                return Ok(new AuthResponseDto
                {
                    Success = true,
                    Token = token,
                    CharacterId = character.Id,
                    CharacterName = character.Name,
                    SessionId = session.Id,
                    ExpiresAt = session.ExpiresAt
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка входа");
                return StatusCode(500, new { error = "Внутренняя ошибка сервера" });
            }
        }

        // POST: api/auth/logout
        [HttpPost("logout")]
        public async Task<ActionResult> Logout()
        {
            try
            {
                var token = Request.Headers["Authorization"].ToString().Replace("Bearer ", "");
                var session = await _context.AccountSessions
                    .FirstOrDefaultAsync(s => s.SessionToken == token && s.IsActive);

                if (session != null)
                {
                    session.IsActive = false;
                    await _context.SaveChangesAsync();
                }

                return Ok(new { success = true, message = "Выход выполнен" });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка выхода");
                return StatusCode(500, new { error = "Внутренняя ошибка сервера" });
            }
        }

        // POST: api/auth/validate
        [HttpPost("validate")]
        public async Task<ActionResult<SessionValidationDto>> ValidateSession([FromBody] ValidateSessionDto request)
        {
            try
            {
                var session = await _context.AccountSessions
                    .Include(s => s.Account)
                    .Include(s => s.Character)
                    .FirstOrDefaultAsync(s => s.SessionToken == request.SessionToken &&
                                             s.CharacterId == request.CharacterId &&
                                             s.IsActive &&
                                             s.ExpiresAt > DateTime.UtcNow);

                if (session == null)
                    return Ok(new SessionValidationDto { IsValid = false, Error = "Сессия недействительна" });

                // Обновляем время активности
                session.LastActivity = DateTime.UtcNow;
                await _context.SaveChangesAsync();

                return Ok(new SessionValidationDto
                {
                    IsValid = true,
                    CharacterId = session.CharacterId
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка валидации сессии");
                return Ok(new SessionValidationDto { IsValid = false, Error = ex.Message });
            }
        }

        // POST: api/auth/refresh
        [HttpPost("refresh")]
        public async Task<ActionResult<AuthResponseDto>> RefreshToken([FromBody] RefreshTokenDto request)
        {
            try
            {
                var session = await _context.AccountSessions
                    .Include(s => s.Account)
                    .Include(s => s.Character)
                    .FirstOrDefaultAsync(s => s.RefreshToken == request.RefreshToken &&
                                             s.CharacterId == request.CharacterId &&
                                             s.IsActive &&
                                             s.RefreshTokenExpiresAt > DateTime.UtcNow);

                if (session == null)
                    return Unauthorized(new { error = "Недействительный refresh token" });

                // Создаем новую сессию
                var newSession = new AccountSession
                {
                    Id = Guid.NewGuid(),
                    AccountId = session.AccountId,
                    CharacterId = session.CharacterId,
                    SessionToken = GenerateRandomToken(),
                    RefreshToken = GenerateRandomToken(),
                    CreatedAt = DateTime.UtcNow,
                    ExpiresAt = DateTime.UtcNow.AddDays(7),
                    RefreshTokenExpiresAt = DateTime.UtcNow.AddDays(30),
                    IPAddress = HttpContext.Connection.RemoteIpAddress?.ToString() ?? "Unknown",
                    UserAgent = Request.Headers.UserAgent.ToString(),
                    IsActive = true,
                    LastActivity = DateTime.UtcNow
                };

                // Деактивируем старую сессию
                session.IsActive = false;

                _context.AccountSessions.Add(newSession);
                await _context.SaveChangesAsync();

                // Генерация нового JWT
                var token = GenerateJwtToken(session.Account, session.Character, newSession);

                return Ok(new AuthResponseDto
                {
                    Success = true,
                    Token = token,
                    CharacterId = session.CharacterId,
                    CharacterName = session.Character.Name,
                    SessionId = newSession.Id,
                    ExpiresAt = newSession.ExpiresAt
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка обновления токена");
                return StatusCode(500, new { error = "Внутренняя ошибка сервера" });
            }
        }

        // Приватные методы
        private void CreatePasswordHash(string password, out byte[] passwordHash, out byte[] passwordSalt)
        {
            using var hmac = new HMACSHA512();
            passwordSalt = hmac.Key;
            passwordHash = hmac.ComputeHash(Encoding.UTF8.GetBytes(password));
        }

        private bool VerifyPasswordHash(string password, byte[] storedHash, byte[] storedSalt)
        {
            using var hmac = new HMACSHA512(storedSalt);
            var computedHash = hmac.ComputeHash(Encoding.UTF8.GetBytes(password));
            return computedHash.SequenceEqual(storedHash);
        }

        private string GenerateRandomToken()
        {
            return Convert.ToBase64String(RandomNumberGenerator.GetBytes(64));
        }

        private string GenerateJwtToken(Account account, Character character, AccountSession session)
        {
            var tokenHandler = new JwtSecurityTokenHandler();
            var key = Encoding.ASCII.GetBytes(_configuration["Jwt:Secret"] ?? "YourSuperSecretKey123!");

            var claims = new List<Claim>
            {
                new Claim(JwtRegisteredClaimNames.Sub, account.Id.ToString()),
                new Claim(JwtRegisteredClaimNames.Email, account.Email),
                new Claim("CharacterId", character.Id.ToString()),
                new Claim("SessionId", session.Id.ToString()),
                new Claim(JwtRegisteredClaimNames.Jti, Guid.NewGuid().ToString())
            };

            if (account.IsAdmin) claims.Add(new Claim(ClaimTypes.Role, "Admin"));

            var tokenDescriptor = new SecurityTokenDescriptor
            {
                Subject = new ClaimsIdentity(claims),
                Expires = session.ExpiresAt,
                SigningCredentials = new SigningCredentials(
                    new SymmetricSecurityKey(key),
                    SecurityAlgorithms.HmacSha256Signature),
                Issuer = _configuration["Jwt:Issuer"] ?? "EchoesAPI",
                Audience = _configuration["Jwt:Audience"] ?? "EchoesClient"
            };

            var token = tokenHandler.CreateToken(tokenDescriptor);
            return tokenHandler.WriteToken(token);
        }
    }
}