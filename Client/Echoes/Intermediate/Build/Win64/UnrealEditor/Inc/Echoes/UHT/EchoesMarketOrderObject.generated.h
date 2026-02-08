// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/Logic/EchoesMarketOrderObject.h"

#ifdef ECHOES_EchoesMarketOrderObject_generated_h
#error "EchoesMarketOrderObject.generated.h already included, missing '#pragma once' in EchoesMarketOrderObject.h"
#endif
#define ECHOES_EchoesMarketOrderObject_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FGuid;
struct FMarketOrderDto;

// ********** Begin Class UEchoesMarketOrderObject *************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesMarketOrderObject_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetPrice); \
	DECLARE_FUNCTION(execGetItemId); \
	DECLARE_FUNCTION(execGetFormattedIssuedTime); \
	DECLARE_FUNCTION(execGetStationName); \
	DECLARE_FUNCTION(execGetRemainingQuantity); \
	DECLARE_FUNCTION(execGetFormattedPrice); \
	DECLARE_FUNCTION(execIsBuyOrder); \
	DECLARE_FUNCTION(execGetOrderId); \
	DECLARE_FUNCTION(execGetOrderData); \
	DECLARE_FUNCTION(execInitializeWithData);


ECHOES_API UClass* Z_Construct_UClass_UEchoesMarketOrderObject_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesMarketOrderObject_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesMarketOrderObject(); \
	friend struct Z_Construct_UClass_UEchoesMarketOrderObject_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesMarketOrderObject_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesMarketOrderObject, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesMarketOrderObject_NoRegister) \
	DECLARE_SERIALIZER(UEchoesMarketOrderObject)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesMarketOrderObject_h_25_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesMarketOrderObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesMarketOrderObject(UEchoesMarketOrderObject&&) = delete; \
	UEchoesMarketOrderObject(const UEchoesMarketOrderObject&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesMarketOrderObject); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesMarketOrderObject); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEchoesMarketOrderObject) \
	NO_API virtual ~UEchoesMarketOrderObject();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesMarketOrderObject_h_22_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesMarketOrderObject_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesMarketOrderObject_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesMarketOrderObject_h_25_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesMarketOrderObject_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesMarketOrderObject;

// ********** End Class UEchoesMarketOrderObject ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesMarketOrderObject_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
