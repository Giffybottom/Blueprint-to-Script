// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "HUDBase.generated.h"

/**
 * 
 */
UCLASS()
class ZACHARYGIFFIN_06_END_API UHUDBase : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION()
		void SetHealth(float percent);
	void HandleCrosshair();
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual void NativeOnInitialized() override;
	void CreateCrosshair();
	FVector GetEndPoint();
	UFUNCTION()
		void SetAmmo(float maxAmmo, float currAmmo);
protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UProgressBar* progressBar;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UImage* Crosshair;
	UMaterialInstanceDynamic* MaterialInstance;
	FName parameterName;
	FLinearColor DangerColor;
	FLinearColor SafeColor;

	TArray<AActor*> IgnoreMe;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectsToHit;

	FVector2D GetScreenPosition();

	FVector EndPoint;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* MaxAmmo;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* CurrentAmmo;
};
