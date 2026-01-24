// Copyright (c) 2024 Echoes MMO. All rights reserved.

using Echoes.API.Models.Entities.Universe;
using Echoes.API.Models.Enums;
using System;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.Server.Models.Entities.Universe
{
    /// <summary>
    /// Космическая аномалия - динамический контент в системе
    /// </summary>
    [Table("anomalies")]
    public class Anomaly
    {
        /// <summary>
        /// Уникальный идентификатор аномалии
        /// </summary>
        [Key]
        [Column("id")]
        public Guid Id { get; set; }

        /// <summary>
        /// ID солнечной системы, в которой находится аномалия
        /// </summary>
        [Column("solar_system_id")]
        public Guid SolarSystemId { get; set; }

        /// <summary>
        /// Навигационное свойство к системе
        /// </summary>
        [ForeignKey("SolarSystemId")]
        public virtual SolarSystem SolarSystem { get; set; } = null!;

        /// <summary>
        /// Тип аномалии
        /// </summary>
        [Column("type")]
        public AnomalyType Type { get; set; }

        /// <summary>
        /// Сложность аномалии
        /// </summary>
        [Column("difficulty")]
        public AnomalyDifficulty Difficulty { get; set; }

        /// <summary>
        /// Название аномалии (сгенерированное)
        /// </summary>
        [Column("name")]
        [MaxLength(100)]
        public string Name { get; set; } = string.Empty;

        /// <summary>
        /// Описание аномалии (для UI)
        /// </summary>
        [Column("description")]
        [MaxLength(500)]
        public string Description { get; set; } = string.Empty;

        /// <summary>
        /// Позиция X в системе (в метрах, int64 для масштаба космоса)
        /// </summary>
        [Column("position_x")]
        public long PositionX { get; set; }

        /// <summary>
        /// Позиция Y в системе
        /// </summary>
        [Column("position_y")]
        public long PositionY { get; set; }

        /// <summary>
        /// Позиция Z в системе
        /// </summary>
        [Column("position_z")]
        public long PositionZ { get; set; }

        /// <summary>
        /// Радиус аномалии (в метрах)
        /// </summary>
        [Column("radius")]
        public double Radius { get; set; }

        /// <summary>
        /// Время истечения аномалии (когда она исчезнет, если не пройдена)
        /// </summary>
        [Column("expires_at")]
        public DateTime ExpiresAt { get; set; }

        /// <summary>
        /// Сигнатура сканирования (например: "ABC-123")
        /// </summary>
        [Column("signature")]
        [MaxLength(20)]
        public string Signature { get; set; } = string.Empty;

        /// <summary>
        /// Прочность аномалии (HP для боевых, ресурсы для добычи)
        /// </summary>
        [Column("durability")]
        public double Durability { get; set; }

        /// <summary>
        /// Текущая прочность
        /// </summary>
        [Column("current_durability")]
        public double CurrentDurability { get; set; }

        /// <summary>
        /// Уровень сканирования для обнаружения (1-10)
        /// </summary>
        [Column("scan_strength")]
        public int ScanStrength { get; set; }

        /// <summary>
        /// Награда за прохождение аномалии (JSON с предметами)
        /// </summary>
        [Column("reward_data")]
        public string RewardData { get; set; } = string.Empty;

        /// <summary>
        /// Время создания аномалии
        /// </summary>
        [Column("created_at")]
        public DateTime CreatedAt { get; set; }

        /// <summary>
        /// Время последнего обновления
        /// </summary>
        [Column("updated_at")]
        public DateTime UpdatedAt { get; set; }

        /// <summary>
        /// Конструктор по умолчанию
        /// </summary>
        public Anomaly()
        {
            Id = Guid.NewGuid();
            CreatedAt = DateTime.UtcNow;
            UpdatedAt = DateTime.UtcNow;
            ExpiresAt = DateTime.UtcNow.AddHours(24); // Аномалии живут 24 часа
            CurrentDurability = Durability;
        }

        /// <summary>
        /// Проверить, активна ли аномалия
        /// </summary>
        public bool IsActive =>
            CurrentDurability > 0 &&
            ExpiresAt > DateTime.UtcNow;
    }
}