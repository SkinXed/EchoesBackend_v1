using System;
using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace Echoes.API.Migrations
{
    /// <inheritdoc />
    public partial class AddCharacterStatePersistence : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "character_states",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    CharacterId = table.Column<Guid>(type: "uuid", nullable: false),
                    LastSystemId = table.Column<Guid>(type: "uuid", nullable: true),
                    PosX = table.Column<double>(type: "double precision", nullable: false),
                    PosY = table.Column<double>(type: "double precision", nullable: false),
                    PosZ = table.Column<double>(type: "double precision", nullable: false),
                    RotW = table.Column<float>(type: "real", nullable: false, defaultValue: 1.0f),
                    RotX = table.Column<float>(type: "real", nullable: false),
                    RotY = table.Column<float>(type: "real", nullable: false),
                    RotZ = table.Column<float>(type: "real", nullable: false),
                    CurrentShield = table.Column<float>(type: "real", nullable: false),
                    CurrentArmor = table.Column<float>(type: "real", nullable: false),
                    CurrentHull = table.Column<float>(type: "real", nullable: false),
                    CurrentCapacitor = table.Column<float>(type: "real", nullable: false),
                    LastUpdated = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_character_states", x => x.Id);
                    table.ForeignKey(
                        name: "FK_character_states_characters_CharacterId",
                        column: x => x.CharacterId,
                        principalTable: "characters",
                        principalColumn: "character_id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_character_states_solar_systems_LastSystemId",
                        column: x => x.LastSystemId,
                        principalTable: "solar_systems",
                        principalColumn: "system_id",
                        onDelete: ReferentialAction.SetNull);
                });

            migrationBuilder.CreateIndex(
                name: "IX_character_states_CharacterId",
                table: "character_states",
                column: "CharacterId",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_character_states_LastSystemId",
                table: "character_states",
                column: "LastSystemId");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "character_states");
        }
    }
}
