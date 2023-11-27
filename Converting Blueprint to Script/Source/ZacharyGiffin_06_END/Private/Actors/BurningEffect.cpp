// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BurningEffect.h"

// Sets default values
ABurningEffect::ABurningEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	particleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemComponent"));
	SetRootComponent(particleSystemComponent);
	InitialLifeSpan = 2.0f;
}

// Called when the game starts or when spawned
void ABurningEffect::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABurningEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	HandleBurningEffectDamage(DeltaTime);

}

void ABurningEffect::HandleBurningEffectDamage(float deltaTime)
{

	float dps = deltaTime * DamagePerSecond;
	//AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser
	GetOwner()->OnTakeAnyDamage.Broadcast(GetAttachParentActor(), dps, nullptr, nullptr, GetOwner());
}

