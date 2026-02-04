using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace Echoes.API.Migrations
{
    /// <inheritdoc />
    public partial class RenameStartingISKToStartingCredits : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.RenameColumn(
                name: "StartingISK",
                table: "race_configs",
                newName: "StartingCredits");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.RenameColumn(
                name: "StartingCredits",
                table: "race_configs",
                newName: "StartingISK");
        }
    }
}
