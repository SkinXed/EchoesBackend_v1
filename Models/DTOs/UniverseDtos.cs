// Copyright (c) 2024 Echoes MMO. All rights reserved.

using Echoes.API.Models.Enums;
using Echoes.Server.Models.Entities;
using System;
using Echoes.API.Models.Entities.Universe;

using System.Collections.Generic;

namespace Echoes.Server.Models.DTOs
{
    /// <summary>
    /// DTO для аномалии
    /// </summary>
    public class AnomalyDto
    {
        public Guid Id { get; set; }
        public Guid SolarSystemId { get; set; }
        public AnomalyType Type { get; set; }
        public AnomalyDifficulty Difficulty { get; set; }
        public string Name { get; set; }
        public string Description { get; set; }
        public long PositionX { get; set; }
        public long PositionY { get; set; }
        public long PositionZ { get; set; }
        public double Radius { get; set; }
        public string Signature { get; set; }
        public double Durability { get; set; }
        public double CurrentDurability { get; set; }
        public int ScanStrength { get; set; }
        public DateTime ExpiresAt { get; set; }
        public string RewardData { get; set; }
        public DateTime CreatedAt { get; set; }
        public bool IsActive { get; set; }

        /// <summary>
        /// Создать DTO из сущности
        /// </summary>
        public static AnomalyDto FromEntity(Models.Entities.Universe.Anomaly entity)
        {
            if (entity == null) return null;

            return new AnomalyDto
            {
                Id = entity.Id,
                SolarSystemId = entity.SolarSystemId,
                Type = entity.Type,
                Difficulty = entity.Difficulty,
                Name = entity.Name,
                Description = entity.Description,
                PositionX = entity.PositionX,
                PositionY = entity.PositionY,
                PositionZ = entity.PositionZ,
                Radius = entity.Radius,
                Signature = entity.Signature,
                Durability = entity.Durability,
                CurrentDurability = entity.CurrentDurability,
                ScanStrength = entity.ScanStrength,
                ExpiresAt = entity.ExpiresAt,
                RewardData = entity.RewardData,
                CreatedAt = entity.CreatedAt,
                IsActive = entity.IsActive
            };
        }
    }

    /// <summary>
    /// DTO для вормхола
    /// </summary>
    public class WormholeDto
    {
        public Guid Id { get; set; }
        public Guid SourceSystemId { get; set; }
        public Guid TargetSystemId { get; set; }
        public string SourceSystemName { get; set; }
        public string TargetSystemName { get; set; }
        public string Name { get; set; }
        public WormholeClass Class { get; set; }
        public double MaxMass { get; set; }
        public double RemainingMass { get; set; }
        public WormholeShipSize MaxShipSize { get; set; }
        public DateTime ExpiresAt { get; set; }
        public long PositionX { get; set; }
        public long PositionY { get; set; }
        public long PositionZ { get; set; }
        public double Radius { get; set; }
        public double Stability { get; set; }
        public string Signature { get; set; }
        public DateTime CreatedAt { get; set; }
        public DateTime? LastUsedAt { get; set; }
        public int TotalPasses { get; set; }
        public Guid? PairedWormholeId { get; set; }
        public bool IsExitOnly { get; set; }
        public bool IsActive { get; set; }

        /// <summary>
        /// Создать DTO из сущности
        /// </summary>
        public static WormholeDto? FromEntity(Models.Entities.Universe.Wormhole? entity,
            string? sourceSystemName = null, string? targetSystemName = null)
        {
            if (entity == null) return null;

            return new WormholeDto
            {
                Id = entity.Id,
                SourceSystemId = entity.SourceSystemId,
                TargetSystemId = entity.TargetSystemId,
                SourceSystemName = sourceSystemName,
                TargetSystemName = targetSystemName,
                Name = entity.Name,
                Class = entity.Class,
                MaxMass = entity.MaxMass,
                RemainingMass = entity.RemainingMass,
                MaxShipSize = entity.MaxShipSize,
                ExpiresAt = entity.ExpiresAt,
                PositionX = entity.PositionX,
                PositionY = entity.PositionY,
                PositionZ = entity.PositionZ,
                Radius = entity.Radius,
                Stability = entity.Stability,
                Signature = entity.Signature,
                CreatedAt = entity.CreatedAt,
                LastUsedAt = entity.LastUsedAt,
                TotalPasses = entity.TotalPasses,
                PairedWormholeId = entity.PairedWormholeId,
                IsExitOnly = entity.IsExitOnly,
                IsActive = entity.IsActive
            };
        }
    }

    /// <summary>
    /// DTO для звездной системы (обновленный)
    /// </summary>
    public class SolarSystemDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; }
        public long PositionX { get; set; }
        public long PositionY { get; set; }
        public long PositionZ { get; set; }
        public float SecurityStatus { get; set; }
        public string StarClass { get; set; }
        public double StarRadius { get; set; } // Оставляем это свойство в DTO
        public List<PlanetDto> Planets { get; set; } = new();
        public List<StargateDto> Stargates { get; set; } = new();

        // Новые поля
        public List<AnomalyDto> Anomalies { get; set; } = new();
        public List<WormholeDto> Wormholes { get; set; } = new();

        /// <summary>
        /// Количество активных аномалий (для UI)
        /// </summary>
        public int ActiveAnomaliesCount { get; set; }

        /// <summary>
        /// Количество активных вормхолов (для UI)
        /// </summary>
        public int ActiveWormholesCount { get; set; }

        /// <summary>
        /// Создать DTO из сущности
        /// </summary>
        public static SolarSystemDto FromEntity(Echoes.API.Models.Entities.Universe.SolarSystem entity)
        {
            if (entity == null) return null;

            var dto = new SolarSystemDto
            {
                Id = entity.Id,
                Name = entity.Name,
                PositionX = entity.PositionX,
                PositionY = entity.PositionY,
                PositionZ = entity.PositionZ,
                SecurityStatus = entity.SecurityStatus,
                StarClass = entity.StarClass.ToString(), // если StarClass - enum, используем .ToString()
                StarRadius = entity.SolarRadius // Исправлено: было entity.StarRadius, стало entity.SolarRadius
            };

            // Конвертируем планеты
            if (entity.Planets != null)
            {
                foreach (var planet in entity.Planets)
                {
                    dto.Planets.Add(PlanetDto.FromEntity(planet));
                }
            }

            // Конвертируем врата
            if (entity.Stargates != null)
            {
                foreach (var gate in entity.Stargates)
                {
                    dto.Stargates.Add(StargateDto.FromEntity(gate));
                }
            }

            // Конвертируем аномалии
            if (entity.Anomalies != null)
            {
                foreach (var anomaly in entity.Anomalies)
                {
                    dto.Anomalies.Add(AnomalyDto.FromEntity(anomaly));
                }
                dto.ActiveAnomaliesCount = entity.Anomalies.Count(a => a.IsActive);
            }

            // Конвертируем вормхолы
            if (entity.SourceWormholes != null)
            {
                foreach (var wormhole in entity.SourceWormholes)
                {
                    dto.Wormholes.Add(WormholeDto.FromEntity(wormhole, entity.Name, null));
                }
                dto.ActiveWormholesCount = entity.SourceWormholes.Count(w => w.IsActive);
            }

            return dto;
        }
    }

    // Существующие DTO (для полноты)
    public class PlanetDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; }
        public string Type { get; set; }
        public double Radius { get; set; }
        public long OrbitDistance { get; set; }

        public static PlanetDto FromEntity(Planet entity)
        {
            return entity == null ? null : new PlanetDto
            {
                Id = entity.Id,
                Name = entity.Name,
                Type = entity.Type,
                Radius = entity.Radius,
                OrbitDistance = entity.OrbitDistance
            };
        }
    }

    public class StargateDto
    {
        public Guid Id { get; set; }
        public Guid SolarSystemId { get; set; }
        public Guid TargetSystemId { get; set; }
        public string TargetSystemName { get; set; }
        public long PositionX { get; set; }
        public long PositionY { get; set; }
        public long PositionZ { get; set; }

        public static StargateDto FromEntity(Echoes.API.Models.Entities.Universe.Stargate entity)
        {
            return entity == null ? null : new StargateDto
            {
                Id = entity.Id,
                SolarSystemId = entity.SourceSolarSystemId,
                TargetSystemId = entity.DestinationSolarSystemId,
                TargetSystemName = entity.DestinationSolarSystem?.Name,
                PositionX = entity.PositionX,
                PositionY = entity.PositionY,
                PositionZ = entity.PositionZ
            };
        }
    }
}