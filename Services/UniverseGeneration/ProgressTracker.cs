internal class ProgressTracker
{
    private int regionCount;
    private string v;
    private ILogger logger;
    private int logProgressEveryNRegions;

    public ProgressTracker(int regionCount, string v, ILogger logger, int logProgressEveryNRegions)
    {
        this.regionCount = regionCount;
        this.v = v;
        this.logger = logger;
        this.logProgressEveryNRegions = logProgressEveryNRegions;
    }
}