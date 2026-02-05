using System;
using Microsoft.EntityFrameworkCore.Migrations;
using Npgsql.EntityFrameworkCore.PostgreSQL.Metadata;

#nullable disable

#pragma warning disable CA1814 // Prefer jagged arrays over multidimensional

namespace Echoes.API.Migrations
{
    /// <inheritdoc />
    public partial class AddFactionsAndSkillGroups : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.RenameColumn(
                name: "skill_group",
                table: "skills",
                newName: "skill_group_id");

            migrationBuilder.AddColumn<int>(
                name: "faction_id",
                table: "Characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.CreateTable(
                name: "factions",
                columns: table => new
                {
                    faction_id = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    name = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: false),
                    config_json = table.Column<string>(type: "text", nullable: false),
                    description = table.Column<string>(type: "text", nullable: true),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_factions", x => x.faction_id);
                });

            migrationBuilder.CreateTable(
                name: "skill_groups",
                columns: table => new
                {
                    skill_group_id = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    name = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: false),
                    description = table.Column<string>(type: "text", nullable: true),
                    config_json = table.Column<string>(type: "text", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_skill_groups", x => x.skill_group_id);
                });

            migrationBuilder.InsertData(
                table: "factions",
                columns: new[] { "faction_id", "config_json", "created_at", "description", "name", "updated_at" },
                values: new object[,]
                {
                    { 1, "{}", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc), "Faction Arden", "Arden", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc) },
                    { 2, "{}", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc), "Faction Nova", "Nova", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc) },
                    { 3, "{}", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc), "Faction Solaris", "Solaris", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc) },
                    { 4, "{}", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc), "Faction Valerion", "Valerion", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc) }
                });

            migrationBuilder.InsertData(
                table: "skill_groups",
                columns: new[] { "skill_group_id", "config_json", "created_at", "description", "name", "updated_at" },
                values: new object[,]
                {
                    { 1, "{}", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc), "Gunnery skills", "Gunnery", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc) },
                    { 2, "{}", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc), "Missile skills", "Missiles", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc) },
                    { 3, "{}", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc), "Drone skills", "Drones", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc) },
                    { 4, "{}", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc), "Navigation skills", "Navigation", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc) },
                    { 5, "{}", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc), "Targeting skills", "Targeting", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc) },
                    { 6, "{}", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc), "Engineering skills", "Engineering", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc) },
                    { 7, "{}", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc), "Electronics skills", "Electronics", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc) },
                    { 8, "{}", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc), "Mechanics skills", "Mechanics", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc) },
                    { 9, "{}", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc), "Shield skills", "Shield", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc) },
                    { 10, "{}", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc), "Armor skills", "Armor", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc) },
                    { 11, "{}", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc), "Spaceship Command skills", "SpaceshipCommand", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc) },
                    { 12, "{}", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc), "Frigate skills", "Frigate", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc) },
                    { 13, "{}", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc), "Cruiser skills", "Cruiser", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc) },
                    { 14, "{}", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc), "Battleship skills", "Battleship", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc) },
                    { 15, "{}", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc), "Industrial skills", "Industrial", new DateTime(2026, 2, 5, 0, 0, 0, 0, DateTimeKind.Utc) }
                });

            migrationBuilder.CreateIndex(
                name: "IX_skills_skill_group_id",
                table: "skills",
                column: "skill_group_id");

            migrationBuilder.CreateIndex(
                name: "IX_Characters_faction_id",
                table: "Characters",
                column: "faction_id");

            migrationBuilder.AddForeignKey(
                name: "FK_Characters_factions_faction_id",
                table: "Characters",
                column: "faction_id",
                principalTable: "factions",
                principalColumn: "faction_id",
                onDelete: ReferentialAction.Restrict);

            migrationBuilder.AddForeignKey(
                name: "FK_skills_skill_groups_skill_group_id",
                table: "skills",
                column: "skill_group_id",
                principalTable: "skill_groups",
                principalColumn: "skill_group_id",
                onDelete: ReferentialAction.Restrict);
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Characters_factions_faction_id",
                table: "Characters");

            migrationBuilder.DropForeignKey(
                name: "FK_skills_skill_groups_skill_group_id",
                table: "skills");

            migrationBuilder.DropTable(
                name: "factions");

            migrationBuilder.DropTable(
                name: "skill_groups");

            migrationBuilder.DropIndex(
                name: "IX_skills_skill_group_id",
                table: "skills");

            migrationBuilder.DropIndex(
                name: "IX_Characters_faction_id",
                table: "Characters");

            migrationBuilder.DropColumn(
                name: "faction_id",
                table: "Characters");

            migrationBuilder.RenameColumn(
                name: "skill_group_id",
                table: "skills",
                newName: "skill_group");
        }
    }
}
