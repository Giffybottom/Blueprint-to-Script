// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PickupInterface.generated.h"

UENUM(BlueprintType)
enum class EEffects : uint8
{
	Effect_Burning UMETA(DisplayName = "Burning"),
	Effect_ENumOFEffects UMETA(DisplayName = "NumOfEffects")
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UPickupInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ZACHARYGIFFIN_06_END_API IPickupInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable)
		virtual bool CanPickup() = 0;
	UFUNCTION(BlueprintCallable)
		virtual bool ShouldPickup() = 0;
};
