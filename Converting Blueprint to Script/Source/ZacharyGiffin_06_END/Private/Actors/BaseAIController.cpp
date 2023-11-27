// Fill out your copyright notice in the Description page of Project Settings.

#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionSystem.h"
#include "Actors/BaseAIController.h"

ABaseAIController::ABaseAIController()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	AIPerceptionSight = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));
	
	AIPerceptionSight->OnTargetPerceptionUpdated.AddDynamic(this, &ABaseAIController::HandleDetectPlayer);
}

void ABaseAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	RunBehaviorTree(aiControllerBTree);

}

void ABaseAIController::HandleDetectPlayer(AActor* Actor, FAIStimulus Stimulus)
{
	UE_LOG(LogTemp, Warning, TEXT("I SEE YOU!"));
	UBlackboardComponent* bBoard = GetBlackboardComponent();
	if (Stimulus.WasSuccessfullySensed())
	{
		bBoard->SetValueAsObject("Player", Actor);
	}
	else
	{
		bBoard->ClearValue(FName("Player"));
	}
}

void ABaseAIController::SetGenericTeamId(const FGenericTeamId& NewTeamID)
{
	Super::SetGenericTeamId(NewTeamID);

	UAIPerceptionSystem* AIPerceptionComp = UAIPerceptionSystem::GetCurrent(GetWorld());
	AIPerceptionComp->UpdateListener(*AIPerceptionSight);
}
