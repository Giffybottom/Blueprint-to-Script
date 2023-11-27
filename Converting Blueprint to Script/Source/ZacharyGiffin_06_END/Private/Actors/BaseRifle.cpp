// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseRifle.h"
#include "Actors/BaseBullet.h"
#include "Components/SkeletalMeshComponent.h"
#include "Templates/SubclassOf.h"

// Sets default values
ABaseRifle::ABaseRifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMesh->SetupAttachment(GetRootComponent());

	MaxAmmo = 5.0f;
	CurrentAmmo = MaxAmmo;
}

FVector ABaseRifle::GetRifleMuzzleSocketLocation()
{
	return SpawnTransformLocation = SkeletalMesh->GetSocketLocation(FName("MuzzleFlashSocket"));
}

// Called when the game starts or when spawned
void ABaseRifle::BeginPlay()
{
	Super::BeginPlay();
	
	//Cast from mesh to pawn
	Pawn = Cast<APawn>(GetParentActor());
}

bool ABaseRifle::CanShoot()
{
	return (!animatingCheck && !DeathCheck && (CurrentAmmo > 0));
}

void ABaseRifle::OwnerDied()
{
	DeathCheck = true;
}

void ABaseRifle::Reload()
{
	CurrentAmmo = MaxAmmo;
	UpdateAmmo.Broadcast(MaxAmmo, CurrentAmmo);

}

void ABaseRifle::UseAmmo()
{
	CurrentAmmo = CurrentAmmo - 1;
	if (CurrentAmmo < 0.0f)
	{
		CurrentAmmo = 0.0f;
	}
	UpdateAmmo.Broadcast(MaxAmmo, CurrentAmmo);
}

void ABaseRifle::CanReload()
{
	if (!animatingCheck)
	{
		animatingCheck = true;
		//Reload();
		ReloadAnimation.Broadcast();
	}

}

float ABaseRifle::GetMaxAmmo()
{
	return MaxAmmo;
}

float ABaseRifle::GetCurrentAmmo()
{
	return CurrentAmmo;
}

void ABaseRifle::Attack()
{
	if (CanShoot() && !DeathCheck)
	{
		SpawnTransformLocation = SkeletalMesh->GetSocketLocation(FName("MuzzleFlashSocket"));
		SpawnTransformRotation = Pawn->GetBaseAimRotation();
		OwnerAndInstigator.Owner = Pawn->GetController();
		OwnerAndInstigator.Instigator = Pawn;

		AActor* Actor = GetWorld()->SpawnActor<AActor>(BaseBullet, SpawnTransformLocation,
			SpawnTransformRotation, OwnerAndInstigator);

		animatingCheck = true;

		//Tell the objects with SayShoot to run their functions attached to this broadcast.
		SayShoot.Broadcast();

		UseAmmo();
	}
}

void ABaseRifle::ResetAnimation()
{
	animatingCheck = false;
}
