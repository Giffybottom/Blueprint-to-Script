// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/Components/EffectsComponent.h"
#include "Actors/BurningDamageType.h"

void UBurningDamageType::StartEffect(AActor* DamagedActor, AActor* DamageCauser) const
{
	UEffectsComponent* effectComp = DamagedActor->FindComponentByClass<UEffectsComponent>();

	if (effectComp != nullptr)
	{
		effectComp->StartEffect(EEffects::Effect_Burning, DamagedActor);
	}
}
