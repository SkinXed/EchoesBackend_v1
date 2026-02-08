// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WorldObjectManager.h"
#include "EWorldContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeWorldObjectManager() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_AEWorldContainer_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UWorldObjectManager();
ECHOES_API UClass* Z_Construct_UClass_UWorldObjectManager_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FWorldObjectData();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UWorldObjectManager Function GetContainerCount ***************************
struct Z_Construct_UFunction_UWorldObjectManager_GetContainerCount_Statics
{
	struct WorldObjectManager_eventGetContainerCount_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WorldObject" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get count of spawned containers\n\x09 * @return Number of containers currently spawned\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/WorldObjectManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get count of spawned containers\n@return Number of containers currently spawned" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UWorldObjectManager_GetContainerCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldObjectManager_eventGetContainerCount_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWorldObjectManager_GetContainerCount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldObjectManager_GetContainerCount_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldObjectManager_GetContainerCount_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWorldObjectManager_GetContainerCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWorldObjectManager, nullptr, "GetContainerCount", Z_Construct_UFunction_UWorldObjectManager_GetContainerCount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldObjectManager_GetContainerCount_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWorldObjectManager_GetContainerCount_Statics::WorldObjectManager_eventGetContainerCount_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldObjectManager_GetContainerCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWorldObjectManager_GetContainerCount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWorldObjectManager_GetContainerCount_Statics::WorldObjectManager_eventGetContainerCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWorldObjectManager_GetContainerCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWorldObjectManager_GetContainerCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWorldObjectManager::execGetContainerCount)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetContainerCount();
	P_NATIVE_END;
}
// ********** End Class UWorldObjectManager Function GetContainerCount *****************************

// ********** Begin Class UWorldObjectManager Function GetSpawnedContainers ************************
struct Z_Construct_UFunction_UWorldObjectManager_GetSpawnedContainers_Statics
{
	struct WorldObjectManager_eventGetSpawnedContainers_Parms
	{
		TArray<AEWorldContainer*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WorldObject" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get all spawned world objects\n\x09 * @return Array of spawned container actors\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/WorldObjectManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get all spawned world objects\n@return Array of spawned container actors" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UWorldObjectManager_GetSpawnedContainers_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AEWorldContainer_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UWorldObjectManager_GetSpawnedContainers_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldObjectManager_eventGetSpawnedContainers_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWorldObjectManager_GetSpawnedContainers_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldObjectManager_GetSpawnedContainers_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldObjectManager_GetSpawnedContainers_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldObjectManager_GetSpawnedContainers_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWorldObjectManager_GetSpawnedContainers_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWorldObjectManager, nullptr, "GetSpawnedContainers", Z_Construct_UFunction_UWorldObjectManager_GetSpawnedContainers_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldObjectManager_GetSpawnedContainers_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWorldObjectManager_GetSpawnedContainers_Statics::WorldObjectManager_eventGetSpawnedContainers_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldObjectManager_GetSpawnedContainers_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWorldObjectManager_GetSpawnedContainers_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWorldObjectManager_GetSpawnedContainers_Statics::WorldObjectManager_eventGetSpawnedContainers_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWorldObjectManager_GetSpawnedContainers()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWorldObjectManager_GetSpawnedContainers_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWorldObjectManager::execGetSpawnedContainers)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<AEWorldContainer*>*)Z_Param__Result=P_THIS->GetSpawnedContainers();
	P_NATIVE_END;
}
// ********** End Class UWorldObjectManager Function GetSpawnedContainers **************************

// ********** Begin Class UWorldObjectManager Function ServerOnly_LoadWorldObjects *****************
struct Z_Construct_UFunction_UWorldObjectManager_ServerOnly_LoadWorldObjects_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WorldObject" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Load world objects from backend and spawn them\n\x09 * Can be called manually or automatically on BeginPlay\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/WorldObjectManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Load world objects from backend and spawn them\nCan be called manually or automatically on BeginPlay" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWorldObjectManager_ServerOnly_LoadWorldObjects_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWorldObjectManager, nullptr, "ServerOnly_LoadWorldObjects", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldObjectManager_ServerOnly_LoadWorldObjects_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWorldObjectManager_ServerOnly_LoadWorldObjects_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UWorldObjectManager_ServerOnly_LoadWorldObjects()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWorldObjectManager_ServerOnly_LoadWorldObjects_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWorldObjectManager::execServerOnly_LoadWorldObjects)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_LoadWorldObjects();
	P_NATIVE_END;
}
// ********** End Class UWorldObjectManager Function ServerOnly_LoadWorldObjects *******************

// ********** Begin Class UWorldObjectManager Function ServerOnly_QueryBackend *********************
struct Z_Construct_UFunction_UWorldObjectManager_ServerOnly_QueryBackend_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Query backend for world objects in this system\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/WorldObjectManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Query backend for world objects in this system" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWorldObjectManager_ServerOnly_QueryBackend_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWorldObjectManager, nullptr, "ServerOnly_QueryBackend", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldObjectManager_ServerOnly_QueryBackend_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWorldObjectManager_ServerOnly_QueryBackend_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UWorldObjectManager_ServerOnly_QueryBackend()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWorldObjectManager_ServerOnly_QueryBackend_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWorldObjectManager::execServerOnly_QueryBackend)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_QueryBackend();
	P_NATIVE_END;
}
// ********** End Class UWorldObjectManager Function ServerOnly_QueryBackend ***********************

// ********** Begin Class UWorldObjectManager Function ServerOnly_SpawnContainer *******************
struct Z_Construct_UFunction_UWorldObjectManager_ServerOnly_SpawnContainer_Statics
{
	struct WorldObjectManager_eventServerOnly_SpawnContainer_Parms
	{
		FWorldObjectData Data;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Spawn a container from database data\n\x09 * @param Data - World object data from backend\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/WorldObjectManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spawn a container from database data\n@param Data - World object data from backend" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Data_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Data;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWorldObjectManager_ServerOnly_SpawnContainer_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldObjectManager_eventServerOnly_SpawnContainer_Parms, Data), Z_Construct_UScriptStruct_FWorldObjectData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Data_MetaData), NewProp_Data_MetaData) }; // 3328031925
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWorldObjectManager_ServerOnly_SpawnContainer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldObjectManager_ServerOnly_SpawnContainer_Statics::NewProp_Data,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldObjectManager_ServerOnly_SpawnContainer_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWorldObjectManager_ServerOnly_SpawnContainer_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWorldObjectManager, nullptr, "ServerOnly_SpawnContainer", Z_Construct_UFunction_UWorldObjectManager_ServerOnly_SpawnContainer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldObjectManager_ServerOnly_SpawnContainer_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWorldObjectManager_ServerOnly_SpawnContainer_Statics::WorldObjectManager_eventServerOnly_SpawnContainer_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldObjectManager_ServerOnly_SpawnContainer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWorldObjectManager_ServerOnly_SpawnContainer_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWorldObjectManager_ServerOnly_SpawnContainer_Statics::WorldObjectManager_eventServerOnly_SpawnContainer_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWorldObjectManager_ServerOnly_SpawnContainer()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWorldObjectManager_ServerOnly_SpawnContainer_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWorldObjectManager::execServerOnly_SpawnContainer)
{
	P_GET_STRUCT_REF(FWorldObjectData,Z_Param_Out_Data);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_SpawnContainer(Z_Param_Out_Data);
	P_NATIVE_END;
}
// ********** End Class UWorldObjectManager Function ServerOnly_SpawnContainer *********************

// ********** Begin Class UWorldObjectManager ******************************************************
void UWorldObjectManager::StaticRegisterNativesUWorldObjectManager()
{
	UClass* Class = UWorldObjectManager::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetContainerCount", &UWorldObjectManager::execGetContainerCount },
		{ "GetSpawnedContainers", &UWorldObjectManager::execGetSpawnedContainers },
		{ "ServerOnly_LoadWorldObjects", &UWorldObjectManager::execServerOnly_LoadWorldObjects },
		{ "ServerOnly_QueryBackend", &UWorldObjectManager::execServerOnly_QueryBackend },
		{ "ServerOnly_SpawnContainer", &UWorldObjectManager::execServerOnly_SpawnContainer },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UWorldObjectManager;
UClass* UWorldObjectManager::GetPrivateStaticClass()
{
	using TClass = UWorldObjectManager;
	if (!Z_Registration_Info_UClass_UWorldObjectManager.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("WorldObjectManager"),
			Z_Registration_Info_UClass_UWorldObjectManager.InnerSingleton,
			StaticRegisterNativesUWorldObjectManager,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UWorldObjectManager.InnerSingleton;
}
UClass* Z_Construct_UClass_UWorldObjectManager_NoRegister()
{
	return UWorldObjectManager::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UWorldObjectManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Echoes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UWorldObjectManager\n * \n * Manages world object persistence for a solar system\n * Server-only component that queries backend for existing world objects on startup\n * and spawns them back into the world\n * \n * Usage:\n * 1. Attach to GameMode or World State actor\n * 2. Set SystemId to current solar system\n * 3. On BeginPlay, queries backend and spawns all containers/debris\n * 4. New containers auto-register themselves via AEWorldContainer\n * \n * Features:\n * - Queries backend for existing world objects on startup\n * - Spawns containers from database\n * - Tracks spawned objects for management\n * - Can manually trigger refresh\n */" },
#endif
		{ "IncludePath", "Core/Server/Managers/WorldObjectManager.h" },
		{ "ModuleRelativePath", "Core/Server/Managers/WorldObjectManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UWorldObjectManager\n\nManages world object persistence for a solar system\nServer-only component that queries backend for existing world objects on startup\nand spawns them back into the world\n\nUsage:\n1. Attach to GameMode or World State actor\n2. Set SystemId to current solar system\n3. On BeginPlay, queries backend and spawns all containers/debris\n4. New containers auto-register themselves via AEWorldContainer\n\nFeatures:\n- Queries backend for existing world objects on startup\n- Spawns containers from database\n- Tracks spawned objects for management\n- Can manually trigger refresh" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ApiBaseUrl_MetaData[] = {
		{ "Category", "WorldObject|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Backend API base URL */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/WorldObjectManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Backend API base URL" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerSecret_MetaData[] = {
		{ "Category", "WorldObject|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Server secret for X-Server-Secret header authentication */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/WorldObjectManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server secret for X-Server-Secret header authentication" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SystemId_MetaData[] = {
		{ "Category", "WorldObject|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Solar system ID to query world objects for */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/WorldObjectManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Solar system ID to query world objects for" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContainerClass_MetaData[] = {
		{ "Category", "WorldObject|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Container actor class to spawn */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/WorldObjectManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Container actor class to spawn" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoLoadOnBeginPlay_MetaData[] = {
		{ "Category", "WorldObject|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether to auto-load on BeginPlay */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/WorldObjectManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether to auto-load on BeginPlay" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnedContainers_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** List of containers spawned by this manager */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/WorldObjectManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "List of containers spawned by this manager" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ApiBaseUrl;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerSecret;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SystemId;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ContainerClass;
	static void NewProp_bAutoLoadOnBeginPlay_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoLoadOnBeginPlay;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnedContainers_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SpawnedContainers;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UWorldObjectManager_GetContainerCount, "GetContainerCount" }, // 1966106232
		{ &Z_Construct_UFunction_UWorldObjectManager_GetSpawnedContainers, "GetSpawnedContainers" }, // 235674206
		{ &Z_Construct_UFunction_UWorldObjectManager_ServerOnly_LoadWorldObjects, "ServerOnly_LoadWorldObjects" }, // 2667887372
		{ &Z_Construct_UFunction_UWorldObjectManager_ServerOnly_QueryBackend, "ServerOnly_QueryBackend" }, // 330765440
		{ &Z_Construct_UFunction_UWorldObjectManager_ServerOnly_SpawnContainer, "ServerOnly_SpawnContainer" }, // 1270201959
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWorldObjectManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UWorldObjectManager_Statics::NewProp_ApiBaseUrl = { "ApiBaseUrl", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWorldObjectManager, ApiBaseUrl), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ApiBaseUrl_MetaData), NewProp_ApiBaseUrl_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UWorldObjectManager_Statics::NewProp_ServerSecret = { "ServerSecret", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWorldObjectManager, ServerSecret), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerSecret_MetaData), NewProp_ServerSecret_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UWorldObjectManager_Statics::NewProp_SystemId = { "SystemId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWorldObjectManager, SystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SystemId_MetaData), NewProp_SystemId_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UWorldObjectManager_Statics::NewProp_ContainerClass = { "ContainerClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWorldObjectManager, ContainerClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AEWorldContainer_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContainerClass_MetaData), NewProp_ContainerClass_MetaData) };
void Z_Construct_UClass_UWorldObjectManager_Statics::NewProp_bAutoLoadOnBeginPlay_SetBit(void* Obj)
{
	((UWorldObjectManager*)Obj)->bAutoLoadOnBeginPlay = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UWorldObjectManager_Statics::NewProp_bAutoLoadOnBeginPlay = { "bAutoLoadOnBeginPlay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UWorldObjectManager), &Z_Construct_UClass_UWorldObjectManager_Statics::NewProp_bAutoLoadOnBeginPlay_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoLoadOnBeginPlay_MetaData), NewProp_bAutoLoadOnBeginPlay_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWorldObjectManager_Statics::NewProp_SpawnedContainers_Inner = { "SpawnedContainers", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AEWorldContainer_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UWorldObjectManager_Statics::NewProp_SpawnedContainers = { "SpawnedContainers", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWorldObjectManager, SpawnedContainers), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnedContainers_MetaData), NewProp_SpawnedContainers_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UWorldObjectManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWorldObjectManager_Statics::NewProp_ApiBaseUrl,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWorldObjectManager_Statics::NewProp_ServerSecret,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWorldObjectManager_Statics::NewProp_SystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWorldObjectManager_Statics::NewProp_ContainerClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWorldObjectManager_Statics::NewProp_bAutoLoadOnBeginPlay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWorldObjectManager_Statics::NewProp_SpawnedContainers_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWorldObjectManager_Statics::NewProp_SpawnedContainers,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWorldObjectManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UWorldObjectManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWorldObjectManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UWorldObjectManager_Statics::ClassParams = {
	&UWorldObjectManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UWorldObjectManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UWorldObjectManager_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UWorldObjectManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UWorldObjectManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UWorldObjectManager()
{
	if (!Z_Registration_Info_UClass_UWorldObjectManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWorldObjectManager.OuterSingleton, Z_Construct_UClass_UWorldObjectManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UWorldObjectManager.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UWorldObjectManager);
UWorldObjectManager::~UWorldObjectManager() {}
// ********** End Class UWorldObjectManager ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_WorldObjectManager_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UWorldObjectManager, UWorldObjectManager::StaticClass, TEXT("UWorldObjectManager"), &Z_Registration_Info_UClass_UWorldObjectManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWorldObjectManager), 3520839232U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_WorldObjectManager_h__Script_Echoes_3856592902(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_WorldObjectManager_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_WorldObjectManager_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
