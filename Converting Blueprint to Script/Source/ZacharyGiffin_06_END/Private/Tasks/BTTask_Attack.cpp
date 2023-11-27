// Fill out your copyright notice in the Description page of Project Settings.

#include "Interfaces/EnemyInterface.h"
#include "Tasks/BTTask_Attack.h"

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
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

	IEnemyInterface* EnemyInterface = Cast<IEnemyInterface>(aiPawn);
	if (EnemyInterface == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	EnemyInterface->AIAttak();

	//Finish on Send Message
	OwnerComp.RegisterMessageObserver(this, FName("AttackActionComplete"));

	return EBTNodeResult::InProgress;
}
