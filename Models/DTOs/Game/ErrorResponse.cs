namespace Echoes.API.Models.DTOs.Game
{
    public class ErrorResponse
    {
        public bool Success { get; set; } = false;
        public string Message { get; set; } = string.Empty;
        public string? Error { get; set; }
        public DateTime Timestamp { get; set; } = DateTime.UtcNow;

        public static ErrorResponse NotFound(string message)
        {
            return new ErrorResponse
            {
                Message = message,
                Error = "Not Found",
                Timestamp = DateTime.UtcNow
            };
        }

        public static ErrorResponse BadRequest(string message)
        {
            return new ErrorResponse
            {
                Message = message,
                Error = "Bad Request",
                Timestamp = DateTime.UtcNow
            };
        }

        public static ErrorResponse InternalServerError(string? message = null)
        {
            return new ErrorResponse
            {
                Message = message ?? "Internal server error",
                Error = "Internal Server Error",
                Timestamp = DateTime.UtcNow
            };
        }
    }
}
