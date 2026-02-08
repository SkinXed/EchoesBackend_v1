// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Actor/EWorldContainer.h"

#ifdef ECHOES_EWorldContainer_generated_h
#error "EWorldContainer.generated.h already included, missing '#pragma once' in EWorldContainer.h"
#endif
#define ECHOES_EWorldContainer_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FGuid;
struct FWorldObjectData;

// ********** Begin ScriptStruct FWorldObjectData **************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EWorldContainer_h_17_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FWorldObjectData_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FWorldObjectData;
// ********** End ScriptStruct FWorldObjectData ****************************************************

// ********** Begin Class AEWorldContainer *********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EWorldContainer_h_78_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execServerOnly_SendInventoryUpdate); \
	DECLARE_FUNCTION(execServerOnly_UnregisterFromBackend); \
	DECLARE_FUNCTION(execServerOnly_RegisterToBackend); \
	DECLARE_FUNCTION(execGetObjectId); \
	DECLARE_FUNCTION(execInitializeFromDatabase); \
	DECLARE_FUNCTION(execGetWorldObjectData); \
	DECLARE_FUNCTION(execServerOnly_UpdateInventory);


ECHOES_API UClass* Z_Construct_UClass_AEWorldContainer_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EWorldContainer_h_78_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEWorldContainer(); \
	friend struct Z_Construct_UClass_AEWorldContainer_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AEWorldContainer_NoRegister(); \
public: \
	DECLARE_CLASS2(AEWorldContainer, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AEWorldContainer_NoRegister) \
	DECLARE_SERIALIZER(AEWorldContainer)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EWorldContainer_h_78_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AEWorldContainer(AEWorldContainer&&) = delete; \
	AEWorldContainer(const AEWorldContainer&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEWorldContainer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEWorldContainer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEWorldContainer) \
	NO_API virtual ~AEWorldContainer();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EWorldContainer_h_75_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EWorldContainer_h_78_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EWorldContainer_h_78_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EWorldContainer_h_78_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EWorldContainer_h_78_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AEWorldContainer;

// ********** End Class AEWorldContainer ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EWorldContainer_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
