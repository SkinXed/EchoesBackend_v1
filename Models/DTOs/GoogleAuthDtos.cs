using System.ComponentModel.DataAnnotations;

namespace Echoes.API.Models.DTOs;

public class GoogleLoginRequestDto
{
    [Required(ErrorMessage = "Google ID token is required")]
    public string GoogleIdToken { get; set; } = string.Empty;
}

public class GoogleRegisterRequestDto
{
    [Required(ErrorMessage = "Google ID token is required")]
    public string GoogleIdToken { get; set; } = string.Empty;
    
    [Required(ErrorMessage = "Nickname is required")]
    [StringLength(50, MinimumLength = 3, ErrorMessage = "Nickname must be between 3 and 50 characters")]
    public string Nickname { get; set; } = string.Empty;
}

public class GoogleAuthResponseDto
{
    public bool Success { get; set; }
    public string? Token { get; set; }
    public Guid? CharacterId { get; set; }
    public string? CharacterName { get; set; }
    public bool RegistrationNeeded { get; set; }
    public string? Email { get; set; }
    public string? Error { get; set; }
}
