using Microsoft.AspNetCore.Components.Web;
using Microsoft.AspNetCore.Components.WebAssembly.Hosting;
using EchoesOfImperial.Client;
using EchoesOfImperial.Client.Services;
using Blazored.LocalStorage;

var builder = WebAssemblyHostBuilder.CreateDefault(args);
builder.RootComponents.Add<App>("#app");
builder.RootComponents.Add<HeadOutlet>("head::after");

// Add Blazored LocalStorage (must be before HttpClient configuration)
builder.Services.AddBlazoredLocalStorage();

// Add custom authorization message handler
builder.Services.AddScoped<AuthorizationMessageHandler>();

// Configure HttpClient with authorization handler
builder.Services.AddScoped(sp =>
{
    var handler = sp.GetRequiredService<AuthorizationMessageHandler>();
    handler.InnerHandler = new HttpClientHandler();
    
    var httpClient = new HttpClient(handler)
    {
        BaseAddress = new Uri("https://localhost:5115")
    };
    
    return httpClient;
});

// Add AuthService
builder.Services.AddScoped<AuthService>();

await builder.Build().RunAsync();
