// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Components/EffectsComponent.h"

// Sets default values for this component's properties
UEffectsComponent::UEffectsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	
}

void UEffectsComponent::StartEffect(EEffects effect, AActor* damageCauser)
{
	switch (effect)
	{
	case EEffects::Effect_Burning:
		BurningEffect(damageCauser);
		break;
	case EEffects::Effect_ENumOFEffects:
		UE_LOG(LogTemp, Error, TEXT("Current Number of Effects"))
		break;
	default:

		UE_LOG(LogTemp, Error, TEXT("No Valid Effect"))
		break;
	}
}

void UEffectsComponent::BurningEffect(AActor* actor)
{

	FActorSpawnParameters spawnParams;
	APawn* pawn = Cast<APawn>(actor);
	SpawnTransformLocation = this->GetComponentLocation();
	SpawnTransformRotation = pawn->GetActorRotation();
	spawnParams.Owner = pawn->GetController();
	spawnParams.Instigator = pawn;

	AActor* spawnedEffect = GetWorld()->SpawnActor<AActor>(inClass, SpawnTransformLocation, SpawnTransformRotation, spawnParams);

	spawnedEffect->SetOwner(actor);

	spawnedEffect->AttachToActor(spawnedEffect->GetOwner(), FAttachmentTransformRules::KeepWorldTransform);

}


