// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamage, float, dmg);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeath, float, dmg);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZACHARYGIFFIN_06_END_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();
	UFUNCTION()
	void HandleDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	FOnDamage OnDamage;
	FOnDamage OnHeal;
	FOnDeath OnDeath;
	bool doIHaveFullHP();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
		float MaxHealth;
	UPROPERTY(VisibleAnywhere)
		float CurrentHealth;
};
