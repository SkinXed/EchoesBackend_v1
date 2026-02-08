// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Actor/EchoesWreck.h"

#ifdef ECHOES_EchoesWreck_generated_h
#error "EchoesWreck.generated.h already included, missing '#pragma once' in EchoesWreck.h"
#endif
#define ECHOES_EchoesWreck_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FGuid;
struct FKillmailItem;
struct FWreckAccessEntry;

// ********** Begin ScriptStruct FWreckAccessEntry *************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesWreck_h_14_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FWreckAccessEntry_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FWreckAccessEntry;
// ********** End ScriptStruct FWreckAccessEntry ***************************************************

// ********** Begin Class AEchoesWreck *************************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesWreck_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execIsEmpty); \
	DECLARE_FUNCTION(execGetKillmailId); \
	DECLARE_FUNCTION(execGetContents); \
	DECLARE_FUNCTION(execServerOnly_TakeItem); \
	DECLARE_FUNCTION(execServerOnly_HasLootRights); \
	DECLARE_FUNCTION(execServerOnly_InitializeWreck);


ECHOES_API UClass* Z_Construct_UClass_AEchoesWreck_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesWreck_h_38_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEchoesWreck(); \
	friend struct Z_Construct_UClass_AEchoesWreck_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AEchoesWreck_NoRegister(); \
public: \
	DECLARE_CLASS2(AEchoesWreck, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AEchoesWreck_NoRegister) \
	DECLARE_SERIALIZER(AEchoesWreck) \
	NO_API void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		DroppedItems=NETFIELD_REP_START, \
		NETFIELD_REP_END=DroppedItems	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesWreck_h_38_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AEchoesWreck(AEchoesWreck&&) = delete; \
	AEchoesWreck(const AEchoesWreck&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEchoesWreck); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEchoesWreck); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEchoesWreck) \
	NO_API virtual ~AEchoesWreck();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesWreck_h_35_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesWreck_h_38_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesWreck_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesWreck_h_38_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesWreck_h_38_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AEchoesWreck;

// ********** End Class AEchoesWreck ***************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesWreck_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
