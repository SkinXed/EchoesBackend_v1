using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.Logging;
using System.Net;
using System.Net.Mail;

namespace Echoes.API.Services.Email
{
    public class EmailService : IEmailService
    {
        private readonly ILogger<EmailService> _logger;
        private readonly IConfiguration _configuration;
        private readonly string? _smtpHost;
        private readonly int _smtpPort;
        private readonly string? _smtpUsername;
        private readonly string? _smtpPassword;
        private readonly string? _fromEmail;
        private readonly string? _fromName;
        private readonly bool _smtpEnabled;

        public EmailService(ILogger<EmailService> logger, IConfiguration configuration)
        {
            _logger = logger;
            _configuration = configuration;

            _smtpHost = configuration["Email:SmtpHost"];
            _smtpPort = int.TryParse(configuration["Email:SmtpPort"], out var port) ? port : 587;
            _smtpUsername = configuration["Email:SmtpUsername"];
            _smtpPassword = configuration["Email:SmtpPassword"];
            _fromEmail = configuration["Email:FromEmail"] ?? "noreply@echoes.game";
            _fromName = configuration["Email:FromName"] ?? "Echoes Game";
            _smtpEnabled = !string.IsNullOrEmpty(_smtpHost) && 
                          !string.IsNullOrEmpty(_smtpUsername) && 
                          !string.IsNullOrEmpty(_smtpPassword);
        }

        public async Task SendEmailVerificationAsync(string email, string username, string verificationToken)
        {
            var subject = "Verify your Echoes account";
            var verificationUrl = $"{_configuration["AppUrl"]}/verify-email?token={verificationToken}";
            var body = $@"
                <html>
                <body>
                    <h2>Welcome to Echoes, {username}!</h2>
                    <p>Thank you for registering. Please verify your email address by clicking the link below:</p>
                    <p><a href='{verificationUrl}'>Verify Email Address</a></p>
                    <p>Or copy and paste this link into your browser:</p>
                    <p>{verificationUrl}</p>
                    <p>This link will expire in 24 hours.</p>
                    <p>If you did not create this account, please ignore this email.</p>
                    <br>
                    <p>Best regards,<br>The Echoes Team</p>
                </body>
                </html>
            ";

            await SendEmailAsync(email, subject, body);
        }

        public async Task SendPasswordResetAsync(string email, string username, string resetToken)
        {
            var subject = "Reset your Echoes password";
            var resetUrl = $"{_configuration["AppUrl"]}/reset-password?token={resetToken}&email={Uri.EscapeDataString(email)}";
            var body = $@"
                <html>
                <body>
                    <h2>Password Reset Request</h2>
                    <p>Hello {username},</p>
                    <p>We received a request to reset your password. Click the link below to create a new password:</p>
                    <p><a href='{resetUrl}'>Reset Password</a></p>
                    <p>Or copy and paste this link into your browser:</p>
                    <p>{resetUrl}</p>
                    <p>This link will expire in 1 hour.</p>
                    <p>If you did not request a password reset, please ignore this email and your password will remain unchanged.</p>
                    <br>
                    <p>Best regards,<br>The Echoes Team</p>
                </body>
                </html>
            ";

            await SendEmailAsync(email, subject, body);
        }

        public async Task SendTwoFactorSetupAsync(string email, string username, string secret, string qrCodeUrl)
        {
            var subject = "Two-Factor Authentication Setup";
            var body = $@"
                <html>
                <body>
                    <h2>Two-Factor Authentication Setup</h2>
                    <p>Hello {username},</p>
                    <p>You have enabled two-factor authentication for your Echoes account.</p>
                    <p>To complete the setup, scan the QR code below with your authenticator app (such as Google Authenticator, Authy, or Microsoft Authenticator):</p>
                    <p><img src='{qrCodeUrl}' alt='QR Code' /></p>
                    <p>Or manually enter this secret key:</p>
                    <p><strong>{secret}</strong></p>
                    <p>After adding the account to your authenticator app, you will need to enter a 6-digit code from the app when logging in.</p>
                    <br>
                    <p>Best regards,<br>The Echoes Team</p>
                </body>
                </html>
            ";

            await SendEmailAsync(email, subject, body);
        }

        public async Task SendWelcomeEmailAsync(string email, string username)
        {
            var subject = "Welcome to Echoes!";
            var body = $@"
                <html>
                <body>
                    <h2>Welcome to Echoes, {username}!</h2>
                    <p>Your account has been successfully created and verified.</p>
                    <p>You can now log in and start your journey in the Echoes universe.</p>
                    <p>If you have any questions or need assistance, please don't hesitate to contact our support team.</p>
                    <br>
                    <p>Best regards,<br>The Echoes Team</p>
                </body>
                </html>
            ";

            await SendEmailAsync(email, subject, body);
        }

        private async Task SendEmailAsync(string to, string subject, string body)
        {
            if (_smtpEnabled)
            {
                try
                {
                    using var client = new SmtpClient(_smtpHost, _smtpPort)
                    {
                        Credentials = new NetworkCredential(_smtpUsername, _smtpPassword),
                        EnableSsl = true
                    };

                    var message = new MailMessage(_fromEmail!, to)
                    {
                        Subject = subject,
                        Body = body,
                        IsBodyHtml = true
                    };

                    message.From = new MailAddress(_fromEmail!, _fromName);

                    await client.SendMailAsync(message);
                    _logger.LogInformation("Email sent to {Email} with subject: {Subject}", to, subject);
                }
                catch (Exception ex)
                {
                    _logger.LogError(ex, "Failed to send email to {Email}", to);
                    throw;
                }
            }
            else
            {
                // For development: just log the email content
                _logger.LogWarning("SMTP not configured. Email would be sent to {Email}", to);
                _logger.LogInformation("Subject: {Subject}", subject);
                _logger.LogInformation("Body: {Body}", body);
            }
        }
    }
}
