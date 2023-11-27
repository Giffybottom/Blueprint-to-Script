// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseCharacter.h"
#include "Components/ChildActorComponent.h"
#include "Core/IronSightsEventGraph.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.
	// You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	ChildActorComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("ChildActorComponent"));
	ChildActorComponent->SetupAttachment(GetMesh(), FName("WeaponPlacement"));
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	EffectsComponent = CreateDefaultSubobject<UEffectsComponent>(TEXT("EffectComponent"));
	EffectsComponent->SetupAttachment(GetMesh());
	EffectsComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 130.0f));
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	ChildActorComponent->SetChildActorClass(InClass, SpawnRifle);
	//                 Cast To
	SpawnRifle = Cast<ABaseRifle>(ChildActorComponent->GetChildActor());

	//Animation Object
	AnimInstance = Cast<UIronSightsEventGraph>(GetMesh()->GetAnimInstance());

	//Gives access to the rifles reset animation funciton
	rifleTimerDelegate = FTimerDelegate::CreateUObject(SpawnRifle, &ABaseRifle::ResetAnimation);

	if (SpawnRifle != nullptr && AnimInstance != nullptr)
	{
		SpawnRifle->SayShoot.AddDynamic(AnimInstance, &UIronSightsEventGraph::AttackAnimation);
		SpawnRifle->ReloadAnimation.AddDynamic(AnimInstance, &UIronSightsEventGraph::ReloadAnimation);
		AnimInstance->ReloadAction.AddDynamic(SpawnRifle, &ABaseRifle::Reload);
	}
	//Delegate using Rifle object to call reset animation bool
	if (AnimInstance != nullptr)
		AnimInstance->AnaimationPlay.AddDynamic(SpawnRifle, &ABaseRifle::ResetAnimation);

	if (HealthComponent != nullptr)
		HealthComponent->OnDamage.AddDynamic(AnimInstance, &UIronSightsEventGraph::HurtAnimation);
	else
		UE_LOG(LogTemp, Error, TEXT("This isnt working"));

	if (HealthComponent != nullptr)
		HealthComponent->OnDeath.AddDynamic(this, &ABaseCharacter::CharacterDeath);

}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABaseCharacter::CharacterAttack()
{

	//if not animating then character can shoot
	if (SpawnRifle->CanShoot())
	{
		GetWorldTimerManager().SetTimer(rifleTimerHandle, rifleTimerDelegate, 0.1f, false, AnimInstance->LengthOfFireAttackAnimation());
	}

	SpawnRifle->Attack();
}

void ABaseCharacter::CharacterDeath(float ratio)
{

	SpawnRifle->OwnerDied();
	AnimInstance->DeathAnimation();
	SetActorEnableCollision(false);
	
}

bool ABaseCharacter::CanPickup()
{
	UE_LOG(LogTemp, Warning, TEXT("Can Pickup"));
	return false;
}

bool ABaseCharacter::ShouldPickup()
{
	UE_LOG(LogTemp, Warning, TEXT("Should Pickup"));
	return true;
}

void ABaseCharacter::Reload()
{
	AnimInstance->ReloadAnimation();
	SpawnRifle->Reload();
}