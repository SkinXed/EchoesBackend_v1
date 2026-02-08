// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Components/PersistenceComponent.h"

#ifdef ECHOES_PersistenceComponent_generated_h
#error "PersistenceComponent.generated.h already included, missing '#pragma once' in PersistenceComponent.h"
#endif
#define ECHOES_PersistenceComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FCommon_StateData;
struct FGuid;

// ********** Begin ScriptStruct FCommon_StateData *************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceComponent_h_20_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCommon_StateData_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FCommon_StateData;
// ********** End ScriptStruct FCommon_StateData ***************************************************

// ********** Begin Class UPersistenceComponent ****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceComponent_h_87_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execServerOnly_OnHeartbeatTimer); \
	DECLARE_FUNCTION(execServerOnly_IsDirty); \
	DECLARE_FUNCTION(execServerOnly_CollectCurrentState); \
	DECLARE_FUNCTION(execCommon_SetCharacterId); \
	DECLARE_FUNCTION(execServerOnly_TriggerSave);


ECHOES_API UClass* Z_Construct_UClass_UPersistenceComponent_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceComponent_h_87_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPersistenceComponent(); \
	friend struct Z_Construct_UClass_UPersistenceComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UPersistenceComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UPersistenceComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UPersistenceComponent_NoRegister) \
	DECLARE_SERIALIZER(UPersistenceComponent)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceComponent_h_87_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPersistenceComponent(UPersistenceComponent&&) = delete; \
	UPersistenceComponent(const UPersistenceComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPersistenceComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPersistenceComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPersistenceComponent) \
	NO_API virtual ~UPersistenceComponent();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceComponent_h_84_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceComponent_h_87_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceComponent_h_87_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceComponent_h_87_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceComponent_h_87_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPersistenceComponent;

// ********** End Class UPersistenceComponent ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
