using System;
using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace Echoes.API.Migrations
{
    /// <inheritdoc />
    public partial class AddWorldObjectsPersistence : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "world_objects",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    TemplateId = table.Column<int>(type: "integer", nullable: false),
                    SystemId = table.Column<Guid>(type: "uuid", nullable: false),
                    PosX = table.Column<double>(type: "double precision", nullable: false),
                    PosY = table.Column<double>(type: "double precision", nullable: false),
                    PosZ = table.Column<double>(type: "double precision", nullable: false),
                    RotW = table.Column<float>(type: "real", nullable: false, defaultValue: 1.0f),
                    RotX = table.Column<float>(type: "real", nullable: false),
                    RotY = table.Column<float>(type: "real", nullable: false),
                    RotZ = table.Column<float>(type: "real", nullable: false),
                    InventoryJson = table.Column<string>(type: "jsonb", nullable: false, defaultValue: "{}"),
                    ExpirationTime = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    LastUpdated = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_world_objects", x => x.Id);
                    table.ForeignKey(
                        name: "FK_world_objects_solar_systems_SystemId",
                        column: x => x.SystemId,
                        principalTable: "solar_systems",
                        principalColumn: "system_id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateIndex(
                name: "IX_world_objects_SystemId",
                table: "world_objects",
                column: "SystemId");

            migrationBuilder.CreateIndex(
                name: "IX_world_objects_ExpirationTime",
                table: "world_objects",
                column: "ExpirationTime");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "world_objects");
        }
    }
}
