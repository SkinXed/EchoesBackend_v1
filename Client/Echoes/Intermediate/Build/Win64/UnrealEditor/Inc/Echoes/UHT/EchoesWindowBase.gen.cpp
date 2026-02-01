// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesWindowBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesWindowBase() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ECHOES_API UClass* Z_Construct_UClass_UEchoesWindowBase();
ECHOES_API UClass* Z_Construct_UClass_UEchoesWindowBase_NoRegister();
UMG_API UClass* Z_Construct_UClass_UBorder_NoRegister();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UCanvasPanelSlot_NoRegister();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UMG_API UClass* Z_Construct_UClass_UNamedSlot_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UEchoesWindowBase Function BringToFront **********************************
struct Z_Construct_UFunction_UEchoesWindowBase_BringToFront_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Bring this window to front (highest Z-order)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Bring this window to front (highest Z-order)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesWindowBase_BringToFront_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesWindowBase, nullptr, "BringToFront", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_BringToFront_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesWindowBase_BringToFront_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesWindowBase_BringToFront()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesWindowBase_BringToFront_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesWindowBase::execBringToFront)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->BringToFront();
	P_NATIVE_END;
}
// ********** End Class UEchoesWindowBase Function BringToFront ************************************

// ********** Begin Class UEchoesWindowBase Function CloseWindow ***********************************
struct Z_Construct_UFunction_UEchoesWindowBase_CloseWindow_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Close this window (removes from parent and destroys)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Close this window (removes from parent and destroys)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesWindowBase_CloseWindow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesWindowBase, nullptr, "CloseWindow", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_CloseWindow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesWindowBase_CloseWindow_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesWindowBase_CloseWindow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesWindowBase_CloseWindow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesWindowBase::execCloseWindow)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CloseWindow();
	P_NATIVE_END;
}
// ********** End Class UEchoesWindowBase Function CloseWindow *************************************

// ********** Begin Class UEchoesWindowBase Function GetWindowPosition *****************************
struct Z_Construct_UFunction_UEchoesWindowBase_GetWindowPosition_Statics
{
	struct EchoesWindowBase_eventGetWindowPosition_Parms
	{
		FVector2D ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get window position\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get window position" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesWindowBase_GetWindowPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWindowBase_eventGetWindowPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesWindowBase_GetWindowPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesWindowBase_GetWindowPosition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_GetWindowPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesWindowBase_GetWindowPosition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesWindowBase, nullptr, "GetWindowPosition", Z_Construct_UFunction_UEchoesWindowBase_GetWindowPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_GetWindowPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesWindowBase_GetWindowPosition_Statics::EchoesWindowBase_eventGetWindowPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_GetWindowPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesWindowBase_GetWindowPosition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesWindowBase_GetWindowPosition_Statics::EchoesWindowBase_eventGetWindowPosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesWindowBase_GetWindowPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesWindowBase_GetWindowPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesWindowBase::execGetWindowPosition)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector2D*)Z_Param__Result=P_THIS->GetWindowPosition();
	P_NATIVE_END;
}
// ********** End Class UEchoesWindowBase Function GetWindowPosition *******************************

// ********** Begin Class UEchoesWindowBase Function GetWindowSize *********************************
struct Z_Construct_UFunction_UEchoesWindowBase_GetWindowSize_Statics
{
	struct EchoesWindowBase_eventGetWindowSize_Parms
	{
		FVector2D ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get window size\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get window size" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesWindowBase_GetWindowSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWindowBase_eventGetWindowSize_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesWindowBase_GetWindowSize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesWindowBase_GetWindowSize_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_GetWindowSize_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesWindowBase_GetWindowSize_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesWindowBase, nullptr, "GetWindowSize", Z_Construct_UFunction_UEchoesWindowBase_GetWindowSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_GetWindowSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesWindowBase_GetWindowSize_Statics::EchoesWindowBase_eventGetWindowSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_GetWindowSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesWindowBase_GetWindowSize_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesWindowBase_GetWindowSize_Statics::EchoesWindowBase_eventGetWindowSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesWindowBase_GetWindowSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesWindowBase_GetWindowSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesWindowBase::execGetWindowSize)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector2D*)Z_Param__Result=P_THIS->GetWindowSize();
	P_NATIVE_END;
}
// ********** End Class UEchoesWindowBase Function GetWindowSize ***********************************

// ********** Begin Class UEchoesWindowBase Function GetWindowTitle ********************************
struct Z_Construct_UFunction_UEchoesWindowBase_GetWindowTitle_Statics
{
	struct EchoesWindowBase_eventGetWindowTitle_Parms
	{
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the window title text\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the window title text" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UEchoesWindowBase_GetWindowTitle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWindowBase_eventGetWindowTitle_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesWindowBase_GetWindowTitle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesWindowBase_GetWindowTitle_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_GetWindowTitle_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesWindowBase_GetWindowTitle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesWindowBase, nullptr, "GetWindowTitle", Z_Construct_UFunction_UEchoesWindowBase_GetWindowTitle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_GetWindowTitle_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesWindowBase_GetWindowTitle_Statics::EchoesWindowBase_eventGetWindowTitle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_GetWindowTitle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesWindowBase_GetWindowTitle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesWindowBase_GetWindowTitle_Statics::EchoesWindowBase_eventGetWindowTitle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesWindowBase_GetWindowTitle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesWindowBase_GetWindowTitle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesWindowBase::execGetWindowTitle)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetWindowTitle();
	P_NATIVE_END;
}
// ********** End Class UEchoesWindowBase Function GetWindowTitle **********************************

// ********** Begin Class UEchoesWindowBase Function LoadWindowPosition ****************************
struct Z_Construct_UFunction_UEchoesWindowBase_LoadWindowPosition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Load window position from player settings\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Load window position from player settings" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesWindowBase_LoadWindowPosition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesWindowBase, nullptr, "LoadWindowPosition", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_LoadWindowPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesWindowBase_LoadWindowPosition_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesWindowBase_LoadWindowPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesWindowBase_LoadWindowPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesWindowBase::execLoadWindowPosition)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->LoadWindowPosition();
	P_NATIVE_END;
}
// ********** End Class UEchoesWindowBase Function LoadWindowPosition ******************************

// ********** Begin Class UEchoesWindowBase Function OnCloseButtonClicked **************************
struct Z_Construct_UFunction_UEchoesWindowBase_OnCloseButtonClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called when close button is clicked\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when close button is clicked" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesWindowBase_OnCloseButtonClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesWindowBase, nullptr, "OnCloseButtonClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_OnCloseButtonClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesWindowBase_OnCloseButtonClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesWindowBase_OnCloseButtonClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesWindowBase_OnCloseButtonClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesWindowBase::execOnCloseButtonClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnCloseButtonClicked();
	P_NATIVE_END;
}
// ********** End Class UEchoesWindowBase Function OnCloseButtonClicked ****************************

// ********** Begin Class UEchoesWindowBase Function OnWindowClosed ********************************
static FName NAME_UEchoesWindowBase_OnWindowClosed = FName(TEXT("OnWindowClosed"));
void UEchoesWindowBase::OnWindowClosed()
{
	UFunction* Func = FindFunctionChecked(NAME_UEchoesWindowBase_OnWindowClosed);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UEchoesWindowBase_OnWindowClosed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Blueprint event called when window is closed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event called when window is closed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesWindowBase_OnWindowClosed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesWindowBase, nullptr, "OnWindowClosed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_OnWindowClosed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesWindowBase_OnWindowClosed_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesWindowBase_OnWindowClosed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesWindowBase_OnWindowClosed_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEchoesWindowBase Function OnWindowClosed **********************************

// ********** Begin Class UEchoesWindowBase Function OnWindowFocused *******************************
static FName NAME_UEchoesWindowBase_OnWindowFocused = FName(TEXT("OnWindowFocused"));
void UEchoesWindowBase::OnWindowFocused()
{
	UFunction* Func = FindFunctionChecked(NAME_UEchoesWindowBase_OnWindowFocused);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UEchoesWindowBase_OnWindowFocused_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Blueprint event called when window gains focus\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event called when window gains focus" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesWindowBase_OnWindowFocused_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesWindowBase, nullptr, "OnWindowFocused", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_OnWindowFocused_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesWindowBase_OnWindowFocused_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesWindowBase_OnWindowFocused()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesWindowBase_OnWindowFocused_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEchoesWindowBase Function OnWindowFocused *********************************

// ********** Begin Class UEchoesWindowBase Function SaveWindowPosition ****************************
struct Z_Construct_UFunction_UEchoesWindowBase_SaveWindowPosition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Save window position to player settings\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Save window position to player settings" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesWindowBase_SaveWindowPosition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesWindowBase, nullptr, "SaveWindowPosition", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_SaveWindowPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesWindowBase_SaveWindowPosition_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesWindowBase_SaveWindowPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesWindowBase_SaveWindowPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesWindowBase::execSaveWindowPosition)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SaveWindowPosition();
	P_NATIVE_END;
}
// ********** End Class UEchoesWindowBase Function SaveWindowPosition ******************************

// ********** Begin Class UEchoesWindowBase Function SetWindowPosition *****************************
struct Z_Construct_UFunction_UEchoesWindowBase_SetWindowPosition_Statics
{
	struct EchoesWindowBase_eventSetWindowPosition_Parms
	{
		FVector2D Position;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set window position\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set window position" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesWindowBase_SetWindowPosition_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWindowBase_eventSetWindowPosition_Parms, Position), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesWindowBase_SetWindowPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesWindowBase_SetWindowPosition_Statics::NewProp_Position,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_SetWindowPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesWindowBase_SetWindowPosition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesWindowBase, nullptr, "SetWindowPosition", Z_Construct_UFunction_UEchoesWindowBase_SetWindowPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_SetWindowPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesWindowBase_SetWindowPosition_Statics::EchoesWindowBase_eventSetWindowPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_SetWindowPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesWindowBase_SetWindowPosition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesWindowBase_SetWindowPosition_Statics::EchoesWindowBase_eventSetWindowPosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesWindowBase_SetWindowPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesWindowBase_SetWindowPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesWindowBase::execSetWindowPosition)
{
	P_GET_STRUCT(FVector2D,Z_Param_Position);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetWindowPosition(Z_Param_Position);
	P_NATIVE_END;
}
// ********** End Class UEchoesWindowBase Function SetWindowPosition *******************************

// ********** Begin Class UEchoesWindowBase Function SetWindowSize *********************************
struct Z_Construct_UFunction_UEchoesWindowBase_SetWindowSize_Statics
{
	struct EchoesWindowBase_eventSetWindowSize_Parms
	{
		FVector2D Size;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set window size\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set window size" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Size;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesWindowBase_SetWindowSize_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWindowBase_eventSetWindowSize_Parms, Size), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesWindowBase_SetWindowSize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesWindowBase_SetWindowSize_Statics::NewProp_Size,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_SetWindowSize_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesWindowBase_SetWindowSize_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesWindowBase, nullptr, "SetWindowSize", Z_Construct_UFunction_UEchoesWindowBase_SetWindowSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_SetWindowSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesWindowBase_SetWindowSize_Statics::EchoesWindowBase_eventSetWindowSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_SetWindowSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesWindowBase_SetWindowSize_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesWindowBase_SetWindowSize_Statics::EchoesWindowBase_eventSetWindowSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesWindowBase_SetWindowSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesWindowBase_SetWindowSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesWindowBase::execSetWindowSize)
{
	P_GET_STRUCT(FVector2D,Z_Param_Size);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetWindowSize(Z_Param_Size);
	P_NATIVE_END;
}
// ********** End Class UEchoesWindowBase Function SetWindowSize ***********************************

// ********** Begin Class UEchoesWindowBase Function SetWindowTitle ********************************
struct Z_Construct_UFunction_UEchoesWindowBase_SetWindowTitle_Statics
{
	struct EchoesWindowBase_eventSetWindowTitle_Parms
	{
		FText Title;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set the window title text\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the window title text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Title_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_Title;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UEchoesWindowBase_SetWindowTitle_Statics::NewProp_Title = { "Title", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWindowBase_eventSetWindowTitle_Parms, Title), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Title_MetaData), NewProp_Title_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesWindowBase_SetWindowTitle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesWindowBase_SetWindowTitle_Statics::NewProp_Title,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_SetWindowTitle_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesWindowBase_SetWindowTitle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesWindowBase, nullptr, "SetWindowTitle", Z_Construct_UFunction_UEchoesWindowBase_SetWindowTitle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_SetWindowTitle_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesWindowBase_SetWindowTitle_Statics::EchoesWindowBase_eventSetWindowTitle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesWindowBase_SetWindowTitle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesWindowBase_SetWindowTitle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesWindowBase_SetWindowTitle_Statics::EchoesWindowBase_eventSetWindowTitle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesWindowBase_SetWindowTitle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesWindowBase_SetWindowTitle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesWindowBase::execSetWindowTitle)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Title);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetWindowTitle(Z_Param_Out_Title);
	P_NATIVE_END;
}
// ********** End Class UEchoesWindowBase Function SetWindowTitle **********************************

// ********** Begin Class UEchoesWindowBase ********************************************************
void UEchoesWindowBase::StaticRegisterNativesUEchoesWindowBase()
{
	UClass* Class = UEchoesWindowBase::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "BringToFront", &UEchoesWindowBase::execBringToFront },
		{ "CloseWindow", &UEchoesWindowBase::execCloseWindow },
		{ "GetWindowPosition", &UEchoesWindowBase::execGetWindowPosition },
		{ "GetWindowSize", &UEchoesWindowBase::execGetWindowSize },
		{ "GetWindowTitle", &UEchoesWindowBase::execGetWindowTitle },
		{ "LoadWindowPosition", &UEchoesWindowBase::execLoadWindowPosition },
		{ "OnCloseButtonClicked", &UEchoesWindowBase::execOnCloseButtonClicked },
		{ "SaveWindowPosition", &UEchoesWindowBase::execSaveWindowPosition },
		{ "SetWindowPosition", &UEchoesWindowBase::execSetWindowPosition },
		{ "SetWindowSize", &UEchoesWindowBase::execSetWindowSize },
		{ "SetWindowTitle", &UEchoesWindowBase::execSetWindowTitle },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesWindowBase;
UClass* UEchoesWindowBase::GetPrivateStaticClass()
{
	using TClass = UEchoesWindowBase;
	if (!Z_Registration_Info_UClass_UEchoesWindowBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesWindowBase"),
			Z_Registration_Info_UClass_UEchoesWindowBase.InnerSingleton,
			StaticRegisterNativesUEchoesWindowBase,
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
	return Z_Registration_Info_UClass_UEchoesWindowBase.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesWindowBase_NoRegister()
{
	return UEchoesWindowBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesWindowBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesWindowBase\n * \n * Base class for draggable and resizable window-style UI widgets\n * Provides Windows-like window behavior with title bar, resize handles, and focus management\n * \n * Features:\n * - Draggable via title bar\n * - Resizable from bottom-right corner\n * - Minimum size constraints\n * - Z-order focus system\n * - Close button\n * - Content slot for child widgets\n * - Position persistence (optional)\n * \n * Usage:\n * - Create widget blueprint based on this class\n * - Add required widget bindings: TitleBar, TitleText, CloseButton, ResizeHandle, ContentSlot\n * - Set MinWindowSize and DefaultWindowSize in Blueprint\n * - Place content widgets in ContentSlot in Blueprint editor\n */" },
#endif
		{ "IncludePath", "UI/Framework/EchoesWindowBase.h" },
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesWindowBase\n\nBase class for draggable and resizable window-style UI widgets\nProvides Windows-like window behavior with title bar, resize handles, and focus management\n\nFeatures:\n- Draggable via title bar\n- Resizable from bottom-right corner\n- Minimum size constraints\n- Z-order focus system\n- Close button\n- Content slot for child widgets\n- Position persistence (optional)\n\nUsage:\n- Create widget blueprint based on this class\n- Add required widget bindings: TitleBar, TitleText, CloseButton, ResizeHandle, ContentSlot\n- Set MinWindowSize and DefaultWindowSize in Blueprint\n- Place content widgets in ContentSlot in Blueprint editor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TitleBar_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Title bar border (draggable area) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Title bar border (draggable area)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TitleText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Title text block */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Title text block" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloseButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Close button */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Close button" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResizeHandle_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Resize handle (bottom-right corner) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Resize handle (bottom-right corner)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContentSlot_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Content slot for child widgets */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Content slot for child widgets" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinWindowSize_MetaData[] = {
		{ "Category", "Echoes|Window|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Minimum window size (width, height) */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Minimum window size (width, height)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxWindowSize_MetaData[] = {
		{ "Category", "Echoes|Window|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum window size (0 = no limit) */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum window size (0 = no limit)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultWindowSize_MetaData[] = {
		{ "Category", "Echoes|Window|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default window size */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default window size" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultWindowPosition_MetaData[] = {
		{ "Category", "Echoes|Window|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default window position (relative to screen) */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default window position (relative to screen)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSavePosition_MetaData[] = {
		{ "Category", "Echoes|Window|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether to save/load window position */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether to save/load window position" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WindowId_MetaData[] = {
		{ "Category", "Echoes|Window|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unique window ID for position saving (auto-generated from class name) */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unique window ID for position saving (auto-generated from class name)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanResize_MetaData[] = {
		{ "Category", "Echoes|Window|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether window can be resized */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether window can be resized" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanDrag_MetaData[] = {
		{ "Category", "Echoes|Window|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether window can be dragged */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether window can be dragged" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableSnapping_MetaData[] = {
		{ "Category", "Echoes|Window|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Enable window snapping to screen edges and other windows */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enable window snapping to screen edges and other windows" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SnapThreshold_MetaData[] = {
		{ "Category", "Echoes|Window|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Distance threshold for snapping (in pixels) */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Distance threshold for snapping (in pixels)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSnapToScreenEdges_MetaData[] = {
		{ "Category", "Echoes|Window|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Snap to screen edges */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Snap to screen edges" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSnapToOtherWindows_MetaData[] = {
		{ "Category", "Echoes|Window|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Snap to other windows */" },
#endif
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Snap to other windows" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CanvasSlot_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached canvas panel slot for position/size manipulation */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Framework/EchoesWindowBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached canvas panel slot for position/size manipulation" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TitleBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TitleText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CloseButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ResizeHandle;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ContentSlot;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MinWindowSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MaxWindowSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultWindowSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultWindowPosition;
	static void NewProp_bSavePosition_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSavePosition;
	static const UECodeGen_Private::FStrPropertyParams NewProp_WindowId;
	static void NewProp_bCanResize_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanResize;
	static void NewProp_bCanDrag_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanDrag;
	static void NewProp_bEnableSnapping_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableSnapping;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SnapThreshold;
	static void NewProp_bSnapToScreenEdges_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSnapToScreenEdges;
	static void NewProp_bSnapToOtherWindows_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSnapToOtherWindows;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CanvasSlot;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesWindowBase_BringToFront, "BringToFront" }, // 3939485939
		{ &Z_Construct_UFunction_UEchoesWindowBase_CloseWindow, "CloseWindow" }, // 883239599
		{ &Z_Construct_UFunction_UEchoesWindowBase_GetWindowPosition, "GetWindowPosition" }, // 2484980260
		{ &Z_Construct_UFunction_UEchoesWindowBase_GetWindowSize, "GetWindowSize" }, // 1269511037
		{ &Z_Construct_UFunction_UEchoesWindowBase_GetWindowTitle, "GetWindowTitle" }, // 739113689
		{ &Z_Construct_UFunction_UEchoesWindowBase_LoadWindowPosition, "LoadWindowPosition" }, // 2410691880
		{ &Z_Construct_UFunction_UEchoesWindowBase_OnCloseButtonClicked, "OnCloseButtonClicked" }, // 1578176309
		{ &Z_Construct_UFunction_UEchoesWindowBase_OnWindowClosed, "OnWindowClosed" }, // 911372440
		{ &Z_Construct_UFunction_UEchoesWindowBase_OnWindowFocused, "OnWindowFocused" }, // 242657106
		{ &Z_Construct_UFunction_UEchoesWindowBase_SaveWindowPosition, "SaveWindowPosition" }, // 45380814
		{ &Z_Construct_UFunction_UEchoesWindowBase_SetWindowPosition, "SetWindowPosition" }, // 517414884
		{ &Z_Construct_UFunction_UEchoesWindowBase_SetWindowSize, "SetWindowSize" }, // 4063371398
		{ &Z_Construct_UFunction_UEchoesWindowBase_SetWindowTitle, "SetWindowTitle" }, // 3726813262
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesWindowBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_TitleBar = { "TitleBar", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesWindowBase, TitleBar), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TitleBar_MetaData), NewProp_TitleBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_TitleText = { "TitleText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesWindowBase, TitleText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TitleText_MetaData), NewProp_TitleText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_CloseButton = { "CloseButton", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesWindowBase, CloseButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloseButton_MetaData), NewProp_CloseButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_ResizeHandle = { "ResizeHandle", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesWindowBase, ResizeHandle), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResizeHandle_MetaData), NewProp_ResizeHandle_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_ContentSlot = { "ContentSlot", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesWindowBase, ContentSlot), Z_Construct_UClass_UNamedSlot_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContentSlot_MetaData), NewProp_ContentSlot_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_MinWindowSize = { "MinWindowSize", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesWindowBase, MinWindowSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinWindowSize_MetaData), NewProp_MinWindowSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_MaxWindowSize = { "MaxWindowSize", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesWindowBase, MaxWindowSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxWindowSize_MetaData), NewProp_MaxWindowSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_DefaultWindowSize = { "DefaultWindowSize", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesWindowBase, DefaultWindowSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultWindowSize_MetaData), NewProp_DefaultWindowSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_DefaultWindowPosition = { "DefaultWindowPosition", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesWindowBase, DefaultWindowPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultWindowPosition_MetaData), NewProp_DefaultWindowPosition_MetaData) };
void Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bSavePosition_SetBit(void* Obj)
{
	((UEchoesWindowBase*)Obj)->bSavePosition = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bSavePosition = { "bSavePosition", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEchoesWindowBase), &Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bSavePosition_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSavePosition_MetaData), NewProp_bSavePosition_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_WindowId = { "WindowId", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesWindowBase, WindowId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WindowId_MetaData), NewProp_WindowId_MetaData) };
void Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bCanResize_SetBit(void* Obj)
{
	((UEchoesWindowBase*)Obj)->bCanResize = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bCanResize = { "bCanResize", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEchoesWindowBase), &Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bCanResize_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanResize_MetaData), NewProp_bCanResize_MetaData) };
void Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bCanDrag_SetBit(void* Obj)
{
	((UEchoesWindowBase*)Obj)->bCanDrag = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bCanDrag = { "bCanDrag", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEchoesWindowBase), &Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bCanDrag_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanDrag_MetaData), NewProp_bCanDrag_MetaData) };
void Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bEnableSnapping_SetBit(void* Obj)
{
	((UEchoesWindowBase*)Obj)->bEnableSnapping = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bEnableSnapping = { "bEnableSnapping", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEchoesWindowBase), &Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bEnableSnapping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableSnapping_MetaData), NewProp_bEnableSnapping_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_SnapThreshold = { "SnapThreshold", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesWindowBase, SnapThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SnapThreshold_MetaData), NewProp_SnapThreshold_MetaData) };
void Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bSnapToScreenEdges_SetBit(void* Obj)
{
	((UEchoesWindowBase*)Obj)->bSnapToScreenEdges = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bSnapToScreenEdges = { "bSnapToScreenEdges", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEchoesWindowBase), &Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bSnapToScreenEdges_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSnapToScreenEdges_MetaData), NewProp_bSnapToScreenEdges_MetaData) };
void Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bSnapToOtherWindows_SetBit(void* Obj)
{
	((UEchoesWindowBase*)Obj)->bSnapToOtherWindows = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bSnapToOtherWindows = { "bSnapToOtherWindows", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEchoesWindowBase), &Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bSnapToOtherWindows_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSnapToOtherWindows_MetaData), NewProp_bSnapToOtherWindows_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_CanvasSlot = { "CanvasSlot", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesWindowBase, CanvasSlot), Z_Construct_UClass_UCanvasPanelSlot_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CanvasSlot_MetaData), NewProp_CanvasSlot_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesWindowBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_TitleBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_TitleText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_CloseButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_ResizeHandle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_ContentSlot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_MinWindowSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_MaxWindowSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_DefaultWindowSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_DefaultWindowPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bSavePosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_WindowId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bCanResize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bCanDrag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bEnableSnapping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_SnapThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bSnapToScreenEdges,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_bSnapToOtherWindows,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesWindowBase_Statics::NewProp_CanvasSlot,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesWindowBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesWindowBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesWindowBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesWindowBase_Statics::ClassParams = {
	&UEchoesWindowBase::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesWindowBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesWindowBase_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesWindowBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesWindowBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesWindowBase()
{
	if (!Z_Registration_Info_UClass_UEchoesWindowBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesWindowBase.OuterSingleton, Z_Construct_UClass_UEchoesWindowBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesWindowBase.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesWindowBase);
UEchoesWindowBase::~UEchoesWindowBase() {}
// ********** End Class UEchoesWindowBase **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Framework_EchoesWindowBase_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesWindowBase, UEchoesWindowBase::StaticClass, TEXT("UEchoesWindowBase"), &Z_Registration_Info_UClass_UEchoesWindowBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesWindowBase), 3367101607U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Framework_EchoesWindowBase_h__Script_Echoes_3634189016(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Framework_EchoesWindowBase_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Framework_EchoesWindowBase_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
