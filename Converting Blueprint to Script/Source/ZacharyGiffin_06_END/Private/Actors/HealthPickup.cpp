// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/HealthPickup.h"

AHealthPickup::AHealthPickup()
{
	particleSystemComponent->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
	particleSystemComponent->SetWorldScale3D(FVector(0.5f, 0.5f, 0.7f));

	Damage = -1.0f;
}



void AHealthPickup::BeginPlay()
{
	Super::BeginPlay();
}

void AHealthPickup::HandlePostPickup()
{

	bool test = this->Destroy();

	if(test)
		UE_LOG(LogTemp, Error, TEXT("destoryed"))
	else
		UE_LOG(LogTemp, Error, TEXT("IMMORTAL"))
}

void AHealthPickup::HandleHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	IPickupInterface* PickupInterface = Cast<IPickupInterface>(OtherActor);
	if (PickupInterface != nullptr)
	{
		if (PickupInterface->CanPickup() && PickupInterface->ShouldPickup())
		{
			HandlePickup(OtherActor, SweepResult);
			HandlePostPickup();
		}
	}

}
