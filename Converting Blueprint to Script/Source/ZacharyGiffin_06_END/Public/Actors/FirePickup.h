// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BasePickup.h"
#include "Particles/ParticleSystemComponent.h"
#include "FirePickup.generated.h"

/**
 * 
 */
UCLASS()
class ZACHARYGIFFIN_06_END_API AFirePickup : public ABasePickup
{
	GENERATED_BODY()
public:
	AFirePickup();
protected:
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UParticleSystemComponent* particleSystemComponent;
	virtual void HandlePickup(AActor* OtherActor, const FHitResult& SweepResult) override;
	virtual void HandlePostPickup() override;
	float Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable | Class")
		TSubclassOf<class UDamageType> damageType;
private:
};
