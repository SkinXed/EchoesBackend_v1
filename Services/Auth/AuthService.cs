using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;
using System.Security.Cryptography;
using System.Text;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;
using Microsoft.IdentityModel.Tokens;
using Echoes.API.Data;
using Echoes.API.Models.Entities.Character;
using Echoes.API.Models.Enums;
using Echoes.API.Models.DTOs;

namespace Echoes.API.Services.Auth
{
    public interface IAuthService
    {
        Task<AuthResponseDto> RegisterAsync(RegisterDto dto);
        Task<AuthResponseDto> LoginAsync(LoginDto dto, string ipAddress);
        Task<AuthResponseDto> RefreshTokenAsync(string refreshToken);
        Task LogoutAsync(Guid accountId, string? refreshToken = null);
        Task VerifyEmailAsync(string token);
        Task ResendVerificationEmailAsync(string email);
        Task RequestPasswordResetAsync(string email);
        Task ResetPasswordAsync(ResetPasswordDto dto);
        Task ChangePasswordAsync(Guid accountId, ChangePasswordDto dto);
        Task EnableTwoFactorAsync(Guid accountId, TwoFactorType type);
        Task DisableTwoFactorAsync(Guid accountId);
        Task<bool> VerifyTwoFactorAsync(Guid accountId, string code);
    }

    public class AuthService : IAuthService
    {
        private readonly DatabaseContext _context;
        private readonly IConfiguration _configuration;

        public AuthService(DatabaseContext context, IConfiguration configuration)
        {
            _context = context;
            _configuration = configuration;
        }

        public async Task<AuthResponseDto> RegisterAsync(RegisterDto dto)
        {
            // Check if user already exists
            if (await _context.Accounts.AnyAsync(a => a.Email == dto.Email || a.Username == dto.Username))
            {
                throw new InvalidOperationException("User with this email or username already exists");
            }

            // Create account
            var account = new Account
            {
                Id = Guid.NewGuid(),
                Username = dto.Username,
                Email = dto.Email,
                IsActive = true,
                EmailVerificationToken = GenerateRandomToken(),
                CreatedAt = DateTime.UtcNow,
                UpdatedAt = DateTime.UtcNow
            };

            // Hash password
            CreatePasswordHash(dto.Password, out byte[] passwordHash, out byte[] passwordSalt);
            account.PasswordHash = passwordHash;
            account.PasswordSalt = passwordSalt;

            // Create default character
            var character = new Character
            {
                Id = Guid.NewGuid(),
                AccountId = account.Id,
                Name = $"{dto.Username}'s Pilot",
                IsMain = true,
                WalletBalance = 1000000,
                SecurityStatus = 0.0f,
                CloneExpiration = DateTime.UtcNow.AddDays(30)
            };

            _context.Accounts.Add(account);
            _context.Characters.Add(character);
            await _context.SaveChangesAsync();

            // Create session
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
                IPAddress = "Unknown",
                IsActive = true,
                LastActivity = DateTime.UtcNow
            };

            _context.AccountSessions.Add(session);
            await _context.SaveChangesAsync();

            // Generate JWT token
            var token = GenerateJwtToken(account, character, session);

            return new AuthResponseDto
            {
                Success = true,
                Token = token,
                CharacterId = character.Id,
                CharacterName = character.Name,
                SessionId = session.Id,
                ExpiresAt = session.ExpiresAt
            };
        }

        public async Task<AuthResponseDto> LoginAsync(LoginDto dto, string ipAddress)
        {
            var account = await _context.Accounts
                .FirstOrDefaultAsync(a => a.Email == dto.EmailOrUsername || a.Username == dto.EmailOrUsername);

            if (account == null || !VerifyPasswordHash(dto.Password, account.PasswordHash, account.PasswordSalt))
            {
                throw new UnauthorizedAccessException("Invalid credentials");
            }

            if (!account.IsActive)
            {
                throw new UnauthorizedAccessException("Account is not active");
            }

            // Get main character
            var character = await _context.Characters
                .FirstOrDefaultAsync(c => c.AccountId == account.Id && c.IsMain);

            if (character == null)
            {
                throw new InvalidOperationException("No main character found");
            }

            // Create session
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
                IPAddress = ipAddress,
                IsActive = true,
                LastActivity = DateTime.UtcNow
            };

            _context.AccountSessions.Add(session);

            // Update last login
            account.LastLogin = DateTime.UtcNow;
            account.LastLoginIp = ipAddress;

            await _context.SaveChangesAsync();

            // Generate JWT token
            var token = GenerateJwtToken(account, character, session);

            return new AuthResponseDto
            {
                Success = true,
                Token = token,
                CharacterId = character.Id,
                CharacterName = character.Name,
                SessionId = session.Id,
                ExpiresAt = session.ExpiresAt
            };
        }

        public async Task<AuthResponseDto> RefreshTokenAsync(string refreshToken)
        {
            var session = await _context.AccountSessions
                .Include(s => s.Account)
                .Include(s => s.Character)
                .FirstOrDefaultAsync(s => s.RefreshToken == refreshToken &&
                                         s.IsActive &&
                                         s.RefreshTokenExpiresAt > DateTime.UtcNow);

            if (session == null || session.Character == null)
            {
                throw new UnauthorizedAccessException("Invalid refresh token");
            }

            // Create new session
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
                IPAddress = session.IPAddress,
                IsActive = true,
                LastActivity = DateTime.UtcNow
            };

            // Deactivate old session
            session.IsActive = false;

            _context.AccountSessions.Add(newSession);
            await _context.SaveChangesAsync();

            // Generate JWT token
            var token = GenerateJwtToken(session.Account, session.Character, newSession);

            return new AuthResponseDto
            {
                Success = true,
                Token = token,
                CharacterId = session.Character.Id,
                CharacterName = session.Character.Name,
                SessionId = newSession.Id,
                ExpiresAt = newSession.ExpiresAt
            };
        }

        public async Task LogoutAsync(Guid accountId, string? refreshToken = null)
        {
            if (refreshToken != null)
            {
                var session = await _context.AccountSessions
                    .FirstOrDefaultAsync(s => s.RefreshToken == refreshToken && s.AccountId == accountId);

                if (session != null)
                {
                    session.IsActive = false;
                    await _context.SaveChangesAsync();
                }
            }
            else
            {
                // Logout all sessions
                var sessions = await _context.AccountSessions
                    .Where(s => s.AccountId == accountId && s.IsActive)
                    .ToListAsync();

                foreach (var session in sessions)
                {
                    session.IsActive = false;
                }

                await _context.SaveChangesAsync();
            }
        }

        public async Task VerifyEmailAsync(string token)
        {
            var account = await _context.Accounts
                .FirstOrDefaultAsync(a => a.EmailVerificationToken == token);

            if (account == null)
            {
                throw new InvalidOperationException("Invalid verification token");
            }

            account.IsEmailVerified = true;
            account.EmailVerifiedAt = DateTime.UtcNow;
            account.EmailVerificationToken = null;

            await _context.SaveChangesAsync();
        }

        public async Task ResendVerificationEmailAsync(string email)
        {
            var account = await _context.Accounts
                .FirstOrDefaultAsync(a => a.Email == email);

            if (account == null)
            {
                throw new InvalidOperationException("Account not found");
            }

            if (account.IsEmailVerified)
            {
                throw new InvalidOperationException("Email already verified");
            }

            account.EmailVerificationToken = GenerateRandomToken();
            await _context.SaveChangesAsync();

            // TODO: Send verification email
        }

        public async Task RequestPasswordResetAsync(string email)
        {
            var account = await _context.Accounts
                .FirstOrDefaultAsync(a => a.Email == email);

            if (account == null)
            {
                // Don't reveal if account exists
                return;
            }

            account.PasswordResetToken = GenerateRandomToken();
            account.PasswordResetExpires = DateTime.UtcNow.AddHours(1);

            await _context.SaveChangesAsync();

            // TODO: Send password reset email
        }

        public async Task ResetPasswordAsync(ResetPasswordDto dto)
        {
            var account = await _context.Accounts
                .FirstOrDefaultAsync(a => a.Email == dto.Email &&
                                         a.PasswordResetToken == dto.Token &&
                                         a.PasswordResetExpires > DateTime.UtcNow);

            if (account == null)
            {
                throw new InvalidOperationException("Invalid or expired reset token");
            }

            CreatePasswordHash(dto.NewPassword, out byte[] passwordHash, out byte[] passwordSalt);
            account.PasswordHash = passwordHash;
            account.PasswordSalt = passwordSalt;
            account.PasswordResetToken = null;
            account.PasswordResetExpires = null;
            account.PasswordChangedAt = DateTime.UtcNow;

            await _context.SaveChangesAsync();
        }

        public async Task ChangePasswordAsync(Guid accountId, ChangePasswordDto dto)
        {
            var account = await _context.Accounts.FindAsync(accountId);

            if (account == null)
            {
                throw new InvalidOperationException("Account not found");
            }

            if (!VerifyPasswordHash(dto.CurrentPassword, account.PasswordHash, account.PasswordSalt))
            {
                throw new UnauthorizedAccessException("Current password is incorrect");
            }

            CreatePasswordHash(dto.NewPassword, out byte[] passwordHash, out byte[] passwordSalt);
            account.PasswordHash = passwordHash;
            account.PasswordSalt = passwordSalt;
            account.PasswordChangedAt = DateTime.UtcNow;

            await _context.SaveChangesAsync();
        }

        public async Task EnableTwoFactorAsync(Guid accountId, TwoFactorType type)
        {
            var account = await _context.Accounts.FindAsync(accountId);

            if (account == null)
            {
                throw new InvalidOperationException("Account not found");
            }

            account.TwoFactorType = type;
            account.TwoFactorSecret = GenerateRandomToken();

            await _context.SaveChangesAsync();

            // TODO: Send 2FA setup instructions
        }

        public async Task DisableTwoFactorAsync(Guid accountId)
        {
            var account = await _context.Accounts.FindAsync(accountId);

            if (account == null)
            {
                throw new InvalidOperationException("Account not found");
            }

            account.TwoFactorType = TwoFactorType.None;
            account.TwoFactorSecret = null;

            await _context.SaveChangesAsync();
        }

        public async Task<bool> VerifyTwoFactorAsync(Guid accountId, string code)
        {
            var account = await _context.Accounts.FindAsync(accountId);

            if (account == null)
            {
                return false;
            }

            // TODO: Implement actual 2FA verification logic
            // For now, just return true if 2FA is enabled
            return account.TwoFactorType != TwoFactorType.None;
        }

        // Helper methods
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

            if (account.IsAdmin)
            {
                claims.Add(new Claim(ClaimTypes.Role, "Admin"));
            }

            var tokenDescriptor = new SecurityTokenDescriptor
            {
                Subject = new ClaimsIdentity(claims),
                Expires = DateTime.UtcNow.AddDays(7),
                SigningCredentials = new SigningCredentials(
                    new SymmetricSecurityKey(key),
                    SecurityAlgorithms.HmacSha256Signature
                ),
                Issuer = _configuration["Jwt:Issuer"] ?? "EchoesAPI",
                Audience = _configuration["Jwt:Audience"] ?? "EchoesClient"
            };

            var token = tokenHandler.CreateToken(tokenDescriptor);
            return tokenHandler.WriteToken(token);
        }
    }
}
