using System;
using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace Echoes.API.Migrations
{
    /// <inheritdoc />
    public partial class AddNewsAndWikiTables : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "news_posts",
                columns: table => new
                {
                    news_post_id = table.Column<Guid>(type: "uuid", nullable: false),
                    title = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    content = table.Column<string>(type: "text", nullable: false),
                    image_url = table.Column<string>(type: "character varying(500)", maxLength: 500, nullable: true),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    author_id = table.Column<Guid>(type: "uuid", nullable: false),
                    author_name = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: false),
                    is_published = table.Column<bool>(type: "boolean", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_news_posts", x => x.news_post_id);
                    table.ForeignKey(
                        name: "FK_news_posts_accounts_author_id",
                        column: x => x.author_id,
                        principalTable: "accounts",
                        principalColumn: "account_id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "wiki_pages",
                columns: table => new
                {
                    wiki_page_id = table.Column<Guid>(type: "uuid", nullable: false),
                    section_name = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: false),
                    title = table.Column<string>(type: "character varying(200)", maxLength: 200, nullable: false),
                    content_html = table.Column<string>(type: "text", nullable: false),
                    created_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    updated_at = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    created_by_id = table.Column<Guid>(type: "uuid", nullable: false),
                    created_by_name = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: false),
                    last_updated_by_id = table.Column<Guid>(type: "uuid", nullable: true),
                    last_updated_by = table.Column<string>(type: "character varying(100)", maxLength: 100, nullable: true),
                    is_published = table.Column<bool>(type: "boolean", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_wiki_pages", x => x.wiki_page_id);
                    table.ForeignKey(
                        name: "FK_wiki_pages_accounts_created_by_id",
                        column: x => x.created_by_id,
                        principalTable: "accounts",
                        principalColumn: "account_id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_wiki_pages_accounts_last_updated_by_id",
                        column: x => x.last_updated_by_id,
                        principalTable: "accounts",
                        principalColumn: "account_id");
                });

            migrationBuilder.CreateIndex(
                name: "IX_news_posts_author_id",
                table: "news_posts",
                column: "author_id");

            migrationBuilder.CreateIndex(
                name: "IX_wiki_pages_created_by_id",
                table: "wiki_pages",
                column: "created_by_id");

            migrationBuilder.CreateIndex(
                name: "IX_wiki_pages_last_updated_by_id",
                table: "wiki_pages",
                column: "last_updated_by_id");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "news_posts");

            migrationBuilder.DropTable(
                name: "wiki_pages");
        }
    }
}
