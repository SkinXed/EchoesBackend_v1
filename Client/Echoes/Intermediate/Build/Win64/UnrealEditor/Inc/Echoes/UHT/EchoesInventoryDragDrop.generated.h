// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/Logic/EchoesInventoryDragDrop.h"

#ifdef ECHOES_EchoesInventoryDragDrop_generated_h
#error "EchoesInventoryDragDrop.generated.h already included, missing '#pragma once' in EchoesInventoryDragDrop.h"
#endif
#define ECHOES_EchoesInventoryDragDrop_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
struct FEchoesInventoryItem;
struct FGuid;

// ********** Begin Class UEchoesInventoryDragDrop *************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesInventoryDragDrop_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execIsPartialStack); \
	DECLARE_FUNCTION(execSetQuantity); \
	DECLARE_FUNCTION(execGetQuantity); \
	DECLARE_FUNCTION(execGetSourceActor); \
	DECLARE_FUNCTION(execGetSourceStorageId); \
	DECLARE_FUNCTION(execGetItemData); \
	DECLARE_FUNCTION(execInitializeDragOperation);


ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryDragDrop_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesInventoryDragDrop_h_32_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesInventoryDragDrop(); \
	friend struct Z_Construct_UClass_UEchoesInventoryDragDrop_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryDragDrop_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesInventoryDragDrop, UDragDropOperation, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesInventoryDragDrop_NoRegister) \
	DECLARE_SERIALIZER(UEchoesInventoryDragDrop)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesInventoryDragDrop_h_32_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesInventoryDragDrop(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesInventoryDragDrop(UEchoesInventoryDragDrop&&) = delete; \
	UEchoesInventoryDragDrop(const UEchoesInventoryDragDrop&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesInventoryDragDrop); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesInventoryDragDrop); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEchoesInventoryDragDrop) \
	NO_API virtual ~UEchoesInventoryDragDrop();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesInventoryDragDrop_h_29_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesInventoryDragDrop_h_32_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesInventoryDragDrop_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesInventoryDragDrop_h_32_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesInventoryDragDrop_h_32_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesInventoryDragDrop;

// ********** End Class UEchoesInventoryDragDrop ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesInventoryDragDrop_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
