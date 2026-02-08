// Copyright Epic Games, Inc. All Rights Reserved.

#include "OverviewWidget.h"
#include "Components/ListView.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

// Distance constants (in cm)
static const float CENTIMETERS_PER_METER = 100.0f;
static const float METERS_PER_KILOMETER = 1000.0f;
static const float METERS_PER_AU = 149597870700.0f; // 1 Astronomical Unit in meters

FString FOverviewRowData::GetFormattedDistance() const
{
return UOverviewWidget::Common_FormatDistance(Distance);
}

FString FOverviewRowData::GetFormattedVelocity() const
{
return UOverviewWidget::Common_FormatVelocity(RadialVelocity);
}

// ==================== UOverviewRowWidget ====================

void UOverviewRowWidget::SetRowData(const FOverviewRowData& InRowData)
{
RowData = InRowData;
UpdateDisplay();
}

void UOverviewRowWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

if (UOverviewRowObject* RowObject = Cast<UOverviewRowObject>(ListItemObject))
{
SetRowData(RowObject->RowData);
}
}

// ==================== UOverviewWidget ====================

UOverviewWidget::UOverviewWidget(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
, UpdateInterval(1.0f) // Update distances every second
, MaxDisplayedEntries(0) // 0 = unlimited
, CurrentSortBy(EOverviewSortBy::Distance)
, bCurrentSortDescending(false)
{
}

void UOverviewWidget::NativeConstruct()
{
Super::NativeConstruct();

// Bind list view events
if (OverviewListView)
{
    OverviewListView->OnItemSelectionChanged().AddUObject(this, &UOverviewWidget::HandleSelectionChanged);
    OverviewListView->OnItemDoubleClicked().AddUObject(this, &UOverviewWidget::HandleItemDoubleClicked);
}

// Bind sort button events
if (SortDistanceButton)
{
SortDistanceButton->OnClicked.AddDynamic(this, &UOverviewWidget::HandleSortDistanceClicked);
}
if (SortNameButton)
{
SortNameButton->OnClicked.AddDynamic(this, &UOverviewWidget::HandleSortNameClicked);
}
if (SortTypeButton)
{
SortTypeButton->OnClicked.AddDynamic(this, &UOverviewWidget::HandleSortTypeClicked);
}

// Start periodic update timer
if (UWorld* World = GetWorld())
{
World->GetTimerManager().SetTimer(
UpdateTimerHandle,
this,
&UOverviewWidget::ClientOnly_RefreshEntries,
UpdateInterval,
true // Loop
);
}

UpdateHeaderText();
}

void UOverviewWidget::NativeDestruct()
{
// Clear timer
if (UWorld* World = GetWorld())
{
World->GetTimerManager().ClearTimer(UpdateTimerHandle);
}

Super::NativeDestruct();
}

void UOverviewWidget::AddEntry(const FOverviewRowData& RowData)
{
if (!OverviewListView)
{
return;
}

// Check if entry already exists
if (EntryMap.Contains(RowData.EntityID))
{
UpdateEntry(RowData.EntityID, RowData);
return;
}

// Check type filter
if (!PassesTypeFilter(RowData))
{
return;
}

// Create new list object
UOverviewRowObject* RowObject = NewObject<UOverviewRowObject>(this);
RowObject->RowData = RowData;

// Add to map and list
EntryMap.Add(RowData.EntityID, RowObject);
OverviewListView->AddItem(RowObject);

UpdateHeaderText();

// Re-sort if needed
if (EntryMap.Num() > 1)
{
ClientOnly_SortOverview(CurrentSortBy, bCurrentSortDescending);
}
}

void UOverviewWidget::RemoveEntry(int32 EntityID)
{
if (!OverviewListView)
{
return;
}

if (UOverviewRowObject** FoundObject = EntryMap.Find(EntityID))
{
OverviewListView->RemoveItem(*FoundObject);
EntryMap.Remove(EntityID);
UpdateHeaderText();
}
}

void UOverviewWidget::UpdateEntry(int32 EntityID, const FOverviewRowData& NewRowData)
{
if (UOverviewRowObject** FoundObject = EntryMap.Find(EntityID))
{
(*FoundObject)->RowData = NewRowData;

// Check if still passes filter
if (!PassesTypeFilter(NewRowData))
{
RemoveEntry(EntityID);
return;
}

// Refresh the list item
if (OverviewListView)
{
OverviewListView->RegenerateAllEntries();
}
}
}

void UOverviewWidget::ClearAll()
{
if (OverviewListView)
{
OverviewListView->ClearListItems();
}
EntryMap.Empty();
UpdateHeaderText();
}

void UOverviewWidget::ClientOnly_SortOverview(EOverviewSortBy SortBy, bool bDescending)
{
if (!OverviewListView)
{
return;
}

CurrentSortBy = SortBy;
bCurrentSortDescending = bDescending;

// Get all items
TArray<UOverviewRowObject*> AllItems;
EntryMap.GenerateValueArray(AllItems);

// Sort based on criteria
AllItems.Sort([SortBy, bDescending](const UOverviewRowObject& A, const UOverviewRowObject& B)
{
bool bResult = false;

switch (SortBy)
{
case EOverviewSortBy::Distance:
bResult = A.RowData.Distance < B.RowData.Distance;
break;

case EOverviewSortBy::Name:
bResult = A.RowData.EntityName < B.RowData.EntityName;
break;

case EOverviewSortBy::Type:
bResult = static_cast<uint8>(A.RowData.EntryType) < static_cast<uint8>(B.RowData.EntryType);
break;

case EOverviewSortBy::RadialVelocity:
bResult = A.RowData.RadialVelocity < B.RowData.RadialVelocity;
break;
}

return bDescending ? !bResult : bResult;
});

// Rebuild list in sorted order
OverviewListView->ClearListItems();
for (UOverviewRowObject* Item : AllItems)
{
OverviewListView->AddItem(Item);
}
}

FString UOverviewWidget::Common_FormatDistance(float DistanceInCm)
{
// Convert to meters
float Meters = DistanceInCm / CENTIMETERS_PER_METER;

if (Meters < 1.0f)
{
// Less than 1 meter - show in cm
return FString::Printf(TEXT("%.0f cm"), DistanceInCm);
}
else if (Meters < 1000.0f)
{
// Less than 1 km - show in meters
return FString::Printf(TEXT("%.0f m"), Meters);
}
else if (Meters < 1000000.0f)
{
// Less than 1000 km - show in km
float Kilometers = Meters / METERS_PER_KILOMETER;
return FString::Printf(TEXT("%.1f km"), Kilometers);
}
else
{
// Show in AU (Astronomical Units)
float AU = Meters / METERS_PER_AU;
return FString::Printf(TEXT("%.2f AU"), AU);
}
}

FString UOverviewWidget::Common_FormatVelocity(float VelocityInMps)
{
float AbsVelocity = FMath::Abs(VelocityInMps);

if (AbsVelocity < 0.1f)
{
return TEXT("Stationary");
}

FString DirectionStr = (VelocityInMps < 0.0f) ? TEXT("↓") : TEXT("↑"); // Approaching : Fleeing

if (AbsVelocity < 1000.0f)
{
return FString::Printf(TEXT("%s %.0f m/s"), *DirectionStr, AbsVelocity);
}
else
{
float KmPerSec = AbsVelocity / 1000.0f;
return FString::Printf(TEXT("%s %.1f km/s"), *DirectionStr, KmPerSec);
}
}

bool UOverviewWidget::GetSelectedEntry(FOverviewRowData& OutRowData) const
{
if (!OverviewListView)
{
return false;
}

UObject* SelectedItem = OverviewListView->GetSelectedItem();
if (UOverviewRowObject* RowObject = Cast<UOverviewRowObject>(SelectedItem))
{
OutRowData = RowObject->RowData;
return true;
}

return false;
}

void UOverviewWidget::SetTypeFilter(const TArray<EOverviewEntryType>& AllowedTypes)
{
TypeFilter = AllowedTypes;

// Rebuild list with filter
if (OverviewListView)
{
TArray<int32> EntriesToRemove;

for (const auto& Entry : EntryMap)
{
if (!PassesTypeFilter(Entry.Value->RowData))
{
EntriesToRemove.Add(Entry.Key);
}
}

for (int32 EntityID : EntriesToRemove)
{
RemoveEntry(EntityID);
}
}
}

void UOverviewWidget::ClientOnly_RefreshEntries()
{
if (!OverviewListView)
{
return;
}

FVector PlayerPos = GetPlayerPosition();

// Update distances for all entries
bool bNeedsResort = false;
for (auto& Entry : EntryMap)
{
UOverviewRowObject* RowObject = Entry.Value;
if (RowObject && RowObject->RowData.ActorReference)
{
AActor* TargetActor = RowObject->RowData.ActorReference;

// Calculate new distance
float NewDistance = FVector::Dist(PlayerPos, TargetActor->GetActorLocation());

// Only update if significantly changed (> 1% difference)
if (FMath::Abs(NewDistance - RowObject->RowData.Distance) / FMath::Max(1.0f, RowObject->RowData.Distance) > 0.01f)
{
RowObject->RowData.Distance = NewDistance;
bNeedsResort = true;
}

// Calculate radial velocity if target has velocity component
if (UPrimitiveComponent* RootComp = Cast<UPrimitiveComponent>(TargetActor->GetRootComponent()))
{
FVector TargetVelocity = RootComp->GetPhysicsLinearVelocity();
FVector ToTarget = (TargetActor->GetActorLocation() - PlayerPos).GetSafeNormal();

// Radial velocity is velocity projected onto direction to target
float RadialVel = FVector::DotProduct(TargetVelocity, ToTarget) / CENTIMETERS_PER_METER; // Convert to m/s
RowObject->RowData.RadialVelocity = RadialVel;
}
}
}

// Regenerate entries to update display
OverviewListView->RegenerateAllEntries();

// Re-sort if distances changed and we're sorting by distance
if (bNeedsResort && CurrentSortBy == EOverviewSortBy::Distance)
{
ClientOnly_SortOverview(CurrentSortBy, bCurrentSortDescending);
}
}

void UOverviewWidget::HandleSelectionChanged(UObject* Item)
{
if (UOverviewRowObject* RowObject = Cast<UOverviewRowObject>(Item))
{
OnSelectionChanged.Broadcast(RowObject->RowData);
}
}

void UOverviewWidget::HandleItemDoubleClicked(UObject* Item)
{
if (UOverviewRowObject* RowObject = Cast<UOverviewRowObject>(Item))
{
OnItemDoubleClicked.Broadcast(RowObject->RowData.ActorReference);
}
}

void UOverviewWidget::HandleSortDistanceClicked()
{
// Toggle descending if already sorting by distance
bool bDesc = (CurrentSortBy == EOverviewSortBy::Distance) ? !bCurrentSortDescending : false;
ClientOnly_SortOverview(EOverviewSortBy::Distance, bDesc);
}

void UOverviewWidget::HandleSortNameClicked()
{
bool bDesc = (CurrentSortBy == EOverviewSortBy::Name) ? !bCurrentSortDescending : false;
ClientOnly_SortOverview(EOverviewSortBy::Name, bDesc);
}

void UOverviewWidget::HandleSortTypeClicked()
{
bool bDesc = (CurrentSortBy == EOverviewSortBy::Type) ? !bCurrentSortDescending : false;
ClientOnly_SortOverview(EOverviewSortBy::Type, bDesc);
}

void UOverviewWidget::UpdateHeaderText()
{
if (HeaderText)
{
int32 EntryCount = EntryMap.Num();
FString HeaderString = FString::Printf(TEXT("Overview (%d)"), EntryCount);
HeaderText->SetText(FText::FromString(HeaderString));
}
}

bool UOverviewWidget::PassesTypeFilter(const FOverviewRowData& RowData) const
{
// Empty filter = all pass
if (TypeFilter.Num() == 0)
{
return true;
}

return TypeFilter.Contains(RowData.EntryType);
}

FVector UOverviewWidget::GetPlayerPosition() const
{
if (APlayerController* PC = GetOwningPlayer())
{
if (APawn* PlayerPawn = PC->GetPawn())
{
return PlayerPawn->GetActorLocation();
}
}
return FVector::ZeroVector;
}
