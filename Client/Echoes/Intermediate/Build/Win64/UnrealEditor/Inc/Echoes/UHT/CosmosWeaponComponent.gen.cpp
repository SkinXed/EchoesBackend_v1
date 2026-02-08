// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CosmosWeaponComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeCosmosWeaponComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ECHOES_API UClass* Z_Construct_UClass_ACosmosProjectile_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UCosmosWeaponComponent();
ECHOES_API UClass* Z_Construct_UClass_UCosmosWeaponComponent_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_ECosmosDamageType();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UCosmosWeaponComponent Function CanFire **********************************
struct Z_Construct_UFunction_UCosmosWeaponComponent_CanFire_Statics
{
	struct CosmosWeaponComponent_eventCanFire_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if weapon is ready to fire (cooldown expired)\n\x09 * \n\x09 * @return True if cooldown has expired\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosWeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if weapon is ready to fire (cooldown expired)\n\n@return True if cooldown has expired" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UCosmosWeaponComponent_CanFire_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CosmosWeaponComponent_eventCanFire_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCosmosWeaponComponent_CanFire_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CosmosWeaponComponent_eventCanFire_Parms), &Z_Construct_UFunction_UCosmosWeaponComponent_CanFire_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCosmosWeaponComponent_CanFire_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosWeaponComponent_CanFire_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosWeaponComponent_CanFire_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCosmosWeaponComponent_CanFire_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCosmosWeaponComponent, nullptr, "CanFire", Z_Construct_UFunction_UCosmosWeaponComponent_CanFire_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosWeaponComponent_CanFire_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCosmosWeaponComponent_CanFire_Statics::CosmosWeaponComponent_eventCanFire_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosWeaponComponent_CanFire_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCosmosWeaponComponent_CanFire_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCosmosWeaponComponent_CanFire_Statics::CosmosWeaponComponent_eventCanFire_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCosmosWeaponComponent_CanFire()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCosmosWeaponComponent_CanFire_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCosmosWeaponComponent::execCanFire)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanFire();
	P_NATIVE_END;
}
// ********** End Class UCosmosWeaponComponent Function CanFire ************************************

// ********** Begin Class UCosmosWeaponComponent Function Common_GetPredictionLocation *************
struct Z_Construct_UFunction_UCosmosWeaponComponent_Common_GetPredictionLocation_Statics
{
	struct CosmosWeaponComponent_eventCommon_GetPredictionLocation_Parms
	{
		AActor* Target;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Calculate prediction point for target leading (First-Order Intercept)\n\x09 * Pure math function - works on server and client\n\x09 * \n\x09 * @param Target - Actor to predict position for\n\x09 * @return Predicted world position where target will be when projectile arrives\n\x09 * \n\x09 * Algorithm:\n\x09 * 1. Get relative position and velocity vectors\n\x09 * 2. Solve quadratic equation for intercept time\n\x09 * 3. Calculate predicted position = current + velocity * time\n\x09 * 4. Return predicted point or current position if no solution\n\x09 * \n\x09 * Math:\n\x09 * Let t = time to intercept\n\x09 * Target position: Pt = P0 + Vt * t\n\x09 * Projectile travel: |Pt - Pw| = Vp * t\n\x09 * Solve for t, then calculate Pt\n\x09 * \n\x09 * Example:\n\x09 * FVector PredictionPoint = WeaponComp->Common_GetPredictionLocation(TargetShip);\n\x09 * AimDirection = (PredictionPoint - WeaponComp->GetComponentLocation()).GetSafeNormal();\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosWeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Calculate prediction point for target leading (First-Order Intercept)\nPure math function - works on server and client\n\n@param Target - Actor to predict position for\n@return Predicted world position where target will be when projectile arrives\n\nAlgorithm:\n1. Get relative position and velocity vectors\n2. Solve quadratic equation for intercept time\n3. Calculate predicted position = current + velocity * time\n4. Return predicted point or current position if no solution\n\nMath:\nLet t = time to intercept\nTarget position: Pt = P0 + Vt * t\nProjectile travel: |Pt - Pw| = Vp * t\nSolve for t, then calculate Pt\n\nExample:\nFVector PredictionPoint = WeaponComp->Common_GetPredictionLocation(TargetShip);\nAimDirection = (PredictionPoint - WeaponComp->GetComponentLocation()).GetSafeNormal();" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCosmosWeaponComponent_Common_GetPredictionLocation_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosWeaponComponent_eventCommon_GetPredictionLocation_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCosmosWeaponComponent_Common_GetPredictionLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosWeaponComponent_eventCommon_GetPredictionLocation_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCosmosWeaponComponent_Common_GetPredictionLocation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosWeaponComponent_Common_GetPredictionLocation_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosWeaponComponent_Common_GetPredictionLocation_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosWeaponComponent_Common_GetPredictionLocation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCosmosWeaponComponent_Common_GetPredictionLocation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCosmosWeaponComponent, nullptr, "Common_GetPredictionLocation", Z_Construct_UFunction_UCosmosWeaponComponent_Common_GetPredictionLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosWeaponComponent_Common_GetPredictionLocation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCosmosWeaponComponent_Common_GetPredictionLocation_Statics::CosmosWeaponComponent_eventCommon_GetPredictionLocation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosWeaponComponent_Common_GetPredictionLocation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCosmosWeaponComponent_Common_GetPredictionLocation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCosmosWeaponComponent_Common_GetPredictionLocation_Statics::CosmosWeaponComponent_eventCommon_GetPredictionLocation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCosmosWeaponComponent_Common_GetPredictionLocation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCosmosWeaponComponent_Common_GetPredictionLocation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCosmosWeaponComponent::execCommon_GetPredictionLocation)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->Common_GetPredictionLocation(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UCosmosWeaponComponent Function Common_GetPredictionLocation ***************

// ********** Begin Class UCosmosWeaponComponent Function GetCooldownRemaining *********************
struct Z_Construct_UFunction_UCosmosWeaponComponent_GetCooldownRemaining_Statics
{
	struct CosmosWeaponComponent_eventGetCooldownRemaining_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get current cooldown remaining in seconds\n\x09 * \n\x09 * @return Seconds until weapon can fire again (0.0 if ready)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosWeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get current cooldown remaining in seconds\n\n@return Seconds until weapon can fire again (0.0 if ready)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCosmosWeaponComponent_GetCooldownRemaining_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosWeaponComponent_eventGetCooldownRemaining_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCosmosWeaponComponent_GetCooldownRemaining_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosWeaponComponent_GetCooldownRemaining_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosWeaponComponent_GetCooldownRemaining_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCosmosWeaponComponent_GetCooldownRemaining_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCosmosWeaponComponent, nullptr, "GetCooldownRemaining", Z_Construct_UFunction_UCosmosWeaponComponent_GetCooldownRemaining_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosWeaponComponent_GetCooldownRemaining_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCosmosWeaponComponent_GetCooldownRemaining_Statics::CosmosWeaponComponent_eventGetCooldownRemaining_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosWeaponComponent_GetCooldownRemaining_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCosmosWeaponComponent_GetCooldownRemaining_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCosmosWeaponComponent_GetCooldownRemaining_Statics::CosmosWeaponComponent_eventGetCooldownRemaining_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCosmosWeaponComponent_GetCooldownRemaining()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCosmosWeaponComponent_GetCooldownRemaining_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCosmosWeaponComponent::execGetCooldownRemaining)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetCooldownRemaining();
	P_NATIVE_END;
}
// ********** End Class UCosmosWeaponComponent Function GetCooldownRemaining ***********************

// ********** Begin Class UCosmosWeaponComponent Function ServerOnly_Fire **************************
struct Z_Construct_UFunction_UCosmosWeaponComponent_ServerOnly_Fire_Statics
{
	struct CosmosWeaponComponent_eventServerOnly_Fire_Parms
	{
		AActor* Target;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Fire weapon at target (Server Only)\n\x09 * Checks cooldown, spawns projectile with prediction\n\x09 * \n\x09 * @param Target - Actor to fire at (can be nullptr for dumbfire)\n\x09 * \n\x09 * Behavior:\n\x09 * - Validates server authority\n\x09 * - Checks fire rate cooldown\n\x09 * - Calculates prediction point if target provided\n\x09 * - Spawns projectile (deferred)\n\x09 * - Initializes projectile with weapon stats\n\x09 * - Finishes spawning projectile\n\x09 * - Starts cooldown timer\n\x09 * \n\x09 * Example:\n\x09 * if (HasAuthority())\n\x09 * {\n\x09 *     WeaponComp->ServerOnly_Fire(EnemyShip);\n\x09 * }\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosWeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fire weapon at target (Server Only)\nChecks cooldown, spawns projectile with prediction\n\n@param Target - Actor to fire at (can be nullptr for dumbfire)\n\nBehavior:\n- Validates server authority\n- Checks fire rate cooldown\n- Calculates prediction point if target provided\n- Spawns projectile (deferred)\n- Initializes projectile with weapon stats\n- Finishes spawning projectile\n- Starts cooldown timer\n\nExample:\nif (HasAuthority())\n{\n    WeaponComp->ServerOnly_Fire(EnemyShip);\n}" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCosmosWeaponComponent_ServerOnly_Fire_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosWeaponComponent_eventServerOnly_Fire_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCosmosWeaponComponent_ServerOnly_Fire_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosWeaponComponent_ServerOnly_Fire_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosWeaponComponent_ServerOnly_Fire_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCosmosWeaponComponent_ServerOnly_Fire_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCosmosWeaponComponent, nullptr, "ServerOnly_Fire", Z_Construct_UFunction_UCosmosWeaponComponent_ServerOnly_Fire_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosWeaponComponent_ServerOnly_Fire_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCosmosWeaponComponent_ServerOnly_Fire_Statics::CosmosWeaponComponent_eventServerOnly_Fire_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosWeaponComponent_ServerOnly_Fire_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCosmosWeaponComponent_ServerOnly_Fire_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCosmosWeaponComponent_ServerOnly_Fire_Statics::CosmosWeaponComponent_eventServerOnly_Fire_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCosmosWeaponComponent_ServerOnly_Fire()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCosmosWeaponComponent_ServerOnly_Fire_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCosmosWeaponComponent::execServerOnly_Fire)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_Fire(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UCosmosWeaponComponent Function ServerOnly_Fire ****************************

// ********** Begin Class UCosmosWeaponComponent ***************************************************
void UCosmosWeaponComponent::StaticRegisterNativesUCosmosWeaponComponent()
{
	UClass* Class = UCosmosWeaponComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CanFire", &UCosmosWeaponComponent::execCanFire },
		{ "Common_GetPredictionLocation", &UCosmosWeaponComponent::execCommon_GetPredictionLocation },
		{ "GetCooldownRemaining", &UCosmosWeaponComponent::execGetCooldownRemaining },
		{ "ServerOnly_Fire", &UCosmosWeaponComponent::execServerOnly_Fire },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCosmosWeaponComponent;
UClass* UCosmosWeaponComponent::GetPrivateStaticClass()
{
	using TClass = UCosmosWeaponComponent;
	if (!Z_Registration_Info_UClass_UCosmosWeaponComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("CosmosWeaponComponent"),
			Z_Registration_Info_UClass_UCosmosWeaponComponent.InnerSingleton,
			StaticRegisterNativesUCosmosWeaponComponent,
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
	return Z_Registration_Info_UClass_UCosmosWeaponComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UCosmosWeaponComponent_NoRegister()
{
	return UCosmosWeaponComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCosmosWeaponComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Echoes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UCosmosWeaponComponent\n * \n * EVE-like weapon component for ship-mounted turrets and launchers\n * Handles target prediction, fire rate, and projectile spawning\n * \n * Architecture:\n * - SceneComponent: Attached to ship at weapon mount point (muzzle socket)\n * - Server-authoritative: Only server can fire weapons\n * - Target prediction: Calculates lead point for moving targets\n * - Deferred spawning: Initializes projectiles before completing spawn\n * \n * Weapon Stats:\n * - BaseDamage: Raw damage before resistance mitigation\n * - DamageType: Type of damage (EM, Thermal, Kinetic, Explosive, Omni)\n * - MuzzleVelocity: Projectile speed in cm/s (for prediction calculations)\n * - FireRate: Shots per second (cooldown management)\n * \n * Target Prediction:\n * Uses First-Order Intercept algorithm to calculate where to aim\n * Accounts for target velocity and projectile speed\n * Returns prediction point in world space\n * \n * Fire Sequence:\n * 1. Check fire rate cooldown\n * 2. Calculate prediction point\n * 3. Spawn projectile (deferred)\n * 4. Initialize projectile with damage/type/speed\n * 5. Finish spawning projectile\n * 6. Start cooldown timer\n * \n * Usage:\n * // Attach weapon to ship\n * WeaponComp->AttachToComponent(ShipMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, \n *     TEXT(\"WeaponSocket_01\"));\n * \n * // Fire at target\n * WeaponComp->ServerOnly_Fire(TargetShip);\n */" },
#endif
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "Core/Common/Components/CosmosWeaponComponent.h" },
		{ "ModuleRelativePath", "Core/Common/Components/CosmosWeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UCosmosWeaponComponent\n\nEVE-like weapon component for ship-mounted turrets and launchers\nHandles target prediction, fire rate, and projectile spawning\n\nArchitecture:\n- SceneComponent: Attached to ship at weapon mount point (muzzle socket)\n- Server-authoritative: Only server can fire weapons\n- Target prediction: Calculates lead point for moving targets\n- Deferred spawning: Initializes projectiles before completing spawn\n\nWeapon Stats:\n- BaseDamage: Raw damage before resistance mitigation\n- DamageType: Type of damage (EM, Thermal, Kinetic, Explosive, Omni)\n- MuzzleVelocity: Projectile speed in cm/s (for prediction calculations)\n- FireRate: Shots per second (cooldown management)\n\nTarget Prediction:\nUses First-Order Intercept algorithm to calculate where to aim\nAccounts for target velocity and projectile speed\nReturns prediction point in world space\n\nFire Sequence:\n1. Check fire rate cooldown\n2. Calculate prediction point\n3. Spawn projectile (deferred)\n4. Initialize projectile with damage/type/speed\n5. Finish spawning projectile\n6. Start cooldown timer\n\nUsage:\n// Attach weapon to ship\nWeaponComp->AttachToComponent(ShipMesh, FAttachmentTransformRules::SnapToTargetIncludingScale,\n    TEXT(\"WeaponSocket_01\"));\n\n// Fire at target\nWeaponComp->ServerOnly_Fire(TargetShip);" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileClass_MetaData[] = {
		{ "Category", "Weapon Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Projectile class to spawn when firing */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosWeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Projectile class to spawn when firing" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseDamage_MetaData[] = {
		{ "Category", "Weapon Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Base damage dealt by this weapon (before resistance mitigation) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosWeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base damage dealt by this weapon (before resistance mitigation)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DamageType_MetaData[] = {
		{ "Category", "Weapon Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Type of damage dealt by this weapon */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosWeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Type of damage dealt by this weapon" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MuzzleVelocity_MetaData[] = {
		{ "Category", "Weapon Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Projectile muzzle velocity in cm/s (1000 m/s = 100000 cm/s) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosWeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Projectile muzzle velocity in cm/s (1000 m/s = 100000 cm/s)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireRate_MetaData[] = {
		{ "Category", "Weapon Stats" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Rate of fire in shots per second */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosWeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rate of fire in shots per second" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_ProjectileClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseDamage;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DamageType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DamageType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MuzzleVelocity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FireRate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCosmosWeaponComponent_CanFire, "CanFire" }, // 3831301236
		{ &Z_Construct_UFunction_UCosmosWeaponComponent_Common_GetPredictionLocation, "Common_GetPredictionLocation" }, // 1388666330
		{ &Z_Construct_UFunction_UCosmosWeaponComponent_GetCooldownRemaining, "GetCooldownRemaining" }, // 807098604
		{ &Z_Construct_UFunction_UCosmosWeaponComponent_ServerOnly_Fire, "ServerOnly_Fire" }, // 3165712595
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCosmosWeaponComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UCosmosWeaponComponent_Statics::NewProp_ProjectileClass = { "ProjectileClass", nullptr, (EPropertyFlags)0x0014000000010005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCosmosWeaponComponent, ProjectileClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ACosmosProjectile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileClass_MetaData), NewProp_ProjectileClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCosmosWeaponComponent_Statics::NewProp_BaseDamage = { "BaseDamage", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCosmosWeaponComponent, BaseDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseDamage_MetaData), NewProp_BaseDamage_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCosmosWeaponComponent_Statics::NewProp_DamageType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCosmosWeaponComponent_Statics::NewProp_DamageType = { "DamageType", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCosmosWeaponComponent, DamageType), Z_Construct_UEnum_Echoes_ECosmosDamageType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DamageType_MetaData), NewProp_DamageType_MetaData) }; // 4170051619
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCosmosWeaponComponent_Statics::NewProp_MuzzleVelocity = { "MuzzleVelocity", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCosmosWeaponComponent, MuzzleVelocity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MuzzleVelocity_MetaData), NewProp_MuzzleVelocity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCosmosWeaponComponent_Statics::NewProp_FireRate = { "FireRate", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCosmosWeaponComponent, FireRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireRate_MetaData), NewProp_FireRate_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCosmosWeaponComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCosmosWeaponComponent_Statics::NewProp_ProjectileClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCosmosWeaponComponent_Statics::NewProp_BaseDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCosmosWeaponComponent_Statics::NewProp_DamageType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCosmosWeaponComponent_Statics::NewProp_DamageType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCosmosWeaponComponent_Statics::NewProp_MuzzleVelocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCosmosWeaponComponent_Statics::NewProp_FireRate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCosmosWeaponComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCosmosWeaponComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USceneComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCosmosWeaponComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCosmosWeaponComponent_Statics::ClassParams = {
	&UCosmosWeaponComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCosmosWeaponComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCosmosWeaponComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCosmosWeaponComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UCosmosWeaponComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCosmosWeaponComponent()
{
	if (!Z_Registration_Info_UClass_UCosmosWeaponComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCosmosWeaponComponent.OuterSingleton, Z_Construct_UClass_UCosmosWeaponComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCosmosWeaponComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCosmosWeaponComponent);
UCosmosWeaponComponent::~UCosmosWeaponComponent() {}
// ********** End Class UCosmosWeaponComponent *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosWeaponComponent_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCosmosWeaponComponent, UCosmosWeaponComponent::StaticClass, TEXT("UCosmosWeaponComponent"), &Z_Registration_Info_UClass_UCosmosWeaponComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCosmosWeaponComponent), 1538174068U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosWeaponComponent_h__Script_Echoes_2953960(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosWeaponComponent_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosWeaponComponent_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
