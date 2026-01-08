using Echoes.API.Data;
using Echoes.API.Models.Config;
using Echoes.API.Models.Entities.Universe;
using Echoes.API.Models.Enums;
using Echoes.API.Services.UniverseGeneration;
using Echoes.Server.Models.Entities.Universe;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Options;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;
using static Echoes.API.Models.Entities.Universe.UniverseGenerationConfig;
using AnomalyConfig = Echoes.API.Models.Config.AnomalyConfig;
using WormholeConfig = Echoes.API.Models.Config.WormholeConfig;

namespace Echoes.API.Services.UniverseGeneration
{
    public interface IUniverseGenerator
    {
        Task GenerateUniverseAsync();
        Task GenerateTestUniverseAsync();
        Task GenerateUniverseFromConfigAsync(UniverseConfig config);
        Task<UniverseStats> GetUniverseStatsAsync();
        Task ClearUniverseAsync();
        Task<string> ExportUniverseConfigAsync();

        // Новые методы для генерации аномалий и вормхолов
        Task<int> GenerateAnomaliesAsync(UniverseConfig config);
        Task<int> GenerateWormholesAsync(UniverseConfig config);

        // Generation Config Management
        Task<List<UniverseGenerationConfig>> GetSavedConfigsAsync();
        Task<UniverseGenerationConfig?> GetConfigByIdAsync(Guid configId);
        Task<UniverseGenerationConfig> SaveConfigAsync(UniverseConfig config, string? name = null, string? description = null);
        Task<bool> DeleteConfigAsync(Guid configId);
        Task<bool> ActivateConfigAsync(Guid configId);
        Task<UniverseGenerationConfig?> GetActiveConfigAsync();
        Task<UniverseConfig> LoadConfigFromJsonAsync(string configJson);
    }

    public class UniverseGenerator : IUniverseGenerator
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<UniverseGenerator> _logger;
        private readonly UniverseConfig _defaultConfig;
        private readonly Dictionary<int, FactionConfig> _factions = new();
        private readonly Random _random = new();
        private const long AU_TO_METERS = 149_597_870_700;
        private const long LIGHTYEAR_TO_METERS = 9_460_730_472_580_800;

        public UniverseGenerator(
           DatabaseContext context,
           ILogger<UniverseGenerator> logger,
           IOptions<UniverseConfig> config)
        {
            _context = context;
            _logger = logger;
            _defaultConfig = config.Value;

            // Загружаем фракции в словарь для быстрого доступа
            if (_defaultConfig.FactionsConfig?.Factions != null)
            {
                foreach (var faction in _defaultConfig.FactionsConfig.Factions)
                {
                    _factions[faction.Id] = faction;
                }
            }
        }

        public async Task GenerateUniverseFromConfigAsync(UniverseConfig config)
        {
            _logger.LogInformation("🚀 Генерация вселенной...");

            // ВЫВОДИМ ВСЕ ПАРАМЕТРЫ
            _logger.LogInformation($"🔧 WormholeConfig загружен: {config.WormholeConfig != null}");
            _logger.LogInformation($"🔧 EnableWormholes: {config.WormholeConfig?.EnableWormholes}");
            _logger.LogInformation($"🔧 ChancePerSystem: {config.WormholeConfig?.ChancePerSystem}");

            // ВЫВОДИМ КОНФИГ ДЛЯ ПРОВЕРКИ
            var wormholeConfigJson = JsonSerializer.Serialize(config.WormholeConfig);
            _logger.LogInformation($"🔧 WormholeConfig JSON: {wormholeConfigJson}");

            var stopwatch = System.Diagnostics.Stopwatch.StartNew();

            try
            {
                // Очищаем старые данные
                _logger.LogInformation("🧹 Очистка вселенной...");
                await ClearUniverseAsync();

                // Генерация по конфигурации
                var stats = new UniverseGenerationStats();

                _logger.LogInformation("📁 Генерация регионов...");
                stats.RegionsGenerated = await GenerateRegionsAsync(config);

                _logger.LogInformation("📊 Генерация констелляций...");
                stats.ConstellationsGenerated = await GenerateConstellationsAsync(config);

                _logger.LogInformation("🌟 Генерация систем...");
                stats.SystemsGenerated = await GenerateSolarSystemsAsync(config);

                _logger.LogInformation("🪐 Генерация планет...");
                stats.PlanetsGenerated = await GeneratePlanetsAsync(config);

                _logger.LogInformation("🌙 Генерация лун...");
                stats.MoonsGenerated = await GenerateMoonsAsync(config);

                if (config.StationConfig.EnableStations)
                {
                    _logger.LogInformation("🏢 Генерация станций...");
                    stats.StationsGenerated = await GenerateStationsAsync(config);
                }

                if (config.StargateConfig.EnableStargates)
                {
                    _logger.LogInformation("🌀 Генерация врат...");
                    stats.StargatesGenerated = await GenerateStargatesAsync(config);
                }

                if (config.ResourcesConfig.EnableResources)
                {
                    _logger.LogInformation("💎 Генерация астероидов...");
                    stats.AsteroidBeltsGenerated = await GenerateAsteroidBeltsAsync(config);
                }

                // ПРОБЛЕМНАЯ ЗОНА: Генерация аномалий и вормхолов
                if (config.AnomalyConfig?.EnableAnomalies ?? false)
                {
                    _logger.LogInformation("🌀 НАЧАЛО ГЕНЕРАЦИИ АНОМАЛИЙ...");
                    try
                    {
                        stats.AnomaliesGenerated = await GenerateAnomaliesAsync(config);
                        _logger.LogInformation($"🌀 Аномалий создано: {stats.AnomaliesGenerated}");
                    }
                    catch (Exception ex)
                    {
                        _logger.LogError(ex, "❌ ОШИБКА В ГЕНЕРАЦИИ АНОМАЛИЙ, ПРОПУСКАЕМ...");
                        // Продолжаем даже с ошибкой аномалий
                        stats.AnomaliesGenerated = 0;
                    }
                }
                else
                {
                    _logger.LogInformation("🌀 Аномалии отключены в конфиге");
                }

                // ГЛАВНАЯ ПРОВЕРКА: ВОРМХОЛЫ
                if (config.WormholeConfig?.EnableWormholes ?? false)
                {
                    _logger.LogInformation("🌌 НАЧАЛО ГЕНЕРАЦИИ ЧЕРВОТОЧИН...");
                    try
                    {
                        stats.WormholesGenerated = await GenerateWormholesAsync(config);
                        _logger.LogInformation($"🌌 Червоточин создано: {stats.WormholesGenerated}");
                    }
                    catch (Exception ex)
                    {
                        _logger.LogError(ex, "❌ ОШИБКА В ГЕНЕРАЦИИ ЧЕРВОТОЧИН");
                        // Все равно бросаем исключение - это критично
                        throw;
                    }
                }
                else
                {
                    _logger.LogInformation("🌌 Червоточины отключены в конфиге");
                }

                stopwatch.Stop();

                // Сохраняем конфигурацию в БД
                await SaveGenerationConfig(config, stats, stopwatch.Elapsed);

                // Получаем итоговую статистику
                var finalStats = await GetUniverseStatsAsync();

                _logger.LogInformation($"✅ Вселенная сгенерирована за {stopwatch.Elapsed.TotalSeconds:F2} секунд");
                _logger.LogInformation($"📊 Сгенерировано: {stats}");
                _logger.LogInformation($"📈 Финальная статистика: {finalStats}");

                // СПЕЦИАЛЬНЫЙ ВЫВОД ДЛЯ ВОРМХОЛОВ
                _logger.LogInformation($"🕳️ ВОРМХОЛОВ В БАЗЕ: {finalStats.Wormholes}");
                _logger.LogInformation($"🕳️ ВОРМХОЛОВ СОЗДАНО В СТАТИСТИКЕ: {stats.WormholesGenerated}");
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "❌ Ошибка генерации вселенной");
                throw;
            }
        }

        public async Task ClearUniverseAsync()
        {
            _logger.LogInformation("🧹 Полная очистка вселенной...");

            try
            {
                // Порядок важен из-за внешних ключей!
                await _context.Anomalies.ExecuteDeleteAsync();
                await _context.Wormholes.ExecuteDeleteAsync();
                await _context.PlanetResources.ExecuteDeleteAsync();
                await _context.AsteroidBelts.ExecuteDeleteAsync();
                await _context.Moons.ExecuteDeleteAsync();
                await _context.Planets.ExecuteDeleteAsync();
                await _context.Stargates.ExecuteDeleteAsync();
                await _context.Stations.ExecuteDeleteAsync();
                await _context.SolarSystems.ExecuteDeleteAsync();
                await _context.Constellations.ExecuteDeleteAsync();
                await _context.Regions.ExecuteDeleteAsync();

                _logger.LogInformation("✅ Вселенная успешно очищена");
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "❌ Ошибка при очистке вселенной");
                throw;
            }
            {
                _logger.LogInformation("🧹 Полная очистка вселенной...");

                try
                {
                    // ОЧИЩАЕМ ВСЁ ПО ПОРЯДКУ
                    await _context.Anomalies.ExecuteDeleteAsync();
                    _logger.LogInformation("🧹 Очищены аномалии");

                    await _context.Wormholes.ExecuteDeleteAsync();
                    _logger.LogInformation("🧹 Очищены червоточины");

                    // ... остальной код очистки
                }
                catch (Exception ex)
                {
                    _logger.LogError(ex, "❌ Ошибка при очистке вселенной");
                    throw;
                }
            }
        }
        #region Генерация аномалий и вормхолов

        public async Task<int> GenerateAnomaliesAsync(UniverseConfig config)
        {
            if (config.AnomalyConfig == null || !config.AnomalyConfig.EnableAnomalies)
                return 0;

            var systems = await _context.SolarSystems
                .Include(s => s.Planets)
                .ToListAsync();

            var allAnomalies = new List<Anomaly>();
            int totalAnomalies = 0;

            _logger.LogInformation("🌀 Создание космических аномалий...");

            var progress = new ProgressTracker(systems.Count, "систем для аномалий", _logger,
                Math.Max(1, systems.Count / 20));

            foreach (var system in systems)
            {
                // Определяем количество аномалий в зависимости от security статуса
                int anomalyCount = GetAnomalyCountBySecurity(system.SecurityStatus, config.AnomalyConfig);

                if (anomalyCount > 0)
                {
                    // Генерируем позиции для аномалий
                    var positions = GenerateAnomalyPositions(system, anomalyCount, config.AnomalyConfig);

                    for (int i = 0; i < positions.Count && i < anomalyCount; i++)
                    {
                        var anomaly = await CreateAnomalyForSystemAsync(system, positions[i], config.AnomalyConfig);
                        allAnomalies.Add(anomaly);
                        totalAnomalies++;
                    }

                    if (config.PerformanceConfig.UseBatchSaving && allAnomalies.Count >= config.PerformanceConfig.BatchSize)
                    {
                        await SaveInBatchesAsync(allAnomalies, config.PerformanceConfig.BatchSize);
                        allAnomalies.Clear();
                    }
                }

                progress.Update(systems.IndexOf(system) + 1);
            }

            // Сохраняем оставшиеся аномалии
            if (allAnomalies.Any())
            {
                if (config.PerformanceConfig.UseBatchSaving)
                    await SaveInBatchesAsync(allAnomalies, config.PerformanceConfig.BatchSize);
                else
                    await _context.Anomalies.AddRangeAsync(allAnomalies);
            }

            await _context.SaveChangesAsync();
            _logger.LogInformation($"✅ Создано аномалий: {totalAnomalies}");

            return totalAnomalies;
        }

        public async Task<int> GenerateWormholesAsync(UniverseConfig config)
        {
            if (config.WormholeConfig == null || !config.WormholeConfig.EnableWormholes)
            {
                _logger.LogInformation("🌌 Генерация червоточин отключена в конфигурации");
                return 0;
            }

            try
            {
                var systems = await _context.SolarSystems.ToListAsync();
                int totalWormholes = 0;
                int pairsCreated = 0;

                _logger.LogInformation($"🌌 Генерация червоточин для {systems.Count} систем (шанс: {config.WormholeConfig.ChancePerSystem:P0})");

                var progress = new ProgressTracker(systems.Count, "систем", _logger, Math.Max(1, systems.Count / 10));

                // Получаем существующие червоточины для проверки дубликатов
                var existingConnections = await GetExistingWormholeConnectionsAsync();

                foreach (var sourceSystem in systems)
                {
                    // Шанс создания червоточины
                    if (_random.NextDouble() > config.WormholeConfig.ChancePerSystem)
                    {
                        progress.Update(systems.IndexOf(sourceSystem) + 1);
                        continue;
                    }

                    // Ищем подходящую целевую систему
                    var targetSystem = FindSuitableTargetSystem(sourceSystem, systems, config.WormholeConfig, existingConnections);
                    if (targetSystem == null)
                    {
                        progress.Update(systems.IndexOf(sourceSystem) + 1);
                        continue;
                    }

                    // Создаем пару
                    var wormholePair = CreateWormholePair(sourceSystem, targetSystem, config.WormholeConfig);

                    // Сохраняем сразу
                    await _context.Wormholes.AddRangeAsync(wormholePair);

                    // Добавляем в список существующих соединений
                    var connectionKey = CreateConnectionKey(sourceSystem.Id, targetSystem.Id);
                    existingConnections.Add(connectionKey);

                    totalWormholes += 2;
                    pairsCreated++;

                    // Сохраняем каждые 100 пар
                    if (pairsCreated % 100 == 0)
                    {
                        await _context.SaveChangesAsync();
                        _logger.LogDebug($"💾 Сохранено {pairsCreated} пар червоточин...");
                    }

                    progress.Update(systems.IndexOf(sourceSystem) + 1);
                }

                // Финальное сохранение
                await _context.SaveChangesAsync();

                _logger.LogInformation($"✅ Создано {pairsCreated} пар червоточин ({totalWormholes} всего)");
                return totalWormholes;
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "❌ Ошибка генерации червоточин");
                throw;
            }
        }

        private List<Wormhole> CreateWormholePair(SolarSystem sourceSystem, SolarSystem targetSystem, WormholeConfig config)
        {
            var wormholes = new List<Wormhole>();

            // Определяем класс червоточины
            var wormholeClassStr = DetermineWormholeClass(config);
            if (!Enum.TryParse<WormholeClass>(wormholeClassStr, out var wormholeClass))
                wormholeClass = WormholeClass.C1; // Значение по умолчанию

            var baseSignature = GenerateWormholeSignature();

            // Получаем параметры для класса
            var maxMass = GetWormholeMass(wormholeClassStr, config);
            var maxShipSize = GetWormholeMaxShipSize(wormholeClassStr, config);
            var lifetimeHours = GetWormholeLifetime(wormholeClassStr, config);

            // Позиции
            var sourcePos = GenerateWormholePosition(sourceSystem);
            var targetPos = GenerateWormholePosition(targetSystem);

            // Входная червоточина
            var sourceWormhole = new Wormhole
            {
                Id = Guid.NewGuid(),
                SourceSystemId = sourceSystem.Id,
                TargetSystemId = targetSystem.Id,
                Name = GetWormholeName(wormholeClassStr, config),
                Class = wormholeClass,
                MaxMass = maxMass,
                RemainingMass = maxMass,
                MaxShipSize = Enum.TryParse<WormholeShipSize>(maxShipSize, out var parsedShipSize) ? parsedShipSize : WormholeShipSize.Medium,
                ExpiresAt = DateTime.UtcNow.AddHours(lifetimeHours),
                PositionX = sourcePos.X,
                PositionY = sourcePos.Y,
                PositionZ = sourcePos.Z,
                Radius = 5000.0,
                Stability = 1.0,
                Signature = $"{baseSignature}-A",
                IsExitOnly = false,
                CreatedAt = DateTime.UtcNow,
                UpdatedAt = DateTime.UtcNow
            };

            // Выходная червоточина (K162)
            var targetWormhole = new Wormhole
            {
                Id = Guid.NewGuid(),
                SourceSystemId = targetSystem.Id,
                TargetSystemId = sourceSystem.Id,
                Name = "K162",
                Class = WormholeClass.K162,
                MaxMass = GetWormholeMass("K162", config),
                RemainingMass = GetWormholeMass("K162", config),
                MaxShipSize = WormholeShipSize.Capital,
                ExpiresAt = DateTime.UtcNow.AddHours(GetWormholeLifetime("K162", config)),
                PositionX = targetPos.X,
                PositionY = targetPos.Y,
                PositionZ = targetPos.Z,
                Radius = 5000.0,
                Stability = 1.0,
                Signature = $"{baseSignature}-B",
                IsExitOnly = true,
                CreatedAt = DateTime.UtcNow,
                UpdatedAt = DateTime.UtcNow
            };

            // Связываем
            sourceWormhole.PairedWormholeId = targetWormhole.Id;
            targetWormhole.PairedWormholeId = sourceWormhole.Id;

            wormholes.Add(sourceWormhole);
            wormholes.Add(targetWormhole);

            return wormholes;
        }

        #endregion

        #region Вспомогательные методы для аномалий и вормхолов

        private async Task<HashSet<string>> GetExistingWormholeConnectionsAsync()
        {
            var existingConnections = new HashSet<string>();

            var existingWormholes = await _context.Wormholes
                .Where(w => w.SourceSystemId != Guid.Empty && w.TargetSystemId != Guid.Empty)
                .Select(w => new { w.SourceSystemId, w.TargetSystemId })
                .ToListAsync();

            foreach (var wh in existingWormholes)
            {
                var key = CreateConnectionKey(wh.SourceSystemId, wh.TargetSystemId);
                existingConnections.Add(key);
            }

            return existingConnections;
        }

        private string CreateConnectionKey(Guid system1Id, Guid system2Id)
        {
            // Создаем уникальный ключ для пары (упорядоченный)
            var ids = new[] { system1Id, system2Id }.OrderBy(id => id).ToArray();
            return $"{ids[0]}-{ids[1]}";
        }

        private SolarSystem? FindSuitableTargetSystem(
            SolarSystem sourceSystem,
            List<SolarSystem> allSystems,
            WormholeConfig config,
            HashSet<string> existingConnections)
        {
            try
            {
                var minDistance = config.MinDistanceLightYears * LIGHTYEAR_TO_METERS;
                var maxDistance = config.MaxDistanceLightYears * LIGHTYEAR_TO_METERS;

                // Ищем подходящие системы
                var suitableSystems = allSystems
                    .Where(s => s.Id != sourceSystem.Id)
                    .Where(s =>
                    {
                        var distance = CalculateDistance(
                            sourceSystem.PositionX, sourceSystem.PositionY, sourceSystem.PositionZ,
                            s.PositionX, s.PositionY, s.PositionZ);

                        return distance >= minDistance && distance <= maxDistance;
                    })
                    .Where(s =>
                    {
                        var connectionKey = CreateConnectionKey(sourceSystem.Id, s.Id);
                        return !existingConnections.Contains(connectionKey);
                    })
                    .ToList();

                if (!suitableSystems.Any())
                {
                    return null;
                }

                // Выбираем случайную систему из подходящих
                return suitableSystems[_random.Next(suitableSystems.Count)];
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка поиска целевой системы");
                return null;
            }
        }

        private int GetAnomalyCountBySecurity(float securityStatus, AnomalyConfig config)
        {
            // Больше аномалий в опасных системах
            if (securityStatus < 0) // Null sec
                return _random.Next(config.MinPerSystem + 2, config.MaxPerSystem + 1);
            else if (securityStatus < 0.3f) // Low sec
                return _random.Next(config.MinPerSystem + 1, config.MaxPerSystem);
            else if (securityStatus < 0.7f) // Mid sec
                return _random.Next(config.MinPerSystem, config.MaxPerSystem - 1);
            else // High sec
                return _random.Next(config.MinPerSystem - 1, Math.Max(config.MinPerSystem, config.MaxPerSystem - 2));
        }

        private List<(long X, long Y, long Z)> GenerateAnomalyPositions(SolarSystem system, int count, AnomalyConfig config)
        {
            var positions = new List<(long X, long Y, long Z)>();
            var attempts = 0;
            const int maxAttempts = 1000;

            while (positions.Count < count && attempts < maxAttempts)
            {
                attempts++;

                // Генерируем случайную позицию в сферической оболочке (20-50 AU от центра)
                var position = GeneratePositionInSphericalShell(
                    minRadiusAU: config.MinDistanceFromCenterAU,
                    maxRadiusAU: config.MaxDistanceFromCenterAU);

                // Сдвигаем позицию относительно центра системы
                var shiftedPosition = (
                    X: system.PositionX + position.X,
                    Y: system.PositionY + position.Y,
                    Z: system.PositionZ + position.Z
                );

                // Проверяем, не слишком ли близко к другим объектам
                if (IsPositionValid(shiftedPosition, positions, system, config))
                {
                    positions.Add(shiftedPosition);
                }
            }

            return positions;
        }

        private (long X, long Y, long Z) GeneratePositionInSphericalShell(double minRadiusAU, double maxRadiusAU)
        {
            // Конвертируем AU в метры
            var minRadiusMeters = minRadiusAU * AU_TO_METERS;
            var maxRadiusMeters = maxRadiusAU * AU_TO_METERS;

            // Генерируем случайную точку на сфере
            var u = _random.NextDouble();
            var v = _random.NextDouble();
            var w = _random.NextDouble();

            var theta = u * 2.0 * Math.PI;
            var phi = Math.Acos(2.0 * v - 1.0);
            var r = Math.Pow(w * (Math.Pow(maxRadiusMeters, 3) - Math.Pow(minRadiusMeters, 3)) +
                Math.Pow(minRadiusMeters, 3), 1.0 / 3.0);

            var x = (long)(r * Math.Sin(phi) * Math.Cos(theta));
            var y = (long)(r * Math.Sin(phi) * Math.Sin(theta));
            var z = (long)(r * Math.Cos(phi));

            return (x, y, z);
        }

        private bool IsPositionValid(
            (long X, long Y, long Z) position,
            List<(long X, long Y, long Z)> existingPositions,
            SolarSystem system,
            AnomalyConfig config)
        {
            // Проверяем расстояние до существующих аномалий
            var minDistanceMeters = config.MinDistanceBetweenAnomaliesAU * AU_TO_METERS;
            var minDistanceSquared = minDistanceMeters * minDistanceMeters;

            foreach (var existingPos in existingPositions)
            {
                var dx = (double)(position.X - existingPos.X);
                var dy = (double)(position.Y - existingPos.Y);
                var dz = (double)(position.Z - existingPos.Z);
                var distanceSquared = dx * dx + dy * dy + dz * dz;

                if (distanceSquared < minDistanceSquared)
                    return false;
            }

            // Проверяем расстояние до планет (если есть)
            foreach (var planet in system.Planets)
            {
                var dx = (double)(position.X - planet.PositionX);
                var dy = (double)(position.Y - planet.PositionY);
                var dz = (double)(position.Z - planet.PositionZ);
                var distance = Math.Sqrt(dx * dx + dy * dy + dz * dz);

                // Аномалия должна быть на расстоянии хотя бы 10 радиусов планеты
                if (distance < planet.Radius * 10)
                    return false;
            }

            return true;
        }

        private async Task<Anomaly> CreateAnomalyForSystemAsync(SolarSystem system, (long X, long Y, long Z) position, AnomalyConfig config)
        {
            // Определяем тип аномалии на основе вероятностей
            var anomalyType = DetermineAnomalyType(config);

            // Определяем сложность на основе security статуса системы
            var difficulty = DetermineAnomalyDifficulty(system.SecurityStatus, config);

            // Генерируем имя аномалии
            var name = GenerateAnomalyName(anomalyType, config);

            // Генерируем сигнатуру
            var signature = GenerateAnomalySignature();

            // Создаем аномалию
            var anomaly = new Anomaly
            {
                Id = Guid.NewGuid(),
                SolarSystemId = system.Id,
                Type = anomalyType,
                Difficulty = difficulty,
                Name = name,
                Description = GenerateAnomalyDescription(anomalyType, difficulty),
                PositionX = position.X,
                PositionY = position.Y,
                PositionZ = position.Z,
                Radius = CalculateAnomalyRadius(difficulty, anomalyType),
                Durability = CalculateAnomalyDurability(difficulty, anomalyType),
                CurrentDurability = 0, // Будет установлено равным Durability после создания
                ScanStrength = CalculateScanStrength(difficulty),
                Signature = signature,
                RewardData = GenerateRewardData(anomalyType, difficulty),
                ExpiresAt = DateTime.UtcNow.AddHours(config.LifetimeHours),
                CreatedAt = DateTime.UtcNow,
                UpdatedAt = DateTime.UtcNow
            };

            // Устанавливаем текущую прочность равной максимальной
            anomaly.CurrentDurability = anomaly.Durability;

            return anomaly;
        }
        // Вспомогательные методы для вормхолов
        private string GetWormholeName(string wormholeClass, WormholeConfig config)
        {
            if (config.NamesByClass != null &&
                config.NamesByClass.TryGetValue(wormholeClass, out var names) &&
                names.Any())
            {
                return names[_random.Next(names.Count)];
            }

            return $"WH-{wormholeClass}";
        }
        // Вспомогательные методы для вормхолов
        private double GetWormholeMass(string wormholeClass, WormholeConfig config)
        {
            return config.MassByClass?.TryGetValue(wormholeClass, out var mass) == true
                ? mass
                : 1000000000; // По умолчанию 1 млрд кг
        }
        // Вспомогательные методы для вормхолов
        private string GetWormholeMaxShipSize(string wormholeClass, WormholeConfig config)
        {
            return config.MaxShipSizeByClass?.TryGetValue(wormholeClass, out var size) == true
                ? size
                : "Medium";
        }

        private int GetWormholeLifetime(string wormholeClass, WormholeConfig config)
        {
            return config.LifetimeHoursByClass?.TryGetValue(wormholeClass, out var hours) == true
                ? hours
                : 24;
        }

        private double CalculateDistance(long x1, long y1, long z1, long x2, long y2, long z2)
        {
            var dx = (double)(x2 - x1);
            var dy = (double)(y2 - y1);
            var dz = (double)(z2 - z1);

            return Math.Sqrt(dx * dx + dy * dy + dz * dz);
        }

        private (long X, long Y, long Z) GenerateWormholePosition(SolarSystem system)
        {
            // Позиция в пределах 5-50 тыс. км от центра
            var radius = _random.Next(5_000_000, 50_000_000);
            var angle = _random.NextDouble() * 2 * Math.PI;

            var x = system.PositionX + (long)(radius * Math.Cos(angle));
            var y = system.PositionY + (long)(radius * Math.Sin(angle));
            var z = system.PositionZ + _random.Next(-10_000_000, 10_000_000);

            return (x, y, z);
        }

        private string DetermineWormholeClass(WormholeConfig config)
        {
            if (config.ClassChances == null || !config.ClassChances.Any())
                return "C1";

            var randomValue = _random.NextDouble();
            var cumulative = 0.0;

            foreach (var kvp in config.ClassChances)
            {
                cumulative += kvp.Value;
                if (randomValue <= cumulative)
                    return kvp.Key;
            }

            return config.ClassChances.First().Key;
        }

        private string GenerateWormholeSignature()
        {
            return $"WH-{Guid.NewGuid():N}".Substring(0, 20).ToUpper();
        }

        #endregion

        #region Методы для определения характеристик аномалий и вормхолов

        private AnomalyType DetermineAnomalyType(AnomalyConfig config)
        {
            var roll = _random.NextDouble();
            double cumulative = 0.0;

            foreach (var kvp in config.TypeChances)
            {
                cumulative += kvp.Value;
                if (roll < cumulative)
                {
                    return Enum.Parse<AnomalyType>(kvp.Key);
                }
            }

            return AnomalyType.Combat; // Fallback
        }

        private AnomalyDifficulty DetermineAnomalyDifficulty(float securityStatus, AnomalyConfig config)
        {
            // Находим ближайший security статус из конфига
            var parsedSecurities = config.DifficultyBySecurity.Keys
        .Select(k => new
        {
            Key = k,
            Value = float.TryParse(k, NumberStyles.Float, CultureInfo.InvariantCulture, out float val) ? val : 0.0f
        })
        .ToList();

            // Находим ближайший security статус из конфига
            var closestSecurityKey = parsedSecurities
                .OrderBy(s => Math.Abs(s.Value - securityStatus))
                .FirstOrDefault()?.Key;

            // Если ничего не нашли, берем первый попавшийся или дефолт
            if (closestSecurityKey == null && config.DifficultyBySecurity.Any())
            {
                closestSecurityKey = config.DifficultyBySecurity.Keys.First();
            }

            if (closestSecurityKey != null && config.DifficultyBySecurity.TryGetValue(closestSecurityKey, out var difficulties))
            {
                var roll = _random.NextDouble();
                double cumulative = 0.0;

                foreach (var kvp in difficulties)
                {
                    cumulative += kvp.Value;
                    if (roll < cumulative)
                    {
                        // Parsing enum safely
                        if (Enum.TryParse<AnomalyDifficulty>(kvp.Key, out var difficulty))
                        {
                            return difficulty;
                        }
                    }
                }
            }

            return AnomalyDifficulty.Medium; // Fallback
        }

        private string GenerateAnomalyName(AnomalyType type, AnomalyConfig config)
        {
            return type switch
            {
                AnomalyType.Combat => $"{config.CombatNamePrefixes[_random.Next(config.CombatNamePrefixes.Count)]} " +
                                      $"{config.CombatNameSuffixes[_random.Next(config.CombatNameSuffixes.Count)]}",

                AnomalyType.Ore => $"Ore Site {GenerateRandomCode(3)}-{_random.Next(100, 1000)}",

                AnomalyType.Data => $"Data Site {GenerateRandomCode(3)}-{_random.Next(100, 1000)}",

                AnomalyType.Relic => $"Relic Site {GenerateRandomCode(3)}-{_random.Next(100, 1000)}",

                AnomalyType.Gas => $"Gas Site {GenerateRandomCode(3)}-{_random.Next(100, 1000)}",

                AnomalyType.Expedition => $"Expedition {_random.Choice("Alpha", "Beta", "Gamma", "Delta")}",

                _ => $"Unknown Site {_random.Next(1000, 9999)}"
            };
        }

        private string GenerateRandomCode(int length)
        {
            const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
            return new string(Enumerable.Repeat(chars, length)
                .Select(s => s[_random.Next(s.Length)]).ToArray());
        }

        private string GenerateAnomalySignature()
        {
            // Используем GUID для гарантированной уникальности
            return $"AN-{Guid.NewGuid():N}".Substring(0, 20).ToUpper();
        }

        

        private string GenerateAnomalyDescription(AnomalyType type, AnomalyDifficulty difficulty)
        {
            return type switch
            {
                AnomalyType.Combat => $"Пиратская база уровня {difficulty}. " +
                                      $"Содержит корабли и защитные сооружения.",

                AnomalyType.Ore => $"Рудный астероидный пояс. " +
                                   $"Содержит {_random.Next(3, 10)} астероидов с ценными рудами.",

                AnomalyType.Data => $"Заброшенный дата-центр. " +
                                    $"Возможность хакерства и сбора данных.",

                AnomalyType.Relic => $"Древние артефакты неизвестной цивилизации. " +
                                     $"Требуется археологическое сканирование.",

                AnomalyType.Gas => $"Газовое облако экзотического состава. " +
                                   $"Возможна добыча редких газов.",

                AnomalyType.Expedition => $"Секретная экспедиция. " +
                                          $"Высокий риск, высокая награда.",

                _ => "Неизвестный объект. Требуется исследование."
            };
        }

        private double CalculateAnomalyRadius(AnomalyDifficulty difficulty, AnomalyType type)
        {
            var baseRadius = difficulty switch
            {
                AnomalyDifficulty.Easy => 1000.0,
                AnomalyDifficulty.Medium => 2000.0,
                AnomalyDifficulty.Hard => 5000.0,
                AnomalyDifficulty.Elite => 10000.0,
                _ => 1000.0
            };

            // Умножаем на коэффициент типа
            var typeMultiplier = type switch
            {
                AnomalyType.Combat => 1.5,
                AnomalyType.Ore => 3.0,
                AnomalyType.Data => 1.0,
                AnomalyType.Relic => 1.0,
                AnomalyType.Gas => 5.0,
                AnomalyType.Expedition => 2.0,
                _ => 1.0
            };

            return baseRadius * typeMultiplier;
        }

        private double CalculateAnomalyDurability(AnomalyDifficulty difficulty, AnomalyType type)
        {
            var baseDurability = difficulty switch
            {
                AnomalyDifficulty.Easy => 10000.0,
                AnomalyDifficulty.Medium => 50000.0,
                AnomalyDifficulty.Hard => 200000.0,
                AnomalyDifficulty.Elite => 1000000.0,
                _ => 10000.0
            };

            // Умножаем на коэффициент типа
            var typeMultiplier = type switch
            {
                AnomalyType.Combat => 2.0,
                AnomalyType.Ore => 0.5,
                AnomalyType.Data => 0.3,
                AnomalyType.Relic => 0.3,
                AnomalyType.Gas => 0.7,
                AnomalyType.Expedition => 3.0,
                _ => 1.0
            };

            return baseDurability * typeMultiplier;
        }

        private int CalculateScanStrength(AnomalyDifficulty difficulty)
        {
            return difficulty switch
            {
                AnomalyDifficulty.Easy => 1,
                AnomalyDifficulty.Medium => 3,
                AnomalyDifficulty.Hard => 6,
                AnomalyDifficulty.Elite => 10,
                _ => 1
            };
        }

        private string GenerateRewardData(AnomalyType type, AnomalyDifficulty difficulty)
        {
            // Простой пример структуры награды
            var reward = new
            {
                Type = type.ToString(),
                Difficulty = difficulty.ToString(),
                Credits = CalculateRewardCredits(difficulty),
                Experience = CalculateExperience(difficulty)
            };

            return JsonSerializer.Serialize(reward);
        }

        private int CalculateRewardCredits(AnomalyDifficulty difficulty)
        {
            return difficulty switch
            {
                AnomalyDifficulty.Easy => _random.Next(1000, 5000),
                AnomalyDifficulty.Medium => _random.Next(5000, 25000),
                AnomalyDifficulty.Hard => _random.Next(25000, 100000),
                AnomalyDifficulty.Elite => _random.Next(100000, 500000),
                _ => 1000
            };
        }

        private int CalculateExperience(AnomalyDifficulty difficulty)
        {
            return difficulty switch
            {
                AnomalyDifficulty.Easy => 100,
                AnomalyDifficulty.Medium => 500,
                AnomalyDifficulty.Hard => 2000,
                AnomalyDifficulty.Elite => 10000,
                _ => 100
            };
        }

        #endregion

        #region Генерация базовой вселенной

        private async Task<int> GenerateRegionsAsync(UniverseConfig config)
        {
            _logger.LogInformation($"📁 Создание {config.RegionCount} регионов...");

            var regions = new List<Region>();
            var usedNames = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            var progress = new ProgressTracker(config.RegionCount, "регионов", _logger,
                Math.Max(1, config.RegionCount / 10));

            var factionRegions = AssignFactionsToRegions(config);

            for (int i = 1; i <= config.RegionCount; i++)
            {
                string regionName;
                int attempts = 0;
                RegionType regionType;
                float regionSecurity;
                int? factionId;

                do
                {
                    regionType = GetRandomRegionType(config.RegionDistribution);
                    regionSecurity = GetSecurityByType(regionType, config.RegionDistribution);
                    factionId = null;

                    if (factionRegions.TryGetValue(i, out var regionFaction))
                    {
                        factionId = regionFaction.Id;
                        regionSecurity += regionFaction.SecurityBonus;
                    }

                    regionName = GenerateRegionName(config.NamingConfig, i, regionType, factionId);
                    attempts++;

                    if (usedNames.Contains(regionName) && attempts < 10)
                    {
                        regionName = $"{regionName}-{attempts}";
                    }

                } while (usedNames.Contains(regionName) && attempts < 20);

                if (usedNames.Contains(regionName))
                {
                    regionName = $"{regionName}-{Guid.NewGuid().ToString().Substring(0, 4)}";
                }

                usedNames.Add(regionName);

                var region = new Region
                {
                    Id = Guid.NewGuid(),
                    Name = regionName,
                    RegionCode = $"RG{i:0000}",
                    Type = regionType,
                    AverageSecurity = regionSecurity,
                    PositionX = _random.NextLong(-config.SizeConfig.RegionSpreadX, config.SizeConfig.RegionSpreadX),
                    PositionY = _random.NextLong(-config.SizeConfig.RegionSpreadY, config.SizeConfig.RegionSpreadY),
                    PositionZ = _random.NextLong(-config.SizeConfig.RegionSpreadZ, config.SizeConfig.RegionSpreadZ),
                    FactionId = factionId,
                    Description = GenerateRegionDescription(regionType, factionId),
                    CreatedAt = DateTime.UtcNow
                };

                regions.Add(region);
                progress.Update(i);
            }

            if (config.PerformanceConfig.UseBatchSaving)
                await SaveInBatchesAsync(regions, config.PerformanceConfig.BatchSize);
            else
                await _context.Regions.AddRangeAsync(regions);

            await _context.SaveChangesAsync();
            progress.Complete();

            return regions.Count;
        }

        private async Task<int> GenerateConstellationsAsync(UniverseConfig config)
        {
            var regions = await _context.Regions.ToListAsync();
            var allConstellations = new List<Constellation>();
            int totalConstellations = 0;

            _logger.LogInformation("📊 Создание констелляций...");

            var progress = new ProgressTracker(regions.Count, "регионов для констелляций", _logger, 1);

            // Добавляем HashSet для отслеживания использованных имен
            var usedNames = new HashSet<string>(StringComparer.OrdinalIgnoreCase);

            foreach (var region in regions)
            {
                int constellationCount = _random.Next(
                    config.MinConstellationsPerRegion,
                    config.MaxConstellationsPerRegion + 1
                );

                for (int i = 0; i < constellationCount; i++)
                {
                    // Генерируем уникальное имя
                    string constellationName;
                    int attempts = 0;

                    do
                    {
                        constellationName = GenerateConstellationName(config.NamingConfig, region.Name, i + 1 + attempts);
                        attempts++;

                        // Если имя уже используется, добавляем суффикс
                        if (usedNames.Contains(constellationName) && attempts < 10)
                        {
                            constellationName = $"{constellationName}-{attempts}";
                        }

                    } while (usedNames.Contains(constellationName) && attempts < 20);

                    // Если все еще не уникально, добавляем GUID
                    if (usedNames.Contains(constellationName))
                    {
                        constellationName = $"{constellationName}-{Guid.NewGuid().ToString().Substring(0, 4)}";
                    }

                    usedNames.Add(constellationName);

                    var constellation = new Constellation
                    {
                        Id = Guid.NewGuid(),
                        Name = constellationName, // Используем уникальное имя
                        RegionId = region.Id,
                        PositionX = region.PositionX + _random.NextLong(-config.SizeConfig.ConstellationSpread, config.SizeConfig.ConstellationSpread),
                        PositionY = region.PositionY + _random.NextLong(-config.SizeConfig.ConstellationSpread, config.SizeConfig.ConstellationSpread),
                        PositionZ = region.PositionZ + _random.NextLong(-config.SizeConfig.ConstellationSpread / 2, config.SizeConfig.ConstellationSpread / 2),
                        AverageSecurity = Math.Clamp(region.AverageSecurity + ((float)_random.NextDouble() * 0.3f - 0.15f), -1.0f, 1.0f),
                        FactionId = region.FactionId,
                        CreatedAt = DateTime.UtcNow
                    };

                    allConstellations.Add(constellation);
                    totalConstellations++;
                }

                progress.Update(regions.IndexOf(region) + 1);

                // Периодическое сохранение для больших вселенной
                if (config.PerformanceConfig.UseBatchSaving && allConstellations.Count >= config.PerformanceConfig.BatchSize)
                {
                    await SaveInBatchesAsync(allConstellations, config.PerformanceConfig.BatchSize);
                    allConstellations.Clear();
                }
            }

            // Сохраняем оставшиеся
            if (allConstellations.Any())
            {
                if (config.PerformanceConfig.UseBatchSaving)
                    await SaveInBatchesAsync(allConstellations, config.PerformanceConfig.BatchSize);
                else
                    await _context.Constellations.AddRangeAsync(allConstellations);
            }

            await _context.SaveChangesAsync();
            _logger.LogInformation($"✅ Создано констелляций: {totalConstellations}");

            return totalConstellations;
        }

        private async Task<int> GenerateSolarSystemsAsync(UniverseConfig config)
        {
            _logger.LogInformation("🌟 Создание солнечных систем (Batch Mode)...");

            int totalSystems = 0;
            int batchSize = 500; // Обрабатываем по 500 констелляций за раз
            int page = 0;
            bool hasMore = true;

            // Используем локальный HashSet для проверки имен в рамках текущей генерации
            var usedNames = new HashSet<string>(StringComparer.OrdinalIgnoreCase);

            // Для прогресс-бара нам нужно знать общее количество
            int totalConstellations = await _context.Constellations.CountAsync();
            var progress = new ProgressTracker(totalConstellations, "констелляций", _logger, Math.Max(1, totalConstellations / 20));

            while (hasMore)
            {
                // 1. Читаем пачку констелляций. AsNoTracking ускоряет чтение.
                var constellations = await _context.Constellations
                    .Include(c => c.Region)
                    .OrderBy(c => c.Id) // Обязательно для детерминированной пагинации
                    .Skip(page * batchSize)
                    .Take(batchSize)
                    .AsNoTracking()
                    .ToListAsync();

                if (constellations.Count == 0)
                {
                    hasMore = false;
                    break;
                }

                var newSystemsBatch = new List<SolarSystem>();

                foreach (var constellation in constellations)
                {
                    int systemCount = _random.Next(
                        config.MinSystemsPerConstellation,
                        config.MaxSystemsPerConstellation + 1
                    );

                    for (int i = 0; i < systemCount; i++)
                    {
                        var security = Math.Clamp(
                            constellation.AverageSecurity + ((float)_random.NextDouble() * 0.2f - 0.1f),
                            -1.0f, 1.0f
                        );

                        // Генерация имени
                        string systemName;
                        int attempts = 0;
                        do
                        {
                            systemName = GenerateSystemName(config.NamingConfig, constellation.Name, i + 1 + attempts);
                            attempts++;
                        } while (usedNames.Contains(systemName) && attempts < 10);

                        if (usedNames.Contains(systemName))
                        {
                            systemName = $"{systemName}-{Guid.NewGuid().ToString().Substring(0, 4)}";
                        }
                        usedNames.Add(systemName);

                        var (starClass, luminosityClass, tempClass) = GenerateStarCharacteristics(config.StarConfig);
                        var (temperature, radius, mass, luminosity) = CalculateStarProperties(starClass, luminosityClass);

                        var system = new SolarSystem
                        {
                            Id = Guid.NewGuid(),
                            Name = systemName,
                            ConstellationId = constellation.Id,
                            SecurityStatus = security,
                            RegionId = constellation.RegionId,
                            PositionX = constellation.PositionX + _random.NextLong(-config.SizeConfig.SystemSpread, config.SizeConfig.SystemSpread),
                            PositionY = constellation.PositionY + _random.NextLong(-config.SizeConfig.SystemSpread, config.SizeConfig.SystemSpread),
                            PositionZ = constellation.PositionZ + _random.NextLong(-config.SizeConfig.SystemSpread / 3, config.SizeConfig.SystemSpread / 3),

                            StarClass = starClass,
                            LuminosityClass = luminosityClass,
                            TemperatureClass = tempClass,
                            Temperature = temperature,
                            SolarRadius = radius,
                            SolarMass = mass,
                            Luminosity = luminosity,
                            NumberOfStars = _random.Chance(0.3f) ? _random.Next(2, 4) : 1,

                            Radius = _random.Next(5_000_000, 50_000_000),
                            FactionId = constellation.FactionId,
                            HasAsteroidBelts = config.ResourcesConfig.EnableResources && _random.Chance(0.8f),
                            HasStations = config.StationConfig.EnableStations,
                            CreatedAt = DateTime.UtcNow,
                            Description = GenerateSystemDescriptionWithStar(security, starClass, luminosityClass)
                        };

                        newSystemsBatch.Add(system);
                        totalSystems++;
                    }

                    progress.Update((page * batchSize) + constellations.IndexOf(constellation) + 1);
                }

                // 2. Сохраняем пачку
                if (newSystemsBatch.Any())
                {
                    await _context.SolarSystems.AddRangeAsync(newSystemsBatch);
                    await _context.SaveChangesAsync();

                    // ВАЖНО: Очищаем трекер, чтобы освободить память от загруженных объектов
                    _context.ChangeTracker.Clear();
                    newSystemsBatch.Clear();
                }

                page++;
            }

            progress.Complete();
            _logger.LogInformation($"✅ Создано солнечных систем: {totalSystems}");

            return totalSystems;
        }

        private (StarClass, StarLuminosityClass, StarTemperature) GenerateStarCharacteristics(StarConfig config)
        {
            if (!config.EnableStarVariety)
            {
                return (StarClass.G, StarLuminosityClass.V, StarTemperature.Moderate);
            }

            // Генерация звездного класса на основе распределения
            StarClass starClass = GetRandomStarClass(config.ClassDistribution);

            // Генерация класса светимости
            StarLuminosityClass luminosityClass = GetRandomLuminosityClass(starClass);

            // Генерация температурного класса на основе звездного класса
            StarTemperature tempClass = GetTemperatureClass(starClass);

            return (starClass, luminosityClass, tempClass);
        }

        private StarClass GetRandomStarClass(StarClassDistribution distribution)
        {
            // Создаем взвешенный список
            var weightedClasses = new List<(StarClass starClass, float weight)>
            {
                (StarClass.O, distribution.ClassO_Percent),
                (StarClass.B, distribution.ClassB_Percent),
                (StarClass.A, distribution.ClassA_Percent),
                (StarClass.F, distribution.ClassF_Percent),
                (StarClass.G, distribution.ClassG_Percent),
                (StarClass.K, distribution.ClassK_Percent),
                (StarClass.M, distribution.ClassM_Percent),
                (StarClass.L, distribution.BrownDwarf_Percent * 0.4f),
                (StarClass.T, distribution.BrownDwarf_Percent * 0.3f),
                (StarClass.Y, distribution.BrownDwarf_Percent * 0.3f),
                (StarClass.WhiteDwarf, distribution.WhiteDwarf_Percent),
                (StarClass.NeutronStar, distribution.NeutronStar_Percent),
                (StarClass.BlackHole, distribution.BlackHole_Percent),
                (StarClass.RedGiant, distribution.Giant_Percent * 0.7f),
                (StarClass.BlueGiant, distribution.Giant_Percent * 0.3f)
            };

            // Выбираем случайный класс на основе весов
            float totalWeight = weightedClasses.Sum(w => w.weight);
            float randomValue = (float)_random.NextDouble() * totalWeight;

            float cumulative = 0;
            foreach (var (starClass, weight) in weightedClasses)
            {
                cumulative += weight;
                if (randomValue <= cumulative)
                {
                    return starClass;
                }
            }

            return StarClass.G; // По умолчанию
        }

        private StarLuminosityClass GetRandomLuminosityClass(StarClass starClass)
        {
            // В зависимости от класса звезды выбираем класс светимости
            return starClass switch
            {
                StarClass.O => _random.Chance(0.8f) ? StarLuminosityClass.Ia :
                              _random.Chance(0.5f) ? StarLuminosityClass.III : StarLuminosityClass.V,
                StarClass.B => _random.Chance(0.6f) ? StarLuminosityClass.III : StarLuminosityClass.V,
                StarClass.A => _random.Chance(0.4f) ? StarLuminosityClass.IV : StarLuminosityClass.V,
                StarClass.F => StarLuminosityClass.V,
                StarClass.G => StarLuminosityClass.V,
                StarClass.K => _random.Chance(0.2f) ? StarLuminosityClass.IV : StarLuminosityClass.V,
                StarClass.M => StarLuminosityClass.V,
                StarClass.L => StarLuminosityClass.VI,
                StarClass.T => StarLuminosityClass.VI,
                StarClass.Y => StarLuminosityClass.VI,
                StarClass.WhiteDwarf => StarLuminosityClass.VII,
                StarClass.NeutronStar => StarLuminosityClass.VII,
                StarClass.BlackHole => StarLuminosityClass.VII,
                StarClass.RedGiant => StarLuminosityClass.III,
                StarClass.BlueGiant => StarLuminosityClass.Ia,
                _ => StarLuminosityClass.V
            };
        }

        private StarTemperature GetTemperatureClass(StarClass starClass)
        {
            return starClass switch
            {
                StarClass.O => StarTemperature.UltraHot,
                StarClass.B => StarTemperature.VeryHot,
                StarClass.A => StarTemperature.Hot,
                StarClass.F => StarTemperature.Warm,
                StarClass.G => StarTemperature.Moderate,
                StarClass.K => StarTemperature.Cool,
                StarClass.M => StarTemperature.Cold,
                StarClass.L => StarTemperature.VeryCold,
                StarClass.T => StarTemperature.VeryCold,
                StarClass.Y => StarTemperature.UltraCold,
                StarClass.WhiteDwarf => StarTemperature.VeryHot,
                StarClass.NeutronStar => StarTemperature.UltraHot,
                StarClass.BlackHole => StarTemperature.UltraHot,
                StarClass.RedGiant => StarTemperature.Cool,
                StarClass.BlueGiant => StarTemperature.UltraHot,
                _ => StarTemperature.Moderate
            };
        }

        private (int temperature, float radius, float mass, float luminosity) CalculateStarProperties(
            StarClass starClass, StarLuminosityClass luminosityClass)
        {
            // Базовые значения для разных классов звезд
            var baseValues = starClass switch
            {
                StarClass.O => (temperature: 30000, radius: 6.6f, mass: 16.0f, luminosity: 30000f),
                StarClass.B => (temperature: 20000, radius: 3.8f, mass: 7.0f, luminosity: 1000f),
                StarClass.A => (temperature: 8500, radius: 1.7f, mass: 2.1f, luminosity: 20f),
                StarClass.F => (temperature: 6500, radius: 1.3f, mass: 1.4f, luminosity: 4f),
                StarClass.G => (temperature: 5778, radius: 1.0f, mass: 1.0f, luminosity: 1f),
                StarClass.K => (temperature: 4500, radius: 0.8f, mass: 0.7f, luminosity: 0.3f),
                StarClass.M => (temperature: 3200, radius: 0.4f, mass: 0.2f, luminosity: 0.01f),
                StarClass.L => (temperature: 2000, radius: 0.15f, mass: 0.08f, luminosity: 0.001f),
                StarClass.T => (temperature: 1200, radius: 0.12f, mass: 0.05f, luminosity: 0.0001f),
                StarClass.Y => (temperature: 500, radius: 0.1f, mass: 0.03f, luminosity: 0.00001f),
                StarClass.WhiteDwarf => (temperature: 10000, radius: 0.01f, mass: 0.6f, luminosity: 0.001f),
                StarClass.NeutronStar => (temperature: 600000, radius: 0.00001f, mass: 1.4f, luminosity: 0.1f),
                StarClass.BlackHole => (temperature: 1000000, radius: 0.000001f, mass: 5.0f, luminosity: 0.0f),
                StarClass.RedGiant => (temperature: 3500, radius: 100.0f, mass: 1.0f, luminosity: 1000f),
                StarClass.BlueGiant => (temperature: 25000, radius: 25.0f, mass: 20.0f, luminosity: 50000f),
                _ => (temperature: 5778, radius: 1.0f, mass: 1.0f, luminosity: 1f)
            };

            // Корректируем в зависимости от класса светимости
            float luminosityMultiplier = luminosityClass switch
            {
                StarLuminosityClass.Ia => 1000f,    // Яркие сверхгиганты
                StarLuminosityClass.Ib => 500f,     // Сверхгиганты
                StarLuminosityClass.II => 100f,     // Яркие гиганты
                StarLuminosityClass.III => 10f,     // Гиганты
                StarLuminosityClass.IV => 2f,       // Субгиганты
                StarLuminosityClass.V => 1f,        // Карлики
                StarLuminosityClass.VI => 0.1f,     // Субкарлики
                StarLuminosityClass.VII => 0.01f,   // Белые карлики
                _ => 1f
            };

            // Добавляем случайные вариации
            float variation = (float)(_random.NextDouble() * 0.2 + 0.9); // 90-110%

            return (
                temperature: (int)(baseValues.temperature * variation),
                radius: baseValues.radius * variation,
                mass: baseValues.mass * variation,
                luminosity: baseValues.luminosity * luminosityMultiplier * variation
            );
        }

        private string GenerateSystemDescriptionWithStar(float security, StarClass starClass, StarLuminosityClass luminosityClass)
        {
            var description = new StringBuilder();

            // Описание звезды
            description.Append($"A {GetStarClassDescription(starClass)} star");

            if (luminosityClass != StarLuminosityClass.V)
            {
                description.Append($", {GetLuminosityClassDescription(luminosityClass)}");
            }

            description.Append(".");

            // Описание безопасности
            if (security > 0.7f)
                description.Append(" High security system with Concord protection.");
            else if (security > 0.4f)
                description.Append(" Moderately secure system with occasional patrols.");
            else if (security > 0.0f)
                description.Append(" Low security system. Travel with caution.");
            else if (security > -0.5f)
                description.Append(" Null security system. No law enforcement present.");
            else
                description.Append(" Dangerous system with active pirate bases.");

            // Особенности звезды
            if (starClass == StarClass.NeutronStar || starClass == StarClass.Pulsar)
                description.Append(" Intense radiation detected.");
            else if (starClass == StarClass.BlackHole)
                description.Append(" Extreme gravitational forces present.");
            else if (starClass == StarClass.RedGiant || starClass == StarClass.BlueGiant)
                description.Append(" Unstable stellar environment.");

            return description.ToString();
        }

        private string GetStarClassDescription(StarClass starClass)
        {
            return starClass switch
            {
                StarClass.O => "bluish-white O-type",
                StarClass.B => "blue-white B-type",
                StarClass.A => "white A-type",
                StarClass.F => "yellow-white F-type",
                StarClass.G => "yellow G-type",
                StarClass.K => "orange K-type",
                StarClass.M => "red M-type",
                StarClass.L => "brown dwarf L-type",
                StarClass.T => "brown dwarf T-type",
                StarClass.Y => "brown dwarf Y-type",
                StarClass.WhiteDwarf => "white dwarf",
                StarClass.NeutronStar => "neutron star",
                StarClass.BlackHole => "black hole",
                StarClass.RedGiant => "red giant",
                StarClass.BlueGiant => "blue giant",
                _ => "main sequence"
            };
        }

        private string GetLuminosityClassDescription(StarLuminosityClass luminosityClass)
        {
            return luminosityClass switch
            {
                StarLuminosityClass.Ia => "bright supergiant",
                StarLuminosityClass.Ib => "supergiant",
                StarLuminosityClass.II => "bright giant",
                StarLuminosityClass.III => "giant",
                StarLuminosityClass.IV => "subgiant",
                StarLuminosityClass.V => "main sequence",
                StarLuminosityClass.VI => "subdwarf",
                StarLuminosityClass.VII => "white dwarf",
                _ => "star"
            };
        }

        private async Task<int> GeneratePlanetsAsync(UniverseConfig config)
        {
            var systems = await _context.SolarSystems.ToListAsync();
            var allPlanets = new List<Planet>();
            int totalPlanets = 0;

            _logger.LogInformation("🪐 Создание планет...");

            var progress = new ProgressTracker(systems.Count, "систем", _logger,
                Math.Max(1, systems.Count / 20));

            foreach (var system in systems)
            {
                int planetCount = _random.Next(
                    config.MinPlanetsPerSystem,
                    config.MaxPlanetsPerSystem + 1
                );

                // Орбитальное расстояние
                long orbitDistance = config.SizeConfig.PlanetOrbitBase;

                for (int i = 0; i < planetCount; i++)
                {
                    var planetType = GetRandomPlanetType(config.NamingConfig);
                    var hasMoons = _random.Chance(0.7f); // 70% шанс иметь луны

                    // Сначала вычисляем радиус планеты
                    long planetRadius = _random.Next(100, 100_000); // или другое подходящее максимальное значение

                    var planet = new Planet
                    {
                        Id = Guid.NewGuid(),
                        Name = GeneratePlanetName(config.NamingConfig, system.Name, i + 1),
                        SolarSystemId = system.Id,
                        Type = planetType,
                        Radius = planetRadius,
                        OrbitDistance = orbitDistance,
                        OrbitPeriod = _random.Next(24, 365 * 24), // часы
                        HasAtmosphere = _random.Chance(0.6f),
                        Temperature = _random.Next(-200, 500), // °C
                        Gravity = (float)_random.NextDouble() * 3.0f, // g
                        HasMoons = hasMoons,
                        IsColonizable = planetType != "Gas Giant" && planetType != "Lava" && _random.Chance(0.3f),
                        FactionId = system.FactionId,
                        CreatedAt = DateTime.UtcNow,
                        Description = GeneratePlanetDescription(planetType, system.SecurityStatus)
                    };

                    allPlanets.Add(planet);
                    totalPlanets++;

                    // Увеличиваем расстояние для следующей планеты
                    orbitDistance += config.SizeConfig.PlanetOrbitStep + _random.NextLong(0, config.SizeConfig.PlanetOrbitStep / 2);
                }

                progress.Update(systems.IndexOf(system) + 1);

                // Периодическое сохранение
                if (config.PerformanceConfig.UseBatchSaving && allPlanets.Count >= config.PerformanceConfig.BatchSize)
                {
                    await SaveInBatchesAsync(allPlanets, config.PerformanceConfig.BatchSize);
                    allPlanets.Clear();
                }
            }

            // Сохраняем оставшиеся
            if (allPlanets.Any())
            {
                if (config.PerformanceConfig.UseBatchSaving)
                    await SaveInBatchesAsync(allPlanets, config.PerformanceConfig.BatchSize);
                else
                    await _context.Planets.AddRangeAsync(allPlanets);
            }

            await _context.SaveChangesAsync();
            _logger.LogInformation($"✅ Создано планет: {totalPlanets}");

            return totalPlanets;
        }

        private async Task<int> GenerateMoonsAsync(UniverseConfig config)
        {
            var planets = await _context.Planets
                .Where(p => p.HasMoons)
                .ToListAsync();

            var allMoons = new List<Moon>();
            int totalMoons = 0;

            _logger.LogInformation("🌙 Создание лун...");

            var progress = new ProgressTracker(planets.Count, "планет с лунами", _logger,
                Math.Max(1, planets.Count / 10));

            foreach (var planet in planets)
            {
                int moonCount = _random.Next(1, 10); // 1-9 лун

                for (int i = 0; i < moonCount; i++)
                {
                    // ИСПРАВЛЕНИЕ: Проверяем чтобы второй параметр был больше первого
                    int maxRadius = (int)Math.Min(int.MaxValue, planet.Radius / 4);
                    int moonRadius;

                    if (maxRadius > 100)
                    {
                        moonRadius = _random.Next(100, maxRadius);
                    }
                    else
                    {
                        // Если планета слишком маленькая, делаем луну с фиксированным радиусом
                        moonRadius = 100;
                    }

                    var moon = new Moon
                    {
                        Id = Guid.NewGuid(),
                        Name = $"{planet.Name}{config.NamingConfig.MoonNameSuffixes[_random.Next(config.NamingConfig.MoonNameSuffixes.Count)]}",
                        PlanetId = planet.Id,
                        Radius = moonRadius, // Используем исправленное значение
                        OrbitDistance = _random.Next(10000, 1000000), // 10к - 1 млн км
                        OrbitPeriod = _random.Next(1, 30 * 24), // часы
                        HasResources = _random.Chance(0.5f),
                        CreatedAt = DateTime.UtcNow
                    };

                    allMoons.Add(moon);
                    totalMoons++;
                }

                progress.Update(planets.IndexOf(planet) + 1);
            }

            if (allMoons.Any())
            {
                if (config.PerformanceConfig.UseBatchSaving)
                    await SaveInBatchesAsync(allMoons, config.PerformanceConfig.BatchSize);
                else
                    await _context.Moons.AddRangeAsync(allMoons);

                await _context.SaveChangesAsync();
            }

            _logger.LogInformation($"✅ Создано лун: {totalMoons}");

            return totalMoons;
        }

        private async Task<int> GenerateStationsAsync(UniverseConfig config)
        {
            var systems = await _context.SolarSystems.ToListAsync();
            var allStations = new List<Station>();
            int totalStations = 0;

            _logger.LogInformation("🏢 Создание станций...");

            foreach (var system in systems)
            {
                int stationCount = GetStationCountBySecurity(system.SecurityStatus, config.StationConfig);

                for (int i = 0; i < stationCount; i++)
                {
                    var station = new Station
                    {
                        Id = Guid.NewGuid(),
                        Name = GenerateStationName(config.NamingConfig, system.Name, i + 1),
                        SolarSystemId = system.Id,
                        Type = GetRandomStationType(),
                        PositionX = system.PositionX + _random.NextLong(-10_000_000, 10_000_000),
                        PositionY = system.PositionY + _random.NextLong(-10_000_000, 10_000_000),
                        PositionZ = system.PositionZ + _random.NextLong(-1_000_000, 1_000_000),
                        DockingCapacity = _random.Next(config.StationConfig.MinDockingCapacity, config.StationConfig.MaxDockingCapacity),
                        IsOperational = _random.Chance(0.95f),
                        FactionId = system.FactionId,
                        Services = GetStationServices(system.SecurityStatus),
                        CreatedAt = DateTime.UtcNow
                    };

                    allStations.Add(station);
                    totalStations++;
                }
            }

            if (allStations.Any())
            {
                if (config.PerformanceConfig.UseBatchSaving)
                    await SaveInBatchesAsync(allStations, config.PerformanceConfig.BatchSize);
                else
                    await _context.Stations.AddRangeAsync(allStations);

                await _context.SaveChangesAsync();
            }

            _logger.LogInformation($"✅ Создано станций: {totalStations}");

            return totalStations;
        }

        private async Task<int> GenerateStargatesAsync(UniverseConfig config)
        {
            if (!config.StargateConfig.EnableStargates) return 0;

            _logger.LogInformation("🌀 Создание звездных врат (Optimized Region-Based)...");

            int totalStargates = 0;

            // 1. Получаем список ID всех регионов и их координаты (легковесный запрос)
            var regionsData = await _context.Regions
                .Select(r => new { r.Id, r.PositionX, r.PositionY, r.PositionZ })
                .AsNoTracking()
                .ToListAsync();

            var progress = new ProgressTracker(regionsData.Count, "регионов обработано", _logger, 1);
            int processedRegions = 0;

            // Максимальная дистанция для связи (например 50 световых лет в метрах)
            // Это нужно, чтобы определить, какие соседние регионы загружать
            long maxJumpDistanceMeters = (long)(50.0 * LIGHTYEAR_TO_METERS);

            // Используем словарь связей, чтобы не создавать дубликаты (A->B и B->A)
            // Храним пару (MinId, MaxId) чтобы проверить существование связи
            var existingConnections = new HashSet<(Guid, Guid)>();

            foreach (var currentRegion in regionsData)
            {
                // 2. Находим соседние регионы (чистая математика, без БД)
                // Мы будем загружать системы ТОЛЬКО из текущего региона и его ближайших соседей.
                var relevantRegionIds = regionsData
                    .Where(r =>
                        Math.Abs(r.PositionX - currentRegion.PositionX) < maxJumpDistanceMeters * 3 && // *3 для запаса
                        Math.Abs(r.PositionY - currentRegion.PositionY) < maxJumpDistanceMeters * 3 &&
                        Math.Abs(r.PositionZ - currentRegion.PositionZ) < maxJumpDistanceMeters * 3)
                    .Select(r => r.Id)
                    .ToHashSet();

                // 3. Загружаем системы для этого кластера регионов
                var loadedSystems = await _context.SolarSystems
                    .Where(s => relevantRegionIds.Contains(s.Constellation.RegionId))
                    .Select(s => new
                    {
                        s.Id,
                        s.Name,
                        s.PositionX,
                        s.PositionY,
                        s.PositionZ,
                        s.Radius,
                        RegionId = s.Constellation.RegionId
                    })
                    .AsNoTracking()
                    .ToListAsync();

                // Разделяем: 
                // sourceSystems - системы текущего региона (откуда ищем связи)
                // candidateSystems - все загруженные системы (куда можем прыгнуть)
                var sourceSystems = loadedSystems.Where(s => s.RegionId == currentRegion.Id).ToList();

                var newStargatesBatch = new List<Stargate>();

                foreach (var source in sourceSystems)
                {
                    // Пропускаем, если у системы уже достаточно связей (тут упрощение: мы не проверяем БД, 
                    // считаем только вновь создаваемые в памяти, для полной точности нужно сложнее логику)
                    int currentConnectionsCount = existingConnections.Count(x => x.Item1 == source.Id || x.Item2 == source.Id);

                    int targetConnectionCount = _random.Next(
                        config.StargateConfig.MinConnectionsPerSystem,
                        config.StargateConfig.MaxConnectionsPerSystem + 1
                    );

                    if (currentConnectionsCount >= targetConnectionCount) continue;

                    // Ищем ближайших соседей из loadedSystems
                    // Сортировка по дистанции
                    var neighbors = loadedSystems
                        .Where(s => s.Id != source.Id)
                        .Select(s => new
                        {
                            System = s,
                            DistSq = (double)(s.PositionX - source.PositionX) * (s.PositionX - source.PositionX) +
                                     (double)(s.PositionY - source.PositionY) * (s.PositionY - source.PositionY) +
                                     (double)(s.PositionZ - source.PositionZ) * (s.PositionZ - source.PositionZ)
                        })
                        .OrderBy(x => x.DistSq)
                        .Take((targetConnectionCount - currentConnectionsCount) + 2) // Берем с небольшим запасом
                        .ToList();

                    foreach (var neighborEntry in neighbors)
                    {
                        var dest = neighborEntry.System;

                        // Формируем уникальный ключ пары (всегда меньший ID первый)
                        var pairKey = source.Id.CompareTo(dest.Id) < 0
                            ? (source.Id, dest.Id)
                            : (dest.Id, source.Id);

                        if (existingConnections.Contains(pairKey)) continue;
                        if (currentConnectionsCount >= targetConnectionCount) break;

                        // Создаем пару врат

                        // Врата А (в source, ведут в dest)
                        // Примечание: тут нам нужны полные объекты для создания Stargate, 
                        // но метод CreateStargateObject использует поля, которые мы загрузили в анонимный объект.
                        // Поэтому мы инлайнем логику создания здесь для скорости.

                        // Вектор к цели
                        double dx = dest.PositionX - source.PositionX;
                        double dy = dest.PositionY - source.PositionY;
                        double dz = dest.PositionZ - source.PositionZ;
                        double dist = Math.Sqrt(dx * dx + dy * dy + dz * dz);

                        long gateDist = (long)(source.Radius * 0.8); // 80% от радиуса системы

                        newStargatesBatch.Add(new Stargate
                        {
                            Id = Guid.NewGuid(),
                            Name = $"Gate to {dest.Name}",
                            SourceSolarSystemId = source.Id,
                            DestinationSolarSystemId = dest.Id,
                            PositionX = (long)((dx / dist) * gateDist),
                            PositionY = (long)((dy / dist) * gateDist),
                            PositionZ = (long)((dz / dist) * gateDist),
                            IsOperational = _random.Chance(config.StargateConfig.OperationalRate),
                            JumpCost = _random.Next(100, 10000),
                            Model = config.StargateConfig.DefaultStargateModel,
                            CreatedAt = DateTime.UtcNow
                        });

                        // Врата Б (в dest, ведут в source)
                        // Вектор обратный
                        long gateDistDest = (long)(dest.Radius * 0.8);
                        newStargatesBatch.Add(new Stargate
                        {
                            Id = Guid.NewGuid(),
                            Name = $"Gate to {source.Name}",
                            SourceSolarSystemId = dest.Id,
                            DestinationSolarSystemId = source.Id,
                            PositionX = (long)((-dx / dist) * gateDistDest),
                            PositionY = (long)((-dy / dist) * gateDistDest),
                            PositionZ = (long)((-dz / dist) * gateDistDest),
                            IsOperational = _random.Chance(config.StargateConfig.OperationalRate),
                            JumpCost = _random.Next(100, 10000),
                            Model = config.StargateConfig.DefaultStargateModel,
                            CreatedAt = DateTime.UtcNow
                        });

                        existingConnections.Add(pairKey);
                        currentConnectionsCount++;
                        totalStargates += 2;
                    }
                }

                // Сохраняем батч для текущего региона
                if (newStargatesBatch.Any())
                {
                    await _context.Stargates.AddRangeAsync(newStargatesBatch);
                    await _context.SaveChangesAsync();
                    _context.ChangeTracker.Clear(); // Очистка памяти
                }

                processedRegions++;
                progress.Update(processedRegions);
            }

            progress.Complete();
            _logger.LogInformation($"✅ Создано звездных врат: {totalStargates} (парных)");
            return totalStargates;
        }

        private Stargate CreateStargateObject(SolarSystem source, SolarSystem dest, UniverseConfig config)
        {
            // Рассчитываем вектор направления к целевой системе
            double dx = dest.PositionX - source.PositionX;
            double dy = dest.PositionY - source.PositionY;
            double dz = dest.PositionZ - source.PositionZ;
            double distance = Math.Sqrt(dx * dx + dy * dy + dz * dz);

            // Нормализуем вектор
            double nx = dx / distance;
            double ny = dy / distance;
            double nz = dz / distance;

            // Размещаем врата на расстоянии, например, 80% от радиуса системы (или фиксированное число AU)
            // Используем Radius самой системы, чтобы врата были на периферии
            long gateDistance = (long)(source.Radius * 0.8);

            return new Stargate
            {
                Id = Guid.NewGuid(),
                Name = $"Gate to {dest.Name}", // Нормальное имя
                SourceSolarSystemId = source.Id, // Исправлено: было SolarSystemId
                DestinationSolarSystemId = dest.Id,

                // Координаты врат внутри системы (направлены в сторону цели)
                PositionX = (long)(nx * gateDistance),
                PositionY = (long)(ny * gateDistance),
                PositionZ = (long)(nz * gateDistance),

                IsOperational = _random.Chance(config.StargateConfig.OperationalRate),
                JumpCost = _random.Next(100, 10000),
                Model = config.StargateConfig.DefaultStargateModel,
                CreatedAt = DateTime.UtcNow
            };
        }

        private async Task<int> GenerateAsteroidBeltsAsync(UniverseConfig config)
        {
            if (!config.ResourcesConfig.EnableResources)
                return 0;

            var systems = await _context.SolarSystems
                .Where(s => s.HasAsteroidBelts)
                .ToListAsync();

            var allBelts = new List<AsteroidBelt>();
            int totalBelts = 0;

            _logger.LogInformation("💎 Создание астероидных поясов...");

            foreach (var system in systems)
            {
                int beltCount = _random.Next(
                    config.ResourcesConfig.MinAsteroidBeltsPerSystem,
                    config.ResourcesConfig.MaxAsteroidBeltsPerSystem + 1
                );

                for (int i = 0; i < beltCount; i++)
                {
                    var belt = new AsteroidBelt
                    {
                        Id = Guid.NewGuid(),
                        Name = $"{config.ResourcesConfig.AsteroidBeltNames[_random.Next(config.ResourcesConfig.AsteroidBeltNames.Count)]} {i + 1}",
                        SolarSystemId = system.Id,
                        PositionX = system.PositionX + _random.NextLong(-system.Radius / 2, system.Radius / 2),
                        PositionY = system.PositionY + _random.NextLong(-system.Radius / 2, system.Radius / 2),
                        PositionZ = system.PositionZ + _random.NextLong(-system.Radius / 10, system.Radius / 10),
                        Radius = _random.Next(10_000, 1_000_000),
                        Density = (float)_random.NextDouble(),
                        AsteroidCount = _random.Next(100, 10000),
                        CreatedAt = DateTime.UtcNow
                    };

                    // Добавляем ресурсы в пояс
                    int resourceCount = _random.Next(
                        config.ResourcesConfig.MinResourcesPerBelt,
                        config.ResourcesConfig.MaxResourcesPerBelt + 1
                    );

                    for (int r = 0; r < resourceCount; r++)
                    {
                        var resourceType = config.ResourcesConfig.ResourceTypes
                            .Where(rt => _random.Chance(rt.Rarity))
                            .OrderBy(rt => rt.Rarity)
                            .FirstOrDefault();

                        if (resourceType != null)
                        {
                            belt.Resources.Add(new PlanetResource
                            {
                                Id = Guid.NewGuid(),
                                AsteroidBeltId = belt.Id,
                                ResourceType = resourceType.Name,
                                Quantity = (int)(resourceType.BaseAmount * (0.5 + _random.NextDouble())),
                                Quality = (float)_random.NextDouble(),
                                LastHarvested = null
                            });
                        }
                    }

                    allBelts.Add(belt);
                    totalBelts++;
                }
            }

            if (allBelts.Any())
            {
                if (config.PerformanceConfig.UseBatchSaving)
                    await SaveInBatchesAsync(allBelts, config.PerformanceConfig.BatchSize);
                else
                    await _context.AsteroidBelts.AddRangeAsync(allBelts);

                await _context.SaveChangesAsync();
            }

            _logger.LogInformation($"✅ Создано астероидных поясов: {totalBelts}");

            return totalBelts;
        }

        #endregion

        #region Генерация имен и описаний

        private string GenerateRegionName(NamingConfig naming, int index, RegionType type, int? factionId)
        {
            var faction = factionId.HasValue && _factions.ContainsKey(factionId.Value)
                ? _factions[factionId.Value]
                : null;

            if (faction != null && !string.IsNullOrEmpty(faction.HomeRegionName))
            {
                // Используем домашний регион фракции
                return faction.HomeRegionName;
            }

            // Генерация случайного имени
            string prefix = naming.RegionNamePrefixes.Count > 0 ?
                naming.RegionNamePrefixes[_random.Next(naming.RegionNamePrefixes.Count)] : "";
            string word = naming.RegionNameWords.Count > 0 ?
                naming.RegionNameWords[_random.Next(naming.RegionNameWords.Count)] : $"Region-{index}";
            string suffix = naming.RegionNameSuffixes.Count > 0 ?
                naming.RegionNameSuffixes[_random.Next(naming.RegionNameSuffixes.Count)] : "";

            // Добавляем префикс типа региона для разнообразия
            string typePrefix = type switch
            {
                RegionType.Empire => _random.Chance(0.3f) ? "Imperial " : "",
                RegionType.LowSec => _random.Chance(0.3f) ? "Lawless " : "",
                RegionType.NullSec => _random.Chance(0.3f) ? "Wild " : "",
                RegionType.Wormhole => _random.Chance(0.3f) ? "Uncharted " : "",
                _ => ""
            };

            return $"{typePrefix}{prefix}{word}{suffix}";
        }

        private string GenerateConstellationName(NamingConfig naming, string regionName, int index)
        {
            string prefix = naming.ConstellationNamePrefixes.Count > 0 ?
                naming.ConstellationNamePrefixes[_random.Next(naming.ConstellationNamePrefixes.Count)] : "";
            string word = naming.ConstellationNameWords.Count > 0 ?
                naming.ConstellationNameWords[_random.Next(naming.ConstellationNameWords.Count)] : $"Cluster-{index}";
            string suffix = naming.ConstellationNameSuffixes.Count > 0 ?
                naming.ConstellationNameSuffixes[_random.Next(naming.ConstellationNameSuffixes.Count)] : "";

            return $"{prefix}{word}{suffix}";
        }

        private string GenerateSystemName(NamingConfig naming, string constellationName, int index)
        {
            string prefix = naming.SystemNamePrefixes.Count > 0 ?
                naming.SystemNamePrefixes[_random.Next(naming.SystemNamePrefixes.Count)] : "";
            string word = naming.SystemNameWords.Count > 0 ?
                naming.SystemNameWords[_random.Next(naming.SystemNameWords.Count)] : $"System-{index}";
            string suffix = naming.SystemNameSuffixes.Count > 0 ?
                naming.SystemNameSuffixes[_random.Next(naming.SystemNameSuffixes.Count)] : "";

            // 30% шанс использовать номер вместо имени
            if (_random.Chance(0.3f))
            {
                word = $"{constellationName.Substring(0, Math.Min(3, constellationName.Length))}-{index}";
            }

            return $"{prefix}{word}{suffix}";
        }

        private string GeneratePlanetName(NamingConfig naming, string systemName, int index)
        {
            string prefix = naming.PlanetNamePrefixes.Count > 0 ?
                naming.PlanetNamePrefixes[_random.Next(naming.PlanetNamePrefixes.Count)] : "";
            string word = naming.PlanetNameWords.Count > 0 ?
                naming.PlanetNameWords[_random.Next(naming.PlanetNameWords.Count)] : $"Planet-{index}";
            string suffix = naming.PlanetNameSuffixes.Count > 0 ?
                naming.PlanetNameSuffixes[_random.Next(naming.PlanetNameSuffixes.Count)] : "";

            return $"{prefix}{word}{suffix}";
        }

        private string GenerateStationName(NamingConfig naming, string systemName, int index)
        {
            string prefix = naming.StationNamePrefixes.Count > 0 ?
                naming.StationNamePrefixes[_random.Next(naming.StationNamePrefixes.Count)] : "";
            string word = naming.StationNameWords.Count > 0 ?
                naming.StationNameWords[_random.Next(naming.StationNameWords.Count)] : systemName;
            string suffix = naming.StationNameSuffixes.Count > 0 ?
                naming.StationNameSuffixes[_random.Next(naming.StationNameSuffixes.Count)] : " Station";

            return $"{prefix} {word}{suffix}".Trim();
        }

        private string GetRandomPlanetType(NamingConfig naming)
        {
            return naming.PlanetTypes.Count > 0
                ? naming.PlanetTypes[_random.Next(naming.PlanetTypes.Count)]
                : "Barren";
        }

        private string GenerateRegionDescription(RegionType type, int? factionId)
        {
            var faction = factionId.HasValue && _factions.ContainsKey(factionId.Value)
                ? _factions[factionId.Value]
                : null;

            var descriptions = new List<string>();

            if (faction != null)
            {
                descriptions.Add($"Controlled by {faction.Name}. {faction.Description}");
            }

            switch (type)
            {
                case RegionType.Empire:
                    descriptions.Add("A well-patrolled region with high security and thriving commerce.");
                    break;
                case RegionType.LowSec:
                    descriptions.Add("A dangerous region where security is minimal and pirate activity is common.");
                    break;
                case RegionType.NullSec:
                    descriptions.Add("Unclaimed space with no security. Only the strong survive here.");
                    break;
                case RegionType.Wormhole:
                    descriptions.Add("Unstable region with shifting topology and unknown dangers.");
                    break;
            }

            return string.Join(" ", descriptions);
        }

        private string GeneratePlanetDescription(string planetType, float systemSecurity)
        {
            var desc = new StringBuilder($"A {planetType.ToLower()} planet.");

            if (systemSecurity > 0.5f)
                desc.Append(" Suitable for colonization.");
            else if (systemSecurity < 0)
                desc.Append(" Hostile environment.");

            switch (planetType)
            {
                case "Gas Giant":
                    desc.Append(" Rich in atmospheric gases.");
                    break;
                case "Ice":
                    desc.Append(" Valuable ice deposits detected.");
                    break;
                case "Lava":
                    desc.Append(" Extreme temperatures make it uninhabitable.");
                    break;
                case "Oceanic":
                    desc.Append(" Abundant water resources.");
                    break;
            }

            return desc.ToString();
        }

        #endregion

        #region Вспомогательные методы

        private Dictionary<int, FactionConfig> AssignFactionsToRegions(UniverseConfig config)
        {
            var assignments = new Dictionary<int, FactionConfig>();

            if (!config.FactionsConfig.AssignFactionsToRegions || _factions.Count == 0)
                return assignments;

            var factions = _factions.Values
                .Where(f => !string.IsNullOrEmpty(f.HomeRegionName))
                .ToList();

            if (factions.Count == 0)
                return assignments;

            // Распределяем фракции по регионам
            int regionsPerFaction = config.RegionCount / Math.Max(1, factions.Count);

            for (int i = 0; i < config.RegionCount; i++)
            {
                int factionIndex = i / regionsPerFaction;
                if (factionIndex < factions.Count)
                {
                    assignments[i + 1] = factions[factionIndex];
                }
            }

            return assignments;
        }

        private RegionType GetRandomRegionType(RegionDistribution distribution)
        {
            int total = distribution.EmpirePercent + distribution.LowSecPercent +
                       distribution.NullSecPercent + distribution.WormholePercent;

            if (total == 0) return RegionType.Empire;

            int roll = _random.Next(total);

            if (roll < distribution.EmpirePercent) return RegionType.Empire;
            roll -= distribution.EmpirePercent;

            if (roll < distribution.LowSecPercent) return RegionType.LowSec;
            roll -= distribution.LowSecPercent;

            if (roll < distribution.NullSecPercent) return RegionType.NullSec;
            return RegionType.Wormhole;
        }

        private float GetSecurityByType(RegionType type, RegionDistribution distribution)
        {
            return type switch
            {
                RegionType.Empire => distribution.EmpireMinSecurity +
                    (float)_random.NextDouble() * (distribution.EmpireMaxSecurity - distribution.EmpireMinSecurity),
                RegionType.LowSec => distribution.LowSecMinSecurity +
                    (float)_random.NextDouble() * (distribution.LowSecMaxSecurity - distribution.LowSecMinSecurity),
                RegionType.NullSec => distribution.NullSecMinSecurity +
                    (float)_random.NextDouble() * (distribution.NullSecMaxSecurity - distribution.NullSecMinSecurity),
                RegionType.Wormhole => distribution.WormholeSecurity,
                _ => 0.0f
            };
        }

        private int GetStationCountBySecurity(float security, StationConfig config)
        {
            if (security >= 0.5f) // High sec
                return _random.Next(config.HighSecMinStations, config.HighSecMaxStations + 1);
            else if (security >= 0.0f) // Mid sec
                return _random.Next(config.MidSecMinStations, config.MidSecMaxStations + 1);
            else if (security >= -0.5f) // Low sec
                return _random.Next(config.LowSecMinStations, config.LowSecMaxStations + 1);
            else // Null sec
                return _random.Next(config.NullSecMinStations, config.NullSecMaxStations + 1);
        }

        private StationType GetRandomStationType()
        {
            var types = Enum.GetValues(typeof(StationType));
            return (StationType)types.GetValue(_random.Next(types.Length));
        }

        private string GetStationServices(float security)
        {
            var services = new List<string> { "Docking", "Repair", "Refuel" };

            if (security > 0.3f)
                services.Add("Market");
            if (security > 0.5f)
                services.Add("Insurance");
            if (security > 0.7f)
                services.Add("Clone Bay");

            return string.Join(",", services);
        }

        private double GetDistance(SolarSystem a, SolarSystem b)
        {
            long dx = a.PositionX - b.PositionX;
            long dy = a.PositionY - b.PositionY;
            long dz = a.PositionZ - b.PositionZ;
            return Math.Sqrt(dx * dx + dy * dy + dz * dz);
        }

        private async Task SaveInBatchesAsync<T>(List<T> entities, int batchSize) where T : class
        {
            for (int i = 0; i < entities.Count; i += batchSize)
            {
                var batch = entities.Skip(i).Take(batchSize).ToList();
                await _context.AddRangeAsync(batch);
                await _context.SaveChangesAsync();

                _context.ChangeTracker.Clear(); // Очищаем трекер для следующего батча

                if (i % (batchSize * 10) == 0 && i > 0)
                {
                    _logger.LogInformation($"💾 Сохранено {Math.Min(i + batchSize, entities.Count)}/{entities.Count}...");
                }
            }
        }

        private async Task SaveGenerationConfig(UniverseConfig config, UniverseGenerationStats? stats = null, TimeSpan? generationTime = null)
        {
            try
            {
                // Сериализуем конфиг в JSON
                var configJson = JsonSerializer.Serialize(config, new JsonSerializerOptions
                {
                    WriteIndented = true,
                    PropertyNamingPolicy = JsonNamingPolicy.CamelCase
                });

                // Проверяем, есть ли уже такая конфигурация
                var existingConfig = await _context.UniverseGenerationConfigs
                    .FirstOrDefaultAsync(c => c.ConfigJson == configJson && c.IsPreset == false);

                if (existingConfig != null)
                {
                    // Обновляем существующую
                    existingConfig.LastUsedAt = DateTime.UtcNow;
                    existingConfig.UsageCount++;

                    if (stats != null)
                    {
                        existingConfig.RegionCount = stats.RegionsGenerated;
                        existingConfig.SystemCount = stats.SystemsGenerated;
                        existingConfig.PlanetCount = stats.PlanetsGenerated;
                        existingConfig.GenerationStats = JsonSerializer.Serialize(stats);
                    }

                    if (generationTime.HasValue)
                        existingConfig.GenerationTimeMs = (long)generationTime.Value.TotalMilliseconds;

                    _context.UniverseGenerationConfigs.Update(existingConfig);

                    _logger.LogInformation($"📝 Обновлена существующая конфигурация: {existingConfig.ConfigName}");
                }
                else
                {
                    // Создаем новую конфигурация
                    var configName = $"Конфигурация от {DateTime.UtcNow:yyyy-MM-dd HH:mm}";

                    if (config is { UseSeedBasedGeneration: true, Seed: not null })
                        configName = $"Seed: {config.Seed}";

                    var generationConfig = new UniverseGenerationConfig
                    {
                        Id = Guid.NewGuid(),
                        ConfigName = configName,
                        Description = GenerateConfigDescription(config),
                        ConfigJson = configJson,
                        UniverseSeed = config.Seed,
                        UseSeedBasedGeneration = config.UseSeedBasedGeneration,
                        SeedVersion = int.TryParse(config.SeedVersion, out var sv) ? sv : 1,
                        GeneratorVersion = config.GeneratorVersion ?? "1.0.0",
                        IsPreset = false,
                        IsActive = true,
                        Tags = GenerateConfigTags(config),
                        RegionCount = config.RegionCount,
                        PresetType = GetPresetType(config),
                        CreatedAt = DateTime.UtcNow,
                        LastUsedAt = DateTime.UtcNow,
                        UsageCount = 1
                    };

                    // Добавляем статистику если есть
                    if (stats != null)
                    {
                        generationConfig.SystemCount = stats.SystemsGenerated;
                        generationConfig.PlanetCount = stats.PlanetsGenerated;
                        generationConfig.GenerationStats = JsonSerializer.Serialize(stats);
                    }

                    if (generationTime.HasValue)
                        generationConfig.GenerationTimeMs = (long)generationTime.Value.TotalMilliseconds;

                    await _context.UniverseGenerationConfigs.AddAsync(generationConfig);

                    _logger.LogInformation($"💾 Сохранена новая конфигурация: {generationConfig.ConfigName}");
                }

                // Деактивируем другие конфигурации, если эта активна
                if (config.UseSeedBasedGeneration && !string.IsNullOrEmpty(config.Seed))
                {
                    Guid? existingConfigId = existingConfig?.Id;
                    var otherConfigs = await _context.UniverseGenerationConfigs
                        .Where(c => c.UniverseSeed == config.Seed && (existingConfigId == null || c.Id != existingConfigId.Value))
                        .ToListAsync();

                    foreach (var other in otherConfigs)
                    {
                        other.IsActive = false;
                    }
                }

                await _context.SaveChangesAsync();

                _logger.LogInformation("✅ Конфигурация генерации сохранена в базе данных");
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка сохранения конфигурации генерации");
                // Не бросаем исключение - это не критичная ошибка
            }
        }

        // Вспомогательные методы
        private string GenerateConfigDescription(UniverseConfig config)
        {
            var desc = new StringBuilder();

            desc.Append($"Вселенная с {config.RegionCount} регионами, ");
            desc.Append($"{config.MinConstellationsPerRegion}-{config.MaxConstellationsPerRegion} констелляциями на регион, ");
            desc.Append($"{config.MinSystemsPerConstellation}-{config.MaxSystemsPerConstellation} системами на констелляцию.");

            if (config.UseSeedBasedGeneration && !string.IsNullOrEmpty(config.Seed))
                desc.Append($" Seed: {config.Seed}");

            if (config.ForceRegeneration)
                desc.Append(" [FORCE REGEN]");

            return desc.ToString();
        }

        private string GenerateConfigTags(UniverseConfig config)
        {
            var tags = new List<string>();

            // Размер
            if (config.RegionCount <= 1) tags.Add("tiny");
            else if (config.RegionCount <= 3) tags.Add("small");
            else if (config.RegionCount <= 10) tags.Add("medium");
            else if (config.RegionCount <= 50) tags.Add("large");
            else tags.Add("massive");

            // Тип
            if (config.UseSeedBasedGeneration) tags.Add("seed-based");
            else tags.Add("random");

            // Особенности
            if (config.StationConfig.EnableStations) tags.Add("stations");
            if (config.StargateConfig.EnableStargates) tags.Add("stargates");
            if (config.ResourcesConfig.EnableResources) tags.Add("resources");
            if (config.StarConfig.EnableStarVariety) tags.Add("star-variety");

            return string.Join(",", tags);
        }

        private string? GetPresetType(UniverseConfig config)
        {
            // Определяем тип пресета на основе размера
            return config.RegionCount switch
            {
                1 => "UltraSmall",
                <= 3 => "Small",
                <= 10 => "Medium",
                <= 50 => "Large",
                <= 200 => "UltraLarge",
                _ => "Massive"
            };
        }

        #endregion

        #region Интерфейсные методы

        public async Task GenerateTestUniverseAsync()
        {
            var testConfig = new UniverseConfig
            {
                RegionCount = 1,
                MinConstellationsPerRegion = 1,
                MaxConstellationsPerRegion = 2,
                MinSystemsPerConstellation = 3,
                MaxSystemsPerConstellation = 5,
                MinPlanetsPerSystem = 1,
                MaxPlanetsPerSystem = 3,
                StationConfig = { EnableStations = true },
                StargateConfig = { EnableWormholes = true },
                ResourcesConfig = { EnableResources = true },
                AnomalyConfig = new AnomalyConfig
                {
                    EnableAnomalies = true,
                    MinPerSystem = 2,
                    MaxPerSystem = 5,
                    TypeChances = new Dictionary<string, double>
                    {
                        ["Combat"] = 0.5,
                        ["Ore"] = 0.3,
                        ["Gas"] = 0.2
                    }
                },
                WormholeConfig = new WormholeConfig
                {
                    EnableWormholes = true,
                    ChancePerSystem = 0.5,
                    MinDistanceLightYears = 10,
                    MaxDistanceLightYears = 100,
                    ClassChances = new Dictionary<string, double>
                    {
                        ["C1"] = 0.5,
                        ["C2"] = 0.3,
                        ["C3"] = 0.2
                    },
                    MassByClass = new Dictionary<string, double>
                    {
                        ["C1"] = 1000000000,
                        ["C2"] = 2000000000,
                        ["C3"] = 3000000000,
                        ["K162"] = 5000000000
                    },
                    LifetimeHoursByClass = new Dictionary<string, int>
                    {
                        ["C1"] = 16,
                        ["C2"] = 16,
                        ["C3"] = 24,
                        ["K162"] = 24
                    },
                    MaxShipSizeByClass = new Dictionary<string, string>
                    {
                        ["C1"] = "Medium",
                        ["C2"] = "Medium",
                        ["C3"] = "Large",
                        ["K162"] = "Capital"
                    },
                    NamesByClass = new Dictionary<string, List<string>>
                    {
                        ["C1"] = new List<string> { "H121", "Q312" },
                        ["C2"] = new List<string> { "C247", "D382" },
                        ["C3"] = new List<string> { "L477", "N766" }
                    }
                }
            };

            await GenerateUniverseFromConfigAsync(testConfig);
        }

        public async Task GenerateUniverseAsync()
        {
            // Используем дефолтную конфигурацию из appsettings.json
            await GenerateUniverseFromConfigAsync(_defaultConfig);
        }

        public async Task<UniverseStats> GetUniverseStatsAsync()
        {
            var stats = new UniverseStats
            {
                Regions = await _context.Regions.CountAsync(),
                Constellations = await _context.Constellations.CountAsync(),
                SolarSystems = await _context.SolarSystems.CountAsync(),
                Planets = await _context.Planets.CountAsync(),
                Stations = await _context.Stations.CountAsync(),
                Stargates = await _context.Stargates.CountAsync(),
                AsteroidBelts = await _context.AsteroidBelts.CountAsync(),
                Anomalies = await _context.Anomalies.CountAsync(),      // Новое поле
                Wormholes = await _context.Wormholes.CountAsync()       // Новое поле
            };

            return stats;
        }

        public async Task<string> ExportUniverseConfigAsync()
        {
            var stats = await GetUniverseStatsAsync();
            var config = _defaultConfig;

            var export = new
            {
                GeneratedAt = DateTime.UtcNow,
                Stats = stats,
                Config = config,
                Summary = $"Вселенная с {stats.Regions} регионами, {stats.SolarSystems} системами"
            };

            return JsonSerializer.Serialize(export, new JsonSerializerOptions
            {
                WriteIndented = true,
                PropertyNamingPolicy = JsonNamingPolicy.CamelCase
            });
        }

        public async Task<List<UniverseGenerationConfig>> GetSavedConfigsAsync()
        {
            return await _context.UniverseGenerationConfigs
                .OrderByDescending(c => c.LastUsedAt)
                .ThenByDescending(c => c.CreatedAt)
                .ToListAsync();
        }

        public async Task<UniverseGenerationConfig?> GetConfigByIdAsync(Guid configId)
        {
            return await _context.UniverseGenerationConfigs
                .FirstOrDefaultAsync(c => c.Id == configId);
        }

        public async Task<UniverseGenerationConfig> SaveConfigAsync(UniverseConfig config, string? name = null, string? description = null)
        {
            var configJson = JsonSerializer.Serialize(config);

            var generationConfig = new UniverseGenerationConfig
            {
                Id = Guid.NewGuid(),
                ConfigName = name ?? $"Конфигурация от {DateTime.UtcNow:yyyy-MM-dd HH:mm}",
                Description = description ?? GenerateConfigDescription(config),
                ConfigJson = configJson,
                UniverseSeed = config.Seed,
                UseSeedBasedGeneration = config.UseSeedBasedGeneration,
                SeedVersion = int.TryParse(config.SeedVersion, out var sv) ? sv : 1,
                GeneratorVersion = config.GeneratorVersion ?? "1.0.0",
                IsPreset = false,
                IsActive = false,
                Tags = GenerateConfigTags(config),
                RegionCount = config.RegionCount,
                CreatedAt = DateTime.UtcNow,
                UsageCount = 0
            };

            await _context.UniverseGenerationConfigs.AddAsync(generationConfig);
            await _context.SaveChangesAsync();

            _logger.LogInformation($"💾 Сохранена пользовательская конфигурация: {generationConfig.ConfigName}");

            return generationConfig;
        }

        public async Task<bool> DeleteConfigAsync(Guid configId)
        {
            var config = await GetConfigByIdAsync(configId);
            if (config == null) return false;

            if (config.IsActive)
            {
                _logger.LogWarning($"⚠️ Нельзя удалить активную конфигурацию: {config.ConfigName}");
                return false;
            }

            _context.UniverseGenerationConfigs.Remove(config);
            await _context.SaveChangesAsync();

            _logger.LogInformation($"🗑️ Удалена конфигурация: {config.ConfigName}");
            return true;
        }

        public async Task<bool> ActivateConfigAsync(Guid configId)
        {
            var config = await GetConfigByIdAsync(configId);
            if (config == null) return false;

            // Деактивируем все конфигурации
            var allConfigs = await _context.UniverseGenerationConfigs.ToListAsync();
            foreach (var c in allConfigs)
            {
                c.IsActive = false;
            }

            // Активируем выбранную
            config.IsActive = true;
            config.LastUsedAt = DateTime.UtcNow;
            config.UsageCount++;

            await _context.SaveChangesAsync();

            _logger.LogInformation($"✅ Активирована конфигурация: {config.ConfigName}");
            return true;
        }

        public async Task<UniverseGenerationConfig?> GetActiveConfigAsync()
        {
            return await _context.UniverseGenerationConfigs
                .FirstOrDefaultAsync(c => c.IsActive);
        }

        public async Task<UniverseConfig> LoadConfigFromJsonAsync(string configJson)
        {
            try
            {
                return await Task.Run(() =>
                    JsonSerializer.Deserialize<UniverseConfig>(configJson) ??
                    throw new InvalidOperationException("Не удалось десериализовать конфигурацию")
                );
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка загрузки конфигурации из JSON");
                throw;
            }
        }

        #endregion
    }

    public class UniverseGenerationStats
    {
        public int RegionsGenerated { get; set; }
        public int ConstellationsGenerated { get; set; }
        public int SystemsGenerated { get; set; }
        public int PlanetsGenerated { get; set; }
        public int MoonsGenerated { get; set; }
        public int StationsGenerated { get; set; }
        public int StargatesGenerated { get; set; }
        public int AsteroidBeltsGenerated { get; set; }
        public int AnomaliesGenerated { get; set; }
        public int WormholesGenerated { get; set; }

        public override string ToString()
        {
            return $"{RegionsGenerated} регионов, {ConstellationsGenerated} констелляций, " +
                   $"{SystemsGenerated} систем, {PlanetsGenerated} планет, " +
                   $"{MoonsGenerated} лун, {StationsGenerated} станций, " +
                   $"{StargatesGenerated} врат, {AsteroidBeltsGenerated} астероидных поясов, " +
                   $"{AnomaliesGenerated} аномалий, {WormholesGenerated} вормхолов";
        }
    }

    public class UniverseStats
    {
        public int Regions { get; set; }
        public int Constellations { get; set; }
        public int SolarSystems { get; set; }
        public int Planets { get; set; }
        public int Stations { get; set; }
        public int Stargates { get; set; }
        public int AsteroidBelts { get; set; }
        public int Anomalies { get; set; }
        public int Wormholes { get; set; }

        public override string ToString()
        {
            return $"{Regions} регионов, {Constellations} констелляций, " +
                   $"{SolarSystems} систем, {Planets} планет, " +
                   $"{Stations} станций, {Stargates} врат, " +
                   $"{AsteroidBelts} астероидных поясов, " +
                   $"{Anomalies} аномалий, {Wormholes} вормхолов";
        }
    }

    public class ProgressTracker
    {
        private readonly int _total;
        private readonly string _unit;
        private readonly ILogger _logger;
        private readonly int _logEvery;
        private DateTime _startTime;
        private int _lastLogged;

        public ProgressTracker(int total, string unit, ILogger logger, int logEvery = 100)
        {
            _total = total;
            _unit = unit;
            _logger = logger;
            _logEvery = logEvery;
            _startTime = DateTime.UtcNow;
            _lastLogged = 0;
        }

        public void Update(int current)
        {
            if (current == _total || (current - _lastLogged) >= _logEvery)
            {
                var elapsed = DateTime.UtcNow - _startTime;
                var percent = (_total > 0) ? (current * 100) / _total : 0;
                var itemsPerSecond = (elapsed.TotalSeconds > 0) ? current / elapsed.TotalSeconds : 0;

                _logger.LogInformation($"📈 Прогресс: {current}/{_total} {_unit} ({percent}%) - " +
                                     $"{itemsPerSecond:F1} {_unit}/сек");
                _lastLogged = current;
            }
        }

        public void Complete()
        {
            var elapsed = DateTime.UtcNow - _startTime;
            _logger.LogInformation($"✅ Завершено за {elapsed.TotalSeconds:F2} секунд");
        }
    }

    // Методы расширения для Random
    public static class RandomExtensions
    {
        public static long NextLong(this Random random, long min, long max)
        {
            // Проверяем, чтобы min был меньше max
            if (min > max)
            {
                (min, max) = (max, min); // Меняем местами
            }

            long range = max - min;

            // Если range = 0, возвращаем min
            if (range == 0) return min;

            // Генерируем случайное 64-битное число
            long randomLong = ((long)random.Next() << 32) | (long)random.Next();

            // Возвращаем число в диапазоне [min, max)
            return Math.Abs(randomLong % range) + min;
        }

        public static bool Chance(this Random random, float probability)
        {
            return random.NextDouble() < probability;
        }

        public static T Choice<T>(this Random random, params T[] options)
        {
            return options[random.Next(options.Length)];
        }
    }
}