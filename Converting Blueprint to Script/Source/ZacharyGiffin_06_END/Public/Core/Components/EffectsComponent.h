// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Interfaces/PickupInterface.h"
#include "Actors/BurningEffect.h"
#include "EffectsComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZACHARYGIFFIN_06_END_API UEffectsComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEffectsComponent();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable | Class Reference")
	TSubclassOf<class ABurningEffect> inClass;
	FVector SpawnTransformLocation;
	FRotator SpawnTransformRotation;
	FActorSpawnParameters OwnerAndInstigator;
public:	
	void StartEffect(EEffects effect, AActor* actor);
	void BurningEffect(AActor* actor);

		
};
