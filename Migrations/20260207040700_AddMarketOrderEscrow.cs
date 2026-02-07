using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace Echoes.API.Migrations
{
    /// <inheritdoc />
    public partial class AddMarketOrderEscrow : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<decimal>(
                name: "escrow",
                table: "market_orders",
                type: "numeric(18,2)",
                precision: 18,
                scale: 2,
                nullable: false,
                defaultValue: 0m);
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "escrow",
                table: "market_orders");
        }
    }
}
