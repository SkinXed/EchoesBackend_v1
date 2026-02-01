// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Actor/EchoesItemActor.h"

#ifdef ECHOES_EchoesItemActor_generated_h
#error "EchoesItemActor.generated.h already included, missing '#pragma once' in EchoesItemActor.h"
#endif
#define ECHOES_EchoesItemActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class APawn;
class UEchoesInventoryComponent;
class UStaticMesh;
struct FEchoesItemDefinitionRow;
struct FGuid;

// ********** Begin Class AEchoesItemActor *********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesItemActor_h_46_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRep_ItemId); \
	DECLARE_FUNCTION(execOnLifetimeExpired); \
	DECLARE_FUNCTION(execOnMeshLoaded); \
	DECLARE_FUNCTION(execGetRemainingLifetime); \
	DECLARE_FUNCTION(execIsContainer); \
	DECLARE_FUNCTION(execGetInventoryComponent); \
	DECLARE_FUNCTION(execGetItemDefinitionData); \
	DECLARE_FUNCTION(execGetInstanceId); \
	DECLARE_FUNCTION(execGetItemId); \
	DECLARE_FUNCTION(execSetLifetime); \
	DECLARE_FUNCTION(execServerOnly_InitializeItem);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesItemActor_h_46_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_AEchoesItemActor_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesItemActor_h_46_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEchoesItemActor(); \
	friend struct Z_Construct_UClass_AEchoesItemActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AEchoesItemActor_NoRegister(); \
public: \
	DECLARE_CLASS2(AEchoesItemActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AEchoesItemActor_NoRegister) \
	DECLARE_SERIALIZER(AEchoesItemActor) \
	virtual UObject* _getUObject() const override { return const_cast<AEchoesItemActor*>(this); } \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		ItemId=NETFIELD_REP_START, \
		InstanceId, \
		Quantity, \
		NETFIELD_REP_END=Quantity	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesItemActor_h_46_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AEchoesItemActor(AEchoesItemActor&&) = delete; \
	AEchoesItemActor(const AEchoesItemActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEchoesItemActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEchoesItemActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEchoesItemActor) \
	NO_API virtual ~AEchoesItemActor();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesItemActor_h_43_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesItemActor_h_46_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesItemActor_h_46_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesItemActor_h_46_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesItemActor_h_46_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesItemActor_h_46_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AEchoesItemActor;

// ********** End Class AEchoesItemActor ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesItemActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
