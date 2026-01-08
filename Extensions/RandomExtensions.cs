using System.Security.Cryptography;

namespace System
{
    public static class RandomExtensions
    {
        public static long NextLong(this Random random, long min, long max)
        {
            if (min > max)
                throw new ArgumentException("min must be less than or equal to max");

            if (min == max)
                return min;

            // Используем криптографически безопасный генератор для больших чисел
            byte[] buffer = new byte[8];

            // Для больших диапазонов используем более точный метод
            if (max - min > int.MaxValue)
            {
                using (var rng = RandomNumberGenerator.Create())
                {
                    rng.GetBytes(buffer);
                }
                ulong randomValue = BitConverter.ToUInt64(buffer, 0);
                return (long)(randomValue % (ulong)(max - min)) + min;
            }

            return random.Next((int)(max - min)) + min;
        }

        public static T GetRandomItem<T>(this Random random, IList<T> list)
        {
            if (list == null || list.Count == 0)
                throw new ArgumentException("List cannot be null or empty");

            return list[random.Next(list.Count)];
        }

        public static bool Chance(this Random random, double probability)
        {
            if (probability <= 0) return false;
            if (probability >= 1) return true;
            return random.NextDouble() < probability;
        }

        public static T GetRandomItem<T>(this Random random, IList<T> list, Func<T, double> weightSelector)
        {
            if (list == null || list.Count == 0)
                throw new ArgumentException("List cannot be null or empty");

            var totalWeight = list.Sum(weightSelector);
            var randomWeight = random.NextDouble() * totalWeight;

            double cumulative = 0;
            foreach (var item in list)
            {
                cumulative += weightSelector(item);
                if (randomWeight < cumulative)
                    return item;
            }

            return list[0];
        }

        public static float NextFloat(this Random random, float min, float max)
        {
            return (float)(random.NextDouble() * (max - min) + min);
        }
    }
}