// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/EchoesLoginWidget.h"
#include "Core/Common/Networking/EchoesAuthSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesLoginWidget() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UClass* Z_Construct_UClass_UEchoesAuthSubsystem_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesLoginWidget();
ECHOES_API UClass* Z_Construct_UClass_UEchoesLoginWidget_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesWindowBase();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnLoginFailureEvent__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnLoginSuccessEvent__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FAuthResponse();
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextCommit();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UCheckBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_UEditableTextBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnLoginSuccessEvent **************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnLoginSuccessEvent__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnLoginSuccessEvent_Parms
	{
		FAuthResponse AuthResponse;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/EchoesLoginWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AuthResponse_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_AuthResponse;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnLoginSuccessEvent__DelegateSignature_Statics::NewProp_AuthResponse = { "AuthResponse", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnLoginSuccessEvent_Parms, AuthResponse), Z_Construct_UScriptStruct_FAuthResponse, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AuthResponse_MetaData), NewProp_AuthResponse_MetaData) }; // 3112734285
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnLoginSuccessEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnLoginSuccessEvent__DelegateSignature_Statics::NewProp_AuthResponse,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLoginSuccessEvent__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnLoginSuccessEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnLoginSuccessEvent__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnLoginSuccessEvent__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLoginSuccessEvent__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnLoginSuccessEvent__DelegateSignature_Statics::_Script_Echoes_eventOnLoginSuccessEvent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLoginSuccessEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnLoginSuccessEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnLoginSuccessEvent__DelegateSignature_Statics::_Script_Echoes_eventOnLoginSuccessEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnLoginSuccessEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnLoginSuccessEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnLoginSuccessEvent_DelegateWrapper(const FMulticastScriptDelegate& OnLoginSuccessEvent, FAuthResponse const& AuthResponse)
{
	struct _Script_Echoes_eventOnLoginSuccessEvent_Parms
	{
		FAuthResponse AuthResponse;
	};
	_Script_Echoes_eventOnLoginSuccessEvent_Parms Parms;
	Parms.AuthResponse=AuthResponse;
	OnLoginSuccessEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnLoginSuccessEvent ****************************************************

// ********** Begin Delegate FOnLoginFailureEvent **************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnLoginFailureEvent__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnLoginFailureEvent_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/EchoesLoginWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Echoes_OnLoginFailureEvent__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnLoginFailureEvent_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnLoginFailureEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnLoginFailureEvent__DelegateSignature_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLoginFailureEvent__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnLoginFailureEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnLoginFailureEvent__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnLoginFailureEvent__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLoginFailureEvent__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnLoginFailureEvent__DelegateSignature_Statics::_Script_Echoes_eventOnLoginFailureEvent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLoginFailureEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnLoginFailureEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnLoginFailureEvent__DelegateSignature_Statics::_Script_Echoes_eventOnLoginFailureEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnLoginFailureEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnLoginFailureEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnLoginFailureEvent_DelegateWrapper(const FMulticastScriptDelegate& OnLoginFailureEvent, const FString& ErrorMessage)
{
	struct _Script_Echoes_eventOnLoginFailureEvent_Parms
	{
		FString ErrorMessage;
	};
	_Script_Echoes_eventOnLoginFailureEvent_Parms Parms;
	Parms.ErrorMessage=ErrorMessage;
	OnLoginFailureEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnLoginFailureEvent ****************************************************

// ********** Begin Class UEchoesLoginWidget Function OnLoginButtonClicked *************************
struct Z_Construct_UFunction_UEchoesLoginWidget_OnLoginButtonClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle login button click\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesLoginWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle login button click" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesLoginWidget_OnLoginButtonClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesLoginWidget, nullptr, "OnLoginButtonClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesLoginWidget_OnLoginButtonClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesLoginWidget_OnLoginButtonClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesLoginWidget_OnLoginButtonClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesLoginWidget_OnLoginButtonClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesLoginWidget::execOnLoginButtonClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnLoginButtonClicked();
	P_NATIVE_END;
}
// ********** End Class UEchoesLoginWidget Function OnLoginButtonClicked ***************************

// ********** Begin Class UEchoesLoginWidget Function OnLoginFailure *******************************
struct Z_Construct_UFunction_UEchoesLoginWidget_OnLoginFailure_Statics
{
	struct EchoesLoginWidget_eventOnLoginFailure_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called when login fails\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesLoginWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when login fails" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesLoginWidget_OnLoginFailure_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesLoginWidget_eventOnLoginFailure_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesLoginWidget_OnLoginFailure_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesLoginWidget_OnLoginFailure_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesLoginWidget_OnLoginFailure_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesLoginWidget_OnLoginFailure_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesLoginWidget, nullptr, "OnLoginFailure", Z_Construct_UFunction_UEchoesLoginWidget_OnLoginFailure_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesLoginWidget_OnLoginFailure_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesLoginWidget_OnLoginFailure_Statics::EchoesLoginWidget_eventOnLoginFailure_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesLoginWidget_OnLoginFailure_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesLoginWidget_OnLoginFailure_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesLoginWidget_OnLoginFailure_Statics::EchoesLoginWidget_eventOnLoginFailure_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesLoginWidget_OnLoginFailure()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesLoginWidget_OnLoginFailure_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesLoginWidget::execOnLoginFailure)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ErrorMessage);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnLoginFailure(Z_Param_ErrorMessage);
	P_NATIVE_END;
}
// ********** End Class UEchoesLoginWidget Function OnLoginFailure *********************************

// ********** Begin Class UEchoesLoginWidget Function OnLoginSuccess *******************************
struct Z_Construct_UFunction_UEchoesLoginWidget_OnLoginSuccess_Statics
{
	struct EchoesLoginWidget_eventOnLoginSuccess_Parms
	{
		FAuthResponse AuthResponse;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called when login succeeds\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesLoginWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when login succeeds" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AuthResponse_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_AuthResponse;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesLoginWidget_OnLoginSuccess_Statics::NewProp_AuthResponse = { "AuthResponse", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesLoginWidget_eventOnLoginSuccess_Parms, AuthResponse), Z_Construct_UScriptStruct_FAuthResponse, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AuthResponse_MetaData), NewProp_AuthResponse_MetaData) }; // 3112734285
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesLoginWidget_OnLoginSuccess_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesLoginWidget_OnLoginSuccess_Statics::NewProp_AuthResponse,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesLoginWidget_OnLoginSuccess_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesLoginWidget_OnLoginSuccess_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesLoginWidget, nullptr, "OnLoginSuccess", Z_Construct_UFunction_UEchoesLoginWidget_OnLoginSuccess_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesLoginWidget_OnLoginSuccess_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesLoginWidget_OnLoginSuccess_Statics::EchoesLoginWidget_eventOnLoginSuccess_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesLoginWidget_OnLoginSuccess_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesLoginWidget_OnLoginSuccess_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesLoginWidget_OnLoginSuccess_Statics::EchoesLoginWidget_eventOnLoginSuccess_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesLoginWidget_OnLoginSuccess()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesLoginWidget_OnLoginSuccess_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesLoginWidget::execOnLoginSuccess)
{
	P_GET_STRUCT_REF(FAuthResponse,Z_Param_Out_AuthResponse);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnLoginSuccess(Z_Param_Out_AuthResponse);
	P_NATIVE_END;
}
// ********** End Class UEchoesLoginWidget Function OnLoginSuccess *********************************

// ********** Begin Class UEchoesLoginWidget Function OnPasswordCommitted **************************
struct Z_Construct_UFunction_UEchoesLoginWidget_OnPasswordCommitted_Statics
{
	struct EchoesLoginWidget_eventOnPasswordCommitted_Parms
	{
		FText Text;
		TEnumAsByte<ETextCommit::Type> CommitMethod;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle Enter key press in password field\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesLoginWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle Enter key press in password field" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CommitMethod;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UEchoesLoginWidget_OnPasswordCommitted_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesLoginWidget_eventOnPasswordCommitted_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEchoesLoginWidget_OnPasswordCommitted_Statics::NewProp_CommitMethod = { "CommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesLoginWidget_eventOnPasswordCommitted_Parms, CommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(0, nullptr) }; // 1817921380
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesLoginWidget_OnPasswordCommitted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesLoginWidget_OnPasswordCommitted_Statics::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesLoginWidget_OnPasswordCommitted_Statics::NewProp_CommitMethod,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesLoginWidget_OnPasswordCommitted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesLoginWidget_OnPasswordCommitted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesLoginWidget, nullptr, "OnPasswordCommitted", Z_Construct_UFunction_UEchoesLoginWidget_OnPasswordCommitted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesLoginWidget_OnPasswordCommitted_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesLoginWidget_OnPasswordCommitted_Statics::EchoesLoginWidget_eventOnPasswordCommitted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesLoginWidget_OnPasswordCommitted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesLoginWidget_OnPasswordCommitted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesLoginWidget_OnPasswordCommitted_Statics::EchoesLoginWidget_eventOnPasswordCommitted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesLoginWidget_OnPasswordCommitted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesLoginWidget_OnPasswordCommitted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesLoginWidget::execOnPasswordCommitted)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Text);
	P_GET_PROPERTY(FByteProperty,Z_Param_CommitMethod);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnPasswordCommitted(Z_Param_Out_Text,ETextCommit::Type(Z_Param_CommitMethod));
	P_NATIVE_END;
}
// ********** End Class UEchoesLoginWidget Function OnPasswordCommitted ****************************

// ********** Begin Class UEchoesLoginWidget Function OnRegisterButtonClicked **********************
struct Z_Construct_UFunction_UEchoesLoginWidget_OnRegisterButtonClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle register button click\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesLoginWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle register button click" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesLoginWidget_OnRegisterButtonClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesLoginWidget, nullptr, "OnRegisterButtonClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesLoginWidget_OnRegisterButtonClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesLoginWidget_OnRegisterButtonClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesLoginWidget_OnRegisterButtonClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesLoginWidget_OnRegisterButtonClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesLoginWidget::execOnRegisterButtonClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRegisterButtonClicked();
	P_NATIVE_END;
}
// ********** End Class UEchoesLoginWidget Function OnRegisterButtonClicked ************************

// ********** Begin Class UEchoesLoginWidget *******************************************************
void UEchoesLoginWidget::StaticRegisterNativesUEchoesLoginWidget()
{
	UClass* Class = UEchoesLoginWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnLoginButtonClicked", &UEchoesLoginWidget::execOnLoginButtonClicked },
		{ "OnLoginFailure", &UEchoesLoginWidget::execOnLoginFailure },
		{ "OnLoginSuccess", &UEchoesLoginWidget::execOnLoginSuccess },
		{ "OnPasswordCommitted", &UEchoesLoginWidget::execOnPasswordCommitted },
		{ "OnRegisterButtonClicked", &UEchoesLoginWidget::execOnRegisterButtonClicked },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesLoginWidget;
UClass* UEchoesLoginWidget::GetPrivateStaticClass()
{
	using TClass = UEchoesLoginWidget;
	if (!Z_Registration_Info_UClass_UEchoesLoginWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesLoginWidget"),
			Z_Registration_Info_UClass_UEchoesLoginWidget.InnerSingleton,
			StaticRegisterNativesUEchoesLoginWidget,
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
	return Z_Registration_Info_UClass_UEchoesLoginWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesLoginWidget_NoRegister()
{
	return UEchoesLoginWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesLoginWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesLoginWidget\n * \n * Login UI widget for Echoes MMO\n * Provides email/username and password input fields\n * Integrates with UEchoesAuthSubsystem for authentication\n * Inherits from UEchoesWindowBase for drag/focus support\n */" },
#endif
		{ "IncludePath", "UI/EchoesLoginWidget.h" },
		{ "ModuleRelativePath", "UI/EchoesLoginWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesLoginWidget\n\nLogin UI widget for Echoes MMO\nProvides email/username and password input fields\nIntegrates with UEchoesAuthSubsystem for authentication\nInherits from UEchoesWindowBase for drag/focus support" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EmailUsernameInput_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Email or username input field */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesLoginWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Email or username input field" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PasswordInput_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Password input field */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesLoginWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Password input field" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RememberMeCheckbox_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Remember Me checkbox */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesLoginWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Remember Me checkbox" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LoginButton_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Login button */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesLoginWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Login button" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegisterButton_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Register button */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesLoginWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Register button" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StatusText_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Status text (for errors/success messages) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesLoginWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Status text (for errors/success messages)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnLoginSuccessDelegate_MetaData[] = {
		{ "Category", "Echoes|Login" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called when login is successful */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesLoginWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when login is successful" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnLoginFailureDelegate_MetaData[] = {
		{ "Category", "Echoes|Login" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called when login fails */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesLoginWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when login fails" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AuthSubsystem_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reference to auth subsystem */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesLoginWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference to auth subsystem" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EmailUsernameInput;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PasswordInput;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RememberMeCheckbox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LoginButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RegisterButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StatusText;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLoginSuccessDelegate;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLoginFailureDelegate;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AuthSubsystem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesLoginWidget_OnLoginButtonClicked, "OnLoginButtonClicked" }, // 731021437
		{ &Z_Construct_UFunction_UEchoesLoginWidget_OnLoginFailure, "OnLoginFailure" }, // 3189685406
		{ &Z_Construct_UFunction_UEchoesLoginWidget_OnLoginSuccess, "OnLoginSuccess" }, // 3269945178
		{ &Z_Construct_UFunction_UEchoesLoginWidget_OnPasswordCommitted, "OnPasswordCommitted" }, // 3334070126
		{ &Z_Construct_UFunction_UEchoesLoginWidget_OnRegisterButtonClicked, "OnRegisterButtonClicked" }, // 4260072176
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesLoginWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesLoginWidget_Statics::NewProp_EmailUsernameInput = { "EmailUsernameInput", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesLoginWidget, EmailUsernameInput), Z_Construct_UClass_UEditableTextBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EmailUsernameInput_MetaData), NewProp_EmailUsernameInput_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesLoginWidget_Statics::NewProp_PasswordInput = { "PasswordInput", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesLoginWidget, PasswordInput), Z_Construct_UClass_UEditableTextBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PasswordInput_MetaData), NewProp_PasswordInput_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesLoginWidget_Statics::NewProp_RememberMeCheckbox = { "RememberMeCheckbox", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesLoginWidget, RememberMeCheckbox), Z_Construct_UClass_UCheckBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RememberMeCheckbox_MetaData), NewProp_RememberMeCheckbox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesLoginWidget_Statics::NewProp_LoginButton = { "LoginButton", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesLoginWidget, LoginButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoginButton_MetaData), NewProp_LoginButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesLoginWidget_Statics::NewProp_RegisterButton = { "RegisterButton", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesLoginWidget, RegisterButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegisterButton_MetaData), NewProp_RegisterButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesLoginWidget_Statics::NewProp_StatusText = { "StatusText", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesLoginWidget, StatusText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StatusText_MetaData), NewProp_StatusText_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesLoginWidget_Statics::NewProp_OnLoginSuccessDelegate = { "OnLoginSuccessDelegate", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesLoginWidget, OnLoginSuccessDelegate), Z_Construct_UDelegateFunction_Echoes_OnLoginSuccessEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnLoginSuccessDelegate_MetaData), NewProp_OnLoginSuccessDelegate_MetaData) }; // 3511753456
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesLoginWidget_Statics::NewProp_OnLoginFailureDelegate = { "OnLoginFailureDelegate", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesLoginWidget, OnLoginFailureDelegate), Z_Construct_UDelegateFunction_Echoes_OnLoginFailureEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnLoginFailureDelegate_MetaData), NewProp_OnLoginFailureDelegate_MetaData) }; // 2520267840
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesLoginWidget_Statics::NewProp_AuthSubsystem = { "AuthSubsystem", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesLoginWidget, AuthSubsystem), Z_Construct_UClass_UEchoesAuthSubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AuthSubsystem_MetaData), NewProp_AuthSubsystem_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesLoginWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesLoginWidget_Statics::NewProp_EmailUsernameInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesLoginWidget_Statics::NewProp_PasswordInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesLoginWidget_Statics::NewProp_RememberMeCheckbox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesLoginWidget_Statics::NewProp_LoginButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesLoginWidget_Statics::NewProp_RegisterButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesLoginWidget_Statics::NewProp_StatusText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesLoginWidget_Statics::NewProp_OnLoginSuccessDelegate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesLoginWidget_Statics::NewProp_OnLoginFailureDelegate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesLoginWidget_Statics::NewProp_AuthSubsystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesLoginWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesLoginWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEchoesWindowBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesLoginWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesLoginWidget_Statics::ClassParams = {
	&UEchoesLoginWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesLoginWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesLoginWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesLoginWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesLoginWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesLoginWidget()
{
	if (!Z_Registration_Info_UClass_UEchoesLoginWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesLoginWidget.OuterSingleton, Z_Construct_UClass_UEchoesLoginWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesLoginWidget.OuterSingleton;
}
UEchoesLoginWidget::UEchoesLoginWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesLoginWidget);
UEchoesLoginWidget::~UEchoesLoginWidget() {}
// ********** End Class UEchoesLoginWidget *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesLoginWidget_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesLoginWidget, UEchoesLoginWidget::StaticClass, TEXT("UEchoesLoginWidget"), &Z_Registration_Info_UClass_UEchoesLoginWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesLoginWidget), 364248458U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesLoginWidget_h__Script_Echoes_2492493838(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesLoginWidget_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesLoginWidget_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
