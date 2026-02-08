// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Interfaces/ShipStateInterface.h"

#ifdef ECHOES_ShipStateInterface_generated_h
#error "ShipStateInterface.generated.h already included, missing '#pragma once' in ShipStateInterface.h"
#endif
#define ECHOES_ShipStateInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
struct FCommon_ShipDataStruct;

// ********** Begin ScriptStruct FCommon_ShipDataStruct ********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h_16_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FCommon_ShipDataStruct;
// ********** End ScriptStruct FCommon_ShipDataStruct **********************************************

// ********** Begin Interface UShipStateInterface **************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h_148_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual AActor* GetCurrentTarget_Implementation() const { return NULL; }; \
	virtual bool IsShipAlive_Implementation() const { return false; }; \
	virtual FCommon_ShipDataStruct GetShipData_Implementation() const { return FCommon_ShipDataStruct(); }; \
	DECLARE_FUNCTION(execGetCurrentTarget); \
	DECLARE_FUNCTION(execIsShipAlive); \
	DECLARE_FUNCTION(execGetShipData);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h_148_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UShipStateInterface_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h_148_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ECHOES_API UShipStateInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UShipStateInterface(UShipStateInterface&&) = delete; \
	UShipStateInterface(const UShipStateInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ECHOES_API, UShipStateInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UShipStateInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UShipStateInterface) \
	virtual ~UShipStateInterface() = default;


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h_148_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUShipStateInterface(); \
	friend struct Z_Construct_UClass_UShipStateInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UShipStateInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(UShipStateInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UShipStateInterface_NoRegister) \
	DECLARE_SERIALIZER(UShipStateInterface)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h_148_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h_148_GENERATED_UINTERFACE_BODY() \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h_148_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h_148_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IShipStateInterface() {} \
public: \
	typedef UShipStateInterface UClassType; \
	typedef IShipStateInterface ThisClass; \
	static AActor* Execute_GetCurrentTarget(const UObject* O); \
	static FCommon_ShipDataStruct Execute_GetShipData(const UObject* O); \
	static bool Execute_IsShipAlive(const UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h_145_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h_178_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h_148_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h_148_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h_148_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UShipStateInterface;

// ********** End Interface UShipStateInterface ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
