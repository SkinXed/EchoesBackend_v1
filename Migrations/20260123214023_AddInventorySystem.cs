using System;
using Microsoft.EntityFrameworkCore.Migrations;
using Npgsql.EntityFrameworkCore.PostgreSQL.Metadata;

#nullable disable

namespace Echoes.API.Migrations
{
    /// <inheritdoc />
    public partial class AddInventorySystem : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "containers",
                columns: table => new
                {
                    container_id = table.Column<Guid>(type: "uuid", nullable: false),
                    parent_container_id = table.Column<Guid>(type: "uuid", nullable: true),
                    owner_id = table.Column<Guid>(type: "uuid", nullable: false),
                    container_type = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: false),
                    name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: true),
                    max_volume = table.Column<decimal>(type: "numeric(15,4)", precision: 15, scale: 4, nullable: true),
                    used_volume = table.Column<decimal>(type: "numeric(15,4)", precision: 15, scale: 4, nullable: false),
                    location_x = table.Column<decimal>(type: "numeric(20,4)", precision: 20, scale: 4, nullable: true),
                    location_y = table.Column<decimal>(type: "numeric(20,4)", precision: 20, scale: 4, nullable: true),
                    location_z = table.Column<decimal>(type: "numeric(20,4)", precision: 20, scale: 4, nullable: true),
                    solar_system_id = table.Column<int>(type: "integer", nullable: true),
                    station_id = table.Column<int>(type: "integer", nullable: true),
                    is_accessible = table.Column<bool>(type: "boolean", nullable: false),
                    access_level = table.Column<int>(type: "integer", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()"),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()")
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_containers", x => x.container_id);
                    table.ForeignKey(
                        name: "FK_containers_containers_parent_container_id",
                        column: x => x.parent_container_id,
                        principalTable: "containers",
                        principalColumn: "container_id",
                        onDelete: ReferentialAction.Restrict);
                });

            migrationBuilder.CreateTable(
                name: "item_categories",
                columns: table => new
                {
                    category_id = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    name = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: false),
                    description = table.Column<string>(type: "text", nullable: true),
                    icon_name = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: true),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()")
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_item_categories", x => x.category_id);
                });

            migrationBuilder.CreateTable(
                name: "item_groups",
                columns: table => new
                {
                    group_id = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    category_id = table.Column<int>(type: "integer", nullable: true),
                    name = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: false),
                    volume_multiplier = table.Column<decimal>(type: "numeric(5,2)", precision: 5, scale: 2, nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()")
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_item_groups", x => x.group_id);
                    table.ForeignKey(
                        name: "FK_item_groups_item_categories_category_id",
                        column: x => x.category_id,
                        principalTable: "item_categories",
                        principalColumn: "category_id",
                        onDelete: ReferentialAction.Restrict);
                });

            migrationBuilder.CreateTable(
                name: "item_types",
                columns: table => new
                {
                    type_id = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    group_id = table.Column<int>(type: "integer", nullable: true),
                    name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    description = table.Column<string>(type: "text", nullable: true),
                    base_volume = table.Column<decimal>(type: "numeric(12,4)", precision: 12, scale: 4, nullable: false),
                    packaged_volume = table.Column<decimal>(type: "numeric(12,4)", precision: 12, scale: 4, nullable: false),
                    is_stackable = table.Column<bool>(type: "boolean", nullable: false),
                    max_stack_size = table.Column<int>(type: "integer", nullable: false),
                    is_online = table.Column<bool>(type: "boolean", nullable: false),
                    mass = table.Column<decimal>(type: "numeric(12,4)", precision: 12, scale: 4, nullable: true),
                    capacity = table.Column<decimal>(type: "numeric(12,4)", precision: 12, scale: 4, nullable: true),
                    market_group_id = table.Column<int>(type: "integer", nullable: true),
                    icon_id = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: true),
                    meta_level = table.Column<int>(type: "integer", nullable: false),
                    tech_level = table.Column<int>(type: "integer", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()"),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()")
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_item_types", x => x.type_id);
                    table.ForeignKey(
                        name: "FK_item_types_item_groups_group_id",
                        column: x => x.group_id,
                        principalTable: "item_groups",
                        principalColumn: "group_id",
                        onDelete: ReferentialAction.Restrict);
                });

            migrationBuilder.CreateTable(
                name: "assets",
                columns: table => new
                {
                    asset_id = table.Column<Guid>(type: "uuid", nullable: false),
                    type_id = table.Column<int>(type: "integer", nullable: false),
                    owner_id = table.Column<Guid>(type: "uuid", nullable: false),
                    location_id = table.Column<Guid>(type: "uuid", nullable: false),
                    location_flag = table.Column<int>(type: "integer", nullable: false),
                    quantity = table.Column<long>(type: "bigint", nullable: false),
                    is_singleton = table.Column<bool>(type: "boolean", nullable: false),
                    is_online = table.Column<bool>(type: "boolean", nullable: false),
                    is_bpc = table.Column<bool>(type: "boolean", nullable: false),
                    material_efficiency = table.Column<int>(type: "integer", nullable: false),
                    time_efficiency = table.Column<int>(type: "integer", nullable: false),
                    runs = table.Column<int>(type: "integer", nullable: false),
                    damage = table.Column<decimal>(type: "numeric(5,2)", precision: 5, scale: 2, nullable: false),
                    meta_data = table.Column<string>(type: "jsonb", nullable: true),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()"),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()")
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_assets", x => x.asset_id);
                    table.ForeignKey(
                        name: "FK_assets_containers_location_id",
                        column: x => x.location_id,
                        principalTable: "containers",
                        principalColumn: "container_id",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_assets_item_types_type_id",
                        column: x => x.type_id,
                        principalTable: "item_types",
                        principalColumn: "type_id",
                        onDelete: ReferentialAction.Restrict);
                });

            migrationBuilder.CreateTable(
                name: "modules",
                columns: table => new
                {
                    module_type_id = table.Column<int>(type: "integer", nullable: false),
                    name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    description = table.Column<string>(type: "text", nullable: true),
                    module_category = table.Column<int>(type: "integer", nullable: false),
                    slot_type = table.Column<int>(type: "integer", nullable: false),
                    required_cpu = table.Column<decimal>(type: "numeric(10,2)", precision: 10, scale: 2, nullable: false),
                    required_powergrid = table.Column<decimal>(type: "numeric(10,2)", precision: 10, scale: 2, nullable: false),
                    required_capacitor = table.Column<decimal>(type: "numeric(10,2)", precision: 10, scale: 2, nullable: false),
                    required_skills = table.Column<string>(type: "jsonb", nullable: false),
                    module_effects = table.Column<string>(type: "jsonb", nullable: false),
                    activation_cost = table.Column<decimal>(type: "numeric(10,2)", precision: 10, scale: 2, nullable: false),
                    activation_duration = table.Column<decimal>(type: "numeric(10,2)", precision: 10, scale: 2, nullable: false),
                    cooldown_time = table.Column<decimal>(type: "numeric(10,2)", precision: 10, scale: 2, nullable: false),
                    max_group_fitted = table.Column<int>(type: "integer", nullable: true),
                    meta_level = table.Column<int>(type: "integer", nullable: false),
                    tech_level = table.Column<int>(type: "integer", nullable: false),
                    race = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: true),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()"),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()")
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_modules", x => x.module_type_id);
                    table.ForeignKey(
                        name: "FK_modules_item_types_module_type_id",
                        column: x => x.module_type_id,
                        principalTable: "item_types",
                        principalColumn: "type_id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "ships",
                columns: table => new
                {
                    ship_type_id = table.Column<int>(type: "integer", nullable: false),
                    name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    description = table.Column<string>(type: "text", nullable: true),
                    ship_size = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: false),
                    tech_level = table.Column<int>(type: "integer", nullable: false),
                    race = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: true),
                    high_slots = table.Column<int>(type: "integer", nullable: false),
                    medium_slots = table.Column<int>(type: "integer", nullable: false),
                    low_slots = table.Column<int>(type: "integer", nullable: false),
                    rig_slots = table.Column<int>(type: "integer", nullable: false),
                    subsystem_slots = table.Column<int>(type: "integer", nullable: false),
                    drone_capacity = table.Column<int>(type: "integer", nullable: false),
                    drone_bandwidth = table.Column<int>(type: "integer", nullable: false),
                    base_cpu = table.Column<decimal>(type: "numeric(10,2)", precision: 10, scale: 2, nullable: false),
                    base_powergrid = table.Column<decimal>(type: "numeric(10,2)", precision: 10, scale: 2, nullable: false),
                    base_capacitor = table.Column<decimal>(type: "numeric(10,2)", precision: 10, scale: 2, nullable: false),
                    base_shield_hp = table.Column<decimal>(type: "numeric(12,2)", precision: 12, scale: 2, nullable: false),
                    base_armor_hp = table.Column<decimal>(type: "numeric(12,2)", precision: 12, scale: 2, nullable: false),
                    base_structure_hp = table.Column<decimal>(type: "numeric(12,2)", precision: 12, scale: 2, nullable: false),
                    base_speed = table.Column<decimal>(type: "numeric(10,2)", precision: 10, scale: 2, nullable: false),
                    base_agility = table.Column<decimal>(type: "numeric(10,4)", precision: 10, scale: 4, nullable: false),
                    base_signature_radius = table.Column<decimal>(type: "numeric(10,2)", precision: 10, scale: 2, nullable: false),
                    base_cargo_capacity = table.Column<decimal>(type: "numeric(12,2)", precision: 12, scale: 2, nullable: false),
                    shield_resistance_em = table.Column<decimal>(type: "numeric(5,3)", precision: 5, scale: 3, nullable: false),
                    shield_resistance_thermal = table.Column<decimal>(type: "numeric(5,3)", precision: 5, scale: 3, nullable: false),
                    shield_resistance_kinetic = table.Column<decimal>(type: "numeric(5,3)", precision: 5, scale: 3, nullable: false),
                    shield_resistance_explosive = table.Column<decimal>(type: "numeric(5,3)", precision: 5, scale: 3, nullable: false),
                    armor_resistance_em = table.Column<decimal>(type: "numeric(5,3)", precision: 5, scale: 3, nullable: false),
                    armor_resistance_thermal = table.Column<decimal>(type: "numeric(5,3)", precision: 5, scale: 3, nullable: false),
                    armor_resistance_kinetic = table.Column<decimal>(type: "numeric(5,3)", precision: 5, scale: 3, nullable: false),
                    armor_resistance_explosive = table.Column<decimal>(type: "numeric(5,3)", precision: 5, scale: 3, nullable: false),
                    structure_resistance_em = table.Column<decimal>(type: "numeric(5,3)", precision: 5, scale: 3, nullable: false),
                    structure_resistance_thermal = table.Column<decimal>(type: "numeric(5,3)", precision: 5, scale: 3, nullable: false),
                    structure_resistance_kinetic = table.Column<decimal>(type: "numeric(5,3)", precision: 5, scale: 3, nullable: false),
                    structure_resistance_explosive = table.Column<decimal>(type: "numeric(5,3)", precision: 5, scale: 3, nullable: false),
                    ship_bonuses = table.Column<string>(type: "jsonb", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()"),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()")
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_ships", x => x.ship_type_id);
                    table.ForeignKey(
                        name: "FK_ships_item_types_ship_type_id",
                        column: x => x.ship_type_id,
                        principalTable: "item_types",
                        principalColumn: "type_id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "asset_logs",
                columns: table => new
                {
                    log_id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    asset_id = table.Column<Guid>(type: "uuid", nullable: true),
                    actor_id = table.Column<Guid>(type: "uuid", nullable: false),
                    action_type = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: false),
                    old_location_id = table.Column<Guid>(type: "uuid", nullable: true),
                    new_location_id = table.Column<Guid>(type: "uuid", nullable: true),
                    old_quantity = table.Column<long>(type: "bigint", nullable: true),
                    new_quantity = table.Column<long>(type: "bigint", nullable: true),
                    old_flag = table.Column<int>(type: "integer", nullable: true),
                    new_flag = table.Column<int>(type: "integer", nullable: true),
                    reason = table.Column<string>(type: "text", nullable: true),
                    ip_address = table.Column<string>(type: "text", nullable: true),
                    user_agent = table.Column<string>(type: "text", nullable: true),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()")
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_asset_logs", x => x.log_id);
                    table.ForeignKey(
                        name: "FK_asset_logs_assets_asset_id",
                        column: x => x.asset_id,
                        principalTable: "assets",
                        principalColumn: "asset_id",
                        onDelete: ReferentialAction.SetNull);
                });

            migrationBuilder.CreateTable(
                name: "ship_fittings",
                columns: table => new
                {
                    fitting_id = table.Column<Guid>(type: "uuid", nullable: false),
                    ship_asset_id = table.Column<Guid>(type: "uuid", nullable: false),
                    name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    description = table.Column<string>(type: "text", nullable: true),
                    is_active = table.Column<bool>(type: "boolean", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()"),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()")
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_ship_fittings", x => x.fitting_id);
                    table.ForeignKey(
                        name: "FK_ship_fittings_assets_ship_asset_id",
                        column: x => x.ship_asset_id,
                        principalTable: "assets",
                        principalColumn: "asset_id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "fitted_modules",
                columns: table => new
                {
                    fitted_module_id = table.Column<Guid>(type: "uuid", nullable: false),
                    fitting_id = table.Column<Guid>(type: "uuid", nullable: false),
                    module_asset_id = table.Column<Guid>(type: "uuid", nullable: false),
                    slot_number = table.Column<int>(type: "integer", nullable: false),
                    slot_type = table.Column<int>(type: "integer", nullable: false),
                    is_online = table.Column<bool>(type: "boolean", nullable: false),
                    ammo_type_id = table.Column<int>(type: "integer", nullable: true),
                    ammo_quantity = table.Column<int>(type: "integer", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()")
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_fitted_modules", x => x.fitted_module_id);
                    table.ForeignKey(
                        name: "FK_fitted_modules_assets_module_asset_id",
                        column: x => x.module_asset_id,
                        principalTable: "assets",
                        principalColumn: "asset_id",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_fitted_modules_item_types_ammo_type_id",
                        column: x => x.ammo_type_id,
                        principalTable: "item_types",
                        principalColumn: "type_id",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_fitted_modules_ship_fittings_fitting_id",
                        column: x => x.fitting_id,
                        principalTable: "ship_fittings",
                        principalColumn: "fitting_id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateIndex(
                name: "IX_asset_logs_asset_id",
                table: "asset_logs",
                column: "asset_id");

            migrationBuilder.CreateIndex(
                name: "IX_asset_logs_created_at",
                table: "asset_logs",
                column: "created_at",
                descending: new bool[0]);

            migrationBuilder.CreateIndex(
                name: "IX_assets_is_bpc",
                table: "assets",
                column: "is_bpc",
                filter: "is_bpc = true");

            migrationBuilder.CreateIndex(
                name: "IX_assets_is_online",
                table: "assets",
                column: "is_online",
                filter: "is_online = true");

            migrationBuilder.CreateIndex(
                name: "IX_assets_is_singleton",
                table: "assets",
                column: "is_singleton",
                filter: "is_singleton = true");

            migrationBuilder.CreateIndex(
                name: "IX_assets_location_id",
                table: "assets",
                column: "location_id");

            migrationBuilder.CreateIndex(
                name: "IX_assets_location_id_location_flag",
                table: "assets",
                columns: new[] { "location_id", "location_flag" });

            migrationBuilder.CreateIndex(
                name: "IX_assets_owner_id",
                table: "assets",
                column: "owner_id");

            migrationBuilder.CreateIndex(
                name: "IX_assets_owner_id_location_id",
                table: "assets",
                columns: new[] { "owner_id", "location_id" });

            migrationBuilder.CreateIndex(
                name: "IX_assets_type_id",
                table: "assets",
                column: "type_id");

            migrationBuilder.CreateIndex(
                name: "IX_containers_container_type",
                table: "containers",
                column: "container_type");

            migrationBuilder.CreateIndex(
                name: "IX_containers_owner_id",
                table: "containers",
                column: "owner_id");

            migrationBuilder.CreateIndex(
                name: "IX_containers_parent_container_id",
                table: "containers",
                column: "parent_container_id");

            migrationBuilder.CreateIndex(
                name: "IX_fitted_modules_ammo_type_id",
                table: "fitted_modules",
                column: "ammo_type_id");

            migrationBuilder.CreateIndex(
                name: "IX_fitted_modules_fitting_id",
                table: "fitted_modules",
                column: "fitting_id");

            migrationBuilder.CreateIndex(
                name: "IX_fitted_modules_module_asset_id",
                table: "fitted_modules",
                column: "module_asset_id");

            migrationBuilder.CreateIndex(
                name: "IX_item_categories_name",
                table: "item_categories",
                column: "name",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_item_groups_category_id",
                table: "item_groups",
                column: "category_id");

            migrationBuilder.CreateIndex(
                name: "IX_item_groups_name",
                table: "item_groups",
                column: "name",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_item_types_group_id",
                table: "item_types",
                column: "group_id");

            migrationBuilder.CreateIndex(
                name: "IX_item_types_name",
                table: "item_types",
                column: "name");

            migrationBuilder.CreateIndex(
                name: "IX_modules_slot_type",
                table: "modules",
                column: "slot_type");

            migrationBuilder.CreateIndex(
                name: "IX_ship_fittings_ship_asset_id",
                table: "ship_fittings",
                column: "ship_asset_id");

            migrationBuilder.CreateIndex(
                name: "IX_ships_race",
                table: "ships",
                column: "race");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "asset_logs");

            migrationBuilder.DropTable(
                name: "fitted_modules");

            migrationBuilder.DropTable(
                name: "modules");

            migrationBuilder.DropTable(
                name: "ships");

            migrationBuilder.DropTable(
                name: "ship_fittings");

            migrationBuilder.DropTable(
                name: "assets");

            migrationBuilder.DropTable(
                name: "containers");

            migrationBuilder.DropTable(
                name: "item_types");

            migrationBuilder.DropTable(
                name: "item_groups");

            migrationBuilder.DropTable(
                name: "item_categories");
        }
    }
}
