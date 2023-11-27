// Fill out your copyright notice in the Description page of Project Settings.

#include "BrainComponent.h"
#include "Core/IronSightsEventGraph.h"
#include "Actors/BaseAIController.h"
#include "Actors/BaseAI.h"

ABaseAI::ABaseAI()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

void ABaseAI::AttackActionEnds()
{
	FAIMessage::Send(this, FAIMessage(FName("AttackActionComplete"), this));
}

void ABaseAI::ReloadActionEnds()
{
	FAIMessage::Send(this, FAIMessage(FName("ReloadActionComplete"), this));
}

void ABaseAI::BeginPlay()
{
	Super::BeginPlay();

	//Bind AnimationPlay aka OnShotEnd (Animation BP)
	AnimInstance->AnaimationPlay.AddDynamic(this, &ABaseAI::AttackActionEnds);
	//Updates Blackboard information when UpdateAmmo is called
	SpawnRifle->UpdateAmmo.AddDynamic(this, &ABaseAI::UpdateBlackBoard);
	//Updates Ammo Upon BeginPlay
	UpdateBlackBoard(SpawnRifle->GetMaxAmmo(), SpawnRifle->GetCurrentAmmo());

	ABaseAIController* AIController = Cast<ABaseAIController>(GetController());
	if (AIController == nullptr)
	{
		AIController->SetGenericTeamId(FGenericTeamId(AITeamID));
	}
}

void ABaseAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseAI::AIAttak()
{
	CharacterAttack();
}

void ABaseAI::AIReload()
{
	SpawnRifle->CanReload();
}

void ABaseAI::UpdateBlackBoard(float maxAmmo, float currentAmmo)
{
	AAIController* controller = Cast<AAIController>(GetController());
	if (controller == nullptr)
	{
		return;
	}

	UBlackboardComponent* bBoardComp = controller->GetBlackboardComponent();
	if (bBoardComp == nullptr)
	{
		return;
	}

	bBoardComp->SetValueAsFloat(FName("Ammo"), currentAmmo);
}