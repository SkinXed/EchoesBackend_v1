// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EWorldContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEWorldContainer() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ECHOES_API UClass* Z_Construct_UClass_AEWorldContainer();
ECHOES_API UClass* Z_Construct_UClass_AEWorldContainer_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FWorldObjectData();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FWorldObjectData **************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FWorldObjectData;
class UScriptStruct* FWorldObjectData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FWorldObjectData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FWorldObjectData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FWorldObjectData, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("WorldObjectData"));
	}
	return Z_Registration_Info_UScriptStruct_FWorldObjectData.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FWorldObjectData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Structure for world object data\n * Mirrors RegisterWorldObjectRequest and WorldObjectResponse from backend\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Structure for world object data\nMirrors RegisterWorldObjectRequest and WorldObjectResponse from backend" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "WorldObject" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unique ID for this world object (from backend) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unique ID for this world object (from backend)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TemplateId_MetaData[] = {
		{ "Category", "WorldObject" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Template ID for the object type */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Template ID for the object type" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SystemId_MetaData[] = {
		{ "Category", "WorldObject" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Solar system ID */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Solar system ID" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[] = {
		{ "Category", "WorldObject" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Position in 3D space */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Position in 3D space" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "Category", "WorldObject" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Rotation (quaternion) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rotation (quaternion)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryJson_MetaData[] = {
		{ "Category", "WorldObject" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** JSON serialized inventory contents */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "JSON serialized inventory contents" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExpirationTime_MetaData[] = {
		{ "Category", "WorldObject" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Expiration time (optional) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Expiration time (optional)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Id;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TemplateId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SystemId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InventoryJson;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ExpirationTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FWorldObjectData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FWorldObjectData_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWorldObjectData, Id), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FWorldObjectData_Statics::NewProp_TemplateId = { "TemplateId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWorldObjectData, TemplateId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TemplateId_MetaData), NewProp_TemplateId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FWorldObjectData_Statics::NewProp_SystemId = { "SystemId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWorldObjectData, SystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SystemId_MetaData), NewProp_SystemId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FWorldObjectData_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWorldObjectData, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Position_MetaData), NewProp_Position_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FWorldObjectData_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWorldObjectData, Rotation), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FWorldObjectData_Statics::NewProp_InventoryJson = { "InventoryJson", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWorldObjectData, InventoryJson), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryJson_MetaData), NewProp_InventoryJson_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FWorldObjectData_Statics::NewProp_ExpirationTime = { "ExpirationTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWorldObjectData, ExpirationTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExpirationTime_MetaData), NewProp_ExpirationTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FWorldObjectData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWorldObjectData_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWorldObjectData_Statics::NewProp_TemplateId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWorldObjectData_Statics::NewProp_SystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWorldObjectData_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWorldObjectData_Statics::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWorldObjectData_Statics::NewProp_InventoryJson,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWorldObjectData_Statics::NewProp_ExpirationTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWorldObjectData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FWorldObjectData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"WorldObjectData",
	Z_Construct_UScriptStruct_FWorldObjectData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWorldObjectData_Statics::PropPointers),
	sizeof(FWorldObjectData),
	alignof(FWorldObjectData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWorldObjectData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FWorldObjectData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FWorldObjectData()
{
	if (!Z_Registration_Info_UScriptStruct_FWorldObjectData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FWorldObjectData.InnerSingleton, Z_Construct_UScriptStruct_FWorldObjectData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FWorldObjectData.InnerSingleton;
}
// ********** End ScriptStruct FWorldObjectData ****************************************************

// ********** Begin Class AEWorldContainer Function GetObjectId ************************************
struct Z_Construct_UFunction_AEWorldContainer_GetObjectId_Statics
{
	struct EWorldContainer_eventGetObjectId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WorldObject" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the backend object ID\n\x09 * @return Object ID in backend database\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the backend object ID\n@return Object ID in backend database" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEWorldContainer_GetObjectId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EWorldContainer_eventGetObjectId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEWorldContainer_GetObjectId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEWorldContainer_GetObjectId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEWorldContainer_GetObjectId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEWorldContainer_GetObjectId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEWorldContainer, nullptr, "GetObjectId", Z_Construct_UFunction_AEWorldContainer_GetObjectId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEWorldContainer_GetObjectId_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEWorldContainer_GetObjectId_Statics::EWorldContainer_eventGetObjectId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEWorldContainer_GetObjectId_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEWorldContainer_GetObjectId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEWorldContainer_GetObjectId_Statics::EWorldContainer_eventGetObjectId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEWorldContainer_GetObjectId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEWorldContainer_GetObjectId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEWorldContainer::execGetObjectId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetObjectId();
	P_NATIVE_END;
}
// ********** End Class AEWorldContainer Function GetObjectId **************************************

// ********** Begin Class AEWorldContainer Function GetWorldObjectData *****************************
struct Z_Construct_UFunction_AEWorldContainer_GetWorldObjectData_Statics
{
	struct EWorldContainer_eventGetWorldObjectData_Parms
	{
		FWorldObjectData ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WorldObject" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get world object data for this container\n\x09 * @return Current world object data\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get world object data for this container\n@return Current world object data" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEWorldContainer_GetWorldObjectData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EWorldContainer_eventGetWorldObjectData_Parms, ReturnValue), Z_Construct_UScriptStruct_FWorldObjectData, METADATA_PARAMS(0, nullptr) }; // 3328031925
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEWorldContainer_GetWorldObjectData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEWorldContainer_GetWorldObjectData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEWorldContainer_GetWorldObjectData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEWorldContainer_GetWorldObjectData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEWorldContainer, nullptr, "GetWorldObjectData", Z_Construct_UFunction_AEWorldContainer_GetWorldObjectData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEWorldContainer_GetWorldObjectData_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEWorldContainer_GetWorldObjectData_Statics::EWorldContainer_eventGetWorldObjectData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEWorldContainer_GetWorldObjectData_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEWorldContainer_GetWorldObjectData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEWorldContainer_GetWorldObjectData_Statics::EWorldContainer_eventGetWorldObjectData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEWorldContainer_GetWorldObjectData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEWorldContainer_GetWorldObjectData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEWorldContainer::execGetWorldObjectData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FWorldObjectData*)Z_Param__Result=P_THIS->GetWorldObjectData();
	P_NATIVE_END;
}
// ********** End Class AEWorldContainer Function GetWorldObjectData *******************************

// ********** Begin Class AEWorldContainer Function InitializeFromDatabase *************************
struct Z_Construct_UFunction_AEWorldContainer_InitializeFromDatabase_Statics
{
	struct EWorldContainer_eventInitializeFromDatabase_Parms
	{
		FWorldObjectData Data;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WorldObject" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initialize container from database data\n\x09 * Called by WorldManager when spawning from database\n\x09 * @param Data - World object data from database\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize container from database data\nCalled by WorldManager when spawning from database\n@param Data - World object data from database" },
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEWorldContainer_InitializeFromDatabase_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EWorldContainer_eventInitializeFromDatabase_Parms, Data), Z_Construct_UScriptStruct_FWorldObjectData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Data_MetaData), NewProp_Data_MetaData) }; // 3328031925
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEWorldContainer_InitializeFromDatabase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEWorldContainer_InitializeFromDatabase_Statics::NewProp_Data,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEWorldContainer_InitializeFromDatabase_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEWorldContainer_InitializeFromDatabase_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEWorldContainer, nullptr, "InitializeFromDatabase", Z_Construct_UFunction_AEWorldContainer_InitializeFromDatabase_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEWorldContainer_InitializeFromDatabase_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEWorldContainer_InitializeFromDatabase_Statics::EWorldContainer_eventInitializeFromDatabase_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEWorldContainer_InitializeFromDatabase_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEWorldContainer_InitializeFromDatabase_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEWorldContainer_InitializeFromDatabase_Statics::EWorldContainer_eventInitializeFromDatabase_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEWorldContainer_InitializeFromDatabase()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEWorldContainer_InitializeFromDatabase_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEWorldContainer::execInitializeFromDatabase)
{
	P_GET_STRUCT_REF(FWorldObjectData,Z_Param_Out_Data);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeFromDatabase(Z_Param_Out_Data);
	P_NATIVE_END;
}
// ********** End Class AEWorldContainer Function InitializeFromDatabase ***************************

// ********** Begin Class AEWorldContainer Function ServerOnly_RegisterToBackend *******************
struct Z_Construct_UFunction_AEWorldContainer_ServerOnly_RegisterToBackend_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Register this container to backend database\n\x09 * Called automatically in BeginPlay for new containers\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Register this container to backend database\nCalled automatically in BeginPlay for new containers" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEWorldContainer_ServerOnly_RegisterToBackend_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEWorldContainer, nullptr, "ServerOnly_RegisterToBackend", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEWorldContainer_ServerOnly_RegisterToBackend_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEWorldContainer_ServerOnly_RegisterToBackend_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AEWorldContainer_ServerOnly_RegisterToBackend()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEWorldContainer_ServerOnly_RegisterToBackend_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEWorldContainer::execServerOnly_RegisterToBackend)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_RegisterToBackend();
	P_NATIVE_END;
}
// ********** End Class AEWorldContainer Function ServerOnly_RegisterToBackend *********************

// ********** Begin Class AEWorldContainer Function ServerOnly_SendInventoryUpdate *****************
struct Z_Construct_UFunction_AEWorldContainer_ServerOnly_SendInventoryUpdate_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Send inventory update to backend\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Send inventory update to backend" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEWorldContainer_ServerOnly_SendInventoryUpdate_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEWorldContainer, nullptr, "ServerOnly_SendInventoryUpdate", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEWorldContainer_ServerOnly_SendInventoryUpdate_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEWorldContainer_ServerOnly_SendInventoryUpdate_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AEWorldContainer_ServerOnly_SendInventoryUpdate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEWorldContainer_ServerOnly_SendInventoryUpdate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEWorldContainer::execServerOnly_SendInventoryUpdate)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_SendInventoryUpdate();
	P_NATIVE_END;
}
// ********** End Class AEWorldContainer Function ServerOnly_SendInventoryUpdate *******************

// ********** Begin Class AEWorldContainer Function ServerOnly_UnregisterFromBackend ***************
struct Z_Construct_UFunction_AEWorldContainer_ServerOnly_UnregisterFromBackend_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Unregister this container from backend database\n\x09 * Called optionally in EndPlay if needed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unregister this container from backend database\nCalled optionally in EndPlay if needed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEWorldContainer_ServerOnly_UnregisterFromBackend_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEWorldContainer, nullptr, "ServerOnly_UnregisterFromBackend", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEWorldContainer_ServerOnly_UnregisterFromBackend_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEWorldContainer_ServerOnly_UnregisterFromBackend_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AEWorldContainer_ServerOnly_UnregisterFromBackend()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEWorldContainer_ServerOnly_UnregisterFromBackend_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEWorldContainer::execServerOnly_UnregisterFromBackend)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_UnregisterFromBackend();
	P_NATIVE_END;
}
// ********** End Class AEWorldContainer Function ServerOnly_UnregisterFromBackend *****************

// ********** Begin Class AEWorldContainer Function ServerOnly_UpdateInventory *********************
struct Z_Construct_UFunction_AEWorldContainer_ServerOnly_UpdateInventory_Statics
{
	struct EWorldContainer_eventServerOnly_UpdateInventory_Parms
	{
		FString NewInventoryJson;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WorldObject" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Update container inventory and sync to backend\n\x09 * Call this whenever items are added/removed from container\n\x09 * @param NewInventoryJson - Updated inventory JSON\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update container inventory and sync to backend\nCall this whenever items are added/removed from container\n@param NewInventoryJson - Updated inventory JSON" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewInventoryJson_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_NewInventoryJson;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AEWorldContainer_ServerOnly_UpdateInventory_Statics::NewProp_NewInventoryJson = { "NewInventoryJson", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EWorldContainer_eventServerOnly_UpdateInventory_Parms, NewInventoryJson), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewInventoryJson_MetaData), NewProp_NewInventoryJson_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEWorldContainer_ServerOnly_UpdateInventory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEWorldContainer_ServerOnly_UpdateInventory_Statics::NewProp_NewInventoryJson,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEWorldContainer_ServerOnly_UpdateInventory_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEWorldContainer_ServerOnly_UpdateInventory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEWorldContainer, nullptr, "ServerOnly_UpdateInventory", Z_Construct_UFunction_AEWorldContainer_ServerOnly_UpdateInventory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEWorldContainer_ServerOnly_UpdateInventory_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEWorldContainer_ServerOnly_UpdateInventory_Statics::EWorldContainer_eventServerOnly_UpdateInventory_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEWorldContainer_ServerOnly_UpdateInventory_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEWorldContainer_ServerOnly_UpdateInventory_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEWorldContainer_ServerOnly_UpdateInventory_Statics::EWorldContainer_eventServerOnly_UpdateInventory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEWorldContainer_ServerOnly_UpdateInventory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEWorldContainer_ServerOnly_UpdateInventory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEWorldContainer::execServerOnly_UpdateInventory)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_NewInventoryJson);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_UpdateInventory(Z_Param_NewInventoryJson);
	P_NATIVE_END;
}
// ********** End Class AEWorldContainer Function ServerOnly_UpdateInventory ***********************

// ********** Begin Class AEWorldContainer *********************************************************
void AEWorldContainer::StaticRegisterNativesAEWorldContainer()
{
	UClass* Class = AEWorldContainer::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetObjectId", &AEWorldContainer::execGetObjectId },
		{ "GetWorldObjectData", &AEWorldContainer::execGetWorldObjectData },
		{ "InitializeFromDatabase", &AEWorldContainer::execInitializeFromDatabase },
		{ "ServerOnly_RegisterToBackend", &AEWorldContainer::execServerOnly_RegisterToBackend },
		{ "ServerOnly_SendInventoryUpdate", &AEWorldContainer::execServerOnly_SendInventoryUpdate },
		{ "ServerOnly_UnregisterFromBackend", &AEWorldContainer::execServerOnly_UnregisterFromBackend },
		{ "ServerOnly_UpdateInventory", &AEWorldContainer::execServerOnly_UpdateInventory },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AEWorldContainer;
UClass* AEWorldContainer::GetPrivateStaticClass()
{
	using TClass = AEWorldContainer;
	if (!Z_Registration_Info_UClass_AEWorldContainer.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EWorldContainer"),
			Z_Registration_Info_UClass_AEWorldContainer.InnerSingleton,
			StaticRegisterNativesAEWorldContainer,
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
	return Z_Registration_Info_UClass_AEWorldContainer.InnerSingleton;
}
UClass* Z_Construct_UClass_AEWorldContainer_NoRegister()
{
	return AEWorldContainer::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AEWorldContainer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * AEWorldContainer\n * \n * Container actor for items dropped in space\n * Server-only actor that persists across server restarts via backend API\n * \n * Features:\n * - Auto-registration to backend on spawn (BeginPlay)\n * - Real-time inventory sync to backend on changes\n * - Cleanup on destruction or expiration\n * - Spawned from database on server startup via WorldManager\n * \n * Usage:\n * 1. Spawn container in space\n * 2. Component automatically registers to backend\n * 3. When inventory changes, call UpdateInventory()\n * 4. Container persists across server restarts\n * 5. Cleanup service removes expired containers\n */" },
#endif
		{ "IncludePath", "Core/Common/Actor/EWorldContainer.h" },
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AEWorldContainer\n\nContainer actor for items dropped in space\nServer-only actor that persists across server restarts via backend API\n\nFeatures:\n- Auto-registration to backend on spawn (BeginPlay)\n- Real-time inventory sync to backend on changes\n- Cleanup on destruction or expiration\n- Spawned from database on server startup via WorldManager\n\nUsage:\n1. Spawn container in space\n2. Component automatically registers to backend\n3. When inventory changes, call UpdateInventory()\n4. Container persists across server restarts\n5. Cleanup service removes expired containers" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ApiBaseUrl_MetaData[] = {
		{ "Category", "WorldObject|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Backend API base URL */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Backend API base URL" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerSecret_MetaData[] = {
		{ "Category", "WorldObject|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Server secret for X-Server-Secret header authentication */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server secret for X-Server-Secret header authentication" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TemplateId_MetaData[] = {
		{ "Category", "WorldObject|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Template ID for this container type */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Template ID for this container type" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SystemId_MetaData[] = {
		{ "Category", "WorldObject|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Solar system ID where this container exists */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Solar system ID where this container exists" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExpirationHours_MetaData[] = {
		{ "Category", "WorldObject|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional expiration time (hours from now, 0 = never expires) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional expiration time (hours from now, 0 = never expires)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLoadedFromDatabase_MetaData[] = {
		{ "Category", "WorldObject|State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether this container was spawned from database (vs newly created) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EWorldContainer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether this container was spawned from database (vs newly created)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ApiBaseUrl;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerSecret;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TemplateId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SystemId;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExpirationHours;
	static void NewProp_bLoadedFromDatabase_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLoadedFromDatabase;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEWorldContainer_GetObjectId, "GetObjectId" }, // 1383565507
		{ &Z_Construct_UFunction_AEWorldContainer_GetWorldObjectData, "GetWorldObjectData" }, // 1818291451
		{ &Z_Construct_UFunction_AEWorldContainer_InitializeFromDatabase, "InitializeFromDatabase" }, // 503078167
		{ &Z_Construct_UFunction_AEWorldContainer_ServerOnly_RegisterToBackend, "ServerOnly_RegisterToBackend" }, // 33058834
		{ &Z_Construct_UFunction_AEWorldContainer_ServerOnly_SendInventoryUpdate, "ServerOnly_SendInventoryUpdate" }, // 2268517719
		{ &Z_Construct_UFunction_AEWorldContainer_ServerOnly_UnregisterFromBackend, "ServerOnly_UnregisterFromBackend" }, // 1182520567
		{ &Z_Construct_UFunction_AEWorldContainer_ServerOnly_UpdateInventory, "ServerOnly_UpdateInventory" }, // 2408159732
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEWorldContainer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AEWorldContainer_Statics::NewProp_ApiBaseUrl = { "ApiBaseUrl", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEWorldContainer, ApiBaseUrl), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ApiBaseUrl_MetaData), NewProp_ApiBaseUrl_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AEWorldContainer_Statics::NewProp_ServerSecret = { "ServerSecret", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEWorldContainer, ServerSecret), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerSecret_MetaData), NewProp_ServerSecret_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AEWorldContainer_Statics::NewProp_TemplateId = { "TemplateId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEWorldContainer, TemplateId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TemplateId_MetaData), NewProp_TemplateId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEWorldContainer_Statics::NewProp_SystemId = { "SystemId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEWorldContainer, SystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SystemId_MetaData), NewProp_SystemId_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEWorldContainer_Statics::NewProp_ExpirationHours = { "ExpirationHours", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEWorldContainer, ExpirationHours), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExpirationHours_MetaData), NewProp_ExpirationHours_MetaData) };
void Z_Construct_UClass_AEWorldContainer_Statics::NewProp_bLoadedFromDatabase_SetBit(void* Obj)
{
	((AEWorldContainer*)Obj)->bLoadedFromDatabase = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEWorldContainer_Statics::NewProp_bLoadedFromDatabase = { "bLoadedFromDatabase", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AEWorldContainer), &Z_Construct_UClass_AEWorldContainer_Statics::NewProp_bLoadedFromDatabase_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLoadedFromDatabase_MetaData), NewProp_bLoadedFromDatabase_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEWorldContainer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEWorldContainer_Statics::NewProp_ApiBaseUrl,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEWorldContainer_Statics::NewProp_ServerSecret,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEWorldContainer_Statics::NewProp_TemplateId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEWorldContainer_Statics::NewProp_SystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEWorldContainer_Statics::NewProp_ExpirationHours,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEWorldContainer_Statics::NewProp_bLoadedFromDatabase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEWorldContainer_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEWorldContainer_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEWorldContainer_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEWorldContainer_Statics::ClassParams = {
	&AEWorldContainer::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEWorldContainer_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEWorldContainer_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEWorldContainer_Statics::Class_MetaDataParams), Z_Construct_UClass_AEWorldContainer_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEWorldContainer()
{
	if (!Z_Registration_Info_UClass_AEWorldContainer.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEWorldContainer.OuterSingleton, Z_Construct_UClass_AEWorldContainer_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEWorldContainer.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEWorldContainer);
AEWorldContainer::~AEWorldContainer() {}
// ********** End Class AEWorldContainer ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EWorldContainer_h__Script_Echoes_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FWorldObjectData::StaticStruct, Z_Construct_UScriptStruct_FWorldObjectData_Statics::NewStructOps, TEXT("WorldObjectData"), &Z_Registration_Info_UScriptStruct_FWorldObjectData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FWorldObjectData), 3328031925U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEWorldContainer, AEWorldContainer::StaticClass, TEXT("AEWorldContainer"), &Z_Registration_Info_UClass_AEWorldContainer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEWorldContainer), 3903981622U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EWorldContainer_h__Script_Echoes_2932802217(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EWorldContainer_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EWorldContainer_h__Script_Echoes_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EWorldContainer_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EWorldContainer_h__Script_Echoes_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
