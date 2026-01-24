// Copyright (c) 2024 Echoes MMO. All rights reserved.

using Echoes.API.Models.Entities.Universe;
using Echoes.API.Models.Enums;
using Echoes.Server.Models.Entities;
using System;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.Server.Models.Entities.Universe
{
    /// <summary>
    /// Вормхол - нестабильная связь между системами
    /// </summary>
    [Table("wormholes")]
    public class Wormhole
    {
        /// <summary>
        /// Уникальный идентификатор вормхола
        /// </summary>
        [Key]
        [Column("id")]
        public Guid Id { get; set; }

        /// <summary>
        /// ID системы-источника (вход)
        /// </summary>
        [Column("source_system_id")]
        public Guid SourceSystemId { get; set; }

        /// <summary>
        /// Навигационное свойство к системе-источнику
        /// </summary>
        [ForeignKey("SourceSystemId")]
        public virtual SolarSystem SourceSystem { get; set; } = null!;

        /// <summary>
        /// ID системы-назначения (выход)
        /// </summary>
        [Column("target_system_id")]
        public Guid TargetSystemId { get; set; }

        /// <summary>
        /// Навигационное свойство к системе-назначению
        /// </summary>
        [ForeignKey("TargetSystemId")]
        public virtual SolarSystem TargetSystem { get; set; } = null!;

        /// <summary>
        /// Название вормхола (например: "K162", "R051", "X702")
        /// </summary>
        [Column("name")]
        [MaxLength(50)]
        public string Name { get; set; } = string.Empty;

        /// <summary>
        /// Класс вормхола
        /// </summary>
        [Column("class")]
        public WormholeClass Class { get; set; }

        /// <summary>
        /// Максимальная масса, которую может пройти вормхол (в мегатоннах)
        /// </summary>
        [Column("max_mass")]
        public double MaxMass { get; set; }

        /// <summary>
        /// Оставшаяся масса (уменьшается при проходе кораблей)
        /// </summary>
        [Column("remaining_mass")]
        public double RemainingMass { get; set; }

        /// <summary>
        /// Максимальный размер корабля, который может пройти
        /// </summary>
        [Column("max_ship_size")]
        public WormholeShipSize MaxShipSize { get; set; }

        /// <summary>
        /// Время истечения вормхола (когда он схлопнется)
        /// </summary>
        [Column("expires_at")]
        public DateTime ExpiresAt { get; set; }

        /// <summary>
        /// Позиция X в системе-источнике
        /// </summary>
        [Column("position_x")]
        public long PositionX { get; set; }

        /// <summary>
        /// Позиция Y в системе-источнике
        /// </summary>
        [Column("position_y")]
        public long PositionY { get; set; }

        /// <summary>
        /// Позиция Z в системе-источнике
        /// </summary>
        [Column("position_z")]
        public long PositionZ { get; set; }

        /// <summary>
        /// Радиус вормхола (в метрах)
        /// </summary>
        [Column("radius")]
        public double Radius { get; set; }

        /// <summary>
        /// Стабильность вормхола (1.0 = полностью стабилен)
        /// </summary>
        [Column("stability")]
        public double Stability { get; set; }

        /// <summary>
        /// Сигнатура сканирования
        /// </summary>
        [Column("signature")]
        [MaxLength(20)]
        public string Signature { get; set; } = string.Empty;

        /// <summary>
        /// Время создания вормхола
        /// </summary>
        [Column("created_at")]
        public DateTime CreatedAt { get; set; }

        /// <summary>
        /// Время последнего прохода через вормхол
        /// </summary>
        [Column("last_used_at")]
        public DateTime? LastUsedAt { get; set; }

        /// <summary>
        /// Количество проходов через этот вормхол
        /// </summary>
        [Column("total_passes")]
        public int TotalPasses { get; set; }

        /// <summary>
        /// ID вормхола на выходной стороне (парный вормхол)
        /// </summary>
        [Column("paired_wormhole_id")]
        public Guid? PairedWormholeId { get; set; }

        /// <summary>
        /// Флаг, указывающий что это выходной вормхол (K162)
        /// </summary>
        [Column("is_exit_only")]
        public bool IsExitOnly { get; set; }

        /// <summary>
        /// Конструктор по умолчанию
        /// </summary>
        public Wormhole()
        {
            Id = Guid.NewGuid();
            CreatedAt = DateTime.UtcNow;
            Stability = 1.0;
            TotalPasses = 0;
        }

        /// <summary>
        /// Проверить, активен ли вормхол
        /// </summary>
        public bool IsActive =>
            RemainingMass > 0 &&
            Stability > 0.1 &&
            ExpiresAt > DateTime.UtcNow;

        /// <summary>
        /// Проверить, может ли корабль с указанной массой пройти
        /// </summary>
        public bool CanShipPass(double shipMass, WormholeShipSize shipSize)
        {
            return shipMass <= RemainingMass &&
                   (int)shipSize <= (int)MaxShipSize &&
                   IsActive;
        }

        /// <summary>
        /// Обработать проход корабля
        /// </summary>
        public void ProcessShipPass(double shipMass)
        {
            if (!CanShipPass(shipMass, WormholeShipSize.Small))
                throw new InvalidOperationException("Корабль не может пройти через вормхол");

            RemainingMass -= shipMass;
            LastUsedAt = DateTime.UtcNow;
            TotalPasses++;

            // Уменьшаем стабильность при каждом проходе
            Stability = Math.Max(0.1, Stability - 0.05);

            UpdatedAt = DateTime.UtcNow;
        }

        /// <summary>
        /// Время обновления (для EF Core)
        /// </summary>
        [Column("updated_at")]
        public DateTime UpdatedAt { get; set; }
        
        [ForeignKey("PairedWormholeId")]
        public virtual Wormhole? PairedWormhole { get; set; }
    }
}