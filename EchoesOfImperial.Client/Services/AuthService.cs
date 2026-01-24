using System.Net.Http.Json;
using System.Text.Json;
using EchoesOfImperial.Shared.DTOs;
using Microsoft.AspNetCore.Components;
using Blazored.LocalStorage;

namespace EchoesOfImperial.Client.Services;

public class AuthService
{
    private readonly HttpClient _httpClient;
    private readonly ILocalStorageService _localStorage;
    private readonly NavigationManager _navigationManager;

    private const string TOKEN_KEY = "authToken";
    private const string USER_KEY = "currentUser";

    public event Action? OnAuthStateChanged;

    public AuthService(HttpClient httpClient, ILocalStorageService localStorage, NavigationManager navigationManager)
    {
        _httpClient = httpClient;
        _localStorage = localStorage;
        _navigationManager = navigationManager;
    }

    public async Task<(bool Success, string? Error)> RegisterAsync(RegisterRequestDto request)
    {
        try
        {
            var response = await _httpClient.PostAsJsonAsync("api/auth/register", request);
            
            if (response.IsSuccessStatusCode)
            {
                var result = await response.Content.ReadFromJsonAsync<AuthResponseDto>();
                if (result != null && result.Success)
                {
                    await SetAuthDataAsync(result);
                    return (true, null);
                }
            }
            
            var errorContent = await response.Content.ReadAsStringAsync();
            return (false, ParseError(errorContent));
        }
        catch (HttpRequestException ex)
        {
            return (false, $"Network error: {ex.Message}");
        }
        catch (Exception ex)
        {
            return (false, $"Unexpected error: {ex.Message}");
        }
    }

    public async Task<(bool Success, string? Error)> LoginAsync(LoginRequestDto request)
    {
        try
        {
            var response = await _httpClient.PostAsJsonAsync("api/auth/login", request);
            
            if (response.IsSuccessStatusCode)
            {
                var result = await response.Content.ReadFromJsonAsync<AuthResponseDto>();
                if (result != null && result.Success)
                {
                    await SetAuthDataAsync(result);
                    return (true, null);
                }
            }
            
            var errorContent = await response.Content.ReadAsStringAsync();
            return (false, ParseError(errorContent));
        }
        catch (HttpRequestException ex)
        {
            return (false, $"Network error: {ex.Message}");
        }
        catch (Exception ex)
        {
            return (false, $"Unexpected error: {ex.Message}");
        }
    }

    public async Task LogoutAsync()
    {
        try
        {
            var token = await GetTokenAsync();
            if (!string.IsNullOrEmpty(token))
            {
                _httpClient.DefaultRequestHeaders.Authorization = 
                    new System.Net.Http.Headers.AuthenticationHeaderValue("Bearer", token);
                await _httpClient.PostAsync("api/auth/logout", null);
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Logout error: {ex.Message}");
        }
        finally
        {
            await ClearAuthDataAsync();
            _navigationManager.NavigateTo("/login");
        }
    }

    public async Task<bool> IsAuthenticatedAsync()
    {
        var token = await GetTokenAsync();
        if (string.IsNullOrEmpty(token))
            return false;

        var user = await GetCurrentUserAsync();
        if (user == null)
            return false;

        // Check if token is expired
        if (user.ExpiresAt <= DateTime.UtcNow)
        {
            await ClearAuthDataAsync();
            return false;
        }

        return true;
    }

    public async Task<string?> GetTokenAsync()
    {
        return await _localStorage.GetItemAsync<string>(TOKEN_KEY);
    }

    public async Task<AuthResponseDto?> GetCurrentUserAsync()
    {
        return await _localStorage.GetItemAsync<AuthResponseDto>(USER_KEY);
    }

    private async Task SetAuthDataAsync(AuthResponseDto authData)
    {
        await _localStorage.SetItemAsync(TOKEN_KEY, authData.Token);
        await _localStorage.SetItemAsync(USER_KEY, authData);
        _httpClient.DefaultRequestHeaders.Authorization = 
            new System.Net.Http.Headers.AuthenticationHeaderValue("Bearer", authData.Token);
        OnAuthStateChanged?.Invoke();
    }

    private async Task ClearAuthDataAsync()
    {
        await _localStorage.RemoveItemAsync(TOKEN_KEY);
        await _localStorage.RemoveItemAsync(USER_KEY);
        _httpClient.DefaultRequestHeaders.Authorization = null;
        OnAuthStateChanged?.Invoke();
    }

    private string ParseError(string errorContent)
    {
        try
        {
            var errorObj = JsonSerializer.Deserialize<ErrorResponseDto>(errorContent);
            if (errorObj != null && !string.IsNullOrEmpty(errorObj.Error))
            {
                return errorObj.Error;
            }
        }
        catch (JsonException ex)
        {
            Console.WriteLine($"Error parsing error response: {ex.Message}");
        }
        return "An error occurred. Please try again.";
    }
}

