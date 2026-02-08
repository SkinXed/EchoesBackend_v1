// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ShipStatusWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeShipStatusWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ECHOES_API UClass* Z_Construct_UClass_UShipStateObserver();
ECHOES_API UClass* Z_Construct_UClass_UShipStateObserver_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UShipStatusWidget();
ECHOES_API UClass* Z_Construct_UClass_UShipStatusWidget_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UShipStateObserver Function OnCapacitorChanged ***********************
struct ShipStateObserver_eventOnCapacitorChanged_Parms
{
	float CapacitorPct;
};
void IShipStateObserver::OnCapacitorChanged(float CapacitorPct)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnCapacitorChanged instead.");
}
static FName NAME_UShipStateObserver_OnCapacitorChanged = FName(TEXT("OnCapacitorChanged"));
void IShipStateObserver::Execute_OnCapacitorChanged(UObject* O, float CapacitorPct)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UShipStateObserver::StaticClass()));
	ShipStateObserver_eventOnCapacitorChanged_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UShipStateObserver_OnCapacitorChanged);
	if (Func)
	{
		Parms.CapacitorPct=CapacitorPct;
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IShipStateObserver*)(O->GetNativeInterfaceAddress(UShipStateObserver::StaticClass())))
	{
		I->OnCapacitorChanged_Implementation(CapacitorPct);
	}
}
struct Z_Construct_UFunction_UShipStateObserver_OnCapacitorChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship State Observer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Called when capacitor changes\n * \n * @param CapacitorPct Capacitor percentage (0-1)\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when capacitor changes\n\n@param CapacitorPct Capacitor percentage (0-1)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CapacitorPct;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStateObserver_OnCapacitorChanged_Statics::NewProp_CapacitorPct = { "CapacitorPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStateObserver_eventOnCapacitorChanged_Parms, CapacitorPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStateObserver_OnCapacitorChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStateObserver_OnCapacitorChanged_Statics::NewProp_CapacitorPct,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStateObserver_OnCapacitorChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStateObserver_OnCapacitorChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStateObserver, nullptr, "OnCapacitorChanged", Z_Construct_UFunction_UShipStateObserver_OnCapacitorChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStateObserver_OnCapacitorChanged_Statics::PropPointers), sizeof(ShipStateObserver_eventOnCapacitorChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStateObserver_OnCapacitorChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStateObserver_OnCapacitorChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ShipStateObserver_eventOnCapacitorChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStateObserver_OnCapacitorChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStateObserver_OnCapacitorChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IShipStateObserver::execOnCapacitorChanged)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_CapacitorPct);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnCapacitorChanged_Implementation(Z_Param_CapacitorPct);
	P_NATIVE_END;
}
// ********** End Interface UShipStateObserver Function OnCapacitorChanged *************************

// ********** Begin Interface UShipStateObserver Function OnShipStatsChanged ***********************
struct ShipStateObserver_eventOnShipStatsChanged_Parms
{
	float ShieldPct;
	float ArmorPct;
	float HullPct;
};
void IShipStateObserver::OnShipStatsChanged(float ShieldPct, float ArmorPct, float HullPct)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnShipStatsChanged instead.");
}
static FName NAME_UShipStateObserver_OnShipStatsChanged = FName(TEXT("OnShipStatsChanged"));
void IShipStateObserver::Execute_OnShipStatsChanged(UObject* O, float ShieldPct, float ArmorPct, float HullPct)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UShipStateObserver::StaticClass()));
	ShipStateObserver_eventOnShipStatsChanged_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UShipStateObserver_OnShipStatsChanged);
	if (Func)
	{
		Parms.ShieldPct=ShieldPct;
		Parms.ArmorPct=ArmorPct;
		Parms.HullPct=HullPct;
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IShipStateObserver*)(O->GetNativeInterfaceAddress(UShipStateObserver::StaticClass())))
	{
		I->OnShipStatsChanged_Implementation(ShieldPct,ArmorPct,HullPct);
	}
}
struct Z_Construct_UFunction_UShipStateObserver_OnShipStatsChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship State Observer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Called when ship stats change (Shield/Armor/Hull)\n * \n * @param ShieldPct Shield percentage (0-1)\n * @param ArmorPct Armor percentage (0-1)\n * @param HullPct Hull percentage (0-1)\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when ship stats change (Shield/Armor/Hull)\n\n@param ShieldPct Shield percentage (0-1)\n@param ArmorPct Armor percentage (0-1)\n@param HullPct Hull percentage (0-1)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShieldPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ArmorPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HullPct;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStateObserver_OnShipStatsChanged_Statics::NewProp_ShieldPct = { "ShieldPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStateObserver_eventOnShipStatsChanged_Parms, ShieldPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStateObserver_OnShipStatsChanged_Statics::NewProp_ArmorPct = { "ArmorPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStateObserver_eventOnShipStatsChanged_Parms, ArmorPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStateObserver_OnShipStatsChanged_Statics::NewProp_HullPct = { "HullPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStateObserver_eventOnShipStatsChanged_Parms, HullPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStateObserver_OnShipStatsChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStateObserver_OnShipStatsChanged_Statics::NewProp_ShieldPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStateObserver_OnShipStatsChanged_Statics::NewProp_ArmorPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStateObserver_OnShipStatsChanged_Statics::NewProp_HullPct,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStateObserver_OnShipStatsChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStateObserver_OnShipStatsChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStateObserver, nullptr, "OnShipStatsChanged", Z_Construct_UFunction_UShipStateObserver_OnShipStatsChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStateObserver_OnShipStatsChanged_Statics::PropPointers), sizeof(ShipStateObserver_eventOnShipStatsChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStateObserver_OnShipStatsChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStateObserver_OnShipStatsChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ShipStateObserver_eventOnShipStatsChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStateObserver_OnShipStatsChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStateObserver_OnShipStatsChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IShipStateObserver::execOnShipStatsChanged)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_ShieldPct);
	P_GET_PROPERTY(FFloatProperty,Z_Param_ArmorPct);
	P_GET_PROPERTY(FFloatProperty,Z_Param_HullPct);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnShipStatsChanged_Implementation(Z_Param_ShieldPct,Z_Param_ArmorPct,Z_Param_HullPct);
	P_NATIVE_END;
}
// ********** End Interface UShipStateObserver Function OnShipStatsChanged *************************

// ********** Begin Interface UShipStateObserver ***************************************************
void UShipStateObserver::StaticRegisterNativesUShipStateObserver()
{
	UClass* Class = UShipStateObserver::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnCapacitorChanged", &IShipStateObserver::execOnCapacitorChanged },
		{ "OnShipStatsChanged", &IShipStateObserver::execOnShipStatsChanged },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UShipStateObserver;
UClass* UShipStateObserver::GetPrivateStaticClass()
{
	using TClass = UShipStateObserver;
	if (!Z_Registration_Info_UClass_UShipStateObserver.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ShipStateObserver"),
			Z_Registration_Info_UClass_UShipStateObserver.InnerSingleton,
			StaticRegisterNativesUShipStateObserver,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UShipStateObserver.InnerSingleton;
}
UClass* Z_Construct_UClass_UShipStateObserver_NoRegister()
{
	return UShipStateObserver::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UShipStateObserver_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UShipStateObserver_OnCapacitorChanged, "OnCapacitorChanged" }, // 3175830023
		{ &Z_Construct_UFunction_UShipStateObserver_OnShipStatsChanged, "OnShipStatsChanged" }, // 1202071463
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IShipStateObserver>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UShipStateObserver_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UShipStateObserver_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UShipStateObserver_Statics::ClassParams = {
	&UShipStateObserver::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UShipStateObserver_Statics::Class_MetaDataParams), Z_Construct_UClass_UShipStateObserver_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UShipStateObserver()
{
	if (!Z_Registration_Info_UClass_UShipStateObserver.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UShipStateObserver.OuterSingleton, Z_Construct_UClass_UShipStateObserver_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UShipStateObserver.OuterSingleton;
}
UShipStateObserver::UShipStateObserver(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UShipStateObserver);
// ********** End Interface UShipStateObserver *****************************************************

// ********** Begin Class UShipStatusWidget Function BindToShip ************************************
struct Z_Construct_UFunction_UShipStatusWidget_BindToShip_Statics
{
	struct ShipStatusWidget_eventBindToShip_Parms
	{
		AActor* Ship;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Bind to a ship for automatic updates\n * \n * @param Ship The ship actor implementing IShipStateInterface\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Bind to a ship for automatic updates\n\n@param Ship The ship actor implementing IShipStateInterface" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Ship;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UShipStatusWidget_BindToShip_Statics::NewProp_Ship = { "Ship", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventBindToShip_Parms, Ship), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatusWidget_BindToShip_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_BindToShip_Statics::NewProp_Ship,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_BindToShip_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatusWidget_BindToShip_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatusWidget, nullptr, "BindToShip", Z_Construct_UFunction_UShipStatusWidget_BindToShip_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_BindToShip_Statics::PropPointers), sizeof(Z_Construct_UFunction_UShipStatusWidget_BindToShip_Statics::ShipStatusWidget_eventBindToShip_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_BindToShip_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatusWidget_BindToShip_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShipStatusWidget_BindToShip_Statics::ShipStatusWidget_eventBindToShip_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatusWidget_BindToShip()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatusWidget_BindToShip_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatusWidget::execBindToShip)
{
	P_GET_OBJECT(AActor,Z_Param_Ship);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->BindToShip(Z_Param_Ship);
	P_NATIVE_END;
}
// ********** End Class UShipStatusWidget Function BindToShip **************************************

// ********** Begin Class UShipStatusWidget Function ClientOnly_RefreshAllDisplays *****************
struct Z_Construct_UFunction_UShipStatusWidget_ClientOnly_RefreshAllDisplays_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * CLIENT ONLY: Refresh all displays from bound ship\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "CLIENT ONLY: Refresh all displays from bound ship" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatusWidget_ClientOnly_RefreshAllDisplays_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatusWidget, nullptr, "ClientOnly_RefreshAllDisplays", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_RefreshAllDisplays_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatusWidget_ClientOnly_RefreshAllDisplays_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UShipStatusWidget_ClientOnly_RefreshAllDisplays()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatusWidget_ClientOnly_RefreshAllDisplays_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatusWidget::execClientOnly_RefreshAllDisplays)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_RefreshAllDisplays();
	P_NATIVE_END;
}
// ********** End Class UShipStatusWidget Function ClientOnly_RefreshAllDisplays *******************

// ********** Begin Class UShipStatusWidget Function ClientOnly_UpdateArmor ************************
struct Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateArmor_Statics
{
	struct ShipStatusWidget_eventClientOnly_UpdateArmor_Parms
	{
		float ArmorPct;
		float ArmorCurrent;
		float ArmorMax;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * CLIENT ONLY: Update armor display\n * \n * @param ArmorPct Armor percentage (0.0 to 1.0)\n * @param ArmorCurrent Current armor HP\n * @param ArmorMax Maximum armor HP\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "CLIENT ONLY: Update armor display\n\n@param ArmorPct Armor percentage (0.0 to 1.0)\n@param ArmorCurrent Current armor HP\n@param ArmorMax Maximum armor HP" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ArmorPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ArmorCurrent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ArmorMax;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateArmor_Statics::NewProp_ArmorPct = { "ArmorPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventClientOnly_UpdateArmor_Parms, ArmorPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateArmor_Statics::NewProp_ArmorCurrent = { "ArmorCurrent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventClientOnly_UpdateArmor_Parms, ArmorCurrent), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateArmor_Statics::NewProp_ArmorMax = { "ArmorMax", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventClientOnly_UpdateArmor_Parms, ArmorMax), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateArmor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateArmor_Statics::NewProp_ArmorPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateArmor_Statics::NewProp_ArmorCurrent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateArmor_Statics::NewProp_ArmorMax,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateArmor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateArmor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatusWidget, nullptr, "ClientOnly_UpdateArmor", Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateArmor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateArmor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateArmor_Statics::ShipStatusWidget_eventClientOnly_UpdateArmor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateArmor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateArmor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateArmor_Statics::ShipStatusWidget_eventClientOnly_UpdateArmor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateArmor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateArmor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatusWidget::execClientOnly_UpdateArmor)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_ArmorPct);
	P_GET_PROPERTY(FFloatProperty,Z_Param_ArmorCurrent);
	P_GET_PROPERTY(FFloatProperty,Z_Param_ArmorMax);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateArmor(Z_Param_ArmorPct,Z_Param_ArmorCurrent,Z_Param_ArmorMax);
	P_NATIVE_END;
}
// ********** End Class UShipStatusWidget Function ClientOnly_UpdateArmor **************************

// ********** Begin Class UShipStatusWidget Function ClientOnly_UpdateCapacitor ********************
struct Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateCapacitor_Statics
{
	struct ShipStatusWidget_eventClientOnly_UpdateCapacitor_Parms
	{
		float CapacitorPct;
		float CapacitorCurrent;
		float CapacitorMax;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * CLIENT ONLY: Update capacitor display\n * \n * @param CapacitorPct Capacitor percentage (0.0 to 1.0)\n * @param CapacitorCurrent Current capacitor energy\n * @param CapacitorMax Maximum capacitor energy\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "CLIENT ONLY: Update capacitor display\n\n@param CapacitorPct Capacitor percentage (0.0 to 1.0)\n@param CapacitorCurrent Current capacitor energy\n@param CapacitorMax Maximum capacitor energy" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CapacitorPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CapacitorCurrent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CapacitorMax;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateCapacitor_Statics::NewProp_CapacitorPct = { "CapacitorPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventClientOnly_UpdateCapacitor_Parms, CapacitorPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateCapacitor_Statics::NewProp_CapacitorCurrent = { "CapacitorCurrent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventClientOnly_UpdateCapacitor_Parms, CapacitorCurrent), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateCapacitor_Statics::NewProp_CapacitorMax = { "CapacitorMax", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventClientOnly_UpdateCapacitor_Parms, CapacitorMax), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateCapacitor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateCapacitor_Statics::NewProp_CapacitorPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateCapacitor_Statics::NewProp_CapacitorCurrent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateCapacitor_Statics::NewProp_CapacitorMax,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateCapacitor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateCapacitor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatusWidget, nullptr, "ClientOnly_UpdateCapacitor", Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateCapacitor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateCapacitor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateCapacitor_Statics::ShipStatusWidget_eventClientOnly_UpdateCapacitor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateCapacitor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateCapacitor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateCapacitor_Statics::ShipStatusWidget_eventClientOnly_UpdateCapacitor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateCapacitor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateCapacitor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatusWidget::execClientOnly_UpdateCapacitor)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_CapacitorPct);
	P_GET_PROPERTY(FFloatProperty,Z_Param_CapacitorCurrent);
	P_GET_PROPERTY(FFloatProperty,Z_Param_CapacitorMax);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateCapacitor(Z_Param_CapacitorPct,Z_Param_CapacitorCurrent,Z_Param_CapacitorMax);
	P_NATIVE_END;
}
// ********** End Class UShipStatusWidget Function ClientOnly_UpdateCapacitor **********************

// ********** Begin Class UShipStatusWidget Function ClientOnly_UpdateHull *************************
struct Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateHull_Statics
{
	struct ShipStatusWidget_eventClientOnly_UpdateHull_Parms
	{
		float HullPct;
		float HullCurrent;
		float HullMax;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * CLIENT ONLY: Update hull display\n * \n * @param HullPct Hull percentage (0.0 to 1.0)\n * @param HullCurrent Current hull HP\n * @param HullMax Maximum hull HP\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "CLIENT ONLY: Update hull display\n\n@param HullPct Hull percentage (0.0 to 1.0)\n@param HullCurrent Current hull HP\n@param HullMax Maximum hull HP" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HullPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HullCurrent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HullMax;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateHull_Statics::NewProp_HullPct = { "HullPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventClientOnly_UpdateHull_Parms, HullPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateHull_Statics::NewProp_HullCurrent = { "HullCurrent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventClientOnly_UpdateHull_Parms, HullCurrent), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateHull_Statics::NewProp_HullMax = { "HullMax", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventClientOnly_UpdateHull_Parms, HullMax), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateHull_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateHull_Statics::NewProp_HullPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateHull_Statics::NewProp_HullCurrent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateHull_Statics::NewProp_HullMax,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateHull_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateHull_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatusWidget, nullptr, "ClientOnly_UpdateHull", Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateHull_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateHull_Statics::PropPointers), sizeof(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateHull_Statics::ShipStatusWidget_eventClientOnly_UpdateHull_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateHull_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateHull_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateHull_Statics::ShipStatusWidget_eventClientOnly_UpdateHull_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateHull()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateHull_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatusWidget::execClientOnly_UpdateHull)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_HullPct);
	P_GET_PROPERTY(FFloatProperty,Z_Param_HullCurrent);
	P_GET_PROPERTY(FFloatProperty,Z_Param_HullMax);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateHull(Z_Param_HullPct,Z_Param_HullCurrent,Z_Param_HullMax);
	P_NATIVE_END;
}
// ********** End Class UShipStatusWidget Function ClientOnly_UpdateHull ***************************

// ********** Begin Class UShipStatusWidget Function ClientOnly_UpdateShield ***********************
struct Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateShield_Statics
{
	struct ShipStatusWidget_eventClientOnly_UpdateShield_Parms
	{
		float ShieldPct;
		float ShieldCurrent;
		float ShieldMax;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * CLIENT ONLY: Update shield display\n * \n * @param ShieldPct Shield percentage (0.0 to 1.0)\n * @param ShieldCurrent Current shield HP\n * @param ShieldMax Maximum shield HP\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "CLIENT ONLY: Update shield display\n\n@param ShieldPct Shield percentage (0.0 to 1.0)\n@param ShieldCurrent Current shield HP\n@param ShieldMax Maximum shield HP" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShieldPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShieldCurrent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShieldMax;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateShield_Statics::NewProp_ShieldPct = { "ShieldPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventClientOnly_UpdateShield_Parms, ShieldPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateShield_Statics::NewProp_ShieldCurrent = { "ShieldCurrent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventClientOnly_UpdateShield_Parms, ShieldCurrent), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateShield_Statics::NewProp_ShieldMax = { "ShieldMax", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventClientOnly_UpdateShield_Parms, ShieldMax), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateShield_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateShield_Statics::NewProp_ShieldPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateShield_Statics::NewProp_ShieldCurrent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateShield_Statics::NewProp_ShieldMax,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateShield_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateShield_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatusWidget, nullptr, "ClientOnly_UpdateShield", Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateShield_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateShield_Statics::PropPointers), sizeof(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateShield_Statics::ShipStatusWidget_eventClientOnly_UpdateShield_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateShield_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateShield_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateShield_Statics::ShipStatusWidget_eventClientOnly_UpdateShield_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateShield()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateShield_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatusWidget::execClientOnly_UpdateShield)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_ShieldPct);
	P_GET_PROPERTY(FFloatProperty,Z_Param_ShieldCurrent);
	P_GET_PROPERTY(FFloatProperty,Z_Param_ShieldMax);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateShield(Z_Param_ShieldPct,Z_Param_ShieldCurrent,Z_Param_ShieldMax);
	P_NATIVE_END;
}
// ********** End Class UShipStatusWidget Function ClientOnly_UpdateShield *************************

// ********** Begin Class UShipStatusWidget Function Common_GetHealthColor *************************
struct Z_Construct_UFunction_UShipStatusWidget_Common_GetHealthColor_Statics
{
	struct ShipStatusWidget_eventCommon_GetHealthColor_Parms
	{
		float Percentage;
		FLinearColor ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * COMMON (Pure): Get color for health percentage\n * \n * @param Percentage Health percentage (0-1)\n * @return Color (Green > 66%, Yellow 33-66%, Red < 33%)\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "COMMON (Pure): Get color for health percentage\n\n@param Percentage Health percentage (0-1)\n@return Color (Green > 66%, Yellow 33-66%, Red < 33%)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Percentage;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_Common_GetHealthColor_Statics::NewProp_Percentage = { "Percentage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventCommon_GetHealthColor_Parms, Percentage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UShipStatusWidget_Common_GetHealthColor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventCommon_GetHealthColor_Parms, ReturnValue), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatusWidget_Common_GetHealthColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_Common_GetHealthColor_Statics::NewProp_Percentage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_Common_GetHealthColor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_Common_GetHealthColor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatusWidget_Common_GetHealthColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatusWidget, nullptr, "Common_GetHealthColor", Z_Construct_UFunction_UShipStatusWidget_Common_GetHealthColor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_Common_GetHealthColor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UShipStatusWidget_Common_GetHealthColor_Statics::ShipStatusWidget_eventCommon_GetHealthColor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_Common_GetHealthColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatusWidget_Common_GetHealthColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShipStatusWidget_Common_GetHealthColor_Statics::ShipStatusWidget_eventCommon_GetHealthColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatusWidget_Common_GetHealthColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatusWidget_Common_GetHealthColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatusWidget::execCommon_GetHealthColor)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Percentage);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FLinearColor*)Z_Param__Result=UShipStatusWidget::Common_GetHealthColor(Z_Param_Percentage);
	P_NATIVE_END;
}
// ********** End Class UShipStatusWidget Function Common_GetHealthColor ***************************

// ********** Begin Class UShipStatusWidget Function HandlePeriodicUpdate **************************
struct Z_Construct_UFunction_UShipStatusWidget_HandlePeriodicUpdate_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Periodic update function called by timer\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Periodic update function called by timer" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatusWidget_HandlePeriodicUpdate_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatusWidget, nullptr, "HandlePeriodicUpdate", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_HandlePeriodicUpdate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatusWidget_HandlePeriodicUpdate_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UShipStatusWidget_HandlePeriodicUpdate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatusWidget_HandlePeriodicUpdate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatusWidget::execHandlePeriodicUpdate)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandlePeriodicUpdate();
	P_NATIVE_END;
}
// ********** End Class UShipStatusWidget Function HandlePeriodicUpdate ****************************

// ********** Begin Class UShipStatusWidget Function OnArmorChanged ********************************
struct ShipStatusWidget_eventOnArmorChanged_Parms
{
	float NewPct;
	float OldPct;
};
static FName NAME_UShipStatusWidget_OnArmorChanged = FName(TEXT("OnArmorChanged"));
void UShipStatusWidget::OnArmorChanged(float NewPct, float OldPct)
{
	ShipStatusWidget_eventOnArmorChanged_Parms Parms;
	Parms.NewPct=NewPct;
	Parms.OldPct=OldPct;
	UFunction* Func = FindFunctionChecked(NAME_UShipStatusWidget_OnArmorChanged);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UShipStatusWidget_OnArmorChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Status Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Called when armor changes\n * Override in Blueprint for custom animations\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when armor changes\nOverride in Blueprint for custom animations" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OldPct;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_OnArmorChanged_Statics::NewProp_NewPct = { "NewPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventOnArmorChanged_Parms, NewPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_OnArmorChanged_Statics::NewProp_OldPct = { "OldPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventOnArmorChanged_Parms, OldPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatusWidget_OnArmorChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_OnArmorChanged_Statics::NewProp_NewPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_OnArmorChanged_Statics::NewProp_OldPct,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_OnArmorChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatusWidget_OnArmorChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatusWidget, nullptr, "OnArmorChanged", Z_Construct_UFunction_UShipStatusWidget_OnArmorChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_OnArmorChanged_Statics::PropPointers), sizeof(ShipStatusWidget_eventOnArmorChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_OnArmorChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatusWidget_OnArmorChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ShipStatusWidget_eventOnArmorChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatusWidget_OnArmorChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatusWidget_OnArmorChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UShipStatusWidget Function OnArmorChanged **********************************

// ********** Begin Class UShipStatusWidget Function OnCapacitorChangedBP **************************
struct ShipStatusWidget_eventOnCapacitorChangedBP_Parms
{
	float NewPct;
	float OldPct;
};
static FName NAME_UShipStatusWidget_OnCapacitorChangedBP = FName(TEXT("OnCapacitorChangedBP"));
void UShipStatusWidget::OnCapacitorChangedBP(float NewPct, float OldPct)
{
	ShipStatusWidget_eventOnCapacitorChangedBP_Parms Parms;
	Parms.NewPct=NewPct;
	Parms.OldPct=OldPct;
	UFunction* Func = FindFunctionChecked(NAME_UShipStatusWidget_OnCapacitorChangedBP);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UShipStatusWidget_OnCapacitorChangedBP_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Status Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Called when capacitor changes\n * Override in Blueprint for pulsing effects\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when capacitor changes\nOverride in Blueprint for pulsing effects" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OldPct;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_OnCapacitorChangedBP_Statics::NewProp_NewPct = { "NewPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventOnCapacitorChangedBP_Parms, NewPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_OnCapacitorChangedBP_Statics::NewProp_OldPct = { "OldPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventOnCapacitorChangedBP_Parms, OldPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatusWidget_OnCapacitorChangedBP_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_OnCapacitorChangedBP_Statics::NewProp_NewPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_OnCapacitorChangedBP_Statics::NewProp_OldPct,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_OnCapacitorChangedBP_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatusWidget_OnCapacitorChangedBP_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatusWidget, nullptr, "OnCapacitorChangedBP", Z_Construct_UFunction_UShipStatusWidget_OnCapacitorChangedBP_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_OnCapacitorChangedBP_Statics::PropPointers), sizeof(ShipStatusWidget_eventOnCapacitorChangedBP_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_OnCapacitorChangedBP_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatusWidget_OnCapacitorChangedBP_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ShipStatusWidget_eventOnCapacitorChangedBP_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatusWidget_OnCapacitorChangedBP()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatusWidget_OnCapacitorChangedBP_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UShipStatusWidget Function OnCapacitorChangedBP ****************************

// ********** Begin Class UShipStatusWidget Function OnHullChanged *********************************
struct ShipStatusWidget_eventOnHullChanged_Parms
{
	float NewPct;
	float OldPct;
};
static FName NAME_UShipStatusWidget_OnHullChanged = FName(TEXT("OnHullChanged"));
void UShipStatusWidget::OnHullChanged(float NewPct, float OldPct)
{
	ShipStatusWidget_eventOnHullChanged_Parms Parms;
	Parms.NewPct=NewPct;
	Parms.OldPct=OldPct;
	UFunction* Func = FindFunctionChecked(NAME_UShipStatusWidget_OnHullChanged);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UShipStatusWidget_OnHullChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Status Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Called when hull changes (CRITICAL!)\n * Override in Blueprint for warning animations\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when hull changes (CRITICAL!)\nOverride in Blueprint for warning animations" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OldPct;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_OnHullChanged_Statics::NewProp_NewPct = { "NewPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventOnHullChanged_Parms, NewPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_OnHullChanged_Statics::NewProp_OldPct = { "OldPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventOnHullChanged_Parms, OldPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatusWidget_OnHullChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_OnHullChanged_Statics::NewProp_NewPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_OnHullChanged_Statics::NewProp_OldPct,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_OnHullChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatusWidget_OnHullChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatusWidget, nullptr, "OnHullChanged", Z_Construct_UFunction_UShipStatusWidget_OnHullChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_OnHullChanged_Statics::PropPointers), sizeof(ShipStatusWidget_eventOnHullChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_OnHullChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatusWidget_OnHullChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ShipStatusWidget_eventOnHullChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatusWidget_OnHullChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatusWidget_OnHullChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UShipStatusWidget Function OnHullChanged ***********************************

// ********** Begin Class UShipStatusWidget Function OnShieldChanged *******************************
struct ShipStatusWidget_eventOnShieldChanged_Parms
{
	float NewPct;
	float OldPct;
};
static FName NAME_UShipStatusWidget_OnShieldChanged = FName(TEXT("OnShieldChanged"));
void UShipStatusWidget::OnShieldChanged(float NewPct, float OldPct)
{
	ShipStatusWidget_eventOnShieldChanged_Parms Parms;
	Parms.NewPct=NewPct;
	Parms.OldPct=OldPct;
	UFunction* Func = FindFunctionChecked(NAME_UShipStatusWidget_OnShieldChanged);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UShipStatusWidget_OnShieldChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Status Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Called when shield changes\n * Override in Blueprint for custom animations\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when shield changes\nOverride in Blueprint for custom animations" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OldPct;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_OnShieldChanged_Statics::NewProp_NewPct = { "NewPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventOnShieldChanged_Parms, NewPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatusWidget_OnShieldChanged_Statics::NewProp_OldPct = { "OldPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatusWidget_eventOnShieldChanged_Parms, OldPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatusWidget_OnShieldChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_OnShieldChanged_Statics::NewProp_NewPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatusWidget_OnShieldChanged_Statics::NewProp_OldPct,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_OnShieldChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatusWidget_OnShieldChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatusWidget, nullptr, "OnShieldChanged", Z_Construct_UFunction_UShipStatusWidget_OnShieldChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_OnShieldChanged_Statics::PropPointers), sizeof(ShipStatusWidget_eventOnShieldChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_OnShieldChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatusWidget_OnShieldChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ShipStatusWidget_eventOnShieldChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatusWidget_OnShieldChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatusWidget_OnShieldChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UShipStatusWidget Function OnShieldChanged *********************************

// ********** Begin Class UShipStatusWidget Function UnbindFromShip ********************************
struct Z_Construct_UFunction_UShipStatusWidget_UnbindFromShip_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Unbind from current ship\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unbind from current ship" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatusWidget_UnbindFromShip_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatusWidget, nullptr, "UnbindFromShip", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatusWidget_UnbindFromShip_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatusWidget_UnbindFromShip_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UShipStatusWidget_UnbindFromShip()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatusWidget_UnbindFromShip_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatusWidget::execUnbindFromShip)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UnbindFromShip();
	P_NATIVE_END;
}
// ********** End Class UShipStatusWidget Function UnbindFromShip **********************************

// ********** Begin Class UShipStatusWidget ********************************************************
void UShipStatusWidget::StaticRegisterNativesUShipStatusWidget()
{
	UClass* Class = UShipStatusWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "BindToShip", &UShipStatusWidget::execBindToShip },
		{ "ClientOnly_RefreshAllDisplays", &UShipStatusWidget::execClientOnly_RefreshAllDisplays },
		{ "ClientOnly_UpdateArmor", &UShipStatusWidget::execClientOnly_UpdateArmor },
		{ "ClientOnly_UpdateCapacitor", &UShipStatusWidget::execClientOnly_UpdateCapacitor },
		{ "ClientOnly_UpdateHull", &UShipStatusWidget::execClientOnly_UpdateHull },
		{ "ClientOnly_UpdateShield", &UShipStatusWidget::execClientOnly_UpdateShield },
		{ "Common_GetHealthColor", &UShipStatusWidget::execCommon_GetHealthColor },
		{ "HandlePeriodicUpdate", &UShipStatusWidget::execHandlePeriodicUpdate },
		{ "UnbindFromShip", &UShipStatusWidget::execUnbindFromShip },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UShipStatusWidget;
UClass* UShipStatusWidget::GetPrivateStaticClass()
{
	using TClass = UShipStatusWidget;
	if (!Z_Registration_Info_UClass_UShipStatusWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ShipStatusWidget"),
			Z_Registration_Info_UClass_UShipStatusWidget.InnerSingleton,
			StaticRegisterNativesUShipStatusWidget,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UShipStatusWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UShipStatusWidget_NoRegister()
{
	return UShipStatusWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UShipStatusWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UShipStatusWidget\n * \n * Central radial HUD display showing ship survivability\n * EVE-like circular health bars with capacitor in center\n * \n * Features:\n * - Radial progress bars: Shield (outer), Armor (middle), Hull (inner)\n * - Central capacitor display with animation\n * - Color-coded health states (green/yellow/red)\n * - Event-driven updates (implements IShipStateObserver)\n * - No Tick function for performance\n * \n * Visual Layout:\n * ```\n *     \xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x90\n *     \xe2\x94\x82   Shield    \xe2\x94\x82 Outer ring (blue)\n *     \xe2\x94\x82  \xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x90  \xe2\x94\x82\n *     \xe2\x94\x82  \xe2\x94\x82 Armor \xe2\x94\x82  \xe2\x94\x82 Middle ring (yellow/orange)\n *     \xe2\x94\x82  \xe2\x94\x82 \xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x90 \xe2\x94\x82  \xe2\x94\x82\n *     \xe2\x94\x82  \xe2\x94\x82 \xe2\x94\x82""Cap\xe2\x94\x82 \xe2\x94\x82  \xe2\x94\x82 Inner = Hull (red), Center = Capacitor\n *     \xe2\x94\x82  \xe2\x94\x82 \xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x98 \xe2\x94\x82  \xe2\x94\x82\n *     \xe2\x94\x82  \xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x98  \xe2\x94\x82\n *     \xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x98\n * ```\n * \n * Implementation Options:\n * 1. Blueprint: Use Progress Bar widgets with custom materials\n * 2. C++: Use UMG Canvas with custom radial drawing\n * 3. Hybrid: C++ logic + Blueprint materials\n * \n * Usage:\n * // Bind to ship state interface\n * ShipStatusWidget->BindToShip(PlayerShip);\n * \n * // Updates automatically via IShipStateObserver\n */" },
#endif
		{ "IncludePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UShipStatusWidget\n\nCentral radial HUD display showing ship survivability\nEVE-like circular health bars with capacitor in center\n\nFeatures:\n- Radial progress bars: Shield (outer), Armor (middle), Hull (inner)\n- Central capacitor display with animation\n- Color-coded health states (green/yellow/red)\n- Event-driven updates (implements IShipStateObserver)\n- No Tick function for performance\n\nVisual Layout:\n```\n    \xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x90\n    \xe2\x94\x82   Shield    \xe2\x94\x82 Outer ring (blue)\n    \xe2\x94\x82  \xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x90  \xe2\x94\x82\n    \xe2\x94\x82  \xe2\x94\x82 Armor \xe2\x94\x82  \xe2\x94\x82 Middle ring (yellow/orange)\n    \xe2\x94\x82  \xe2\x94\x82 \xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x90 \xe2\x94\x82  \xe2\x94\x82\n    \xe2\x94\x82  \xe2\x94\x82 \xe2\x94\x82""Cap\xe2\x94\x82 \xe2\x94\x82  \xe2\x94\x82 Inner = Hull (red), Center = Capacitor\n    \xe2\x94\x82  \xe2\x94\x82 \xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x98 \xe2\x94\x82  \xe2\x94\x82\n    \xe2\x94\x82  \xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x98  \xe2\x94\x82\n    \xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x98\n```\n\nImplementation Options:\n1. Blueprint: Use Progress Bar widgets with custom materials\n2. C++: Use UMG Canvas with custom radial drawing\n3. Hybrid: C++ logic + Blueprint materials\n\nUsage:\n// Bind to ship state interface\nShipStatusWidget->BindToShip(PlayerShip);\n\n// Updates automatically via IShipStateObserver" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShieldBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "ShipStatusWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shield progress bar (outer ring) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shield progress bar (outer ring)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArmorBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "ShipStatusWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Armor progress bar (middle ring) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Armor progress bar (middle ring)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HullBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "ShipStatusWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Hull progress bar (inner ring) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hull progress bar (inner ring)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CapacitorBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "ShipStatusWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Capacitor progress bar (center) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Capacitor progress bar (center)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShieldText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "ShipStatusWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shield value text */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shield value text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArmorText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "ShipStatusWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Armor value text */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Armor value text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HullText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "ShipStatusWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Hull value text */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hull value text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CapacitorText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "ShipStatusWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Capacitor value text */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Capacitor value text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UpdateInterval_MetaData[] = {
		{ "Category", "Ship Status Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Update interval for polling ship state (seconds) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update interval for polling ship state (seconds)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableAnimations_MetaData[] = {
		{ "Category", "Ship Status Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Enable smooth animations for value changes */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enable smooth animations for value changes" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimationSpeed_MetaData[] = {
		{ "Category", "Ship Status Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Animation speed for smooth transitions */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Animation speed for smooth transitions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoundShip_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current bound ship */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current bound ship" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentShieldPct_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current shield percentage (for interpolation) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current shield percentage (for interpolation)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentArmorPct_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current armor percentage (for interpolation) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current armor percentage (for interpolation)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentHullPct_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current hull percentage (for interpolation) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current hull percentage (for interpolation)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentCapacitorPct_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current capacitor percentage (for interpolation) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/ShipStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current capacitor percentage (for interpolation)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShieldBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ArmorBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HullBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CapacitorBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShieldText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ArmorText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HullText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CapacitorText;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UpdateInterval;
	static void NewProp_bEnableAnimations_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableAnimations;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AnimationSpeed;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BoundShip;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentShieldPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentArmorPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentHullPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentCapacitorPct;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UShipStatusWidget_BindToShip, "BindToShip" }, // 1691426600
		{ &Z_Construct_UFunction_UShipStatusWidget_ClientOnly_RefreshAllDisplays, "ClientOnly_RefreshAllDisplays" }, // 3139854888
		{ &Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateArmor, "ClientOnly_UpdateArmor" }, // 2845037174
		{ &Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateCapacitor, "ClientOnly_UpdateCapacitor" }, // 939291997
		{ &Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateHull, "ClientOnly_UpdateHull" }, // 833498281
		{ &Z_Construct_UFunction_UShipStatusWidget_ClientOnly_UpdateShield, "ClientOnly_UpdateShield" }, // 2771421057
		{ &Z_Construct_UFunction_UShipStatusWidget_Common_GetHealthColor, "Common_GetHealthColor" }, // 3398324271
		{ &Z_Construct_UFunction_UShipStatusWidget_HandlePeriodicUpdate, "HandlePeriodicUpdate" }, // 3097594033
		{ &Z_Construct_UFunction_UShipStatusWidget_OnArmorChanged, "OnArmorChanged" }, // 4235656911
		{ &Z_Construct_UFunction_UShipStatusWidget_OnCapacitorChangedBP, "OnCapacitorChangedBP" }, // 2257622928
		{ &Z_Construct_UFunction_UShipStatusWidget_OnHullChanged, "OnHullChanged" }, // 2881730899
		{ &Z_Construct_UFunction_UShipStatusWidget_OnShieldChanged, "OnShieldChanged" }, // 3310614989
		{ &Z_Construct_UFunction_UShipStatusWidget_UnbindFromShip, "UnbindFromShip" }, // 1147015620
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UShipStatusWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_ShieldBar = { "ShieldBar", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatusWidget, ShieldBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShieldBar_MetaData), NewProp_ShieldBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_ArmorBar = { "ArmorBar", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatusWidget, ArmorBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArmorBar_MetaData), NewProp_ArmorBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_HullBar = { "HullBar", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatusWidget, HullBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HullBar_MetaData), NewProp_HullBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_CapacitorBar = { "CapacitorBar", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatusWidget, CapacitorBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CapacitorBar_MetaData), NewProp_CapacitorBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_ShieldText = { "ShieldText", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatusWidget, ShieldText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShieldText_MetaData), NewProp_ShieldText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_ArmorText = { "ArmorText", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatusWidget, ArmorText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArmorText_MetaData), NewProp_ArmorText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_HullText = { "HullText", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatusWidget, HullText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HullText_MetaData), NewProp_HullText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_CapacitorText = { "CapacitorText", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatusWidget, CapacitorText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CapacitorText_MetaData), NewProp_CapacitorText_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_UpdateInterval = { "UpdateInterval", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatusWidget, UpdateInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UpdateInterval_MetaData), NewProp_UpdateInterval_MetaData) };
void Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_bEnableAnimations_SetBit(void* Obj)
{
	((UShipStatusWidget*)Obj)->bEnableAnimations = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_bEnableAnimations = { "bEnableAnimations", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UShipStatusWidget), &Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_bEnableAnimations_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableAnimations_MetaData), NewProp_bEnableAnimations_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_AnimationSpeed = { "AnimationSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatusWidget, AnimationSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimationSpeed_MetaData), NewProp_AnimationSpeed_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_BoundShip = { "BoundShip", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatusWidget, BoundShip), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoundShip_MetaData), NewProp_BoundShip_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_CurrentShieldPct = { "CurrentShieldPct", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatusWidget, CurrentShieldPct), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentShieldPct_MetaData), NewProp_CurrentShieldPct_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_CurrentArmorPct = { "CurrentArmorPct", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatusWidget, CurrentArmorPct), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentArmorPct_MetaData), NewProp_CurrentArmorPct_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_CurrentHullPct = { "CurrentHullPct", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatusWidget, CurrentHullPct), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentHullPct_MetaData), NewProp_CurrentHullPct_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_CurrentCapacitorPct = { "CurrentCapacitorPct", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatusWidget, CurrentCapacitorPct), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentCapacitorPct_MetaData), NewProp_CurrentCapacitorPct_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UShipStatusWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_ShieldBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_ArmorBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_HullBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_CapacitorBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_ShieldText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_ArmorText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_HullText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_CapacitorText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_UpdateInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_bEnableAnimations,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_AnimationSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_BoundShip,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_CurrentShieldPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_CurrentArmorPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_CurrentHullPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatusWidget_Statics::NewProp_CurrentCapacitorPct,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UShipStatusWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UShipStatusWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UShipStatusWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UShipStatusWidget_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UShipStateObserver_NoRegister, (int32)VTABLE_OFFSET(UShipStatusWidget, IShipStateObserver), false },  // 2010149196
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UShipStatusWidget_Statics::ClassParams = {
	&UShipStatusWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UShipStatusWidget_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UShipStatusWidget_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UShipStatusWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UShipStatusWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UShipStatusWidget()
{
	if (!Z_Registration_Info_UClass_UShipStatusWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UShipStatusWidget.OuterSingleton, Z_Construct_UClass_UShipStatusWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UShipStatusWidget.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UShipStatusWidget);
UShipStatusWidget::~UShipStatusWidget() {}
// ********** End Class UShipStatusWidget **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UShipStateObserver, UShipStateObserver::StaticClass, TEXT("UShipStateObserver"), &Z_Registration_Info_UClass_UShipStateObserver, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UShipStateObserver), 2010149196U) },
		{ Z_Construct_UClass_UShipStatusWidget, UShipStatusWidget::StaticClass, TEXT("UShipStatusWidget"), &Z_Registration_Info_UClass_UShipStatusWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UShipStatusWidget), 3698541082U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h__Script_Echoes_2056702759(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
