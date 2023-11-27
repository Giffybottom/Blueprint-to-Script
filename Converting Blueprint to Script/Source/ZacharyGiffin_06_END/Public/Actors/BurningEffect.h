// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystemComponent.h"
#include "BurningEffect.generated.h"

UCLASS()
class ZACHARYGIFFIN_06_END_API ABurningEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABurningEffect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UParticleSystemComponent* particleSystemComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float DamagePerSecond = 0.5f;
	void HandleBurningEffectDamage(float deltaTime);

};
