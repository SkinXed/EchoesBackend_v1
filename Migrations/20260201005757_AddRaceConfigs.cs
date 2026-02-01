using System;
using Microsoft.EntityFrameworkCore.Migrations;
using Npgsql.EntityFrameworkCore.PostgreSQL.Metadata;

#nullable disable

namespace Echoes.API.Migrations
{
    /// <inheritdoc />
    public partial class AddRaceConfigs : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<decimal>(
                name: "base_mass",
                table: "ships",
                type: "numeric",
                nullable: false,
                defaultValue: 0m);

            migrationBuilder.AddColumn<decimal>(
                name: "inertia_multiplier",
                table: "ships",
                type: "numeric",
                nullable: false,
                defaultValue: 0m);

            migrationBuilder.AddColumn<decimal>(
                name: "max_velocity",
                table: "ships",
                type: "numeric",
                nullable: false,
                defaultValue: 0m);

            migrationBuilder.AddColumn<decimal>(
                name: "rotation_speed",
                table: "ships",
                type: "numeric",
                nullable: false,
                defaultValue: 0m);

            migrationBuilder.AddColumn<decimal>(
                name: "thrust",
                table: "ships",
                type: "numeric",
                nullable: false,
                defaultValue: 0m);

            migrationBuilder.AddColumn<decimal>(
                name: "warp_speed",
                table: "ships",
                type: "numeric",
                nullable: false,
                defaultValue: 0m);

            migrationBuilder.AddColumn<Guid>(
                name: "HomeStationId",
                table: "Characters",
                type: "uuid",
                nullable: true);

            migrationBuilder.CreateTable(
                name: "race_configs",
                columns: table => new
                {
                    RaceId = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    RaceName = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: false),
                    Description = table.Column<string>(type: "character varying(500)", maxLength: 500, nullable: false),
                    StartingSystemId = table.Column<Guid>(type: "uuid", nullable: false),
                    StartingStationId = table.Column<Guid>(type: "uuid", nullable: false),
                    DefaultShipTypeId = table.Column<int>(type: "integer", nullable: false),
                    RaceBonuses = table.Column<string>(type: "character varying(1000)", maxLength: 1000, nullable: false),
                    StartingSkillPoints = table.Column<int>(type: "integer", nullable: false),
                    StartingISK = table.Column<long>(type: "bigint", nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    UpdatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_race_configs", x => x.RaceId);
                });

            migrationBuilder.CreateTable(
                name: "ship_instances",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    name = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: false),
                    ship_type_id = table.Column<int>(type: "integer", nullable: false),
                    character_id = table.Column<Guid>(type: "uuid", nullable: false),
                    location_system_id = table.Column<Guid>(type: "uuid", nullable: true),
                    is_active = table.Column<bool>(type: "boolean", nullable: false),
                    is_docked = table.Column<bool>(type: "boolean", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_ship_instances", x => x.Id);
                    table.ForeignKey(
                        name: "FK_ship_instances_Characters_character_id",
                        column: x => x.character_id,
                        principalTable: "Characters",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_ship_instances_ships_ship_type_id",
                        column: x => x.ship_type_id,
                        principalTable: "ships",
                        principalColumn: "ship_type_id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "ship_instance_modules",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    ship_instance_id = table.Column<Guid>(type: "uuid", nullable: true),
                    module_type_id = table.Column<int>(type: "integer", nullable: false),
                    mass = table.Column<decimal>(type: "numeric", nullable: false),
                    slot = table.Column<string>(type: "character varying(20)", maxLength: 20, nullable: false),
                    slot_index = table.Column<int>(type: "integer", nullable: false),
                    is_online = table.Column<bool>(type: "boolean", nullable: false),
                    thrust_bonus = table.Column<decimal>(type: "numeric", nullable: false),
                    inertia_modifier = table.Column<decimal>(type: "numeric", nullable: false),
                    rotation_bonus = table.Column<decimal>(type: "numeric", nullable: false),
                    max_velocity_modifier = table.Column<decimal>(type: "numeric", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_ship_instance_modules", x => x.Id);
                    table.ForeignKey(
                        name: "FK_ship_instance_modules_ship_instances_ship_instance_id",
                        column: x => x.ship_instance_id,
                        principalTable: "ship_instances",
                        principalColumn: "Id");
                });

            migrationBuilder.CreateIndex(
                name: "IX_ship_instance_modules_ship_instance_id",
                table: "ship_instance_modules",
                column: "ship_instance_id");

            migrationBuilder.CreateIndex(
                name: "IX_ship_instances_character_id",
                table: "ship_instances",
                column: "character_id");

            migrationBuilder.CreateIndex(
                name: "IX_ship_instances_ship_type_id",
                table: "ship_instances",
                column: "ship_type_id");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "race_configs");

            migrationBuilder.DropTable(
                name: "ship_instance_modules");

            migrationBuilder.DropTable(
                name: "ship_instances");

            migrationBuilder.DropColumn(
                name: "base_mass",
                table: "ships");

            migrationBuilder.DropColumn(
                name: "inertia_multiplier",
                table: "ships");

            migrationBuilder.DropColumn(
                name: "max_velocity",
                table: "ships");

            migrationBuilder.DropColumn(
                name: "rotation_speed",
                table: "ships");

            migrationBuilder.DropColumn(
                name: "thrust",
                table: "ships");

            migrationBuilder.DropColumn(
                name: "warp_speed",
                table: "ships");

            migrationBuilder.DropColumn(
                name: "HomeStationId",
                table: "Characters");
        }
    }
}
