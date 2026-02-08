// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Libraries/EchoesItemDataLibrary.h"

#ifdef ECHOES_EchoesItemDataLibrary_generated_h
#error "EchoesItemDataLibrary.generated.h already included, missing '#pragma once' in EchoesItemDataLibrary.h"
#endif
#define ECHOES_EchoesItemDataLibrary_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UDataTable;
class UTexture2D;
enum class EEchoesSlotType : uint8;
struct FCompleteModuleData;
struct FEchoesItemDefinitionRow;
struct FWeaponAttributesRow;

// ********** Begin ScriptStruct FCompleteModuleData ***********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Libraries_EchoesItemDataLibrary_h_23_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCompleteModuleData_Statics; \
	static class UScriptStruct* StaticStruct();


struct FCompleteModuleData;
// ********** End ScriptStruct FCompleteModuleData *************************************************

// ********** Begin Class UEchoesItemDataLibrary ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Libraries_EchoesItemDataLibrary_h_72_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execClearCache); \
	DECLARE_FUNCTION(execCommon_ItemExists); \
	DECLARE_FUNCTION(execCommon_GetItemIcon); \
	DECLARE_FUNCTION(execCommon_GetItemName); \
	DECLARE_FUNCTION(execCommon_GetCPURequired); \
	DECLARE_FUNCTION(execCommon_GetPowergridRequired); \
	DECLARE_FUNCTION(execCommon_GetFitSlot); \
	DECLARE_FUNCTION(execCommon_IsFittableModule); \
	DECLARE_FUNCTION(execCommon_GetCompleteModuleData); \
	DECLARE_FUNCTION(execCommon_GetWeaponAttributes); \
	DECLARE_FUNCTION(execCommon_GetItemDefinition); \
	DECLARE_FUNCTION(execSetDataTableReferences);


ECHOES_API UClass* Z_Construct_UClass_UEchoesItemDataLibrary_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Libraries_EchoesItemDataLibrary_h_72_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesItemDataLibrary(); \
	friend struct Z_Construct_UClass_UEchoesItemDataLibrary_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesItemDataLibrary_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesItemDataLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesItemDataLibrary_NoRegister) \
	DECLARE_SERIALIZER(UEchoesItemDataLibrary)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Libraries_EchoesItemDataLibrary_h_72_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesItemDataLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesItemDataLibrary(UEchoesItemDataLibrary&&) = delete; \
	UEchoesItemDataLibrary(const UEchoesItemDataLibrary&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesItemDataLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesItemDataLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEchoesItemDataLibrary) \
	NO_API virtual ~UEchoesItemDataLibrary();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Libraries_EchoesItemDataLibrary_h_69_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Libraries_EchoesItemDataLibrary_h_72_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Libraries_EchoesItemDataLibrary_h_72_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Libraries_EchoesItemDataLibrary_h_72_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Libraries_EchoesItemDataLibrary_h_72_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesItemDataLibrary;

// ********** End Class UEchoesItemDataLibrary *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Libraries_EchoesItemDataLibrary_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
