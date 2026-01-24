using Microsoft.AspNetCore.Components.Web;
using Microsoft.AspNetCore.Components.WebAssembly.Hosting;
using EchoesOfImperial.Client;
using EchoesOfImperial.Client.Services;
using Blazored.LocalStorage;

var builder = WebAssemblyHostBuilder.CreateDefault(args);
builder.RootComponents.Add<App>("#app");
builder.RootComponents.Add<HeadOutlet>("head::after");

// Configure HttpClient to point to the API
builder.Services.AddScoped(sp => new HttpClient 
{ 
    BaseAddress = new Uri("https://localhost:5115") 
});

// Add Blazored LocalStorage
builder.Services.AddBlazoredLocalStorage();

// Add AuthService
builder.Services.AddScoped<AuthService>();

await builder.Build().RunAsync();
