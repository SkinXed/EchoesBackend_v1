namespace Echoes.API.Models.Entities.Universe
{
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
            return $"{Regions} regions, {Constellations} constellations, {SolarSystems} systems, " +
                   $"{Planets} planets, {Stations} stations, {Stargates} stargates, {AsteroidBelts} asteroid belts";
        }
    }
}