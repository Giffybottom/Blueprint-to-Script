// Fill out your copyright notice in the Description page of Project Settings.


#include "Bind/BindVariables.h"
#include "../../ZacharyGiffin_06_END.h"
#include "GameFramework/Character.h"

// Sets default values
ABindVariables::ABindVariables()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABindVariables::BeginPlay()
{
	Super::BeginPlay();

	//Using %s means you have to provide an extra string parameter.
	UE_LOG(Game, Error, TEXT("Actor's name is %s"), *GetName());
	//Using %d and %f is for int and float
	UE_LOG(Game, Display, TEXT("int is %d float is %f"), VisibleInstanceOnlyOdd, EditAnywhere);
	
	UE_LOG(Game, Warning, TEXT("Velocity is %s"), *GetVelocity().ToString());
	//Cant get until the game starts
	FTimerHandle handle;
	GetWorld()->GetTimerManager().SetTimer(handle, this, &ABindVariables::K2_DestroyActor, 3.0f, false, 0.0f);
}

// Called every frame
void ABindVariables::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABindVariables::K2_DestroyActor()
{
	FActorSpawnParameters Params;
	Params.Owner = this;
	Params.Instigator = nullptr;
	GetWorld()->SpawnActor<AActor>(ClassType, FVector(0.0f,0.0f,500.0f), FRotator(), Params);
	Super::K2_DestroyActor();
}

