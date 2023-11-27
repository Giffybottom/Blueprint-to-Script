// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseBullet.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABaseBullet::ABaseBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	//Collision->OnComponentBeginOverlap.AddDynamic(this, &ABaseBullet::HandleHit);
	Collision->SetWorldScale3D(FVector(0.2f));
	
	SetRootComponent(Collision);
	
	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	Sphere->SetRelativeScale3D(FVector(0.6f));
	Sphere->SetCollisionProfileName("NoCollision");
	Sphere->SetGenerateOverlapEvents(false);

	Sphere->SetupAttachment(Collision);
	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->InitialSpeed = 1800.0f;
	ProjectileMovement->MaxSpeed = 2000.0f;
	ProjectileMovement->ProjectileGravityScale = 0.0f;

	//Damage Values
	BaseDamage = 1.0f;
}

// Called when the game starts or when spawned
void ABaseBullet::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(TimeHandle,this, &ABaseBullet::DestroyMe, 0.01f, true, 3.0f);
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ABaseBullet::HandleHit);
}

void ABaseBullet::HandleHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Handle Hit Parameters
	//UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult
	
	//Handle Damage Function Parameters
	//AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser
	OtherActor->OnTakeAnyDamage.Broadcast(OtherActor, BaseDamage, nullptr, this->GetInstigatorController(), this);

	UE_LOG(LogTemp, Warning, TEXT("HIT A THING ONCE"));
	DestroyMe();
}

void ABaseBullet::DestroyMe()
{
	Destroy();
}

