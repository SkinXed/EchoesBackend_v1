using System;
using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace Echoes.API.Migrations
{
    /// <inheritdoc />
    public partial class AddKillmailsTable : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "killmails",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    VictimId = table.Column<Guid>(type: "uuid", nullable: false),
                    FinalStrikerId = table.Column<Guid>(type: "uuid", nullable: false),
                    SolarSystemId = table.Column<Guid>(type: "uuid", nullable: false),
                    ShipTypeId = table.Column<int>(type: "integer", nullable: false),
                    ShipTypeName = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: false),
                    TotalLossValue = table.Column<decimal>(type: "numeric(18,2)", precision: 18, scale: 2, nullable: false),
                    KillmailDataJson = table.Column<string>(type: "jsonb", nullable: false),
                    KilledAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()")
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_killmails", x => x.Id);
                    table.ForeignKey(
                        name: "FK_killmails_Characters_VictimId",
                        column: x => x.VictimId,
                        principalTable: "Characters",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                });

            migrationBuilder.CreateIndex(
                name: "IX_killmails_VictimId",
                table: "killmails",
                column: "VictimId");

            migrationBuilder.CreateIndex(
                name: "IX_killmails_FinalStrikerId",
                table: "killmails",
                column: "FinalStrikerId");

            migrationBuilder.CreateIndex(
                name: "IX_killmails_SolarSystemId",
                table: "killmails",
                column: "SolarSystemId");

            migrationBuilder.CreateIndex(
                name: "IX_killmails_KilledAt",
                table: "killmails",
                column: "KilledAt",
                descending: new[] { true });
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "killmails");
        }
    }
}
