// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"
#include "Interfaces/BPI_Effects.h"
#include "BurningDamageType.generated.h"

/**
 * 
 */
UCLASS()
class ZACHARYGIFFIN_06_END_API UBurningDamageType : public UDamageType, public IBPI_Effects
{
	GENERATED_BODY()

public:
	void StartEffect(AActor* DamagedActor, AActor* DamageCauser) const override;
};
