// Fill out your copyright notice in the Description page of Project Settings.

#include "NavigationSystem.h"
#include "Tasks/BTTask_FindPointAgain.h"

UBTTask_FindPointAgain::UBTTask_FindPointAgain()
{
	radius = 1000.0f;
}

EBTNodeResult::Type UBTTask_FindPointAgain::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	/*Super::ExecuteTask(OwnerComp, NodeMemory);*/

	AAIController* AIcontroller = OwnerComp.GetAIOwner();
	if (AIcontroller == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	APawn* aiPawn = AIcontroller->GetPawn();
	if (aiPawn == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	UNavigationSystemV1* V1NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());
	if (V1NavSystem == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	FVector randomDest = V1NavSystem->GetRandomPointInNavigableRadius(GetWorld(), aiPawn->GetActorLocation(), radius);

	UBlackboardComponent* bComponent = OwnerComp.GetBlackboardComponent();
	if (bComponent == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	bComponent->SetValueAsVector(DestinationKey.SelectedKeyName, randomDest);

	return EBTNodeResult::Succeeded;
}
