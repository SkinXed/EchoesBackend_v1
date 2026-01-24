namespace EchoesOfImperial.Shared.DTOs;

public class WeatherForecast
{
    public DateOnly Date { get; set; }
    public int TemperatureC { get; set; }
    public string? Summary { get; set; }
    public int TemperatureF => (TemperatureC * 9 / 5) + 32;
}
