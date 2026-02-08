using System.Security.Claims;
using System.Text;
using System.Text.Json;
using Blazored.LocalStorage;
using Microsoft.AspNetCore.Components.Authorization;

namespace EchoesOfImperial.Client.Services;

public class ApiAuthenticationStateProvider : AuthenticationStateProvider
{
    private readonly ILocalStorageService _localStorage;
    private const string TOKEN_KEY = "authToken";

    public ApiAuthenticationStateProvider(ILocalStorageService localStorage)
    {
        _localStorage = localStorage;
    }

    public override async Task<AuthenticationState> GetAuthenticationStateAsync()
    {
        try
        {
            var token = await _localStorage.GetItemAsync<string>(TOKEN_KEY);
            if (string.IsNullOrEmpty(token))
            {
                return new AuthenticationState(new ClaimsPrincipal(new ClaimsIdentity()));
            }

            var claims = ParseClaimsFromJwt(token);
            var identity = new ClaimsIdentity(claims, "jwt");
            var user = new ClaimsPrincipal(identity);
            return new AuthenticationState(user);
        }
        catch
        {
            return new AuthenticationState(new ClaimsPrincipal(new ClaimsIdentity()));
        }
    }

    public void NotifyUserAuthentication()
    {
        NotifyAuthenticationStateChanged(GetAuthenticationStateAsync());
    }

    public void NotifyUserLogout()
    {
        var anon = Task.FromResult(new AuthenticationState(new ClaimsPrincipal(new ClaimsIdentity())));
        NotifyAuthenticationStateChanged(anon);
    }

    private static IEnumerable<Claim> ParseClaimsFromJwt(string jwt)
    {
        var claims = new List<Claim>();

        var payload = jwt.Split('.').Length > 1 ? jwt.Split('.')[1] : string.Empty;
        if (string.IsNullOrEmpty(payload)) return claims;

        string jsonString;
        try
        {
            jsonString = Base64UrlDecode(payload);
        }
        catch
        {
            return claims;
        }

        using var doc = JsonDocument.Parse(jsonString);
        foreach (var prop in doc.RootElement.EnumerateObject())
        {
            var name = prop.Name;
            var value = prop.Value;

            if (name.Equals("role", StringComparison.OrdinalIgnoreCase) ||
                name.Equals("roles", StringComparison.OrdinalIgnoreCase) ||
                name.Equals("http://schemas.microsoft.com/ws/2008/06/identity/claims/role", StringComparison.OrdinalIgnoreCase))
            {
                // role can be string or array
                if (value.ValueKind == JsonValueKind.Array)
                {
                    foreach (var v in value.EnumerateArray())
                    {
                        claims.Add(new Claim(ClaimTypes.Role, v.GetString() ?? string.Empty));
                    }
                }
                else
                {
                    claims.Add(new Claim(ClaimTypes.Role, value.GetString() ?? string.Empty));
                }
            }
            else if (name.Equals("sub", StringComparison.OrdinalIgnoreCase))
            {
                var sub = value.GetString();
                if (!string.IsNullOrEmpty(sub)) claims.Add(new Claim(ClaimTypes.NameIdentifier, sub));
            }
            else if (name.Equals("email", StringComparison.OrdinalIgnoreCase) || name.Equals("unique_name", StringComparison.OrdinalIgnoreCase))
            {
                var s = value.GetString();
                if (!string.IsNullOrEmpty(s)) claims.Add(new Claim(ClaimTypes.Name, s));
            }
            else
            {
                // Add other claims as simple string
                if (value.ValueKind == JsonValueKind.String)
                {
                    claims.Add(new Claim(name, value.GetString() ?? string.Empty));
                }
            }
        }

        return claims;
    }

    private static string Base64UrlDecode(string input)
    {
        input = input.Replace('-', '+').Replace('_', '/');
        switch (input.Length % 4)
        {
            case 2: input += "=="; break;
            case 3: input += "="; break;
        }
        var bytes = Convert.FromBase64String(input);
        return Encoding.UTF8.GetString(bytes);
    }
}
