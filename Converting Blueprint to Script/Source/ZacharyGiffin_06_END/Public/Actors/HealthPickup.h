// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/FirePickup.h"
#include "HealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class ZACHARYGIFFIN_06_END_API AHealthPickup : public AFirePickup
{
	GENERATED_BODY()
	
public:
	AHealthPickup();
protected:
	virtual void BeginPlay() override;
	virtual void HandlePostPickup() override;
	virtual void HandleHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
private:
	
};
