using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace Echoes.API.Migrations
{
    /// <summary>
    /// Add SequenceNumber field to character_states for optimistic concurrency control
    /// Prevents race conditions when multiple state updates arrive out of order
    /// </summary>
    public partial class AddSequenceNumberToCharacterState : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<long>(
                name: "SequenceNumber",
                table: "character_states",
                type: "bigint",
                nullable: false,
                defaultValue: 0L);

            // Create index for faster sequence number lookups
            migrationBuilder.CreateIndex(
                name: "IX_character_states_SequenceNumber",
                table: "character_states",
                column: "SequenceNumber");
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropIndex(
                name: "IX_character_states_SequenceNumber",
                table: "character_states");

            migrationBuilder.DropColumn(
                name: "SequenceNumber",
                table: "character_states");
        }
    }
}
