namespace Echoes.API.Services.Email
{
    public interface IEmailService
    {
        Task SendEmailVerificationAsync(string email, string username, string verificationToken);
        Task SendPasswordResetAsync(string email, string username, string resetToken);
        Task SendTwoFactorSetupAsync(string email, string username, string secret, string qrCodeUrl);
        Task SendWelcomeEmailAsync(string email, string username);
    }
}
