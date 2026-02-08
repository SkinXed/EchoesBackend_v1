// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CosmosProjectile.h"
#include "Engine/HitResult.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeCosmosProjectile() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ECHOES_API UClass* Z_Construct_UClass_ACosmosProjectile();
ECHOES_API UClass* Z_Construct_UClass_ACosmosProjectile_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_ECosmosDamageType();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UProjectileMovementComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ACosmosProjectile Function InitializeProjectile **************************
struct Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile_Statics
{
	struct CosmosProjectile_eventInitializeProjectile_Parms
	{
		float NewDamage;
		ECosmosDamageType NewType;
		float NewSpeed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Projectile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initialize projectile parameters before finishing spawn (Deferred Spawn Pattern)\n\x09 * Called by weapon component after SpawnActorDeferred and before FinishSpawningActor\n\x09 * \n\x09 * @param NewDamage - Raw damage amount to apply on hit\n\x09 * @param NewType - Type of damage (affects resistance mitigation)\n\x09 * @param NewSpeed - Projectile muzzle velocity in cm/s\n\x09 * \n\x09 * Example:\n\x09 * Projectile->InitializeProjectile(150.0f, ECosmosDamageType::Kinetic, 100000.0f);\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/CosmosProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize projectile parameters before finishing spawn (Deferred Spawn Pattern)\nCalled by weapon component after SpawnActorDeferred and before FinishSpawningActor\n\n@param NewDamage - Raw damage amount to apply on hit\n@param NewType - Type of damage (affects resistance mitigation)\n@param NewSpeed - Projectile muzzle velocity in cm/s\n\nExample:\nProjectile->InitializeProjectile(150.0f, ECosmosDamageType::Kinetic, 100000.0f);" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewDamage;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewSpeed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile_Statics::NewProp_NewDamage = { "NewDamage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosProjectile_eventInitializeProjectile_Parms, NewDamage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile_Statics::NewProp_NewType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile_Statics::NewProp_NewType = { "NewType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosProjectile_eventInitializeProjectile_Parms, NewType), Z_Construct_UEnum_Echoes_ECosmosDamageType, METADATA_PARAMS(0, nullptr) }; // 4170051619
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile_Statics::NewProp_NewSpeed = { "NewSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosProjectile_eventInitializeProjectile_Parms, NewSpeed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile_Statics::NewProp_NewDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile_Statics::NewProp_NewType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile_Statics::NewProp_NewType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile_Statics::NewProp_NewSpeed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACosmosProjectile, nullptr, "InitializeProjectile", Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile_Statics::CosmosProjectile_eventInitializeProjectile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile_Statics::CosmosProjectile_eventInitializeProjectile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACosmosProjectile::execInitializeProjectile)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_NewDamage);
	P_GET_ENUM(ECosmosDamageType,Z_Param_NewType);
	P_GET_PROPERTY(FFloatProperty,Z_Param_NewSpeed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeProjectile(Z_Param_NewDamage,ECosmosDamageType(Z_Param_NewType),Z_Param_NewSpeed);
	P_NATIVE_END;
}
// ********** End Class ACosmosProjectile Function InitializeProjectile ****************************

// ********** Begin Class ACosmosProjectile Function OnHit *****************************************
struct Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics
{
	struct CosmosProjectile_eventOnHit_Parms
	{
		UPrimitiveComponent* HitComponent;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComp;
		FVector NormalImpulse;
		FHitResult Hit;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called when projectile hits something\n\x09 * Applies damage to target and destroys projectile\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/CosmosProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when projectile hits something\nApplies damage to target and destroys projectile" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HitComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NormalImpulse;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hit;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::NewProp_HitComponent = { "HitComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosProjectile_eventOnHit_Parms, HitComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitComponent_MetaData), NewProp_HitComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosProjectile_eventOnHit_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosProjectile_eventOnHit_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::NewProp_NormalImpulse = { "NormalImpulse", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosProjectile_eventOnHit_Parms, NormalImpulse), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosProjectile_eventOnHit_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hit_MetaData), NewProp_Hit_MetaData) }; // 267591329
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::NewProp_HitComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::NewProp_NormalImpulse,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::NewProp_Hit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACosmosProjectile, nullptr, "OnHit", Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::CosmosProjectile_eventOnHit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C80401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::CosmosProjectile_eventOnHit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACosmosProjectile_OnHit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACosmosProjectile_OnHit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACosmosProjectile::execOnHit)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_STRUCT(FVector,Z_Param_NormalImpulse);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnHit(Z_Param_HitComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit);
	P_NATIVE_END;
}
// ********** End Class ACosmosProjectile Function OnHit *******************************************

// ********** Begin Class ACosmosProjectile ********************************************************
void ACosmosProjectile::StaticRegisterNativesACosmosProjectile()
{
	UClass* Class = ACosmosProjectile::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "InitializeProjectile", &ACosmosProjectile::execInitializeProjectile },
		{ "OnHit", &ACosmosProjectile::execOnHit },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ACosmosProjectile;
UClass* ACosmosProjectile::GetPrivateStaticClass()
{
	using TClass = ACosmosProjectile;
	if (!Z_Registration_Info_UClass_ACosmosProjectile.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("CosmosProjectile"),
			Z_Registration_Info_UClass_ACosmosProjectile.InnerSingleton,
			StaticRegisterNativesACosmosProjectile,
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
	return Z_Registration_Info_UClass_ACosmosProjectile.InnerSingleton;
}
UClass* Z_Construct_UClass_ACosmosProjectile_NoRegister()
{
	return ACosmosProjectile::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ACosmosProjectile_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * ACosmosProjectile\n * \n * EVE-like projectile actor for ship weapons\n * Handles ballistic physics, damage application, and visual effects\n * \n * Architecture:\n * - Spawned by weapon components in deferred mode\n * - Initialized with damage, type, and velocity before finishing spawn\n * - Uses ProjectileMovementComponent for realistic ballistics\n * - Applies typed damage to targets on collision\n * - Server-authoritative hit detection\n * \n * Lifecycle:\n * 1. SpawnActorDeferred() by weapon\n * 2. InitializeProjectile() sets parameters\n * 3. FinishSpawningActor() completes spawn\n * 4. ProjectileMovementComponent handles flight\n * 5. OnHit() applies damage and destroys projectile\n * \n * Usage:\n * FActorSpawnParameters SpawnParams;\n * SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;\n * ACosmosProjectile* Projectile = GetWorld()->SpawnActorDeferred<ACosmosProjectile>(\n *     ProjectileClass, SpawnTransform, Owner, Instigator, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);\n * Projectile->InitializeProjectile(100.0f, ECosmosDamageType::Kinetic, 1000.0f);\n * UGameplayStatics::FinishSpawningActor(Projectile, SpawnTransform);\n */" },
#endif
		{ "IncludePath", "Core/Common/Actor/CosmosProjectile.h" },
		{ "ModuleRelativePath", "Core/Common/Actor/CosmosProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "ACosmosProjectile\n\nEVE-like projectile actor for ship weapons\nHandles ballistic physics, damage application, and visual effects\n\nArchitecture:\n- Spawned by weapon components in deferred mode\n- Initialized with damage, type, and velocity before finishing spawn\n- Uses ProjectileMovementComponent for realistic ballistics\n- Applies typed damage to targets on collision\n- Server-authoritative hit detection\n\nLifecycle:\n1. SpawnActorDeferred() by weapon\n2. InitializeProjectile() sets parameters\n3. FinishSpawningActor() completes spawn\n4. ProjectileMovementComponent handles flight\n5. OnHit() applies damage and destroys projectile\n\nUsage:\nFActorSpawnParameters SpawnParams;\nSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;\nACosmosProjectile* Projectile = GetWorld()->SpawnActorDeferred<ACosmosProjectile>(\n    ProjectileClass, SpawnTransform, Owner, Instigator, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);\nProjectile->InitializeProjectile(100.0f, ECosmosDamageType::Kinetic, 1000.0f);\nUGameplayStatics::FinishSpawningActor(Projectile, SpawnTransform);" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionComponent_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Collision component for hit detection */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/CosmosProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Collision component for hit detection" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeshComponent_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Visual mesh for the projectile */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/CosmosProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visual mesh for the projectile" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileMovementComponent_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Projectile movement component for ballistic physics */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/CosmosProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Projectile movement component for ballistic physics" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RawDamage_MetaData[] = {
		{ "Category", "Projectile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Raw damage amount before resistance mitigation */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/CosmosProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Raw damage amount before resistance mitigation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DamageType_MetaData[] = {
		{ "Category", "Projectile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Type of damage dealt (EM, Thermal, Kinetic, Explosive, Omni) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/CosmosProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Type of damage dealt (EM, Thermal, Kinetic, Explosive, Omni)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxLifetime_MetaData[] = {
		{ "Category", "Projectile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum lifetime in seconds before auto-destruction */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/CosmosProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum lifetime in seconds before auto-destruction" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CollisionComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ProjectileMovementComponent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RawDamage;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DamageType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DamageType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxLifetime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ACosmosProjectile_InitializeProjectile, "InitializeProjectile" }, // 3446502286
		{ &Z_Construct_UFunction_ACosmosProjectile_OnHit, "OnHit" }, // 3710683480
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACosmosProjectile>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACosmosProjectile_Statics::NewProp_CollisionComponent = { "CollisionComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACosmosProjectile, CollisionComponent), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionComponent_MetaData), NewProp_CollisionComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACosmosProjectile_Statics::NewProp_MeshComponent = { "MeshComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACosmosProjectile, MeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshComponent_MetaData), NewProp_MeshComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACosmosProjectile_Statics::NewProp_ProjectileMovementComponent = { "ProjectileMovementComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACosmosProjectile, ProjectileMovementComponent), Z_Construct_UClass_UProjectileMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileMovementComponent_MetaData), NewProp_ProjectileMovementComponent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACosmosProjectile_Statics::NewProp_RawDamage = { "RawDamage", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACosmosProjectile, RawDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RawDamage_MetaData), NewProp_RawDamage_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ACosmosProjectile_Statics::NewProp_DamageType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ACosmosProjectile_Statics::NewProp_DamageType = { "DamageType", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACosmosProjectile, DamageType), Z_Construct_UEnum_Echoes_ECosmosDamageType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DamageType_MetaData), NewProp_DamageType_MetaData) }; // 4170051619
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACosmosProjectile_Statics::NewProp_MaxLifetime = { "MaxLifetime", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACosmosProjectile, MaxLifetime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxLifetime_MetaData), NewProp_MaxLifetime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACosmosProjectile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACosmosProjectile_Statics::NewProp_CollisionComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACosmosProjectile_Statics::NewProp_MeshComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACosmosProjectile_Statics::NewProp_ProjectileMovementComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACosmosProjectile_Statics::NewProp_RawDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACosmosProjectile_Statics::NewProp_DamageType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACosmosProjectile_Statics::NewProp_DamageType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACosmosProjectile_Statics::NewProp_MaxLifetime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACosmosProjectile_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACosmosProjectile_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACosmosProjectile_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACosmosProjectile_Statics::ClassParams = {
	&ACosmosProjectile::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ACosmosProjectile_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ACosmosProjectile_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACosmosProjectile_Statics::Class_MetaDataParams), Z_Construct_UClass_ACosmosProjectile_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACosmosProjectile()
{
	if (!Z_Registration_Info_UClass_ACosmosProjectile.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACosmosProjectile.OuterSingleton, Z_Construct_UClass_ACosmosProjectile_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACosmosProjectile.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACosmosProjectile);
ACosmosProjectile::~ACosmosProjectile() {}
// ********** End Class ACosmosProjectile **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_CosmosProjectile_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACosmosProjectile, ACosmosProjectile::StaticClass, TEXT("ACosmosProjectile"), &Z_Registration_Info_UClass_ACosmosProjectile, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACosmosProjectile), 1494673068U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_CosmosProjectile_h__Script_Echoes_1729894000(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_CosmosProjectile_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_CosmosProjectile_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
