// Fill out your copyright notice in the Description page of Project Settings.


#include "Bind/BindFunctions.h"
#include "../../ZacharyGiffin_06_END.h"


// Sets default values
ABindFunctions::ABindFunctions()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABindFunctions::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABindFunctions::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABindFunctions::BlueprintCallable()
{
	UE_LOG(Game, Warning, TEXT("in C++ BlueprintCallable"));
}

