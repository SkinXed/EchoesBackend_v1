using System;
using Microsoft.EntityFrameworkCore.Migrations;
using Npgsql.EntityFrameworkCore.PostgreSQL.Metadata;

#nullable disable

namespace Echoes.API.Migrations
{
    /// <inheritdoc />
    public partial class InitialCreate : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "accounts",
                columns: table => new
                {
                    account_id = table.Column<Guid>(type: "uuid", nullable: false),
                    email = table.Column<string>(type: "text", nullable: false),
                    username = table.Column<string>(type: "text", nullable: false),
                    display_name = table.Column<string>(type: "text", nullable: true),
                    nickname = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: true),
                    google_id = table.Column<string>(type: "character varying(255)", maxLength: 255, nullable: true),
                    password_hash = table.Column<byte[]>(type: "bytea", nullable: false),
                    password_salt = table.Column<byte[]>(type: "bytea", nullable: false),
                    phone_number = table.Column<string>(type: "text", nullable: true),
                    account_type = table.Column<int>(type: "integer", nullable: false),
                    account_status = table.Column<int>(type: "integer", nullable: false, defaultValue: 1),
                    roles = table.Column<long>(type: "bigint", nullable: false),
                    subscription_type = table.Column<int>(type: "integer", nullable: false),
                    subscription_start = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    subscription_end = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    trial_ends_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    two_factor_type = table.Column<int>(type: "integer", nullable: false),
                    two_factor_secret = table.Column<string>(type: "text", nullable: true),
                    two_factor_recovery_codes = table.Column<string>(type: "text", nullable: true),
                    is_email_verified = table.Column<bool>(type: "boolean", nullable: false),
                    email_verified_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    email_verification_token = table.Column<string>(type: "text", nullable: true),
                    phone_verified_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    failed_login_attempts = table.Column<int>(type: "integer", nullable: false),
                    locked_until = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    last_login = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    last_login_ip = table.Column<string>(type: "text", nullable: true),
                    last_active = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    password_changed_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    password_reset_token = table.Column<string>(type: "text", nullable: true),
                    password_reset_expires = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    notification_settings = table.Column<long>(type: "bigint", nullable: false),
                    language = table.Column<string>(type: "text", nullable: false),
                    timezone = table.Column<string>(type: "text", nullable: false),
                    country_code = table.Column<string>(type: "text", nullable: true),
                    referral_code = table.Column<string>(type: "text", nullable: false),
                    referred_by = table.Column<string>(type: "text", nullable: true),
                    total_play_time = table.Column<long>(type: "bigint", nullable: false),
                    total_characters = table.Column<int>(type: "integer", nullable: false),
                    total_spent = table.Column<decimal>(type: "numeric", nullable: false),
                    total_referrals = table.Column<int>(type: "integer", nullable: false),
                    metadata = table.Column<string>(type: "text", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()"),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    is_active = table.Column<bool>(type: "boolean", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_accounts", x => x.account_id);
                });

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
                    StartingCredits = table.Column<long>(type: "bigint", nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    UpdatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_race_configs", x => x.RaceId);
                });

            migrationBuilder.CreateTable(
                name: "shop_items",
                columns: table => new
                {
                    id = table.Column<Guid>(type: "uuid", nullable: false),
                    name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    description = table.Column<string>(type: "character varying(1000)", maxLength: 1000, nullable: false),
                    price = table.Column<long>(type: "bigint", nullable: false),
                    category = table.Column<int>(type: "integer", nullable: false),
                    image_url = table.Column<string>(type: "character varying(500)", maxLength: 500, nullable: true),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    is_active = table.Column<bool>(type: "boolean", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_shop_items", x => x.id);
                });

            migrationBuilder.CreateTable(
                name: "skills",
                columns: table => new
                {
                    skill_id = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    name = table.Column<string>(type: "text", nullable: false),
                    description = table.Column<string>(type: "text", nullable: false),
                    skill_group = table.Column<int>(type: "integer", nullable: false),
                    skill_type = table.Column<int>(type: "integer", nullable: false),
                    rank = table.Column<decimal>(type: "numeric", nullable: false),
                    primary_attribute = table.Column<int>(type: "integer", nullable: false),
                    secondary_attribute = table.Column<int>(type: "integer", nullable: false),
                    required_skills = table.Column<string>(type: "text", nullable: false),
                    bonus_effects = table.Column<string>(type: "text", nullable: false),
                    icon_id = table.Column<string>(type: "text", nullable: true),
                    market_group_id = table.Column<int>(type: "integer", nullable: true),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_skills", x => x.skill_id);
                });

            migrationBuilder.CreateTable(
                name: "universe_generation_configs",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    ConfigName = table.Column<string>(type: "character varying(255)", maxLength: 255, nullable: false),
                    Description = table.Column<string>(type: "character varying(500)", maxLength: 500, nullable: false),
                    ConfigJson = table.Column<string>(type: "jsonb", nullable: false),
                    UniverseSeed = table.Column<string>(type: "text", nullable: true),
                    UseSeedBasedGeneration = table.Column<bool>(type: "boolean", nullable: false),
                    SeedVersion = table.Column<int>(type: "integer", nullable: false),
                    GeneratorVersion = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: false),
                    IsPreset = table.Column<bool>(type: "boolean", nullable: false),
                    IsActive = table.Column<bool>(type: "boolean", nullable: false),
                    Tags = table.Column<string>(type: "text", nullable: true),
                    RegionCount = table.Column<int>(type: "integer", nullable: false),
                    SystemCount = table.Column<int>(type: "integer", nullable: false),
                    PlanetCount = table.Column<int>(type: "integer", nullable: false),
                    Anomalies = table.Column<string>(type: "jsonb", nullable: false),
                    Wormholes = table.Column<string>(type: "jsonb", nullable: false),
                    RandomSeed = table.Column<int>(type: "integer", nullable: false),
                    PresetType = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: true),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    LastUsedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    UsageCount = table.Column<int>(type: "integer", nullable: false),
                    GenerationTimeMs = table.Column<long>(type: "bigint", nullable: true),
                    GenerationStats = table.Column<string>(type: "text", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_universe_generation_configs", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "account_activities",
                columns: table => new
                {
                    activity_id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    account_id = table.Column<Guid>(type: "uuid", nullable: false),
                    activity_type = table.Column<int>(type: "integer", nullable: false),
                    ip_address = table.Column<string>(type: "text", nullable: true),
                    user_agent = table.Column<string>(type: "text", nullable: true),
                    location = table.Column<string>(type: "text", nullable: true),
                    details = table.Column<string>(type: "text", nullable: true),
                    is_suspicious = table.Column<bool>(type: "boolean", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_account_activities", x => x.activity_id);
                    table.ForeignKey(
                        name: "FK_account_activities_accounts_account_id",
                        column: x => x.account_id,
                        principalTable: "accounts",
                        principalColumn: "account_id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "account_bans",
                columns: table => new
                {
                    ban_id = table.Column<Guid>(type: "uuid", nullable: false),
                    account_id = table.Column<Guid>(type: "uuid", nullable: false),
                    banned_by = table.Column<Guid>(type: "uuid", nullable: true),
                    reason = table.Column<int>(type: "integer", nullable: false),
                    reason_text = table.Column<string>(type: "text", nullable: false),
                    start_date = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    end_date = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    is_permanent = table.Column<bool>(type: "boolean", nullable: false),
                    appeal_allowed = table.Column<bool>(type: "boolean", nullable: false),
                    appeal_status = table.Column<int>(type: "integer", nullable: false),
                    appeal_text = table.Column<string>(type: "text", nullable: true),
                    appeal_reviewed_by = table.Column<Guid>(type: "uuid", nullable: true),
                    appeal_reviewed_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    appeal_response = table.Column<string>(type: "text", nullable: true),
                    evidence = table.Column<string>(type: "text", nullable: true),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_account_bans", x => x.ban_id);
                    table.ForeignKey(
                        name: "FK_account_bans_accounts_account_id",
                        column: x => x.account_id,
                        principalTable: "accounts",
                        principalColumn: "account_id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "api_keys",
                columns: table => new
                {
                    api_key_id = table.Column<Guid>(type: "uuid", nullable: false),
                    account_id = table.Column<Guid>(type: "uuid", nullable: false),
                    key_name = table.Column<string>(type: "text", nullable: false),
                    api_key = table.Column<string>(type: "text", nullable: false),
                    key_type = table.Column<int>(type: "integer", nullable: false),
                    key_status = table.Column<int>(type: "integer", nullable: false),
                    character_id = table.Column<Guid>(type: "uuid", nullable: true),
                    corporation_id = table.Column<Guid>(type: "uuid", nullable: true),
                    permissions = table.Column<string>(type: "text", nullable: false),
                    last_used = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    expires_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_api_keys", x => x.api_key_id);
                    table.ForeignKey(
                        name: "FK_api_keys_accounts_account_id",
                        column: x => x.account_id,
                        principalTable: "accounts",
                        principalColumn: "account_id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "support_tickets",
                columns: table => new
                {
                    ticket_id = table.Column<Guid>(type: "uuid", nullable: false),
                    account_id = table.Column<Guid>(type: "uuid", nullable: false),
                    ticket_type = table.Column<int>(type: "integer", nullable: false),
                    subject = table.Column<string>(type: "text", nullable: false),
                    description = table.Column<string>(type: "text", nullable: false),
                    status = table.Column<int>(type: "integer", nullable: false),
                    priority = table.Column<int>(type: "integer", nullable: false),
                    assigned_to = table.Column<Guid>(type: "uuid", nullable: true),
                    category = table.Column<string>(type: "text", nullable: false),
                    metadata = table.Column<string>(type: "text", nullable: false),
                    closed_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    closed_by = table.Column<Guid>(type: "uuid", nullable: true),
                    closure_reason = table.Column<string>(type: "text", nullable: true),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_support_tickets", x => x.ticket_id);
                    table.ForeignKey(
                        name: "FK_support_tickets_accounts_account_id",
                        column: x => x.account_id,
                        principalTable: "accounts",
                        principalColumn: "account_id",
                        onDelete: ReferentialAction.Cascade);
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
                name: "player_inventory_items",
                columns: table => new
                {
                    id = table.Column<Guid>(type: "uuid", nullable: false),
                    player_id = table.Column<Guid>(type: "uuid", nullable: false),
                    shop_item_id = table.Column<Guid>(type: "uuid", nullable: false),
                    quantity = table.Column<int>(type: "integer", nullable: false),
                    acquired_date = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    is_redeemed = table.Column<bool>(type: "boolean", nullable: false),
                    redeemed_date = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    notes = table.Column<string>(type: "character varying(500)", maxLength: 500, nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_player_inventory_items", x => x.id);
                    table.ForeignKey(
                        name: "FK_player_inventory_items_shop_items_shop_item_id",
                        column: x => x.shop_item_id,
                        principalTable: "shop_items",
                        principalColumn: "id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "Regions",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    Name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    RegionCode = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: false),
                    Type = table.Column<int>(type: "integer", nullable: false),
                    AverageSecurity = table.Column<float>(type: "real", precision: 3, scale: 2, nullable: false),
                    PositionX = table.Column<long>(type: "bigint", nullable: false),
                    PositionY = table.Column<long>(type: "bigint", nullable: false),
                    PositionZ = table.Column<long>(type: "bigint", nullable: false),
                    FactionId = table.Column<int>(type: "integer", nullable: true),
                    Description = table.Column<string>(type: "character varying(500)", maxLength: 500, nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()"),
                    UniverseGenerationConfigId = table.Column<Guid>(type: "uuid", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Regions", x => x.Id);
                    table.ForeignKey(
                        name: "FK_Regions_universe_generation_configs_UniverseGenerationConfi~",
                        column: x => x.UniverseGenerationConfigId,
                        principalTable: "universe_generation_configs",
                        principalColumn: "Id");
                });

            migrationBuilder.CreateTable(
                name: "ticket_messages",
                columns: table => new
                {
                    message_id = table.Column<Guid>(type: "uuid", nullable: false),
                    ticket_id = table.Column<Guid>(type: "uuid", nullable: false),
                    account_id = table.Column<Guid>(type: "uuid", nullable: false),
                    message = table.Column<string>(type: "text", nullable: false),
                    is_internal = table.Column<bool>(type: "boolean", nullable: false),
                    read_by_support = table.Column<bool>(type: "boolean", nullable: false),
                    read_by_user = table.Column<bool>(type: "boolean", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_ticket_messages", x => x.message_id);
                    table.ForeignKey(
                        name: "FK_ticket_messages_accounts_account_id",
                        column: x => x.account_id,
                        principalTable: "accounts",
                        principalColumn: "account_id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_ticket_messages_support_tickets_ticket_id",
                        column: x => x.ticket_id,
                        principalTable: "support_tickets",
                        principalColumn: "ticket_id",
                        onDelete: ReferentialAction.Cascade);
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
                name: "Constellations",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    Name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    RegionId = table.Column<Guid>(type: "uuid", nullable: false),
                    AverageSecurity = table.Column<float>(type: "real", precision: 3, scale: 2, nullable: false),
                    PositionX = table.Column<long>(type: "bigint", nullable: false),
                    PositionY = table.Column<long>(type: "bigint", nullable: false),
                    PositionZ = table.Column<long>(type: "bigint", nullable: false),
                    FactionId = table.Column<int>(type: "integer", nullable: true),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Constellations", x => x.Id);
                    table.ForeignKey(
                        name: "FK_Constellations_Regions_RegionId",
                        column: x => x.RegionId,
                        principalTable: "Regions",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "ticket_attachments",
                columns: table => new
                {
                    attachment_id = table.Column<Guid>(type: "uuid", nullable: false),
                    ticket_id = table.Column<Guid>(type: "uuid", nullable: false),
                    message_id = table.Column<Guid>(type: "uuid", nullable: true),
                    file_name = table.Column<string>(type: "text", nullable: false),
                    file_path = table.Column<string>(type: "text", nullable: false),
                    file_size = table.Column<long>(type: "bigint", nullable: false),
                    mime_type = table.Column<string>(type: "text", nullable: false),
                    uploaded_by = table.Column<Guid>(type: "uuid", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_ticket_attachments", x => x.attachment_id);
                    table.ForeignKey(
                        name: "FK_ticket_attachments_support_tickets_ticket_id",
                        column: x => x.ticket_id,
                        principalTable: "support_tickets",
                        principalColumn: "ticket_id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_ticket_attachments_ticket_messages_message_id",
                        column: x => x.message_id,
                        principalTable: "ticket_messages",
                        principalColumn: "message_id");
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
                    base_mass = table.Column<decimal>(type: "numeric", nullable: false),
                    thrust = table.Column<decimal>(type: "numeric", nullable: false),
                    rotation_speed = table.Column<decimal>(type: "numeric", nullable: false),
                    warp_speed = table.Column<decimal>(type: "numeric", nullable: false),
                    inertia_multiplier = table.Column<decimal>(type: "numeric", nullable: false),
                    max_velocity = table.Column<decimal>(type: "numeric", nullable: false),
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
                name: "SolarSystems",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    Name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    ConstellationId = table.Column<Guid>(type: "uuid", nullable: false),
                    SecurityStatus = table.Column<float>(type: "real", precision: 3, scale: 2, nullable: false),
                    IsActive = table.Column<bool>(type: "boolean", nullable: false),
                    PositionX = table.Column<long>(type: "bigint", nullable: false),
                    PositionY = table.Column<long>(type: "bigint", nullable: false),
                    PositionZ = table.Column<long>(type: "bigint", nullable: false),
                    StarClass = table.Column<int>(type: "integer", nullable: false),
                    LuminosityClass = table.Column<int>(type: "integer", nullable: false),
                    TemperatureClass = table.Column<int>(type: "integer", nullable: false),
                    Temperature = table.Column<int>(type: "integer", precision: 7, scale: 2, nullable: false),
                    SolarRadius = table.Column<float>(type: "real", precision: 10, scale: 4, nullable: false),
                    SolarMass = table.Column<float>(type: "real", precision: 10, scale: 4, nullable: false),
                    Luminosity = table.Column<float>(type: "real", precision: 15, scale: 4, nullable: false),
                    NumberOfStars = table.Column<int>(type: "integer", nullable: false),
                    Radius = table.Column<long>(type: "bigint", nullable: false),
                    FactionId = table.Column<int>(type: "integer", nullable: true),
                    HasAsteroidBelts = table.Column<bool>(type: "boolean", nullable: false),
                    HasStations = table.Column<bool>(type: "boolean", nullable: false),
                    Description = table.Column<string>(type: "character varying(1000)", maxLength: 1000, nullable: false),
                    RegionId = table.Column<Guid>(type: "uuid", nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()"),
                    UpdatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_SolarSystems", x => x.Id);
                    table.ForeignKey(
                        name: "FK_SolarSystems_Constellations_ConstellationId",
                        column: x => x.ConstellationId,
                        principalTable: "Constellations",
                        principalColumn: "Id",
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
                name: "Anomalies",
                columns: table => new
                {
                    id = table.Column<Guid>(type: "uuid", nullable: false),
                    solar_system_id = table.Column<Guid>(type: "uuid", nullable: false),
                    type = table.Column<string>(type: "text", nullable: false),
                    difficulty = table.Column<string>(type: "text", nullable: false),
                    name = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: false),
                    description = table.Column<string>(type: "character varying(500)", maxLength: 500, nullable: false),
                    position_x = table.Column<long>(type: "bigint", nullable: false),
                    position_y = table.Column<long>(type: "bigint", nullable: false),
                    position_z = table.Column<long>(type: "bigint", nullable: false),
                    radius = table.Column<double>(type: "double precision", nullable: false),
                    expires_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    signature = table.Column<string>(type: "character varying(20)", maxLength: 20, nullable: false),
                    durability = table.Column<double>(type: "double precision", nullable: false),
                    current_durability = table.Column<double>(type: "double precision", nullable: false),
                    scan_strength = table.Column<int>(type: "integer", nullable: false),
                    reward_data = table.Column<string>(type: "text", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Anomalies", x => x.id);
                    table.ForeignKey(
                        name: "FK_Anomalies_SolarSystems_solar_system_id",
                        column: x => x.solar_system_id,
                        principalTable: "SolarSystems",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "AsteroidBelts",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    Name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    SolarSystemId = table.Column<Guid>(type: "uuid", nullable: false),
                    PositionX = table.Column<long>(type: "bigint", nullable: false),
                    PositionY = table.Column<long>(type: "bigint", nullable: false),
                    PositionZ = table.Column<long>(type: "bigint", nullable: false),
                    Radius = table.Column<long>(type: "bigint", nullable: false),
                    Density = table.Column<float>(type: "real", nullable: false),
                    AsteroidCount = table.Column<int>(type: "integer", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_AsteroidBelts", x => x.Id);
                    table.ForeignKey(
                        name: "FK_AsteroidBelts_SolarSystems_SolarSystemId",
                        column: x => x.SolarSystemId,
                        principalTable: "SolarSystems",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "game_servers",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    InstanceId = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: false),
                    PublicIP = table.Column<string>(type: "character varying(45)", maxLength: 45, nullable: false),
                    GamePort = table.Column<int>(type: "integer", nullable: false),
                    WebPort = table.Column<int>(type: "integer", nullable: false),
                    SolarSystemId = table.Column<Guid>(type: "uuid", nullable: true),
                    RegionId = table.Column<Guid>(type: "uuid", nullable: true),
                    Status = table.Column<int>(type: "integer", nullable: false),
                    OnlinePlayers = table.Column<int>(type: "integer", nullable: false),
                    MaxPlayers = table.Column<int>(type: "integer", nullable: false),
                    CPUUsage = table.Column<float>(type: "real", nullable: false),
                    MemoryUsageMB = table.Column<long>(type: "bigint", nullable: false),
                    NetworkInKbps = table.Column<float>(type: "real", nullable: false),
                    NetworkOutKbps = table.Column<float>(type: "real", nullable: false),
                    LastHeartbeat = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    GeoRegion = table.Column<string>(type: "character varying(10)", maxLength: 10, nullable: false),
                    GameVersion = table.Column<string>(type: "character varying(20)", maxLength: 20, nullable: false),
                    Hostname = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: true),
                    StartupArguments = table.Column<string>(type: "text", nullable: true),
                    ServerTags = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: true),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    UpdatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    IsActive = table.Column<bool>(type: "boolean", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_game_servers", x => x.Id);
                    table.ForeignKey(
                        name: "FK_game_servers_Regions_RegionId",
                        column: x => x.RegionId,
                        principalTable: "Regions",
                        principalColumn: "Id");
                    table.ForeignKey(
                        name: "FK_game_servers_SolarSystems_SolarSystemId",
                        column: x => x.SolarSystemId,
                        principalTable: "SolarSystems",
                        principalColumn: "Id");
                });

            migrationBuilder.CreateTable(
                name: "Planets",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    Name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    SolarSystemId = table.Column<Guid>(type: "uuid", nullable: false),
                    Type = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: false),
                    Radius = table.Column<long>(type: "bigint", nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    OrbitDistance = table.Column<long>(type: "bigint", nullable: false),
                    OrbitPeriod = table.Column<long>(type: "bigint", nullable: false),
                    HasAtmosphere = table.Column<bool>(type: "boolean", nullable: false),
                    AtmosphereType = table.Column<int>(type: "integer", nullable: false),
                    Temperature = table.Column<int>(type: "integer", nullable: false),
                    Gravity = table.Column<float>(type: "real", nullable: false),
                    HasMoons = table.Column<bool>(type: "boolean", nullable: false),
                    MoonCount = table.Column<int>(type: "integer", nullable: false),
                    IsColonizable = table.Column<bool>(type: "boolean", nullable: false),
                    FactionId = table.Column<int>(type: "integer", nullable: true),
                    Description = table.Column<string>(type: "character varying(1000)", maxLength: 1000, nullable: false),
                    PositionX = table.Column<long>(type: "bigint", nullable: false),
                    PositionY = table.Column<long>(type: "bigint", nullable: false),
                    PositionZ = table.Column<long>(type: "bigint", nullable: false),
                    Mass = table.Column<double>(type: "double precision", nullable: false),
                    HasRings = table.Column<bool>(type: "boolean", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Planets", x => x.Id);
                    table.ForeignKey(
                        name: "FK_Planets_SolarSystems_SolarSystemId",
                        column: x => x.SolarSystemId,
                        principalTable: "SolarSystems",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "Stargates",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    Name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    SourceSolarSystemId = table.Column<Guid>(type: "uuid", nullable: false),
                    DestinationSolarSystemId = table.Column<Guid>(type: "uuid", nullable: false),
                    PositionX = table.Column<long>(type: "bigint", nullable: false),
                    PositionY = table.Column<long>(type: "bigint", nullable: false),
                    PositionZ = table.Column<long>(type: "bigint", nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    IsOperational = table.Column<bool>(type: "boolean", nullable: false, defaultValue: true),
                    JumpCost = table.Column<int>(type: "integer", nullable: false),
                    Model = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Stargates", x => x.Id);
                    table.ForeignKey(
                        name: "FK_Stargates_SolarSystems_DestinationSolarSystemId",
                        column: x => x.DestinationSolarSystemId,
                        principalTable: "SolarSystems",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_Stargates_SolarSystems_SourceSolarSystemId",
                        column: x => x.SourceSolarSystemId,
                        principalTable: "SolarSystems",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "Stations",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    Name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    SolarSystemId = table.Column<Guid>(type: "uuid", nullable: false),
                    Type = table.Column<int>(type: "integer", nullable: false),
                    PositionX = table.Column<long>(type: "bigint", nullable: false),
                    PositionY = table.Column<long>(type: "bigint", nullable: false),
                    PositionZ = table.Column<long>(type: "bigint", nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    DockingCapacity = table.Column<int>(type: "integer", nullable: false),
                    IsOperational = table.Column<bool>(type: "boolean", nullable: false),
                    FactionId = table.Column<int>(type: "integer", nullable: true),
                    Services = table.Column<string>(type: "character varying(500)", maxLength: 500, nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Stations", x => x.Id);
                    table.ForeignKey(
                        name: "FK_Stations_SolarSystems_SolarSystemId",
                        column: x => x.SolarSystemId,
                        principalTable: "SolarSystems",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "wormholes",
                columns: table => new
                {
                    id = table.Column<Guid>(type: "uuid", nullable: false),
                    source_system_id = table.Column<Guid>(type: "uuid", nullable: false),
                    target_system_id = table.Column<Guid>(type: "uuid", nullable: false),
                    name = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: false),
                    @class = table.Column<string>(name: "class", type: "text", nullable: false),
                    max_mass = table.Column<double>(type: "double precision", precision: 18, scale: 2, nullable: false),
                    remaining_mass = table.Column<double>(type: "double precision", precision: 18, scale: 2, nullable: false),
                    max_ship_size = table.Column<string>(type: "text", nullable: false),
                    expires_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    position_x = table.Column<long>(type: "bigint", nullable: false),
                    position_y = table.Column<long>(type: "bigint", nullable: false),
                    position_z = table.Column<long>(type: "bigint", nullable: false),
                    radius = table.Column<double>(type: "double precision", nullable: false),
                    stability = table.Column<double>(type: "double precision", precision: 3, scale: 2, nullable: false),
                    signature = table.Column<string>(type: "character varying(20)", maxLength: 20, nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    last_used_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    total_passes = table.Column<int>(type: "integer", nullable: false),
                    paired_wormhole_id = table.Column<Guid>(type: "uuid", nullable: true),
                    is_exit_only = table.Column<bool>(type: "boolean", nullable: false),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_wormholes", x => x.id);
                    table.ForeignKey(
                        name: "FK_wormholes_SolarSystems_source_system_id",
                        column: x => x.source_system_id,
                        principalTable: "SolarSystems",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_wormholes_SolarSystems_target_system_id",
                        column: x => x.target_system_id,
                        principalTable: "SolarSystems",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_wormholes_wormholes_paired_wormhole_id",
                        column: x => x.paired_wormhole_id,
                        principalTable: "wormholes",
                        principalColumn: "id",
                        onDelete: ReferentialAction.SetNull);
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

            migrationBuilder.CreateTable(
                name: "Moons",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    Name = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    PlanetId = table.Column<Guid>(type: "uuid", nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    Radius = table.Column<long>(type: "bigint", nullable: false),
                    OrbitDistance = table.Column<long>(type: "bigint", nullable: false),
                    OrbitPeriod = table.Column<long>(type: "bigint", nullable: false),
                    HasResources = table.Column<bool>(type: "boolean", nullable: false),
                    PositionX = table.Column<long>(type: "bigint", nullable: false),
                    PositionY = table.Column<long>(type: "bigint", nullable: false),
                    PositionZ = table.Column<long>(type: "bigint", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Moons", x => x.Id);
                    table.ForeignKey(
                        name: "FK_Moons_Planets_PlanetId",
                        column: x => x.PlanetId,
                        principalTable: "Planets",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "PlanetResources",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    PlanetId = table.Column<Guid>(type: "uuid", nullable: true),
                    MoonId = table.Column<Guid>(type: "uuid", nullable: true),
                    AsteroidBeltId = table.Column<Guid>(type: "uuid", nullable: true),
                    ResourceType = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: false),
                    Quantity = table.Column<int>(type: "integer", nullable: false),
                    Quality = table.Column<float>(type: "real", nullable: false),
                    LastHarvested = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_PlanetResources", x => x.Id);
                    table.ForeignKey(
                        name: "FK_PlanetResources_AsteroidBelts_AsteroidBeltId",
                        column: x => x.AsteroidBeltId,
                        principalTable: "AsteroidBelts",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_PlanetResources_Moons_MoonId",
                        column: x => x.MoonId,
                        principalTable: "Moons",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_PlanetResources_Planets_PlanetId",
                        column: x => x.PlanetId,
                        principalTable: "Planets",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "AccountSessions",
                columns: table => new
                {
                    id = table.Column<Guid>(type: "uuid", nullable: false),
                    account_id = table.Column<Guid>(type: "uuid", nullable: false),
                    character_id = table.Column<Guid>(type: "uuid", nullable: true),
                    session_token = table.Column<string>(type: "text", nullable: false),
                    refresh_token = table.Column<string>(type: "text", nullable: false),
                    ip_address = table.Column<string>(type: "text", nullable: true),
                    user_agent = table.Column<string>(type: "text", nullable: true),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    expires_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    refresh_token_expires_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    last_activity = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    is_revoked = table.Column<bool>(type: "boolean", nullable: false),
                    is_active = table.Column<bool>(type: "boolean", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_AccountSessions", x => x.id);
                    table.ForeignKey(
                        name: "FK_AccountSessions_accounts_account_id",
                        column: x => x.account_id,
                        principalTable: "accounts",
                        principalColumn: "account_id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "character_clones",
                columns: table => new
                {
                    clone_id = table.Column<Guid>(type: "uuid", nullable: false),
                    character_id = table.Column<Guid>(type: "uuid", nullable: false),
                    clone_type = table.Column<int>(type: "integer", nullable: false),
                    name = table.Column<string>(type: "text", nullable: false),
                    description = table.Column<string>(type: "text", nullable: true),
                    location_id = table.Column<Guid>(type: "uuid", nullable: false),
                    solar_system_id = table.Column<int>(type: "integer", nullable: true),
                    station_id = table.Column<int>(type: "integer", nullable: true),
                    implants = table.Column<string>(type: "text", nullable: false),
                    skill_points = table.Column<long>(type: "bigint", nullable: false),
                    max_skill_points = table.Column<long>(type: "bigint", nullable: false),
                    is_jump_clone = table.Column<bool>(type: "boolean", nullable: false),
                    jump_cooldown_until = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    is_active = table.Column<bool>(type: "boolean", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_character_clones", x => x.clone_id);
                });

            migrationBuilder.CreateTable(
                name: "character_contracts",
                columns: table => new
                {
                    contract_id = table.Column<Guid>(type: "uuid", nullable: false),
                    issuer_id = table.Column<Guid>(type: "uuid", nullable: false),
                    assignee_id = table.Column<Guid>(type: "uuid", nullable: true),
                    acceptor_id = table.Column<Guid>(type: "uuid", nullable: true),
                    contract_type = table.Column<int>(type: "integer", nullable: false),
                    status = table.Column<int>(type: "integer", nullable: false),
                    title = table.Column<string>(type: "text", nullable: false),
                    description = table.Column<string>(type: "text", nullable: true),
                    price = table.Column<decimal>(type: "numeric", nullable: false),
                    reward = table.Column<decimal>(type: "numeric", nullable: true),
                    collateral = table.Column<decimal>(type: "numeric", nullable: true),
                    volume = table.Column<decimal>(type: "numeric", nullable: false),
                    items = table.Column<string>(type: "text", nullable: false),
                    start_location_id = table.Column<Guid>(type: "uuid", nullable: true),
                    end_location_id = table.Column<Guid>(type: "uuid", nullable: true),
                    date_issued = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    date_expired = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    date_accepted = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    date_completed = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_character_contracts", x => x.contract_id);
                });

            migrationBuilder.CreateTable(
                name: "character_implants",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    CharacterId = table.Column<Guid>(type: "uuid", nullable: false),
                    Slot = table.Column<int>(type: "integer", nullable: false),
                    TypeId = table.Column<int>(type: "integer", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_character_implants", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "character_implants_enhanced",
                columns: table => new
                {
                    implant_id = table.Column<Guid>(type: "uuid", nullable: false),
                    character_id = table.Column<Guid>(type: "uuid", nullable: false),
                    asset_id = table.Column<Guid>(type: "uuid", nullable: false),
                    implant_type = table.Column<int>(type: "integer", nullable: false),
                    slot = table.Column<int>(type: "integer", nullable: false),
                    is_active = table.Column<bool>(type: "boolean", nullable: false),
                    effects = table.Column<string>(type: "text", nullable: false),
                    expires_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    installed_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_character_implants_enhanced", x => x.implant_id);
                    table.ForeignKey(
                        name: "FK_character_implants_enhanced_assets_asset_id",
                        column: x => x.asset_id,
                        principalTable: "assets",
                        principalColumn: "asset_id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "character_skills",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    CharacterId = table.Column<Guid>(type: "uuid", nullable: false),
                    SkillId = table.Column<int>(type: "integer", nullable: false),
                    Level = table.Column<int>(type: "integer", nullable: false),
                    Skillpoints = table.Column<int>(type: "integer", nullable: false),
                    IsActive = table.Column<bool>(type: "boolean", nullable: false),
                    TrainingStart = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    TrainingEnd = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_character_skills", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "character_skills_enhanced",
                columns: table => new
                {
                    character_skill_id = table.Column<Guid>(type: "uuid", nullable: false),
                    character_id = table.Column<Guid>(type: "uuid", nullable: false),
                    skill_id = table.Column<int>(type: "integer", nullable: false),
                    skill_level = table.Column<int>(type: "integer", nullable: false),
                    skill_points = table.Column<long>(type: "bigint", nullable: false),
                    skill_points_to_next_level = table.Column<long>(type: "bigint", nullable: false),
                    trained_level = table.Column<int>(type: "integer", nullable: true),
                    training_started_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    training_finished_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    is_active = table.Column<bool>(type: "boolean", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_character_skills_enhanced", x => x.character_skill_id);
                    table.ForeignKey(
                        name: "FK_character_skills_enhanced_skills_skill_id",
                        column: x => x.skill_id,
                        principalTable: "skills",
                        principalColumn: "skill_id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "character_standings",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    CharacterId = table.Column<Guid>(type: "uuid", nullable: false),
                    TargetId = table.Column<int>(type: "integer", nullable: false),
                    TargetType = table.Column<string>(type: "text", nullable: false),
                    Standing = table.Column<float>(type: "real", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_character_standings", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "character_wallets",
                columns: table => new
                {
                    wallet_id = table.Column<Guid>(type: "uuid", nullable: false),
                    character_id = table.Column<Guid>(type: "uuid", nullable: false),
                    currency_type = table.Column<int>(type: "integer", nullable: false),
                    balance = table.Column<decimal>(type: "numeric", nullable: false),
                    balance_updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    wallet_name = table.Column<string>(type: "text", nullable: true),
                    division = table.Column<int>(type: "integer", nullable: true),
                    is_primary = table.Column<bool>(type: "boolean", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_character_wallets", x => x.wallet_id);
                });

            migrationBuilder.CreateTable(
                name: "wallet_transactions",
                columns: table => new
                {
                    transaction_id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    wallet_id = table.Column<Guid>(type: "uuid", nullable: false),
                    transaction_type = table.Column<int>(type: "integer", nullable: false),
                    amount = table.Column<decimal>(type: "numeric", nullable: false),
                    new_balance = table.Column<decimal>(type: "numeric", nullable: false),
                    description = table.Column<string>(type: "text", nullable: true),
                    reference_id = table.Column<Guid>(type: "uuid", nullable: true),
                    reference_type = table.Column<string>(type: "text", nullable: true),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_wallet_transactions", x => x.transaction_id);
                    table.ForeignKey(
                        name: "FK_wallet_transactions_character_wallets_wallet_id",
                        column: x => x.wallet_id,
                        principalTable: "character_wallets",
                        principalColumn: "wallet_id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "CharacterLocations",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    CharacterId = table.Column<Guid>(type: "uuid", nullable: false),
                    SolarSystemId = table.Column<Guid>(type: "uuid", nullable: true),
                    PositionX = table.Column<double>(type: "double precision", nullable: false),
                    PositionY = table.Column<double>(type: "double precision", nullable: false),
                    PositionZ = table.Column<double>(type: "double precision", nullable: false),
                    RotationX = table.Column<float>(type: "real", nullable: false),
                    RotationY = table.Column<float>(type: "real", nullable: false),
                    RotationZ = table.Column<float>(type: "real", nullable: false),
                    RotationW = table.Column<float>(type: "real", nullable: false),
                    VelocityX = table.Column<float>(type: "real", nullable: false),
                    VelocityY = table.Column<float>(type: "real", nullable: false),
                    VelocityZ = table.Column<float>(type: "real", nullable: false),
                    StationId = table.Column<Guid>(type: "uuid", nullable: true),
                    HangarInstanceId = table.Column<Guid>(type: "uuid", nullable: true),
                    ShipItemId = table.Column<long>(type: "bigint", nullable: true),
                    IsDocked = table.Column<bool>(type: "boolean", nullable: false),
                    InWarp = table.Column<bool>(type: "boolean", nullable: false),
                    IsCloaked = table.Column<bool>(type: "boolean", nullable: false),
                    WarpEndTime = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    LocationType = table.Column<int>(type: "integer", nullable: false),
                    LastUpdate = table.Column<DateTime>(type: "timestamp with time zone", nullable: true, defaultValueSql: "NOW()")
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_CharacterLocations", x => x.Id);
                    table.ForeignKey(
                        name: "FK_CharacterLocations_SolarSystems_SolarSystemId",
                        column: x => x.SolarSystemId,
                        principalTable: "SolarSystems",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_CharacterLocations_Stations_StationId",
                        column: x => x.StationId,
                        principalTable: "Stations",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                });

            migrationBuilder.CreateTable(
                name: "Characters",
                columns: table => new
                {
                    Id = table.Column<Guid>(type: "uuid", nullable: false),
                    Name = table.Column<string>(type: "character varying(50)", maxLength: 50, nullable: false),
                    AccountId = table.Column<Guid>(type: "uuid", nullable: false),
                    WalletBalance = table.Column<long>(type: "bigint", nullable: false),
                    SecurityStatus = table.Column<float>(type: "real", nullable: false),
                    CloneExpiration = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    CorporationId = table.Column<Guid>(type: "uuid", nullable: true),
                    CorporationRole = table.Column<long>(type: "bigint", nullable: false),
                    RaceId = table.Column<int>(type: "integer", nullable: false),
                    BloodlineId = table.Column<int>(type: "integer", nullable: false),
                    AncestryId = table.Column<int>(type: "integer", nullable: false),
                    TotalSkillPoints = table.Column<int>(type: "integer", nullable: false),
                    UnallocatedSkillPoints = table.Column<int>(type: "integer", nullable: false),
                    SkillTrainingEnd = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    ActiveShipItemId = table.Column<long>(type: "bigint", nullable: true),
                    HomeStationId = table.Column<Guid>(type: "uuid", nullable: true),
                    SettingsJson = table.Column<string>(type: "text", nullable: false),
                    IsMain = table.Column<bool>(type: "boolean", nullable: false),
                    IsOnline = table.Column<bool>(type: "boolean", nullable: false),
                    IsDocked = table.Column<bool>(type: "boolean", nullable: false),
                    InWarp = table.Column<bool>(type: "boolean", nullable: false),
                    Perception = table.Column<int>(type: "integer", nullable: false),
                    Memory = table.Column<int>(type: "integer", nullable: false),
                    Willpower = table.Column<int>(type: "integer", nullable: false),
                    Intelligence = table.Column<int>(type: "integer", nullable: false),
                    Charisma = table.Column<int>(type: "integer", nullable: false),
                    TotalISKEarned = table.Column<decimal>(type: "numeric", nullable: false),
                    TotalISKLost = table.Column<decimal>(type: "numeric", nullable: false),
                    TotalShipsDestroyed = table.Column<int>(type: "integer", nullable: false),
                    TotalShipsLost = table.Column<int>(type: "integer", nullable: false),
                    TotalKills = table.Column<int>(type: "integer", nullable: false),
                    TotalDeaths = table.Column<int>(type: "integer", nullable: false),
                    ActiveCloneId = table.Column<Guid>(type: "uuid", nullable: true),
                    JumpCloneCount = table.Column<int>(type: "integer", nullable: false),
                    MaxJumpClones = table.Column<int>(type: "integer", nullable: false),
                    LastLogin = table.Column<DateTime>(type: "timestamp with time zone", nullable: true, defaultValueSql: "NOW()"),
                    LastLogout = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    TotalPlayTimeSeconds = table.Column<long>(type: "bigint", nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false, defaultValueSql: "NOW()")
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Characters", x => x.Id);
                    table.ForeignKey(
                        name: "FK_Characters_accounts_AccountId",
                        column: x => x.AccountId,
                        principalTable: "accounts",
                        principalColumn: "account_id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "inventory_items",
                columns: table => new
                {
                    ItemId = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    OwnerId = table.Column<Guid>(type: "uuid", nullable: false),
                    TypeId = table.Column<int>(type: "integer", nullable: false),
                    Quantity = table.Column<int>(type: "integer", nullable: false),
                    IsSingleton = table.Column<bool>(type: "boolean", nullable: false),
                    CharacterId = table.Column<Guid>(type: "uuid", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_inventory_items", x => x.ItemId);
                    table.ForeignKey(
                        name: "FK_inventory_items_Characters_CharacterId",
                        column: x => x.CharacterId,
                        principalTable: "Characters",
                        principalColumn: "Id");
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
                name: "training_queues",
                columns: table => new
                {
                    queue_id = table.Column<Guid>(type: "uuid", nullable: false),
                    character_id = table.Column<Guid>(type: "uuid", nullable: false),
                    character_skill_id = table.Column<Guid>(type: "uuid", nullable: false),
                    target_level = table.Column<int>(type: "integer", nullable: false),
                    queue_position = table.Column<int>(type: "integer", nullable: false),
                    status = table.Column<int>(type: "integer", nullable: false),
                    started_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    finished_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    estimated_finish_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    paused_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    paused_duration = table.Column<long>(type: "bigint", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_training_queues", x => x.queue_id);
                    table.ForeignKey(
                        name: "FK_training_queues_Characters_character_id",
                        column: x => x.character_id,
                        principalTable: "Characters",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_training_queues_character_skills_enhanced_character_skill_id",
                        column: x => x.character_skill_id,
                        principalTable: "character_skills_enhanced",
                        principalColumn: "character_skill_id",
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
                name: "IX_account_activities_account_id",
                table: "account_activities",
                column: "account_id");

            migrationBuilder.CreateIndex(
                name: "IX_account_bans_account_id",
                table: "account_bans",
                column: "account_id");

            migrationBuilder.CreateIndex(
                name: "IX_accounts_email",
                table: "accounts",
                column: "email",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_accounts_username",
                table: "accounts",
                column: "username",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_AccountSessions_account_id",
                table: "AccountSessions",
                column: "account_id");

            migrationBuilder.CreateIndex(
                name: "IX_AccountSessions_character_id",
                table: "AccountSessions",
                column: "character_id");

            migrationBuilder.CreateIndex(
                name: "IX_Anomalies_difficulty",
                table: "Anomalies",
                column: "difficulty");

            migrationBuilder.CreateIndex(
                name: "IX_Anomalies_expires_at",
                table: "Anomalies",
                column: "expires_at");

            migrationBuilder.CreateIndex(
                name: "IX_Anomalies_signature",
                table: "Anomalies",
                column: "signature",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_Anomalies_solar_system_id",
                table: "Anomalies",
                column: "solar_system_id");

            migrationBuilder.CreateIndex(
                name: "IX_Anomalies_type",
                table: "Anomalies",
                column: "type");

            migrationBuilder.CreateIndex(
                name: "IX_api_keys_account_id",
                table: "api_keys",
                column: "account_id");

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
                name: "IX_AsteroidBelts_SolarSystemId",
                table: "AsteroidBelts",
                column: "SolarSystemId");

            migrationBuilder.CreateIndex(
                name: "IX_character_clones_character_id",
                table: "character_clones",
                column: "character_id");

            migrationBuilder.CreateIndex(
                name: "IX_character_contracts_acceptor_id",
                table: "character_contracts",
                column: "acceptor_id");

            migrationBuilder.CreateIndex(
                name: "IX_character_contracts_assignee_id",
                table: "character_contracts",
                column: "assignee_id");

            migrationBuilder.CreateIndex(
                name: "IX_character_contracts_issuer_id",
                table: "character_contracts",
                column: "issuer_id");

            migrationBuilder.CreateIndex(
                name: "IX_character_implants_CharacterId",
                table: "character_implants",
                column: "CharacterId");

            migrationBuilder.CreateIndex(
                name: "IX_character_implants_enhanced_asset_id",
                table: "character_implants_enhanced",
                column: "asset_id");

            migrationBuilder.CreateIndex(
                name: "IX_character_implants_enhanced_character_id",
                table: "character_implants_enhanced",
                column: "character_id");

            migrationBuilder.CreateIndex(
                name: "IX_character_skills_CharacterId",
                table: "character_skills",
                column: "CharacterId");

            migrationBuilder.CreateIndex(
                name: "IX_character_skills_enhanced_character_id",
                table: "character_skills_enhanced",
                column: "character_id");

            migrationBuilder.CreateIndex(
                name: "IX_character_skills_enhanced_skill_id",
                table: "character_skills_enhanced",
                column: "skill_id");

            migrationBuilder.CreateIndex(
                name: "IX_character_standings_CharacterId",
                table: "character_standings",
                column: "CharacterId");

            migrationBuilder.CreateIndex(
                name: "IX_character_wallets_character_id",
                table: "character_wallets",
                column: "character_id");

            migrationBuilder.CreateIndex(
                name: "IX_CharacterLocations_CharacterId",
                table: "CharacterLocations",
                column: "CharacterId",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_CharacterLocations_ShipItemId",
                table: "CharacterLocations",
                column: "ShipItemId");

            migrationBuilder.CreateIndex(
                name: "IX_CharacterLocations_SolarSystemId",
                table: "CharacterLocations",
                column: "SolarSystemId");

            migrationBuilder.CreateIndex(
                name: "IX_CharacterLocations_StationId",
                table: "CharacterLocations",
                column: "StationId");

            migrationBuilder.CreateIndex(
                name: "IX_Characters_AccountId",
                table: "Characters",
                column: "AccountId");

            migrationBuilder.CreateIndex(
                name: "IX_Characters_ActiveShipItemId",
                table: "Characters",
                column: "ActiveShipItemId");

            migrationBuilder.CreateIndex(
                name: "IX_Characters_Name",
                table: "Characters",
                column: "Name",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_Constellations_Name",
                table: "Constellations",
                column: "Name",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_Constellations_RegionId",
                table: "Constellations",
                column: "RegionId");

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
                name: "IX_game_servers_RegionId",
                table: "game_servers",
                column: "RegionId");

            migrationBuilder.CreateIndex(
                name: "IX_game_servers_SolarSystemId",
                table: "game_servers",
                column: "SolarSystemId",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_inventory_items_CharacterId",
                table: "inventory_items",
                column: "CharacterId");

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
                name: "IX_Moons_PlanetId",
                table: "Moons",
                column: "PlanetId");

            migrationBuilder.CreateIndex(
                name: "IX_PlanetResources_AsteroidBeltId",
                table: "PlanetResources",
                column: "AsteroidBeltId");

            migrationBuilder.CreateIndex(
                name: "IX_PlanetResources_MoonId",
                table: "PlanetResources",
                column: "MoonId");

            migrationBuilder.CreateIndex(
                name: "IX_PlanetResources_PlanetId",
                table: "PlanetResources",
                column: "PlanetId");

            migrationBuilder.CreateIndex(
                name: "IX_Planets_SolarSystemId",
                table: "Planets",
                column: "SolarSystemId");

            migrationBuilder.CreateIndex(
                name: "IX_player_inventory_items_shop_item_id",
                table: "player_inventory_items",
                column: "shop_item_id");

            migrationBuilder.CreateIndex(
                name: "IX_Regions_Name",
                table: "Regions",
                column: "Name",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_Regions_UniverseGenerationConfigId",
                table: "Regions",
                column: "UniverseGenerationConfigId");

            migrationBuilder.CreateIndex(
                name: "IX_ship_fittings_ship_asset_id",
                table: "ship_fittings",
                column: "ship_asset_id");

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

            migrationBuilder.CreateIndex(
                name: "IX_ships_race",
                table: "ships",
                column: "race");

            migrationBuilder.CreateIndex(
                name: "IX_SolarSystems_ConstellationId",
                table: "SolarSystems",
                column: "ConstellationId");

            migrationBuilder.CreateIndex(
                name: "IX_SolarSystems_Name",
                table: "SolarSystems",
                column: "Name",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_SolarSystems_PositionX_PositionY_PositionZ",
                table: "SolarSystems",
                columns: new[] { "PositionX", "PositionY", "PositionZ" });

            migrationBuilder.CreateIndex(
                name: "IX_SolarSystems_SecurityStatus",
                table: "SolarSystems",
                column: "SecurityStatus");

            migrationBuilder.CreateIndex(
                name: "IX_Stargates_DestinationSolarSystemId",
                table: "Stargates",
                column: "DestinationSolarSystemId");

            migrationBuilder.CreateIndex(
                name: "IX_Stargates_SourceSolarSystemId",
                table: "Stargates",
                column: "SourceSolarSystemId");

            migrationBuilder.CreateIndex(
                name: "IX_Stations_SolarSystemId",
                table: "Stations",
                column: "SolarSystemId");

            migrationBuilder.CreateIndex(
                name: "IX_support_tickets_account_id",
                table: "support_tickets",
                column: "account_id");

            migrationBuilder.CreateIndex(
                name: "IX_ticket_attachments_message_id",
                table: "ticket_attachments",
                column: "message_id");

            migrationBuilder.CreateIndex(
                name: "IX_ticket_attachments_ticket_id",
                table: "ticket_attachments",
                column: "ticket_id");

            migrationBuilder.CreateIndex(
                name: "IX_ticket_messages_account_id",
                table: "ticket_messages",
                column: "account_id");

            migrationBuilder.CreateIndex(
                name: "IX_ticket_messages_ticket_id",
                table: "ticket_messages",
                column: "ticket_id");

            migrationBuilder.CreateIndex(
                name: "IX_training_queues_character_id",
                table: "training_queues",
                column: "character_id");

            migrationBuilder.CreateIndex(
                name: "IX_training_queues_character_skill_id",
                table: "training_queues",
                column: "character_skill_id");

            migrationBuilder.CreateIndex(
                name: "IX_wallet_transactions_wallet_id",
                table: "wallet_transactions",
                column: "wallet_id");

            migrationBuilder.CreateIndex(
                name: "IX_wormholes_expires_at",
                table: "wormholes",
                column: "expires_at");

            migrationBuilder.CreateIndex(
                name: "IX_wormholes_paired_wormhole_id",
                table: "wormholes",
                column: "paired_wormhole_id",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_wormholes_signature",
                table: "wormholes",
                column: "signature",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_wormholes_source_system_id",
                table: "wormholes",
                column: "source_system_id");

            migrationBuilder.CreateIndex(
                name: "IX_wormholes_target_system_id",
                table: "wormholes",
                column: "target_system_id");

            migrationBuilder.AddForeignKey(
                name: "FK_AccountSessions_Characters_character_id",
                table: "AccountSessions",
                column: "character_id",
                principalTable: "Characters",
                principalColumn: "Id");

            migrationBuilder.AddForeignKey(
                name: "FK_character_clones_Characters_character_id",
                table: "character_clones",
                column: "character_id",
                principalTable: "Characters",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_character_contracts_Characters_acceptor_id",
                table: "character_contracts",
                column: "acceptor_id",
                principalTable: "Characters",
                principalColumn: "Id",
                onDelete: ReferentialAction.Restrict);

            migrationBuilder.AddForeignKey(
                name: "FK_character_contracts_Characters_assignee_id",
                table: "character_contracts",
                column: "assignee_id",
                principalTable: "Characters",
                principalColumn: "Id",
                onDelete: ReferentialAction.Restrict);

            migrationBuilder.AddForeignKey(
                name: "FK_character_contracts_Characters_issuer_id",
                table: "character_contracts",
                column: "issuer_id",
                principalTable: "Characters",
                principalColumn: "Id",
                onDelete: ReferentialAction.Restrict);

            migrationBuilder.AddForeignKey(
                name: "FK_character_implants_Characters_CharacterId",
                table: "character_implants",
                column: "CharacterId",
                principalTable: "Characters",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_character_implants_enhanced_Characters_character_id",
                table: "character_implants_enhanced",
                column: "character_id",
                principalTable: "Characters",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_character_skills_Characters_CharacterId",
                table: "character_skills",
                column: "CharacterId",
                principalTable: "Characters",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_character_skills_enhanced_Characters_character_id",
                table: "character_skills_enhanced",
                column: "character_id",
                principalTable: "Characters",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_character_standings_Characters_CharacterId",
                table: "character_standings",
                column: "CharacterId",
                principalTable: "Characters",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_character_wallets_Characters_character_id",
                table: "character_wallets",
                column: "character_id",
                principalTable: "Characters",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_CharacterLocations_Characters_CharacterId",
                table: "CharacterLocations",
                column: "CharacterId",
                principalTable: "Characters",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_CharacterLocations_inventory_items_ShipItemId",
                table: "CharacterLocations",
                column: "ShipItemId",
                principalTable: "inventory_items",
                principalColumn: "ItemId");

            migrationBuilder.AddForeignKey(
                name: "FK_Characters_inventory_items_ActiveShipItemId",
                table: "Characters",
                column: "ActiveShipItemId",
                principalTable: "inventory_items",
                principalColumn: "ItemId");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Characters_accounts_AccountId",
                table: "Characters");

            migrationBuilder.DropForeignKey(
                name: "FK_inventory_items_Characters_CharacterId",
                table: "inventory_items");

            migrationBuilder.DropTable(
                name: "account_activities");

            migrationBuilder.DropTable(
                name: "account_bans");

            migrationBuilder.DropTable(
                name: "AccountSessions");

            migrationBuilder.DropTable(
                name: "Anomalies");

            migrationBuilder.DropTable(
                name: "api_keys");

            migrationBuilder.DropTable(
                name: "asset_logs");

            migrationBuilder.DropTable(
                name: "character_clones");

            migrationBuilder.DropTable(
                name: "character_contracts");

            migrationBuilder.DropTable(
                name: "character_implants");

            migrationBuilder.DropTable(
                name: "character_implants_enhanced");

            migrationBuilder.DropTable(
                name: "character_skills");

            migrationBuilder.DropTable(
                name: "character_standings");

            migrationBuilder.DropTable(
                name: "CharacterLocations");

            migrationBuilder.DropTable(
                name: "fitted_modules");

            migrationBuilder.DropTable(
                name: "game_servers");

            migrationBuilder.DropTable(
                name: "modules");

            migrationBuilder.DropTable(
                name: "PlanetResources");

            migrationBuilder.DropTable(
                name: "player_inventory_items");

            migrationBuilder.DropTable(
                name: "race_configs");

            migrationBuilder.DropTable(
                name: "ship_instance_modules");

            migrationBuilder.DropTable(
                name: "Stargates");

            migrationBuilder.DropTable(
                name: "ticket_attachments");

            migrationBuilder.DropTable(
                name: "training_queues");

            migrationBuilder.DropTable(
                name: "wallet_transactions");

            migrationBuilder.DropTable(
                name: "wormholes");

            migrationBuilder.DropTable(
                name: "Stations");

            migrationBuilder.DropTable(
                name: "ship_fittings");

            migrationBuilder.DropTable(
                name: "AsteroidBelts");

            migrationBuilder.DropTable(
                name: "Moons");

            migrationBuilder.DropTable(
                name: "shop_items");

            migrationBuilder.DropTable(
                name: "ship_instances");

            migrationBuilder.DropTable(
                name: "ticket_messages");

            migrationBuilder.DropTable(
                name: "character_skills_enhanced");

            migrationBuilder.DropTable(
                name: "character_wallets");

            migrationBuilder.DropTable(
                name: "assets");

            migrationBuilder.DropTable(
                name: "Planets");

            migrationBuilder.DropTable(
                name: "ships");

            migrationBuilder.DropTable(
                name: "support_tickets");

            migrationBuilder.DropTable(
                name: "skills");

            migrationBuilder.DropTable(
                name: "containers");

            migrationBuilder.DropTable(
                name: "SolarSystems");

            migrationBuilder.DropTable(
                name: "item_types");

            migrationBuilder.DropTable(
                name: "Constellations");

            migrationBuilder.DropTable(
                name: "item_groups");

            migrationBuilder.DropTable(
                name: "Regions");

            migrationBuilder.DropTable(
                name: "item_categories");

            migrationBuilder.DropTable(
                name: "universe_generation_configs");

            migrationBuilder.DropTable(
                name: "accounts");

            migrationBuilder.DropTable(
                name: "Characters");

            migrationBuilder.DropTable(
                name: "inventory_items");
        }
    }
}
