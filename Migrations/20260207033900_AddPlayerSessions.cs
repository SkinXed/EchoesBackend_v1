using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace EchoesBackend_v1.Migrations
{
    /// <inheritdoc />
    public partial class AddPlayerSessions : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "player_sessions",
                columns: table => new
                {
                    session_id = table.Column<Guid>(type: "uuid", nullable: false),
                    character_id = table.Column<Guid>(type: "uuid", nullable: false),
                    current_system_id = table.Column<Guid>(type: "uuid", nullable: true),
                    server_address = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: false),
                    connected_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    last_heartbeat = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    is_active = table.Column<bool>(type: "boolean", nullable: false),
                    combat_until = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    aggression_until = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    disconnected_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    metadata = table.Column<string>(type: "jsonb", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_player_sessions", x => x.session_id);
                    table.ForeignKey(
                        name: "FK_player_sessions_characters_character_id",
                        column: x => x.character_id,
                        principalTable: "characters",
                        principalColumn: "character_id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_player_sessions_solar_systems_current_system_id",
                        column: x => x.current_system_id,
                        principalTable: "solar_systems",
                        principalColumn: "system_id",
                        onDelete: ReferentialAction.SetNull);
                });

            // Create indexes for performance
            migrationBuilder.CreateIndex(
                name: "IX_player_sessions_character_id_is_active",
                table: "player_sessions",
                columns: new[] { "character_id", "is_active" });

            migrationBuilder.CreateIndex(
                name: "IX_player_sessions_last_heartbeat",
                table: "player_sessions",
                column: "last_heartbeat");

            migrationBuilder.CreateIndex(
                name: "IX_player_sessions_is_active",
                table: "player_sessions",
                column: "is_active");

            migrationBuilder.CreateIndex(
                name: "IX_player_sessions_current_system_id",
                table: "player_sessions",
                column: "current_system_id");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "player_sessions");
        }
    }
}
