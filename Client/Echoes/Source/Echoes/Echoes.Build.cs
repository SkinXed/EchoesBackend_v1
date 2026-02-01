using UnrealBuildTool;
using System.IO;

public class Echoes : ModuleRules
{
    public Echoes(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // 1. БАЗОВЫЕ МОДУЛИ
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",
            "HTTP",
            "Json",
            "JsonUtilities",
            "Niagara",
            "UMG",
            "Slate",
            "SlateCore"
        });

        // 2. АВТОМАТИЧЕСКИЙ БИНДИНГ ПУТЕЙ
        // Добавляем корневую директорию модуля
        PublicIncludePaths.Add(ModuleDirectory);

        // Рекурсивно сканируем Core и UI, чтобы все подпапки (Server, Client, Widgets и т.д.) 
        // были доступны по короткому имени файла в #include
        AddAllSubdirectories(Path.Combine(ModuleDirectory, "Core"));
        AddAllSubdirectories(Path.Combine(ModuleDirectory, "UI"));
    }

    // Вспомогательная функция для чистой архитектуры: 
    // Добавляет папку и все её подпапки в пути инклудов
    private void AddAllSubdirectories(string StartDir)
    {
        if (!Directory.Exists(StartDir)) return;

        PublicIncludePaths.Add(StartDir);

        foreach (string Dir in Directory.GetDirectories(StartDir, "*", SearchOption.AllDirectories))
        {
            PublicIncludePaths.Add(Dir);
        }
    }
}