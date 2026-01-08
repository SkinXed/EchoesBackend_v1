// /Services/UniverseGeneration/SeedManager.cs
using System.Security.Cryptography;
using System.Text;

namespace Echoes.API.Services.UniverseGeneration
{
    public interface ISeedManager
    {
        int GetSeedValue(string seed);
        Random GetDeterministicRandom(string seed);
    }

    public class SeedManager : ISeedManager
    {
        public int GetSeedValue(string seed)
        {
            // Простой хэш для начала
            return seed.GetHashCode();
        }

        public Random GetDeterministicRandom(string seed)
        {
            return new Random(GetSeedValue(seed));
        }
    }
}