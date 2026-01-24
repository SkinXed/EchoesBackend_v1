using System;
using Microsoft.EntityFrameworkCore.Migrations;
using Npgsql.EntityFrameworkCore.PostgreSQL.Metadata;

#nullable disable

namespace Echoes.API.Migrations
{
    /// <inheritdoc />
    public partial class FixAccountsTableSchema : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_account_bans_Accounts_AccountId",
                table: "account_bans");

            migrationBuilder.DropForeignKey(
                name: "FK_account_bans_Characters_BannedById",
                table: "account_bans");

            migrationBuilder.DropForeignKey(
                name: "FK_AccountSessions_Accounts_AccountId",
                table: "AccountSessions");

            migrationBuilder.DropForeignKey(
                name: "FK_AccountSessions_Characters_CharacterId",
                table: "AccountSessions");

            migrationBuilder.DropForeignKey(
                name: "FK_Characters_Accounts_AccountId",
                table: "Characters");

            migrationBuilder.DropPrimaryKey(
                name: "PK_Accounts",
                table: "Accounts");

            migrationBuilder.DropIndex(
                name: "IX_account_bans_BannedById",
                table: "account_bans");

            migrationBuilder.DropColumn(
                name: "IsAdmin",
                table: "Accounts");

            migrationBuilder.DropColumn(
                name: "IsBanned",
                table: "Accounts");

            migrationBuilder.DropColumn(
                name: "LastIP",
                table: "Accounts");

            migrationBuilder.DropColumn(
                name: "IPAddress",
                table: "account_bans");

            migrationBuilder.RenameTable(
                name: "Accounts",
                newName: "accounts");

            migrationBuilder.RenameColumn(
                name: "Id",
                table: "AccountSessions",
                newName: "id");

            migrationBuilder.RenameColumn(
                name: "UserAgent",
                table: "AccountSessions",
                newName: "user_agent");

            migrationBuilder.RenameColumn(
                name: "SessionToken",
                table: "AccountSessions",
                newName: "session_token");

            migrationBuilder.RenameColumn(
                name: "RefreshTokenExpiresAt",
                table: "AccountSessions",
                newName: "refresh_token_expires_at");

            migrationBuilder.RenameColumn(
                name: "RefreshToken",
                table: "AccountSessions",
                newName: "refresh_token");

            migrationBuilder.RenameColumn(
                name: "LastActivity",
                table: "AccountSessions",
                newName: "last_activity");

            migrationBuilder.RenameColumn(
                name: "IsActive",
                table: "AccountSessions",
                newName: "is_active");

            migrationBuilder.RenameColumn(
                name: "IPAddress",
                table: "AccountSessions",
                newName: "ip_address");

            migrationBuilder.RenameColumn(
                name: "ExpiresAt",
                table: "AccountSessions",
                newName: "expires_at");

            migrationBuilder.RenameColumn(
                name: "CreatedAt",
                table: "AccountSessions",
                newName: "created_at");

            migrationBuilder.RenameColumn(
                name: "CharacterId",
                table: "AccountSessions",
                newName: "character_id");

            migrationBuilder.RenameColumn(
                name: "AccountId",
                table: "AccountSessions",
                newName: "account_id");

            migrationBuilder.RenameIndex(
                name: "IX_AccountSessions_CharacterId",
                table: "AccountSessions",
                newName: "IX_AccountSessions_character_id");

            migrationBuilder.RenameIndex(
                name: "IX_AccountSessions_AccountId",
                table: "AccountSessions",
                newName: "IX_AccountSessions_account_id");

            migrationBuilder.RenameColumn(
                name: "Username",
                table: "accounts",
                newName: "username");

            migrationBuilder.RenameColumn(
                name: "Email",
                table: "accounts",
                newName: "email");

            migrationBuilder.RenameColumn(
                name: "PasswordSalt",
                table: "accounts",
                newName: "password_salt");

            migrationBuilder.RenameColumn(
                name: "PasswordHash",
                table: "accounts",
                newName: "password_hash");

            migrationBuilder.RenameColumn(
                name: "LockedUntil",
                table: "accounts",
                newName: "locked_until");

            migrationBuilder.RenameColumn(
                name: "LastLogin",
                table: "accounts",
                newName: "last_login");

            migrationBuilder.RenameColumn(
                name: "IsActive",
                table: "accounts",
                newName: "is_active");

            migrationBuilder.RenameColumn(
                name: "FailedLoginAttempts",
                table: "accounts",
                newName: "failed_login_attempts");

            migrationBuilder.RenameColumn(
                name: "CreatedAt",
                table: "accounts",
                newName: "created_at");

            migrationBuilder.RenameColumn(
                name: "LastLogout",
                table: "accounts",
                newName: "trial_ends_at");

            migrationBuilder.RenameColumn(
                name: "IsDeveloper",
                table: "accounts",
                newName: "is_email_verified");

            migrationBuilder.RenameColumn(
                name: "Id",
                table: "accounts",
                newName: "account_id");

            migrationBuilder.RenameIndex(
                name: "IX_Accounts_Username",
                table: "accounts",
                newName: "IX_accounts_username");

            migrationBuilder.RenameIndex(
                name: "IX_Accounts_Email",
                table: "accounts",
                newName: "IX_accounts_email");

            migrationBuilder.RenameColumn(
                name: "Reason",
                table: "account_bans",
                newName: "reason");

            migrationBuilder.RenameColumn(
                name: "AccountId",
                table: "account_bans",
                newName: "account_id");

            migrationBuilder.RenameColumn(
                name: "ExpiresAt",
                table: "account_bans",
                newName: "end_date");

            migrationBuilder.RenameColumn(
                name: "BannedById",
                table: "account_bans",
                newName: "banned_by");

            migrationBuilder.RenameColumn(
                name: "BannedAt",
                table: "account_bans",
                newName: "updated_at");

            migrationBuilder.RenameColumn(
                name: "Id",
                table: "account_bans",
                newName: "ban_id");

            migrationBuilder.RenameIndex(
                name: "IX_account_bans_AccountId",
                table: "account_bans",
                newName: "IX_account_bans_account_id");

            migrationBuilder.AlterColumn<DateTime>(
                name: "LastLogin",
                table: "Characters",
                type: "timestamp with time zone",
                nullable: true,
                defaultValueSql: "NOW()",
                oldClrType: typeof(DateTime),
                oldType: "timestamp with time zone",
                oldDefaultValueSql: "NOW()");

            migrationBuilder.AddColumn<Guid>(
                name: "ActiveCloneId",
                table: "Characters",
                type: "uuid",
                nullable: true);

            migrationBuilder.AddColumn<int>(
                name: "Charisma",
                table: "Characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<int>(
                name: "Intelligence",
                table: "Characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<int>(
                name: "JumpCloneCount",
                table: "Characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<DateTime>(
                name: "LastLogout",
                table: "Characters",
                type: "timestamp with time zone",
                nullable: true);

            migrationBuilder.AddColumn<int>(
                name: "MaxJumpClones",
                table: "Characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<int>(
                name: "Memory",
                table: "Characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<int>(
                name: "Perception",
                table: "Characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<int>(
                name: "TotalDeaths",
                table: "Characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<decimal>(
                name: "TotalISKEarned",
                table: "Characters",
                type: "numeric",
                nullable: false,
                defaultValue: 0m);

            migrationBuilder.AddColumn<decimal>(
                name: "TotalISKLost",
                table: "Characters",
                type: "numeric",
                nullable: false,
                defaultValue: 0m);

            migrationBuilder.AddColumn<int>(
                name: "TotalKills",
                table: "Characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<long>(
                name: "TotalPlayTimeSeconds",
                table: "Characters",
                type: "bigint",
                nullable: false,
                defaultValue: 0L);

            migrationBuilder.AddColumn<int>(
                name: "TotalShipsDestroyed",
                table: "Characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<int>(
                name: "TotalShipsLost",
                table: "Characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<int>(
                name: "Willpower",
                table: "Characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AlterColumn<string>(
                name: "user_agent",
                table: "AccountSessions",
                type: "text",
                nullable: true,
                oldClrType: typeof(string),
                oldType: "character varying(500)",
                oldMaxLength: 500);

            migrationBuilder.AlterColumn<string>(
                name: "session_token",
                table: "AccountSessions",
                type: "text",
                nullable: false,
                oldClrType: typeof(string),
                oldType: "character varying(500)",
                oldMaxLength: 500);

            migrationBuilder.AlterColumn<DateTime>(
                name: "refresh_token_expires_at",
                table: "AccountSessions",
                type: "timestamp with time zone",
                nullable: false,
                defaultValue: new DateTime(1, 1, 1, 0, 0, 0, 0, DateTimeKind.Unspecified),
                oldClrType: typeof(DateTime),
                oldType: "timestamp with time zone",
                oldNullable: true);

            migrationBuilder.AlterColumn<string>(
                name: "refresh_token",
                table: "AccountSessions",
                type: "text",
                nullable: false,
                oldClrType: typeof(string),
                oldType: "character varying(500)",
                oldMaxLength: 500);

            migrationBuilder.AlterColumn<string>(
                name: "ip_address",
                table: "AccountSessions",
                type: "text",
                nullable: true,
                oldClrType: typeof(string),
                oldType: "character varying(45)",
                oldMaxLength: 45);

            migrationBuilder.AlterColumn<Guid>(
                name: "character_id",
                table: "AccountSessions",
                type: "uuid",
                nullable: true,
                oldClrType: typeof(Guid),
                oldType: "uuid");

            migrationBuilder.AddColumn<bool>(
                name: "is_revoked",
                table: "AccountSessions",
                type: "boolean",
                nullable: false,
                defaultValue: false);

            migrationBuilder.AlterColumn<string>(
                name: "username",
                table: "accounts",
                type: "text",
                nullable: false,
                oldClrType: typeof(string),
                oldType: "character varying(50)",
                oldMaxLength: 50);

            migrationBuilder.AlterColumn<string>(
                name: "email",
                table: "accounts",
                type: "text",
                nullable: false,
                oldClrType: typeof(string),
                oldType: "character varying(100)",
                oldMaxLength: 100);

            migrationBuilder.AlterColumn<bool>(
                name: "is_active",
                table: "accounts",
                type: "boolean",
                nullable: false,
                oldClrType: typeof(bool),
                oldType: "boolean",
                oldDefaultValue: true);

            migrationBuilder.AddColumn<int>(
                name: "account_status",
                table: "accounts",
                type: "integer",
                nullable: false,
                defaultValue: 1);

            migrationBuilder.AddColumn<int>(
                name: "account_type",
                table: "accounts",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<string>(
                name: "country_code",
                table: "accounts",
                type: "text",
                nullable: true);

            migrationBuilder.AddColumn<string>(
                name: "display_name",
                table: "accounts",
                type: "text",
                nullable: true);

            migrationBuilder.AddColumn<string>(
                name: "email_verification_token",
                table: "accounts",
                type: "text",
                nullable: true);

            migrationBuilder.AddColumn<DateTime>(
                name: "email_verified_at",
                table: "accounts",
                type: "timestamp with time zone",
                nullable: true);

            migrationBuilder.AddColumn<string>(
                name: "google_id",
                table: "accounts",
                type: "character varying(255)",
                maxLength: 255,
                nullable: true);

            migrationBuilder.AddColumn<string>(
                name: "language",
                table: "accounts",
                type: "text",
                nullable: false,
                defaultValue: "");

            migrationBuilder.AddColumn<DateTime>(
                name: "last_active",
                table: "accounts",
                type: "timestamp with time zone",
                nullable: true);

            migrationBuilder.AddColumn<string>(
                name: "last_login_ip",
                table: "accounts",
                type: "text",
                nullable: true);

            migrationBuilder.AddColumn<string>(
                name: "metadata",
                table: "accounts",
                type: "text",
                nullable: false,
                defaultValue: "");

            migrationBuilder.AddColumn<string>(
                name: "nickname",
                table: "accounts",
                type: "character varying(50)",
                maxLength: 50,
                nullable: true);

            migrationBuilder.AddColumn<long>(
                name: "notification_settings",
                table: "accounts",
                type: "bigint",
                nullable: false,
                defaultValue: 0L);

            migrationBuilder.AddColumn<DateTime>(
                name: "password_changed_at",
                table: "accounts",
                type: "timestamp with time zone",
                nullable: false,
                defaultValue: new DateTime(1, 1, 1, 0, 0, 0, 0, DateTimeKind.Unspecified));

            migrationBuilder.AddColumn<DateTime>(
                name: "password_reset_expires",
                table: "accounts",
                type: "timestamp with time zone",
                nullable: true);

            migrationBuilder.AddColumn<string>(
                name: "password_reset_token",
                table: "accounts",
                type: "text",
                nullable: true);

            migrationBuilder.AddColumn<string>(
                name: "phone_number",
                table: "accounts",
                type: "text",
                nullable: true);

            migrationBuilder.AddColumn<DateTime>(
                name: "phone_verified_at",
                table: "accounts",
                type: "timestamp with time zone",
                nullable: true);

            migrationBuilder.AddColumn<string>(
                name: "referral_code",
                table: "accounts",
                type: "text",
                nullable: false,
                defaultValue: "");

            migrationBuilder.AddColumn<string>(
                name: "referred_by",
                table: "accounts",
                type: "text",
                nullable: true);

            migrationBuilder.AddColumn<long>(
                name: "roles",
                table: "accounts",
                type: "bigint",
                nullable: false,
                defaultValue: 0L);

            migrationBuilder.AddColumn<DateTime>(
                name: "subscription_end",
                table: "accounts",
                type: "timestamp with time zone",
                nullable: true);

            migrationBuilder.AddColumn<DateTime>(
                name: "subscription_start",
                table: "accounts",
                type: "timestamp with time zone",
                nullable: true);

            migrationBuilder.AddColumn<int>(
                name: "subscription_type",
                table: "accounts",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<string>(
                name: "timezone",
                table: "accounts",
                type: "text",
                nullable: false,
                defaultValue: "");

            migrationBuilder.AddColumn<int>(
                name: "total_characters",
                table: "accounts",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<long>(
                name: "total_play_time",
                table: "accounts",
                type: "bigint",
                nullable: false,
                defaultValue: 0L);

            migrationBuilder.AddColumn<int>(
                name: "total_referrals",
                table: "accounts",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<decimal>(
                name: "total_spent",
                table: "accounts",
                type: "numeric",
                nullable: false,
                defaultValue: 0m);

            migrationBuilder.AddColumn<string>(
                name: "two_factor_recovery_codes",
                table: "accounts",
                type: "text",
                nullable: true);

            migrationBuilder.AddColumn<string>(
                name: "two_factor_secret",
                table: "accounts",
                type: "text",
                nullable: true);

            migrationBuilder.AddColumn<int>(
                name: "two_factor_type",
                table: "accounts",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<DateTime>(
                name: "updated_at",
                table: "accounts",
                type: "timestamp with time zone",
                nullable: false,
                defaultValue: new DateTime(1, 1, 1, 0, 0, 0, 0, DateTimeKind.Unspecified));

            migrationBuilder.AlterColumn<int>(
                name: "reason",
                table: "account_bans",
                type: "integer",
                nullable: false,
                oldClrType: typeof(string),
                oldType: "character varying(500)",
                oldMaxLength: 500);

            migrationBuilder.AddColumn<bool>(
                name: "appeal_allowed",
                table: "account_bans",
                type: "boolean",
                nullable: false,
                defaultValue: false);

            migrationBuilder.AddColumn<string>(
                name: "appeal_response",
                table: "account_bans",
                type: "text",
                nullable: true);

            migrationBuilder.AddColumn<DateTime>(
                name: "appeal_reviewed_at",
                table: "account_bans",
                type: "timestamp with time zone",
                nullable: true);

            migrationBuilder.AddColumn<Guid>(
                name: "appeal_reviewed_by",
                table: "account_bans",
                type: "uuid",
                nullable: true);

            migrationBuilder.AddColumn<int>(
                name: "appeal_status",
                table: "account_bans",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<string>(
                name: "appeal_text",
                table: "account_bans",
                type: "text",
                nullable: true);

            migrationBuilder.AddColumn<DateTime>(
                name: "created_at",
                table: "account_bans",
                type: "timestamp with time zone",
                nullable: false,
                defaultValue: new DateTime(1, 1, 1, 0, 0, 0, 0, DateTimeKind.Unspecified));

            migrationBuilder.AddColumn<string>(
                name: "evidence",
                table: "account_bans",
                type: "text",
                nullable: true);

            migrationBuilder.AddColumn<bool>(
                name: "is_permanent",
                table: "account_bans",
                type: "boolean",
                nullable: false,
                defaultValue: false);

            migrationBuilder.AddColumn<string>(
                name: "reason_text",
                table: "account_bans",
                type: "text",
                nullable: false,
                defaultValue: "");

            migrationBuilder.AddColumn<DateTime>(
                name: "start_date",
                table: "account_bans",
                type: "timestamp with time zone",
                nullable: false,
                defaultValue: new DateTime(1, 1, 1, 0, 0, 0, 0, DateTimeKind.Unspecified));

            migrationBuilder.AddPrimaryKey(
                name: "PK_accounts",
                table: "accounts",
                column: "account_id");

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
                    table.ForeignKey(
                        name: "FK_character_clones_Characters_character_id",
                        column: x => x.character_id,
                        principalTable: "Characters",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
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
                    table.ForeignKey(
                        name: "FK_character_contracts_Characters_acceptor_id",
                        column: x => x.acceptor_id,
                        principalTable: "Characters",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_character_contracts_Characters_assignee_id",
                        column: x => x.assignee_id,
                        principalTable: "Characters",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_character_contracts_Characters_issuer_id",
                        column: x => x.issuer_id,
                        principalTable: "Characters",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
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
                        name: "FK_character_implants_enhanced_Characters_character_id",
                        column: x => x.character_id,
                        principalTable: "Characters",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_character_implants_enhanced_assets_asset_id",
                        column: x => x.asset_id,
                        principalTable: "assets",
                        principalColumn: "asset_id",
                        onDelete: ReferentialAction.Cascade);
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
                    table.ForeignKey(
                        name: "FK_character_wallets_Characters_character_id",
                        column: x => x.character_id,
                        principalTable: "Characters",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
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
                        name: "FK_character_skills_enhanced_Characters_character_id",
                        column: x => x.character_id,
                        principalTable: "Characters",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_character_skills_enhanced_skills_skill_id",
                        column: x => x.skill_id,
                        principalTable: "skills",
                        principalColumn: "skill_id",
                        onDelete: ReferentialAction.Cascade);
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

            migrationBuilder.CreateIndex(
                name: "IX_account_activities_account_id",
                table: "account_activities",
                column: "account_id");

            migrationBuilder.CreateIndex(
                name: "IX_api_keys_account_id",
                table: "api_keys",
                column: "account_id");

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
                name: "IX_character_implants_enhanced_asset_id",
                table: "character_implants_enhanced",
                column: "asset_id");

            migrationBuilder.CreateIndex(
                name: "IX_character_implants_enhanced_character_id",
                table: "character_implants_enhanced",
                column: "character_id");

            migrationBuilder.CreateIndex(
                name: "IX_character_skills_enhanced_character_id",
                table: "character_skills_enhanced",
                column: "character_id");

            migrationBuilder.CreateIndex(
                name: "IX_character_skills_enhanced_skill_id",
                table: "character_skills_enhanced",
                column: "skill_id");

            migrationBuilder.CreateIndex(
                name: "IX_character_wallets_character_id",
                table: "character_wallets",
                column: "character_id");

            migrationBuilder.CreateIndex(
                name: "IX_player_inventory_items_shop_item_id",
                table: "player_inventory_items",
                column: "shop_item_id");

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

            migrationBuilder.AddForeignKey(
                name: "FK_account_bans_accounts_account_id",
                table: "account_bans",
                column: "account_id",
                principalTable: "accounts",
                principalColumn: "account_id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_AccountSessions_Characters_character_id",
                table: "AccountSessions",
                column: "character_id",
                principalTable: "Characters",
                principalColumn: "Id");

            migrationBuilder.AddForeignKey(
                name: "FK_AccountSessions_accounts_account_id",
                table: "AccountSessions",
                column: "account_id",
                principalTable: "accounts",
                principalColumn: "account_id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_Characters_accounts_AccountId",
                table: "Characters",
                column: "AccountId",
                principalTable: "accounts",
                principalColumn: "account_id",
                onDelete: ReferentialAction.Cascade);
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_account_bans_accounts_account_id",
                table: "account_bans");

            migrationBuilder.DropForeignKey(
                name: "FK_AccountSessions_Characters_character_id",
                table: "AccountSessions");

            migrationBuilder.DropForeignKey(
                name: "FK_AccountSessions_accounts_account_id",
                table: "AccountSessions");

            migrationBuilder.DropForeignKey(
                name: "FK_Characters_accounts_AccountId",
                table: "Characters");

            migrationBuilder.DropTable(
                name: "account_activities");

            migrationBuilder.DropTable(
                name: "api_keys");

            migrationBuilder.DropTable(
                name: "character_clones");

            migrationBuilder.DropTable(
                name: "character_contracts");

            migrationBuilder.DropTable(
                name: "character_implants_enhanced");

            migrationBuilder.DropTable(
                name: "player_inventory_items");

            migrationBuilder.DropTable(
                name: "ticket_attachments");

            migrationBuilder.DropTable(
                name: "training_queues");

            migrationBuilder.DropTable(
                name: "wallet_transactions");

            migrationBuilder.DropTable(
                name: "shop_items");

            migrationBuilder.DropTable(
                name: "ticket_messages");

            migrationBuilder.DropTable(
                name: "character_skills_enhanced");

            migrationBuilder.DropTable(
                name: "character_wallets");

            migrationBuilder.DropTable(
                name: "support_tickets");

            migrationBuilder.DropTable(
                name: "skills");

            migrationBuilder.DropPrimaryKey(
                name: "PK_accounts",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "ActiveCloneId",
                table: "Characters");

            migrationBuilder.DropColumn(
                name: "Charisma",
                table: "Characters");

            migrationBuilder.DropColumn(
                name: "Intelligence",
                table: "Characters");

            migrationBuilder.DropColumn(
                name: "JumpCloneCount",
                table: "Characters");

            migrationBuilder.DropColumn(
                name: "LastLogout",
                table: "Characters");

            migrationBuilder.DropColumn(
                name: "MaxJumpClones",
                table: "Characters");

            migrationBuilder.DropColumn(
                name: "Memory",
                table: "Characters");

            migrationBuilder.DropColumn(
                name: "Perception",
                table: "Characters");

            migrationBuilder.DropColumn(
                name: "TotalDeaths",
                table: "Characters");

            migrationBuilder.DropColumn(
                name: "TotalISKEarned",
                table: "Characters");

            migrationBuilder.DropColumn(
                name: "TotalISKLost",
                table: "Characters");

            migrationBuilder.DropColumn(
                name: "TotalKills",
                table: "Characters");

            migrationBuilder.DropColumn(
                name: "TotalPlayTimeSeconds",
                table: "Characters");

            migrationBuilder.DropColumn(
                name: "TotalShipsDestroyed",
                table: "Characters");

            migrationBuilder.DropColumn(
                name: "TotalShipsLost",
                table: "Characters");

            migrationBuilder.DropColumn(
                name: "Willpower",
                table: "Characters");

            migrationBuilder.DropColumn(
                name: "is_revoked",
                table: "AccountSessions");

            migrationBuilder.DropColumn(
                name: "account_status",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "account_type",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "country_code",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "display_name",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "email_verification_token",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "email_verified_at",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "google_id",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "language",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "last_active",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "last_login_ip",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "metadata",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "nickname",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "notification_settings",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "password_changed_at",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "password_reset_expires",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "password_reset_token",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "phone_number",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "phone_verified_at",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "referral_code",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "referred_by",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "roles",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "subscription_end",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "subscription_start",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "subscription_type",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "timezone",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "total_characters",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "total_play_time",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "total_referrals",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "total_spent",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "two_factor_recovery_codes",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "two_factor_secret",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "two_factor_type",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "updated_at",
                table: "accounts");

            migrationBuilder.DropColumn(
                name: "appeal_allowed",
                table: "account_bans");

            migrationBuilder.DropColumn(
                name: "appeal_response",
                table: "account_bans");

            migrationBuilder.DropColumn(
                name: "appeal_reviewed_at",
                table: "account_bans");

            migrationBuilder.DropColumn(
                name: "appeal_reviewed_by",
                table: "account_bans");

            migrationBuilder.DropColumn(
                name: "appeal_status",
                table: "account_bans");

            migrationBuilder.DropColumn(
                name: "appeal_text",
                table: "account_bans");

            migrationBuilder.DropColumn(
                name: "created_at",
                table: "account_bans");

            migrationBuilder.DropColumn(
                name: "evidence",
                table: "account_bans");

            migrationBuilder.DropColumn(
                name: "is_permanent",
                table: "account_bans");

            migrationBuilder.DropColumn(
                name: "reason_text",
                table: "account_bans");

            migrationBuilder.DropColumn(
                name: "start_date",
                table: "account_bans");

            migrationBuilder.RenameTable(
                name: "accounts",
                newName: "Accounts");

            migrationBuilder.RenameColumn(
                name: "id",
                table: "AccountSessions",
                newName: "Id");

            migrationBuilder.RenameColumn(
                name: "user_agent",
                table: "AccountSessions",
                newName: "UserAgent");

            migrationBuilder.RenameColumn(
                name: "session_token",
                table: "AccountSessions",
                newName: "SessionToken");

            migrationBuilder.RenameColumn(
                name: "refresh_token_expires_at",
                table: "AccountSessions",
                newName: "RefreshTokenExpiresAt");

            migrationBuilder.RenameColumn(
                name: "refresh_token",
                table: "AccountSessions",
                newName: "RefreshToken");

            migrationBuilder.RenameColumn(
                name: "last_activity",
                table: "AccountSessions",
                newName: "LastActivity");

            migrationBuilder.RenameColumn(
                name: "is_active",
                table: "AccountSessions",
                newName: "IsActive");

            migrationBuilder.RenameColumn(
                name: "ip_address",
                table: "AccountSessions",
                newName: "IPAddress");

            migrationBuilder.RenameColumn(
                name: "expires_at",
                table: "AccountSessions",
                newName: "ExpiresAt");

            migrationBuilder.RenameColumn(
                name: "created_at",
                table: "AccountSessions",
                newName: "CreatedAt");

            migrationBuilder.RenameColumn(
                name: "character_id",
                table: "AccountSessions",
                newName: "CharacterId");

            migrationBuilder.RenameColumn(
                name: "account_id",
                table: "AccountSessions",
                newName: "AccountId");

            migrationBuilder.RenameIndex(
                name: "IX_AccountSessions_character_id",
                table: "AccountSessions",
                newName: "IX_AccountSessions_CharacterId");

            migrationBuilder.RenameIndex(
                name: "IX_AccountSessions_account_id",
                table: "AccountSessions",
                newName: "IX_AccountSessions_AccountId");

            migrationBuilder.RenameColumn(
                name: "username",
                table: "Accounts",
                newName: "Username");

            migrationBuilder.RenameColumn(
                name: "email",
                table: "Accounts",
                newName: "Email");

            migrationBuilder.RenameColumn(
                name: "password_salt",
                table: "Accounts",
                newName: "PasswordSalt");

            migrationBuilder.RenameColumn(
                name: "password_hash",
                table: "Accounts",
                newName: "PasswordHash");

            migrationBuilder.RenameColumn(
                name: "locked_until",
                table: "Accounts",
                newName: "LockedUntil");

            migrationBuilder.RenameColumn(
                name: "last_login",
                table: "Accounts",
                newName: "LastLogin");

            migrationBuilder.RenameColumn(
                name: "is_active",
                table: "Accounts",
                newName: "IsActive");

            migrationBuilder.RenameColumn(
                name: "failed_login_attempts",
                table: "Accounts",
                newName: "FailedLoginAttempts");

            migrationBuilder.RenameColumn(
                name: "created_at",
                table: "Accounts",
                newName: "CreatedAt");

            migrationBuilder.RenameColumn(
                name: "trial_ends_at",
                table: "Accounts",
                newName: "LastLogout");

            migrationBuilder.RenameColumn(
                name: "is_email_verified",
                table: "Accounts",
                newName: "IsDeveloper");

            migrationBuilder.RenameColumn(
                name: "account_id",
                table: "Accounts",
                newName: "Id");

            migrationBuilder.RenameIndex(
                name: "IX_accounts_username",
                table: "Accounts",
                newName: "IX_Accounts_Username");

            migrationBuilder.RenameIndex(
                name: "IX_accounts_email",
                table: "Accounts",
                newName: "IX_Accounts_Email");

            migrationBuilder.RenameColumn(
                name: "reason",
                table: "account_bans",
                newName: "Reason");

            migrationBuilder.RenameColumn(
                name: "account_id",
                table: "account_bans",
                newName: "AccountId");

            migrationBuilder.RenameColumn(
                name: "updated_at",
                table: "account_bans",
                newName: "BannedAt");

            migrationBuilder.RenameColumn(
                name: "end_date",
                table: "account_bans",
                newName: "ExpiresAt");

            migrationBuilder.RenameColumn(
                name: "banned_by",
                table: "account_bans",
                newName: "BannedById");

            migrationBuilder.RenameColumn(
                name: "ban_id",
                table: "account_bans",
                newName: "Id");

            migrationBuilder.RenameIndex(
                name: "IX_account_bans_account_id",
                table: "account_bans",
                newName: "IX_account_bans_AccountId");

            migrationBuilder.AlterColumn<DateTime>(
                name: "LastLogin",
                table: "Characters",
                type: "timestamp with time zone",
                nullable: false,
                defaultValueSql: "NOW()",
                oldClrType: typeof(DateTime),
                oldType: "timestamp with time zone",
                oldNullable: true,
                oldDefaultValueSql: "NOW()");

            migrationBuilder.AlterColumn<string>(
                name: "UserAgent",
                table: "AccountSessions",
                type: "character varying(500)",
                maxLength: 500,
                nullable: false,
                defaultValue: "",
                oldClrType: typeof(string),
                oldType: "text",
                oldNullable: true);

            migrationBuilder.AlterColumn<string>(
                name: "SessionToken",
                table: "AccountSessions",
                type: "character varying(500)",
                maxLength: 500,
                nullable: false,
                oldClrType: typeof(string),
                oldType: "text");

            migrationBuilder.AlterColumn<DateTime>(
                name: "RefreshTokenExpiresAt",
                table: "AccountSessions",
                type: "timestamp with time zone",
                nullable: true,
                oldClrType: typeof(DateTime),
                oldType: "timestamp with time zone");

            migrationBuilder.AlterColumn<string>(
                name: "RefreshToken",
                table: "AccountSessions",
                type: "character varying(500)",
                maxLength: 500,
                nullable: false,
                oldClrType: typeof(string),
                oldType: "text");

            migrationBuilder.AlterColumn<string>(
                name: "IPAddress",
                table: "AccountSessions",
                type: "character varying(45)",
                maxLength: 45,
                nullable: false,
                defaultValue: "",
                oldClrType: typeof(string),
                oldType: "text",
                oldNullable: true);

            migrationBuilder.AlterColumn<Guid>(
                name: "CharacterId",
                table: "AccountSessions",
                type: "uuid",
                nullable: false,
                defaultValue: new Guid("00000000-0000-0000-0000-000000000000"),
                oldClrType: typeof(Guid),
                oldType: "uuid",
                oldNullable: true);

            migrationBuilder.AlterColumn<string>(
                name: "Username",
                table: "Accounts",
                type: "character varying(50)",
                maxLength: 50,
                nullable: false,
                oldClrType: typeof(string),
                oldType: "text");

            migrationBuilder.AlterColumn<string>(
                name: "Email",
                table: "Accounts",
                type: "character varying(100)",
                maxLength: 100,
                nullable: false,
                oldClrType: typeof(string),
                oldType: "text");

            migrationBuilder.AlterColumn<bool>(
                name: "IsActive",
                table: "Accounts",
                type: "boolean",
                nullable: false,
                defaultValue: true,
                oldClrType: typeof(bool),
                oldType: "boolean");

            migrationBuilder.AddColumn<bool>(
                name: "IsAdmin",
                table: "Accounts",
                type: "boolean",
                nullable: false,
                defaultValue: false);

            migrationBuilder.AddColumn<bool>(
                name: "IsBanned",
                table: "Accounts",
                type: "boolean",
                nullable: false,
                defaultValue: false);

            migrationBuilder.AddColumn<string>(
                name: "LastIP",
                table: "Accounts",
                type: "character varying(45)",
                maxLength: 45,
                nullable: false,
                defaultValue: "");

            migrationBuilder.AlterColumn<string>(
                name: "Reason",
                table: "account_bans",
                type: "character varying(500)",
                maxLength: 500,
                nullable: false,
                oldClrType: typeof(int),
                oldType: "integer");

            migrationBuilder.AddColumn<string>(
                name: "IPAddress",
                table: "account_bans",
                type: "character varying(45)",
                maxLength: 45,
                nullable: false,
                defaultValue: "");

            migrationBuilder.AddPrimaryKey(
                name: "PK_Accounts",
                table: "Accounts",
                column: "Id");

            migrationBuilder.CreateIndex(
                name: "IX_account_bans_BannedById",
                table: "account_bans",
                column: "BannedById");

            migrationBuilder.AddForeignKey(
                name: "FK_account_bans_Accounts_AccountId",
                table: "account_bans",
                column: "AccountId",
                principalTable: "Accounts",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_account_bans_Characters_BannedById",
                table: "account_bans",
                column: "BannedById",
                principalTable: "Characters",
                principalColumn: "Id");

            migrationBuilder.AddForeignKey(
                name: "FK_AccountSessions_Accounts_AccountId",
                table: "AccountSessions",
                column: "AccountId",
                principalTable: "Accounts",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_AccountSessions_Characters_CharacterId",
                table: "AccountSessions",
                column: "CharacterId",
                principalTable: "Characters",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_Characters_Accounts_AccountId",
                table: "Characters",
                column: "AccountId",
                principalTable: "Accounts",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);
        }
    }
}
