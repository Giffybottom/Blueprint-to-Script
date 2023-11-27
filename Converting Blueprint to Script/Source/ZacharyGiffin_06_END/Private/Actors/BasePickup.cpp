// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BasePickup.h"

// Sets default values
ABasePickup::ABasePickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	boxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));

	//boxCollider->SetWorldScale3D(FVector(0.2f));

	SetRootComponent(boxCollider);
	boxCollider->OnComponentBeginOverlap.AddDynamic(this, &ABasePickup::HandleHit);

}

// Called when the game starts or when spawned
void ABasePickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePickup::Tick(float DeltaTime)
{
	

}

void ABasePickup::HandleHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	HandlePickup(OtherActor, SweepResult);
	HandlePostPickup();
}

void ABasePickup::HandlePickup(AActor* OtherActor, const FHitResult& SweepResult)
{
	//OtherActor->
}

void ABasePickup::HandlePostPickup()
{
	this->Destroy();
}