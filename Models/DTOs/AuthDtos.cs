using System;
using System.ComponentModel.DataAnnotations;

namespace Echoes.API.Models.DTOs
{
    // DTO для регистрации
    public class RegisterRequestDto
    {
        [Required]
        [StringLength(50, MinimumLength = 3)]
        public string Username { get; set; } = string.Empty;

        [Required]
        [EmailAddress]
        public string Email { get; set; } = string.Empty;

        [Required]
        [StringLength(100, MinimumLength = 8)]
        public string Password { get; set; } = string.Empty;
    }

    // DTO для логина
    public class LoginRequestDto
    {
        [Required]
        public string EmailOrUsername { get; set; } = string.Empty;

        [Required]
        public string Password { get; set; } = string.Empty;
    }

    // DTO для ответа авторизации
    public class AuthResponseDto
    {
        public bool Success { get; set; }
        public string Token { get; set; } = string.Empty;
        public Guid AccountId { get; set; }
        public Guid CharacterId { get; set; }
        public string CharacterName { get; set; } = string.Empty;
        public Guid SessionId { get; set; }
        public DateTime ExpiresAt { get; set; }
        public List<CharacterInfoDto> Characters { get; set; } = new List<CharacterInfoDto>();
    }

    // DTO для информации о персонаже
    public class CharacterInfoDto
    {
        public Guid CharacterId { get; set; }
        public string Name { get; set; } = string.Empty;
        public long WalletBalance { get; set; }
        public long? CurrentShipId { get; set; }
        public bool IsMain { get; set; }
        public bool IsOnline { get; set; }
    }

    // DTO для обновления токена
    public class RefreshTokenDto
    {
        [Required]
        public string RefreshToken { get; set; } = string.Empty;

        [Required]
        public Guid CharacterId { get; set; }
    }

    // DTO для валидации сессии (для UE5 сервера)
    public class ValidateSessionDto
    {
        [Required]
        public string SessionToken { get; set; } = string.Empty;

        [Required]
        public Guid CharacterId { get; set; }
    }

    public class SessionValidationDto
    {
        public bool IsValid { get; set; }
        public string Error { get; set; } = string.Empty;
        public Guid CharacterId { get; set; }
        public long? ActiveShipItemId { get; set; }
        public object? ShipSpawnData { get; set; }
        public object? CurrentLocation { get; set; }
    }

    // DTO для регистрации (alias для совместимости)
    public class RegisterDto
    {
        [Required]
        [StringLength(50, MinimumLength = 3)]
        public string Username { get; set; } = string.Empty;

        [Required]
        [EmailAddress]
        public string Email { get; set; } = string.Empty;

        [Required]
        [StringLength(100, MinimumLength = 8)]
        public string Password { get; set; } = string.Empty;
    }

    // DTO для логина (alias для совместимости)
    public class LoginDto
    {
        [Required]
        public string EmailOrUsername { get; set; } = string.Empty;

        [Required]
        public string Password { get; set; } = string.Empty;
    }

    // DTO для сброса пароля
    public class ResetPasswordDto
    {
        [Required]
        public string Token { get; set; } = string.Empty;

        [Required]
        [EmailAddress]
        public string Email { get; set; } = string.Empty;

        [Required]
        [StringLength(100, MinimumLength = 8)]
        public string NewPassword { get; set; } = string.Empty;
    }

    // DTO для изменения пароля
    public class ChangePasswordDto
    {
        [Required]
        public string CurrentPassword { get; set; } = string.Empty;

        [Required]
        [StringLength(100, MinimumLength = 8)]
        public string NewPassword { get; set; } = string.Empty;
    }

    // DTO для подтверждения email
    public class VerifyEmailDto
    {
        [Required]
        public string Token { get; set; } = string.Empty;
    }

    // DTO для запроса отправки письма верификации
    public class ResendVerificationDto
    {
        [Required]
        [EmailAddress]
        public string Email { get; set; } = string.Empty;
    }

    // DTO для запроса сброса пароля
    public class RequestPasswordResetDto
    {
        [Required]
        [EmailAddress]
        public string Email { get; set; } = string.Empty;
    }

    // DTO для включения двухфакторной аутентификации
    public class EnableTwoFactorDto
    {
        [Required]
        public string TwoFactorType { get; set; } = string.Empty;
    }

    // DTO для проверки кода двухфакторной аутентификации
    public class VerifyTwoFactorDto
    {
        [Required]
        public string Code { get; set; } = string.Empty;
    }

    // DTO для валидации JWT токена
    public class ValidateTokenDto
    {
        [Required]
        public string Token { get; set; } = string.Empty;
    }

    // DTO для ответа валидации токена
    public class TokenValidationDto
    {
        public bool IsValid { get; set; }
        public string Error { get; set; } = string.Empty;
        public Guid AccountId { get; set; }
        public Guid CharacterId { get; set; }
        public string CharacterName { get; set; } = string.Empty;
        public List<CharacterInfoDto> Characters { get; set; } = new List<CharacterInfoDto>();
    }
}