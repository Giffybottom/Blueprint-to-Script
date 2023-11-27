// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Actors/BurningDamageType.h"
#include "Actors/FirePickup.h"

AFirePickup::AFirePickup()
{
	particleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemComponent"));
	particleSystemComponent->SetupAttachment(boxCollider);
	particleSystemComponent->SetRelativeLocation(FVector(0.0f, 0.0f, -30.0f));
	particleSystemComponent->SetWorldScale3D(FVector(0.4f, 0.4, 0.025f));

	boxCollider->SetWorldScale3D(FVector(1.6f));

	Damage = 1.0f;
}

void AFirePickup::BeginPlay()
{
	Super::BeginPlay();

}

void AFirePickup::HandlePickup(AActor* OtherActor, const FHitResult& SweepResult)
{
	Super::HandlePickup(OtherActor, SweepResult);

	UBurningDamageType::StaticClass();
	UGameplayStatics::ApplyDamage(OtherActor, Damage,this->GetInstigatorController(), this, damageType);
}

void AFirePickup::HandlePostPickup()
{

}
