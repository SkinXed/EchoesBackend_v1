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
                    { 1, "{}", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6613), "Faction Arden", "Arden", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6613) },
                    { 2, "{}", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6616), "Faction Nova", "Nova", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6616) },
                    { 3, "{}", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6618), "Faction Solaris", "Solaris", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6619) },
                    { 4, "{}", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6621), "Faction Valerion", "Valerion", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6621) }
                });

            migrationBuilder.InsertData(
                table: "skill_groups",
                columns: new[] { "skill_group_id", "config_json", "created_at", "description", "name", "updated_at" },
                values: new object[,]
                {
                    { 1, "{}", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6840), "Gunnery skills", "Gunnery", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6840) },
                    { 2, "{}", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6842), "Missile skills", "Missiles", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6843) },
                    { 3, "{}", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6845), "Drone skills", "Drones", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6845) },
                    { 4, "{}", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6854), "Navigation skills", "Navigation", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6854) },
                    { 5, "{}", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6856), "Targeting skills", "Targeting", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6857) },
                    { 6, "{}", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6858), "Engineering skills", "Engineering", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6859) },
                    { 7, "{}", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6861), "Electronics skills", "Electronics", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6861) },
                    { 8, "{}", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6863), "Mechanics skills", "Mechanics", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6864) },
                    { 9, "{}", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6865), "Shield skills", "Shield", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6866) },
                    { 10, "{}", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6868), "Armor skills", "Armor", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6868) },
                    { 11, "{}", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6870), "Spaceship Command skills", "SpaceshipCommand", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6870) },
                    { 12, "{}", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6872), "Frigate skills", "Frigate", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6873) },
                    { 13, "{}", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6874), "Cruiser skills", "Cruiser", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6875) },
                    { 14, "{}", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6877), "Battleship skills", "Battleship", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6877) },
                    { 15, "{}", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6879), "Industrial skills", "Industrial", new DateTime(2026, 2, 5, 2, 44, 49, 405, DateTimeKind.Utc).AddTicks(6880) }
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
