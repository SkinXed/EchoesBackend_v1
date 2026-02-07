using System.ComponentModel.DataAnnotations;

namespace Echoes.API.Models.DTOs
{
    /// <summary>
    /// Request to initiate a jump between systems
    /// </summary>
    public class JumpRequestDto
    {
        /// <summary>
        /// Character attempting to jump
        /// </summary>
        [Required]
        public Guid CharacterId { get; set; }

        /// <summary>
        /// Stargate being used for the jump
        /// </summary>
        [Required]
        public Guid StargateId { get; set; }

        /// <summary>
        /// Destination solar system (from stargate configuration)
        /// </summary>
        [Required]
        public Guid DestinationSystemId { get; set; }

        /// <summary>
        /// Source system the character is jumping from
        /// </summary>
        [Required]
        public Guid SourceSystemId { get; set; }
    }

    /// <summary>
    /// Response containing jump ticket information
    /// </summary>
    public class JumpResponseDto
    {
        /// <summary>
        /// Whether the jump request was successful
        /// </summary>
        public bool Success { get; set; }

        /// <summary>
        /// Jump ticket ID (used for authentication on destination server)
        /// </summary>
        public string? TicketId { get; set; }

        /// <summary>
        /// Destination server address (IP:Port)
        /// </summary>
        public string? DestinationServerAddress { get; set; }

        /// <summary>
        /// Destination system information
        /// </summary>
        public DestinationSystemInfo? DestinationSystem { get; set; }

        /// <summary>
        /// When the ticket expires (UTC)
        /// </summary>
        public DateTime? ExpiresAt { get; set; }

        /// <summary>
        /// Error or success message
        /// </summary>
        public string Message { get; set; } = string.Empty;

        /// <summary>
        /// Reason for denial (if not successful)
        /// </summary>
        public string? DenialReason { get; set; }
    }

    /// <summary>
    /// Information about the destination system
    /// </summary>
    public class DestinationSystemInfo
    {
        public Guid SystemId { get; set; }
        public string SystemName { get; set; } = string.Empty;
        public double SecurityStatus { get; set; }
    }

    /// <summary>
    /// Request to redeem/validate a jump ticket
    /// </summary>
    public class RedeemTicketRequestDto
    {
        /// <summary>
        /// Jump ticket ID received from jump request
        /// </summary>
        [Required]
        public string TicketId { get; set; } = string.Empty;

        /// <summary>
        /// Character ID attempting to redeem ticket
        /// </summary>
        [Required]
        public Guid CharacterId { get; set; }

        /// <summary>
        /// System ID where the redemption is occurring
        /// </summary>
        [Required]
        public Guid SystemId { get; set; }
    }

    /// <summary>
    /// Response from ticket redemption
    /// </summary>
    public class RedeemTicketResponseDto
    {
        /// <summary>
        /// Whether the ticket is valid and was redeemed
        /// </summary>
        public bool Valid { get; set; }

        /// <summary>
        /// Character ID from the ticket
        /// </summary>
        public Guid? CharacterId { get; set; }

        /// <summary>
        /// Destination system from the ticket
        /// </summary>
        public Guid? DestinationSystemId { get; set; }

        /// <summary>
        /// Source system from the ticket
        /// </summary>
        public Guid? SourceSystemId { get; set; }

        /// <summary>
        /// Message describing the result
        /// </summary>
        public string Message { get; set; } = string.Empty;

        /// <summary>
        /// Reason for invalidity (if not valid)
        /// </summary>
        public string? InvalidReason { get; set; }
    }

    /// <summary>
    /// Jump ticket stored in cache
    /// </summary>
    public class JumpTicket
    {
        /// <summary>
        /// Unique ticket identifier
        /// </summary>
        public string TicketId { get; set; } = string.Empty;

        /// <summary>
        /// Character making the jump
        /// </summary>
        public Guid CharacterId { get; set; }

        /// <summary>
        /// Source system
        /// </summary>
        public Guid SourceSystemId { get; set; }

        /// <summary>
        /// Destination system
        /// </summary>
        public Guid DestinationSystemId { get; set; }

        /// <summary>
        /// Stargate used
        /// </summary>
        public Guid StargateId { get; set; }

        /// <summary>
        /// When the ticket was issued (UTC)
        /// </summary>
        public DateTime IssuedAt { get; set; }

        /// <summary>
        /// When the ticket expires (UTC)
        /// </summary>
        public DateTime ExpiresAt { get; set; }

        /// <summary>
        /// Current status of the ticket
        /// </summary>
        public JumpTicketStatus Status { get; set; }

        /// <summary>
        /// When the ticket was redeemed (if applicable)
        /// </summary>
        public DateTime? RedeemedAt { get; set; }
    }

    /// <summary>
    /// Status of a jump ticket
    /// </summary>
    public enum JumpTicketStatus
    {
        /// <summary>
        /// Ticket is pending use
        /// </summary>
        Pending = 0,

        /// <summary>
        /// Ticket has been redeemed
        /// </summary>
        Redeemed = 1,

        /// <summary>
        /// Ticket has expired
        /// </summary>
        Expired = 2,

        /// <summary>
        /// Ticket was cancelled
        /// </summary>
        Cancelled = 3
    }
}
