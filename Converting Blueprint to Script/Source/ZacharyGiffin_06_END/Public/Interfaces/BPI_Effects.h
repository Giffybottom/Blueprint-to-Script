// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BPI_Effects.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UBPI_Effects : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ZACHARYGIFFIN_06_END_API IBPI_Effects
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	virtual void StartEffect(AActor* DamagedActor, AActor* DamageCauser) const = 0;

};
