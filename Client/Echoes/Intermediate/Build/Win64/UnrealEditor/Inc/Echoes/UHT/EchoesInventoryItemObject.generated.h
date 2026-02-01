// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/EchoesInventoryItemObject.h"

#ifdef ECHOES_EchoesInventoryItemObject_generated_h
#error "EchoesInventoryItemObject.generated.h already included, missing '#pragma once' in EchoesInventoryItemObject.h"
#endif
#define ECHOES_EchoesInventoryItemObject_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FEchoesInventoryItem;
struct FEchoesItemDefinitionRow;
struct FGuid;

// ********** Begin Class UEchoesInventoryItemObject ***********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryItemObject_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHasDefinition); \
	DECLARE_FUNCTION(execGetTotalMass); \
	DECLARE_FUNCTION(execGetUnitVolume); \
	DECLARE_FUNCTION(execGetCalculatedTotalVolume); \
	DECLARE_FUNCTION(execGetDescription); \
	DECLARE_FUNCTION(execGetDisplayName); \
	DECLARE_FUNCTION(execGetItemDefinitionData); \
	DECLARE_FUNCTION(execGetTypeId); \
	DECLARE_FUNCTION(execIsStackable); \
	DECLARE_FUNCTION(execGetAssetId); \
	DECLARE_FUNCTION(execGetFormattedTotalVolume); \
	DECLARE_FUNCTION(execGetFormattedVolume); \
	DECLARE_FUNCTION(execGetQuantity); \
	DECLARE_FUNCTION(execGetItemName); \
	DECLARE_FUNCTION(execGetItemData); \
	DECLARE_FUNCTION(execInitializeWithData);


ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryItemObject_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryItemObject_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesInventoryItemObject(); \
	friend struct Z_Construct_UClass_UEchoesInventoryItemObject_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryItemObject_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesInventoryItemObject, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesInventoryItemObject_NoRegister) \
	DECLARE_SERIALIZER(UEchoesInventoryItemObject)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryItemObject_h_29_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesInventoryItemObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesInventoryItemObject(UEchoesInventoryItemObject&&) = delete; \
	UEchoesInventoryItemObject(const UEchoesInventoryItemObject&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesInventoryItemObject); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesInventoryItemObject); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEchoesInventoryItemObject) \
	NO_API virtual ~UEchoesInventoryItemObject();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryItemObject_h_26_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryItemObject_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryItemObject_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryItemObject_h_29_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryItemObject_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesInventoryItemObject;

// ********** End Class UEchoesInventoryItemObject *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryItemObject_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
