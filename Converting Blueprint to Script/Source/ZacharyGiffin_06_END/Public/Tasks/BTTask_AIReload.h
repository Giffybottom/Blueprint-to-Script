// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTTask_AIReload.generated.h"

/**
 * 
 */
UCLASS()
class ZACHARYGIFFIN_06_END_API UBTTask_AIReload : public UBTTaskNode
{
	GENERATED_BODY()
	
virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

public:

};
