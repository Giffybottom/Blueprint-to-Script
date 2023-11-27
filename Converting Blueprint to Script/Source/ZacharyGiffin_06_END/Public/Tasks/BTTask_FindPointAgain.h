// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTTask_FindPointAgain.generated.h"

/**
 * 
 */
UCLASS()
class ZACHARYGIFFIN_06_END_API UBTTask_FindPointAgain : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTask_FindPointAgain();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float radius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBlackboardKeySelector DestinationKey;
private:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
