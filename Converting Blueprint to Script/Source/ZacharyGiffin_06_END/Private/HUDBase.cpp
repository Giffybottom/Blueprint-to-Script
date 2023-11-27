// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDBase.h"
#include "Blueprint/SlateBlueprintLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/Image.h"
#include "Components/ProgressBar.h"

void UHUDBase::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	HandleCrosshair();

}

void UHUDBase::NativeOnInitialized()
{
	CreateCrosshair();
}

void UHUDBase::CreateCrosshair()
{

	parameterName = "Color";
	DangerColor = FLinearColor(0.85f, 0.1f, 0.1f);
	SafeColor = FLinearColor(0.0f, 0.0f, 1.0);
	MaterialInstance = Crosshair->GetDynamicMaterial();

	//hit the world and ai
	ObjectsToHit.Add(EObjectTypeQuery::ObjectTypeQuery1); //World Static (Walls, Floors, Etc...)
	ObjectsToHit.Add(EObjectTypeQuery::ObjectTypeQuery3); //Pawns (Player, AI, Etc..)

	//Dont try and hit the player
	IgnoreMe.Add(GetOwningPlayerPawn());
}

FVector UHUDBase::GetEndPoint()
{
	return EndPoint;
}

void UHUDBase::SetAmmo(float maxAmmo, float currAmmo)
{
	CurrentAmmo->SetText(FText::AsNumber(currAmmo));
	
	MaxAmmo->SetText(FText::AsNumber(maxAmmo));
}

FVector2D UHUDBase::GetScreenPosition()
{

	FVector2D PixelCoordinate;
	FVector2D WorldCoordinate;

	FGeometry CrosshairGeometry = Crosshair->GetCachedGeometry();

	FVector2D AbsoluteSize = CrosshairGeometry.GetAbsoluteSize();
	FVector2D HalfAbsoluteSize = AbsoluteSize * 0.5f;

	USlateBlueprintLibrary::LocalToViewport(GetOwningPlayer(), CrosshairGeometry, FVector2D(0.0f, 0.0f), PixelCoordinate, WorldCoordinate);

	PixelCoordinate = HalfAbsoluteSize + PixelCoordinate;

	return PixelCoordinate;
}


void UHUDBase::SetHealth(float percent)
{
	UE_LOG(LogTemp, Error, TEXT("BAR UPDATE"));
	progressBar->SetPercent(percent);
}

void UHUDBase::HandleCrosshair()
{
	FVector WorldLocation;
	FVector WorldDirection;

	FHitResult DidIHit;

	FVector2D ScreenPosition = GetScreenPosition();

	GetOwningPlayer()->DeprojectScreenPositionToWorld(ScreenPosition.X, ScreenPosition.Y, WorldLocation, WorldDirection);

	WorldDirection = (WorldDirection * 1000000) + WorldLocation;
	bool hitSomething = UKismetSystemLibrary::LineTraceSingleForObjects(GetOwningPlayer(), WorldLocation, WorldDirection, ObjectsToHit, false, IgnoreMe, EDrawDebugTrace::None, DidIHit, true);

	if (hitSomething)
	{
		EndPoint = DidIHit.Location;

		if (Cast<APawn>(DidIHit.GetActor()))
		{
			MaterialInstance->SetVectorParameterValue(parameterName, DangerColor);
			
		}
		else
		{
			MaterialInstance->SetVectorParameterValue(parameterName, SafeColor);
			
		}
	}
	else
	{
		MaterialInstance->SetVectorParameterValue(parameterName, SafeColor);
		EndPoint = WorldDirection;
	}

	

}
