using System;
using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace Echoes.API.Migrations
{
    /// <inheritdoc />
    public partial class AddMarketOrders : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "market_orders",
                columns: table => new
                {
                    id = table.Column<Guid>(type: "uuid", nullable: false),
                    character_id = table.Column<Guid>(type: "uuid", nullable: false),
                    item_id = table.Column<int>(type: "integer", nullable: false),
                    is_buy_order = table.Column<bool>(type: "boolean", nullable: false),
                    price = table.Column<decimal>(type: "numeric(18,2)", precision: 18, scale: 2, nullable: false),
                    quantity = table.Column<int>(type: "integer", nullable: false),
                    remaining_quantity = table.Column<int>(type: "integer", nullable: false),
                    station_id = table.Column<Guid>(type: "uuid", nullable: false),
                    region_id = table.Column<Guid>(type: "uuid", nullable: false),
                    duration = table.Column<int>(type: "integer", nullable: false),
                    status = table.Column<string>(type: "text", nullable: false),
                    broker_fee = table.Column<decimal>(type: "numeric(18,2)", precision: 18, scale: 2, nullable: false),
                    issued_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()"),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_market_orders", x => x.id);
                    table.ForeignKey(
                        name: "FK_market_orders_characters_character_id",
                        column: x => x.character_id,
                        principalTable: "characters",
                        principalColumn: "character_id",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_market_orders_Stations_station_id",
                        column: x => x.station_id,
                        principalTable: "Stations",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_market_orders_Regions_region_id",
                        column: x => x.region_id,
                        principalTable: "Regions",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                });

            migrationBuilder.CreateIndex(
                name: "IX_market_orders_RegionId_ItemId_Status",
                table: "market_orders",
                columns: new[] { "region_id", "item_id", "status" });

            migrationBuilder.CreateIndex(
                name: "IX_market_orders_CharacterId",
                table: "market_orders",
                column: "character_id");

            migrationBuilder.CreateIndex(
                name: "IX_market_orders_StationId",
                table: "market_orders",
                column: "station_id");

            migrationBuilder.CreateIndex(
                name: "IX_market_orders_IssuedAt",
                table: "market_orders",
                column: "issued_at",
                descending: new[] { true });
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "market_orders");
        }
    }
}
