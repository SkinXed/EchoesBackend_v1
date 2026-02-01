// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Interfaces/EchoesInteractableInterface.h"

#ifdef ECHOES_EchoesInteractableInterface_generated_h
#error "EchoesInteractableInterface.generated.h already included, missing '#pragma once' in EchoesInteractableInterface.h"
#endif
#define ECHOES_EchoesInteractableInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class APawn;
struct FEchoesInteractionResult;

// ********** Begin ScriptStruct FEchoesInteractionResult ******************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_EchoesInteractableInterface_h_19_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FEchoesInteractionResult_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FEchoesInteractionResult;
// ********** End ScriptStruct FEchoesInteractionResult ********************************************

// ********** Begin Interface UEchoesInteractableInterface *****************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_EchoesInteractableInterface_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual FEchoesInteractionResult OnInteract_Implementation(APawn* Interactor) { return FEchoesInteractionResult(); }; \
	virtual FText GetInteractionPrompt_Implementation() const { return FText::GetEmpty(); }; \
	virtual float GetInteractionDistance_Implementation() const { return 0; }; \
	virtual bool CanInteract_Implementation(APawn* Interactor) const { return false; }; \
	DECLARE_FUNCTION(execOnInteract); \
	DECLARE_FUNCTION(execGetInteractionPrompt); \
	DECLARE_FUNCTION(execGetInteractionDistance); \
	DECLARE_FUNCTION(execCanInteract);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_EchoesInteractableInterface_h_38_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UEchoesInteractableInterface_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_EchoesInteractableInterface_h_38_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ECHOES_API UEchoesInteractableInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesInteractableInterface(UEchoesInteractableInterface&&) = delete; \
	UEchoesInteractableInterface(const UEchoesInteractableInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ECHOES_API, UEchoesInteractableInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesInteractableInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEchoesInteractableInterface) \
	virtual ~UEchoesInteractableInterface() = default;


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_EchoesInteractableInterface_h_38_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUEchoesInteractableInterface(); \
	friend struct Z_Construct_UClass_UEchoesInteractableInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesInteractableInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesInteractableInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesInteractableInterface_NoRegister) \
	DECLARE_SERIALIZER(UEchoesInteractableInterface)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_EchoesInteractableInterface_h_38_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_EchoesInteractableInterface_h_38_GENERATED_UINTERFACE_BODY() \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_EchoesInteractableInterface_h_38_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_EchoesInteractableInterface_h_38_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IEchoesInteractableInterface() {} \
public: \
	typedef UEchoesInteractableInterface UClassType; \
	typedef IEchoesInteractableInterface ThisClass; \
	static bool Execute_CanInteract(const UObject* O, APawn* Interactor); \
	static float Execute_GetInteractionDistance(const UObject* O); \
	static FText Execute_GetInteractionPrompt(const UObject* O); \
	static FEchoesInteractionResult Execute_OnInteract(UObject* O, APawn* Interactor); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_EchoesInteractableInterface_h_35_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_EchoesInteractableInterface_h_55_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_EchoesInteractableInterface_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_EchoesInteractableInterface_h_38_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_EchoesInteractableInterface_h_38_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesInteractableInterface;

// ********** End Interface UEchoesInteractableInterface *******************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_EchoesInteractableInterface_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
