// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Interfaces/ShipFittingInterface.h"

#ifdef ECHOES_ShipFittingInterface_generated_h
#error "ShipFittingInterface.generated.h already included, missing '#pragma once' in ShipFittingInterface.h"
#endif
#define ECHOES_ShipFittingInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

enum class ESlotType : uint8;
struct FCommon_ItemSlot;
struct FCommon_ShipFittingData;

// ********** Begin ScriptStruct FCommon_ItemSlot **************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_67_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FCommon_ItemSlot;
// ********** End ScriptStruct FCommon_ItemSlot ****************************************************

// ********** Begin ScriptStruct FCommon_ModuleStats ***********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_167_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FCommon_ModuleStats;
// ********** End ScriptStruct FCommon_ModuleStats *************************************************

// ********** Begin ScriptStruct FCommon_ShipFittingData *******************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_239_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FCommon_ShipFittingData;
// ********** End ScriptStruct FCommon_ShipFittingData *********************************************

// ********** Begin Interface UShipFittingInterface ************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_382_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool CanInstallModule_Implementation(int32 ItemID, ESlotType SlotType, int32 SlotIndex) const { return false; }; \
	virtual bool GetEquipmentSlot_Implementation(ESlotType SlotType, int32 SlotIndex, FCommon_ItemSlot& OutSlot) const { return false; }; \
	virtual FCommon_ShipFittingData GetFittingData_Implementation() const { return FCommon_ShipFittingData(); }; \
	DECLARE_FUNCTION(execCanInstallModule); \
	DECLARE_FUNCTION(execGetEquipmentSlot); \
	DECLARE_FUNCTION(execGetFittingData);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_382_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UShipFittingInterface_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_382_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ECHOES_API UShipFittingInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UShipFittingInterface(UShipFittingInterface&&) = delete; \
	UShipFittingInterface(const UShipFittingInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ECHOES_API, UShipFittingInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UShipFittingInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UShipFittingInterface) \
	virtual ~UShipFittingInterface() = default;


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_382_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUShipFittingInterface(); \
	friend struct Z_Construct_UClass_UShipFittingInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UShipFittingInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(UShipFittingInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UShipFittingInterface_NoRegister) \
	DECLARE_SERIALIZER(UShipFittingInterface)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_382_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_382_GENERATED_UINTERFACE_BODY() \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_382_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_382_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IShipFittingInterface() {} \
public: \
	typedef UShipFittingInterface UClassType; \
	typedef IShipFittingInterface ThisClass; \
	static bool Execute_CanInstallModule(const UObject* O, int32 ItemID, ESlotType SlotType, int32 SlotIndex); \
	static bool Execute_GetEquipmentSlot(const UObject* O, ESlotType SlotType, int32 SlotIndex, FCommon_ItemSlot& OutSlot); \
	static FCommon_ShipFittingData Execute_GetFittingData(const UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_379_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_398_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_382_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_382_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_382_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UShipFittingInterface;

// ********** End Interface UShipFittingInterface **************************************************

// ********** Begin Interface UEquipmentObserver ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_436_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void OnFittingStatsChanged_Implementation(FCommon_ShipFittingData const& NewFittingData) {}; \
	virtual void OnEquipmentChanged_Implementation(ESlotType SlotType, int32 SlotIndex, FCommon_ItemSlot const& NewSlotData) {}; \
	DECLARE_FUNCTION(execOnFittingStatsChanged); \
	DECLARE_FUNCTION(execOnEquipmentChanged);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_436_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UEquipmentObserver_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_436_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ECHOES_API UEquipmentObserver(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEquipmentObserver(UEquipmentObserver&&) = delete; \
	UEquipmentObserver(const UEquipmentObserver&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ECHOES_API, UEquipmentObserver); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEquipmentObserver); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEquipmentObserver) \
	virtual ~UEquipmentObserver() = default;


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_436_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUEquipmentObserver(); \
	friend struct Z_Construct_UClass_UEquipmentObserver_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEquipmentObserver_NoRegister(); \
public: \
	DECLARE_CLASS2(UEquipmentObserver, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEquipmentObserver_NoRegister) \
	DECLARE_SERIALIZER(UEquipmentObserver)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_436_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_436_GENERATED_UINTERFACE_BODY() \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_436_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_436_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IEquipmentObserver() {} \
public: \
	typedef UEquipmentObserver UClassType; \
	typedef IEquipmentObserver ThisClass; \
	static void Execute_OnEquipmentChanged(UObject* O, ESlotType SlotType, int32 SlotIndex, FCommon_ItemSlot const& NewSlotData); \
	static void Execute_OnFittingStatsChanged(UObject* O, FCommon_ShipFittingData const& NewFittingData); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_433_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_452_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_436_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_436_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h_436_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEquipmentObserver;

// ********** End Interface UEquipmentObserver *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h

// ********** Begin Enum ESlotType *****************************************************************
#define FOREACH_ENUM_ESLOTTYPE(op) \
	op(ESlotType::High) \
	op(ESlotType::Mid) \
	op(ESlotType::Low) \
	op(ESlotType::Rig) \
	op(ESlotType::Subsystem) \
	op(ESlotType::None) 

enum class ESlotType : uint8;
template<> struct TIsUEnumClass<ESlotType> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<ESlotType>();
// ********** End Enum ESlotType *******************************************************************

// ********** Begin Enum EModuleState **************************************************************
#define FOREACH_ENUM_EMODULESTATE(op) \
	op(EModuleState::Offline) \
	op(EModuleState::Active) \
	op(EModuleState::Overload) \
	op(EModuleState::Cooldown) \
	op(EModuleState::Damaged) 

enum class EModuleState : uint8;
template<> struct TIsUEnumClass<EModuleState> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<EModuleState>();
// ********** End Enum EModuleState ****************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
