// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Server/CombatServerSubsystem.h"

#ifdef ECHOES_CombatServerSubsystem_generated_h
#error "CombatServerSubsystem.generated.h already included, missing '#pragma once' in CombatServerSubsystem.h"
#endif
#define ECHOES_CombatServerSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FGuid;
struct FKillmailData;
struct FKillmailItem;

// ********** Begin Delegate FOnKillmailReported ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_CombatServerSubsystem_h_15_DELEGATE \
ECHOES_API void FOnKillmailReported_DelegateWrapper(const FMulticastScriptDelegate& OnKillmailReported, FKillmailData const& Killmail);


// ********** End Delegate FOnKillmailReported *****************************************************

// ********** Begin Delegate FOnKillmailReportFailed ***********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_CombatServerSubsystem_h_18_DELEGATE \
ECHOES_API void FOnKillmailReportFailed_DelegateWrapper(const FMulticastScriptDelegate& OnKillmailReportFailed, const FString& ErrorMessage);


// ********** End Delegate FOnKillmailReportFailed *************************************************

// ********** Begin Class UCombatServerSubsystem ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_CombatServerSubsystem_h_42_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execServerOnly_ReportKill); \
	DECLARE_FUNCTION(execServerOnly_HandleDestruction); \
	DECLARE_FUNCTION(execServerOnly_ClearDamageMap); \
	DECLARE_FUNCTION(execServerOnly_RegisterDamage);


ECHOES_API UClass* Z_Construct_UClass_UCombatServerSubsystem_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_CombatServerSubsystem_h_42_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCombatServerSubsystem(); \
	friend struct Z_Construct_UClass_UCombatServerSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UCombatServerSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UCombatServerSubsystem, UWorldSubsystem, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UCombatServerSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UCombatServerSubsystem) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_CombatServerSubsystem_h_42_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCombatServerSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCombatServerSubsystem(UCombatServerSubsystem&&) = delete; \
	UCombatServerSubsystem(const UCombatServerSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCombatServerSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCombatServerSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCombatServerSubsystem) \
	NO_API virtual ~UCombatServerSubsystem();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_CombatServerSubsystem_h_39_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_CombatServerSubsystem_h_42_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_CombatServerSubsystem_h_42_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_CombatServerSubsystem_h_42_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_CombatServerSubsystem_h_42_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCombatServerSubsystem;

// ********** End Class UCombatServerSubsystem *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_CombatServerSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
