# Blazor WebAssembly Project Setup Guide

This document provides the complete commands and code for adding the **EchoesOfImperial.Client** Blazor WebAssembly project to the EchoesBackend solution.

## Prerequisites
- .NET 8.0 SDK or later
- Existing "EchoesBackend.sln" solution

## Step 1: Create the Shared Project

```bash
# Navigate to solution root
cd /path/to/EchoesBackend_v1

# Create Shared class library
dotnet new classlib -n EchoesOfImperial.Shared -f net8.0

# Add to solution
dotnet sln EchoesBackend.sln add EchoesOfImperial.Shared/EchoesOfImperial.Shared.csproj

# Clean up default files
cd EchoesOfImperial.Shared
rm Class1.cs
mkdir DTOs
cd ..

# Add Shared reference to API project
dotnet add Echoes.API.csproj reference EchoesOfImperial.Shared/EchoesOfImperial.Shared.csproj
```

## Step 2: Create the Blazor WebAssembly Project

```bash
# Create Blazor WebAssembly project
dotnet new blazorwasm -n EchoesOfImperial.Client -f net8.0

# Add to solution
dotnet sln EchoesBackend.sln add EchoesOfImperial.Client/EchoesOfImperial.Client.csproj

# Add Shared reference to Client project
dotnet add EchoesOfImperial.Client/EchoesOfImperial.Client.csproj reference EchoesOfImperial.Shared/EchoesOfImperial.Shared.csproj

# Clean up template files
cd EchoesOfImperial.Client
rm Pages/Counter.razor Pages/Weather.razor
rm -rf wwwroot/sample-data
cd ..
```

## Step 3: Update API Project Configuration

Add exclusions to `Echoes.API.csproj` to prevent it from compiling Client and Shared project files:

```xml
<ItemGroup>
  <!-- Exclude Client and Shared project folders from API project -->
  <Compile Remove="EchoesOfImperial.Client\**" />
  <Content Remove="EchoesOfImperial.Client\**" />
  <EmbeddedResource Remove="EchoesOfImperial.Client\**" />
  <None Remove="EchoesOfImperial.Client\**" />
  
  <Compile Remove="EchoesOfImperial.Shared\**" />
  <Content Remove="EchoesOfImperial.Shared\**" />
  <EmbeddedResource Remove="EchoesOfImperial.Shared\**" />
  <None Remove="EchoesOfImperial.Shared\**" />
</ItemGroup>
```

## Code Files

### Program.cs (EchoesOfImperial.Client)

```csharp
using Microsoft.AspNetCore.Components.Web;
using Microsoft.AspNetCore.Components.WebAssembly.Hosting;
using EchoesOfImperial.Client;

var builder = WebAssemblyHostBuilder.CreateDefault(args);
builder.RootComponents.Add<App>("#app");
builder.RootComponents.Add<HeadOutlet>("head::after");

// Configure HttpClient to point to the API
builder.Services.AddScoped(sp => new HttpClient 
{ 
    BaseAddress = new Uri("https://localhost:5115") 
});

await builder.Build().RunAsync();
```

### App.razor (EchoesOfImperial.Client)

```razor
<Router AppAssembly="@typeof(App).Assembly">
    <Found Context="routeData">
        <RouteView RouteData="@routeData" DefaultLayout="@typeof(MainLayout)" />
        <FocusOnNavigate RouteData="@routeData" Selector="h1" />
    </Found>
    <NotFound>
        <PageTitle>404 - Not Found</PageTitle>
        <LayoutView Layout="@typeof(MainLayout)">
            <div class="not-found">
                <h1>404 - Lost in the Void</h1>
                <p>The coordinates you seek do not exist in this sector.</p>
                <a href="/">Return to Command Center</a>
            </div>
        </LayoutView>
    </NotFound>
</Router>
```

### MainLayout.razor (EchoesOfImperial.Client/Layout)

```razor
@inherits LayoutComponentBase
<div class="page">
    <div class="sidebar">
        <NavMenu />
    </div>

    <main>
        <article class="content px-4">
            @Body
        </article>
    </main>
</div>
```

### NavMenu.razor (EchoesOfImperial.Client/Layout)

```razor
<div class="top-row ps-3 navbar navbar-dark">
    <div class="container-fluid">
        <a class="navbar-brand" href="">Echoes of Imperial</a>
        <button title="Navigation menu" class="navbar-toggler" @onclick="ToggleNavMenu">
            <span class="navbar-toggler-icon"></span>
        </button>
    </div>
</div>

<div class="@NavMenuCssClass nav-scrollable" @onclick="ToggleNavMenu">
    <nav class="flex-column">
        <div class="nav-item px-3">
            <NavLink class="nav-link" href="dashboard">
                <span class="bi bi-house-door-fill-nav-menu" aria-hidden="true"></span> Dashboard
            </NavLink>
        </div>
    </nav>
</div>

@code {
    private bool collapseNavMenu = true;

    private string? NavMenuCssClass => collapseNavMenu ? "collapse" : null;

    private void ToggleNavMenu()
    {
        collapseNavMenu = !collapseNavMenu;
    }
}
```

### app.css (EchoesOfImperial.Client/wwwroot/css) - Imperial Void Theme

```css
/* Imperial Void Theme */
@import url('https://fonts.googleapis.com/css2?family=Rajdhani:wght@300;400;500;600;700&display=swap');

:root {
    --imperial-bg: #050505;
    --imperial-panel: rgba(15, 18, 22, 0.95);
    --imperial-gold: #C5A059;
    --imperial-text: #E0E0E0;
    --font-main: 'Rajdhani', sans-serif;
}

* {
    box-sizing: border-box;
}

html, body {
    font-family: var(--font-main);
    margin: 0;
    padding: 0;
    background-color: var(--imperial-bg);
    color: var(--imperial-text);
}

h1, h2, h3, h4, h5, h6 {
    color: var(--imperial-gold);
    font-weight: 600;
    letter-spacing: 0.05em;
}

h1:focus {
    outline: none;
}

a {
    color: var(--imperial-gold);
    text-decoration: none;
    transition: opacity 0.2s;
}

a:hover {
    opacity: 0.8;
}

.btn-link {
    color: var(--imperial-gold);
}

.btn-primary {
    color: var(--imperial-bg);
    background-color: var(--imperial-gold);
    border-color: var(--imperial-gold);
    font-family: var(--font-main);
    font-weight: 600;
    letter-spacing: 0.05em;
}

.btn-primary:hover {
    background-color: #B8964D;
    border-color: #B8964D;
}

.btn:focus, .btn:active:focus, .btn-link.nav-link:focus, .form-control:focus, .form-check-input:focus {
    box-shadow: 0 0 0 0.1rem var(--imperial-panel), 0 0 0 0.25rem var(--imperial-gold);
}

.content {
    padding-top: 1.1rem;
}

.valid.modified:not([type=checkbox]) {
    outline: 1px solid var(--imperial-gold);
}

.invalid {
    outline: 1px solid #d9534f;
}

.validation-message {
    color: #d9534f;
}

.not-found {
    text-align: center;
    margin-top: 3rem;
}

.not-found h1 {
    font-size: 3rem;
    margin-bottom: 1rem;
}

#blazor-error-ui {
    background: var(--imperial-panel);
    bottom: 0;
    box-shadow: 0 -1px 2px rgba(197, 160, 89, 0.3);
    display: none;
    left: 0;
    padding: 0.6rem 1.25rem 0.7rem 1.25rem;
    position: fixed;
    width: 100%;
    z-index: 1000;
    border-top: 2px solid var(--imperial-gold);
}

#blazor-error-ui .dismiss {
    cursor: pointer;
    position: absolute;
    right: 0.75rem;
    top: 0.5rem;
    color: var(--imperial-gold);
}

.blazor-error-boundary {
    background: var(--imperial-panel);
    padding: 1rem 1rem 1rem 3.7rem;
    color: var(--imperial-text);
    border-left: 4px solid var(--imperial-gold);
}

.blazor-error-boundary::after {
    content: "An error has occurred.";
}

.loading-progress {
    position: relative;
    display: block;
    width: 8rem;
    height: 8rem;
    margin: 20vh auto 1rem auto;
}

.loading-progress circle {
    fill: none;
    stroke: var(--imperial-text);
    stroke-width: 0.6rem;
    transform-origin: 50% 50%;
    transform: rotate(-90deg);
}

.loading-progress circle:last-child {
    stroke: var(--imperial-gold);
    stroke-dasharray: calc(3.141 * var(--blazor-load-percentage, 0%) * 0.8), 500%;
    transition: stroke-dasharray 0.05s ease-in-out;
}

.loading-progress-text {
    position: absolute;
    text-align: center;
    font-weight: bold;
    inset: calc(20vh + 3.25rem) 0 auto 0.2rem;
    color: var(--imperial-gold);
}

.loading-progress-text:after {
    content: var(--blazor-load-percentage-text, "Loading");
}

code {
    color: var(--imperial-gold);
}
```

### MainLayout.razor.css (EchoesOfImperial.Client/Layout)

```css
.page {
    position: relative;
    display: flex;
    flex-direction: column;
}

main {
    flex: 1;
    background-color: var(--imperial-bg);
}

.sidebar {
    background: linear-gradient(180deg, var(--imperial-panel) 0%, rgba(10, 12, 15, 0.98) 100%);
    border-right: 1px solid rgba(197, 160, 89, 0.2);
}

.top-row {
    background-color: var(--imperial-panel);
    border-bottom: 1px solid rgba(197, 160, 89, 0.2);
    justify-content: flex-end;
    height: 3.5rem;
    display: flex;
    align-items: center;
}

    .top-row ::deep a, .top-row ::deep .btn-link {
        white-space: nowrap;
        margin-left: 1.5rem;
        text-decoration: none;
        color: var(--imperial-gold);
    }

    .top-row ::deep a:hover, .top-row ::deep .btn-link:hover {
        opacity: 0.8;
    }

    .top-row ::deep a:first-child {
        overflow: hidden;
        text-overflow: ellipsis;
    }

@media (max-width: 640.98px) {
    .top-row {
        justify-content: space-between;
    }

    .top-row ::deep a, .top-row ::deep .btn-link {
        margin-left: 0;
    }
}

@media (min-width: 641px) {
    .page {
        flex-direction: row;
    }

    .sidebar {
        width: 250px;
        height: 100vh;
        position: sticky;
        top: 0;
    }

    .top-row {
        position: sticky;
        top: 0;
        z-index: 1;
    }

    .top-row.auth ::deep a:first-child {
        flex: 1;
        text-align: right;
        width: 0;
    }

    .top-row, article {
        padding-left: 2rem !important;
        padding-right: 1.5rem !important;
    }
}
```

### NavMenu.razor.css (EchoesOfImperial.Client/Layout)

```css
.navbar-toggler {
    background-color: rgba(197, 160, 89, 0.2);
    border-color: var(--imperial-gold);
}

.top-row {
    height: 3.5rem;
    background-color: var(--imperial-panel);
}

.navbar-brand {
    font-size: 1.1rem;
    color: var(--imperial-gold) !important;
    font-weight: 600;
    letter-spacing: 0.05em;
}

.bi {
    display: inline-block;
    position: relative;
    width: 1.25rem;
    height: 1.25rem;
    margin-right: 0.75rem;
    top: -1px;
    background-size: cover;
}

.bi-house-door-fill-nav-menu {
    background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='16' height='16' fill='%23C5A059' class='bi bi-house-door-fill' viewBox='0 0 16 16'%3E%3Cpath d='M6.5 14.5v-3.505c0-.245.25-.495.5-.495h2c.25 0 .5.25.5.5v3.5a.5.5 0 0 0 .5.5h4a.5.5 0 0 0 .5-.5v-7a.5.5 0 0 0-.146-.354L13 5.793V2.5a.5.5 0 0 0-.5-.5h-1a.5.5 0 0 0-.5.5v1.293L8.354 1.146a.5.5 0 0 0-.708 0l-6 6A.5.5 0 0 0 1.5 7.5v7a.5.5 0 0 0 .5.5h4a.5.5 0 0 0 .5-.5Z'/%3E%3C/svg%3E");
}

.bi-plus-square-fill-nav-menu {
    background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='16' height='16' fill='%23C5A059' class='bi bi-plus-square-fill' viewBox='0 0 16 16'%3E%3Cpath d='M2 0a2 2 0 0 0-2 2v12a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V2a2 2 0 0 0-2-2H2zm6.5 4.5v3h3a.5.5 0 0 1 0 1h-3v3a.5.5 0 0 1-1 0v-3h-3a.5.5 0 0 1 0-1h3v-3a.5.5 0 0 1 1 0z'/%3E%3C/svg%3E");
}

.bi-list-nested-nav-menu {
    background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='16' height='16' fill='%23C5A059' class='bi bi-list-nested' viewBox='0 0 16 16'%3E%3Cpath fill-rule='evenodd' d='M4.5 11.5A.5.5 0 0 1 5 11h10a.5.5 0 0 1 0 1H5a.5.5 0 0 1-.5-.5zm-2-4A.5.5 0 0 1 3 7h10a.5.5 0 0 1 0 1H3a.5.5 0 0 1-.5-.5zm-2-4A.5.5 0 0 1 1 3h10a.5.5 0 0 1 0 1H1a.5.5 0 0 1-.5-.5z'/%3E%3C/svg%3E");
}

.nav-item {
    font-size: 0.9rem;
    padding-bottom: 0.5rem;
}

    .nav-item:first-of-type {
        padding-top: 1rem;
    }

    .nav-item:last-of-type {
        padding-bottom: 1rem;
    }

    .nav-item ::deep a {
        color: var(--imperial-text);
        border-radius: 4px;
        height: 3rem;
        display: flex;
        align-items: center;
        line-height: 3rem;
        transition: background-color 0.2s;
    }

.nav-item ::deep a.active {
    background-color: rgba(197, 160, 89, 0.2);
    color: var(--imperial-gold);
}

.nav-item ::deep a:hover {
    background-color: rgba(197, 160, 89, 0.1);
    color: var(--imperial-gold);
}

@media (min-width: 641px) {
    .navbar-toggler {
        display: none;
    }

    .collapse {
        /* Never collapse the sidebar for wide screens */
        display: block;
    }
    
    .nav-scrollable {
        /* Allow sidebar to scroll for tall menus */
        height: calc(100vh - 3.5rem);
        overflow-y: auto;
    }
}
```

## Step 4: Build and Run

```bash
# Build the solution
dotnet build EchoesBackend.sln

# Run the API (in one terminal)
dotnet run --project Echoes.API.csproj

# Run the Client (in another terminal)
dotnet run --project EchoesOfImperial.Client/EchoesOfImperial.Client.csproj
```

## Project Structure

```
EchoesBackend_v1/
├── Echoes.API.csproj                           # API Project
├── EchoesBackend.sln                           # Solution File
├── EchoesOfImperial.Shared/                    # Shared Class Library
│   ├── EchoesOfImperial.Shared.csproj
│   └── DTOs/
│       └── WeatherForecast.cs
└── EchoesOfImperial.Client/                    # Blazor WebAssembly Client
    ├── EchoesOfImperial.Client.csproj
    ├── Program.cs
    ├── App.razor
    ├── _Imports.razor
    ├── Pages/
    │   ├── Home.razor
    │   └── Dashboard.razor
    ├── Layout/
    │   ├── MainLayout.razor
    │   ├── MainLayout.razor.css
    │   ├── NavMenu.razor
    │   └── NavMenu.razor.css
    └── wwwroot/
        ├── index.html
        ├── favicon.png
        └── css/
            └── app.css
```

## Imperial Void Theme Variables

The theme uses the following CSS variables:
- `--imperial-bg: #050505` - Deep black background
- `--imperial-panel: rgba(15, 18, 22, 0.95)` - Semi-transparent dark panels
- `--imperial-gold: #C5A059` - Imperial gold accent color
- `--imperial-text: #E0E0E0` - Light gray text
- `--font-main: 'Rajdhani', sans-serif` - Main font family

## Notes

1. The API runs on `https://localhost:5115` by default
2. The Client is configured to point to this URL in `Program.cs`
3. Update the `BaseAddress` if your API runs on a different port
4. The theme uses Google Fonts (Rajdhani) which requires internet connection
5. All template garbage files have been removed for a clean start
