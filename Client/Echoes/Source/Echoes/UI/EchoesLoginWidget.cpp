// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/EchoesLoginWidget.h"
#include "Components/EditableTextBox.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/CheckBox.h"
#include "Kismet/GameplayStatics.h"

void UEchoesLoginWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Set window title
	SetWindowTitle(FText::FromString("Login"));

	// Get auth subsystem
	if (UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GetWorld()))
	{
		AuthSubsystem = GameInstance->GetSubsystem<UEchoesAuthSubsystem>();
	}

	// Bind button click events
	if (LoginButton)
	{
		LoginButton->OnClicked.AddDynamic(this, &UEchoesLoginWidget::OnLoginButtonClicked);
	}

	if (RegisterButton)
	{
		RegisterButton->OnClicked.AddDynamic(this, &UEchoesLoginWidget::OnRegisterButtonClicked);
	}

	// Bind password field Enter key
	if (PasswordInput)
	{
		PasswordInput->OnTextCommitted.AddDynamic(this, &UEchoesLoginWidget::OnPasswordCommitted);
	}

	// Set Remember Me to checked by default
	if (RememberMeCheckbox)
	{
		RememberMeCheckbox->SetIsChecked(true);
	}

	// Clear status text
	SetStatusText("", FLinearColor::White);
}

void UEchoesLoginWidget::NativeDestruct()
{
	// Unbind events
	if (LoginButton)
	{
		LoginButton->OnClicked.RemoveDynamic(this, &UEchoesLoginWidget::OnLoginButtonClicked);
	}

	if (RegisterButton)
	{
		RegisterButton->OnClicked.RemoveDynamic(this, &UEchoesLoginWidget::OnRegisterButtonClicked);
	}

	if (PasswordInput)
	{
		PasswordInput->OnTextCommitted.RemoveDynamic(this, &UEchoesLoginWidget::OnPasswordCommitted);
	}

	Super::NativeDestruct();
}

void UEchoesLoginWidget::OnLoginButtonClicked()
{
	if (bLoginInProgress)
	{
		return;
	}

	if (!ValidateInput())
	{
		return;
	}

	if (!AuthSubsystem)
	{
		SetStatusText("Error: Auth subsystem not found", FLinearColor::Red);
		return;
	}

	// Disable UI during login
	SetUIEnabled(false);
	bLoginInProgress = true;
	SetStatusText("Logging in...", FLinearColor::Yellow);

	// Create login request
	FAuthRequest LoginRequest;
	LoginRequest.EmailOrUsername = EmailUsernameInput->GetText().ToString();
	LoginRequest.Password = PasswordInput->GetText().ToString();

	// Create delegates
	FOnLoginSuccess SuccessDelegate;
	SuccessDelegate.BindDynamic(this, &UEchoesLoginWidget::OnLoginSuccess);

	FOnLoginFailure FailureDelegate;
	FailureDelegate.BindDynamic(this, &UEchoesLoginWidget::OnLoginFailure);

	// Call auth subsystem
	AuthSubsystem->Auth_Login(LoginRequest, SuccessDelegate, FailureDelegate);
}

void UEchoesLoginWidget::OnRegisterButtonClicked()
{
	// TODO: Navigate to registration screen
	SetStatusText("Registration not yet implemented", FLinearColor::Yellow);
}

void UEchoesLoginWidget::OnPasswordCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
	if (CommitMethod == ETextCommit::OnEnter)
	{
		OnLoginButtonClicked();
	}
}

void UEchoesLoginWidget::OnLoginSuccess(const FAuthResponse& AuthResponse)
{
	bLoginInProgress = false;
	SetUIEnabled(true);

	SetStatusText("Login successful!", FLinearColor::Green);

	// Save token if Remember Me is checked
	if (RememberMeCheckbox && RememberMeCheckbox->IsChecked() && AuthSubsystem)
	{
		AuthSubsystem->SaveAuthToken(true);
		UE_LOG(LogTemp, Log, TEXT("Saved token with Remember Me"));
	}

	// Broadcast to blueprint
	OnLoginSuccessDelegate.Broadcast(AuthResponse);

	// Wait a moment then remove this widget
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		[this]()
		{
			RemoveFromParent();
		},
		0.5f,
		false
	);
}

void UEchoesLoginWidget::OnLoginFailure(const FString& ErrorMessage)
{
	bLoginInProgress = false;
	SetUIEnabled(true);

	SetStatusText(FString::Printf(TEXT("Login failed: %s"), *ErrorMessage), FLinearColor::Red);

	// Broadcast to blueprint
	OnLoginFailureDelegate.Broadcast(ErrorMessage);
}

bool UEchoesLoginWidget::ValidateInput()
{
	if (!EmailUsernameInput || !PasswordInput)
	{
		SetStatusText("Error: Input fields not found", FLinearColor::Red);
		return false;
	}

	FString EmailUsername = EmailUsernameInput->GetText().ToString();
	FString Password = PasswordInput->GetText().ToString();

	if (EmailUsername.IsEmpty())
	{
		SetStatusText("Please enter email or username", FLinearColor::Red);
		return false;
	}

	if (Password.IsEmpty())
	{
		SetStatusText("Please enter password", FLinearColor::Red);
		return false;
	}

	if (Password.Len() < 6)
	{
		SetStatusText("Password must be at least 6 characters", FLinearColor::Red);
		return false;
	}

	return true;
}

void UEchoesLoginWidget::SetStatusText(const FString& Message, const FLinearColor& Color)
{
	if (StatusText)
	{
		StatusText->SetText(FText::FromString(Message));
		StatusText->SetColorAndOpacity(FSlateColor(Color));
	}
}

void UEchoesLoginWidget::SetUIEnabled(bool bEnabled)
{
	if (EmailUsernameInput)
	{
		EmailUsernameInput->SetIsEnabled(bEnabled);
	}

	if (PasswordInput)
	{
		PasswordInput->SetIsEnabled(bEnabled);
	}

	if (LoginButton)
	{
		LoginButton->SetIsEnabled(bEnabled);
	}

	if (RegisterButton)
	{
		RegisterButton->SetIsEnabled(bEnabled);
	}
}
