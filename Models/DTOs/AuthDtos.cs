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
        public Guid CharacterId { get; set; }
        public string CharacterName { get; set; } = string.Empty;
        public Guid SessionId { get; set; }
        public DateTime ExpiresAt { get; set; }
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
}