// Fill out your copyright notice in the Description page of Project Settings.

#include "Interfaces/BPI_Effects.h"
#include "Core/Components/HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	MaxHealth = 5.0f;
	CurrentHealth = 0.0f;

	
}

bool UHealthComponent::doIHaveFullHP()
{
	return ((CurrentHealth / MaxHealth) > 0.99f);
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;

	
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::HandleDamage);
	// ...
	
}

void UHealthComponent::HandleDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	CurrentHealth -= Damage;

	const IBPI_Effects* effects = Cast<IBPI_Effects>(DamageType);

	if (effects != nullptr)
	{
		effects->StartEffect(DamagedActor, DamageCauser);
	}

	if (CurrentHealth <= 0)
	{
		UE_LOG(LogTemp, Error, TEXT("DEATH"));
		CurrentHealth = 0;
		OnDeath.Broadcast((CurrentHealth / MaxHealth));
	}
	else if (CurrentHealth > MaxHealth)
	{
		CurrentHealth = MaxHealth;
	}

	if (CurrentHealth > 0 && Damage > 0)
	{
		UE_LOG(LogTemp, Error, TEXT("DAMAGE"));
		OnDamage.Broadcast((CurrentHealth / MaxHealth));
	}
	else if(Damage < 0)
	{
		UE_LOG(LogTemp, Error, TEXT("HEAL"));
		OnHeal.Broadcast((CurrentHealth / MaxHealth));
	}
}