using System.Security.Cryptography;
using System.Text;

namespace Echoes.API.Services.Auth
{
    public interface ITwoFactorAuthService
    {
        string GenerateSecret();
        string GenerateQrCodeUrl(string accountName, string issuer, string secret);
        bool ValidateCode(string secret, string code);
        string GenerateCode(string secret);
    }

    public class TwoFactorAuthService : ITwoFactorAuthService
    {
        private const int CodeLength = 6;
        private const int TimeStepSeconds = 30;

        public string GenerateSecret()
        {
            // Generate a 20-byte (160-bit) secret key
            var secretBytes = RandomNumberGenerator.GetBytes(20);
            return Base32Encode(secretBytes);
        }

        public string GenerateQrCodeUrl(string accountName, string issuer, string secret)
        {
            var encodedIssuer = Uri.EscapeDataString(issuer);
            var encodedAccount = Uri.EscapeDataString(accountName);
            var otpauthUrl = $"otpauth://totp/{encodedIssuer}:{encodedAccount}?secret={secret}&issuer={encodedIssuer}";
            
            // Return a URL that can be used to generate QR code
            // Using a QR code generator service
            return $"https://api.qrserver.com/v1/create-qr-code/?size=200x200&data={Uri.EscapeDataString(otpauthUrl)}";
        }

        public bool ValidateCode(string secret, string code)
        {
            if (string.IsNullOrEmpty(secret) || string.IsNullOrEmpty(code))
                return false;

            // Validate the code for current time window and adjacent windows (to account for time drift)
            var currentTime = DateTimeOffset.UtcNow.ToUnixTimeSeconds();
            
            for (int i = -1; i <= 1; i++)
            {
                var timeStep = (currentTime / TimeStepSeconds) + i;
                var expectedCode = GenerateCodeForTimeStep(secret, timeStep);
                
                if (expectedCode == code)
                    return true;
            }

            return false;
        }

        public string GenerateCode(string secret)
        {
            var currentTime = DateTimeOffset.UtcNow.ToUnixTimeSeconds();
            var timeStep = currentTime / TimeStepSeconds;
            return GenerateCodeForTimeStep(secret, timeStep);
        }

        private string GenerateCodeForTimeStep(string secret, long timeStep)
        {
            var secretBytes = Base32Decode(secret);
            var timeBytes = BitConverter.GetBytes(timeStep);
            
            if (BitConverter.IsLittleEndian)
                Array.Reverse(timeBytes);

            using var hmac = new HMACSHA1(secretBytes);
            var hash = hmac.ComputeHash(timeBytes);

            // Dynamic truncation
            var offset = hash[hash.Length - 1] & 0x0F;
            var binaryCode = ((hash[offset] & 0x7F) << 24)
                           | ((hash[offset + 1] & 0xFF) << 16)
                           | ((hash[offset + 2] & 0xFF) << 8)
                           | (hash[offset + 3] & 0xFF);

            var code = binaryCode % (int)Math.Pow(10, CodeLength);
            return code.ToString().PadLeft(CodeLength, '0');
        }

        private static string Base32Encode(byte[] data)
        {
            const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
            var result = new StringBuilder();
            int buffer = data[0];
            int next = 1;
            int bitsLeft = 8;

            while (bitsLeft > 0 || next < data.Length)
            {
                if (bitsLeft < 5)
                {
                    if (next < data.Length)
                    {
                        buffer <<= 8;
                        buffer |= data[next++] & 0xFF;
                        bitsLeft += 8;
                    }
                    else
                    {
                        int pad = 5 - bitsLeft;
                        buffer <<= pad;
                        bitsLeft += pad;
                    }
                }

                int index = (buffer >> (bitsLeft - 5)) & 0x1F;
                bitsLeft -= 5;
                result.Append(alphabet[index]);
            }

            return result.ToString();
        }

        private static byte[] Base32Decode(string encoded)
        {
            const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
            encoded = encoded.TrimEnd('=').ToUpper();
            
            var output = new List<byte>();
            int buffer = 0;
            int bitsLeft = 0;

            foreach (char c in encoded)
            {
                int value = alphabet.IndexOf(c);
                if (value < 0)
                    throw new ArgumentException("Invalid Base32 character");

                buffer <<= 5;
                buffer |= value & 0x1F;
                bitsLeft += 5;

                if (bitsLeft >= 8)
                {
                    output.Add((byte)(buffer >> (bitsLeft - 8)));
                    bitsLeft -= 8;
                }
            }

            return output.ToArray();
        }
    }
}
