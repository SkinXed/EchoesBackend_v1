using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace Echoes.API.Migrations
{
    /// <inheritdoc />
    public partial class AddPlanetAtmosphere : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<int>(
                name: "AtmosphereType",
                table: "Planets",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<bool>(
                name: "HasRings",
                table: "Planets",
                type: "boolean",
                nullable: false,
                defaultValue: false);

            migrationBuilder.AddColumn<double>(
                name: "Mass",
                table: "Planets",
                type: "double precision",
                nullable: false,
                defaultValue: 0.0);

            migrationBuilder.AddColumn<int>(
                name: "MoonCount",
                table: "Planets",
                type: "integer",
                nullable: false,
                defaultValue: 0);
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "AtmosphereType",
                table: "Planets");

            migrationBuilder.DropColumn(
                name: "HasRings",
                table: "Planets");

            migrationBuilder.DropColumn(
                name: "Mass",
                table: "Planets");

            migrationBuilder.DropColumn(
                name: "MoonCount",
                table: "Planets");
        }
    }
}
