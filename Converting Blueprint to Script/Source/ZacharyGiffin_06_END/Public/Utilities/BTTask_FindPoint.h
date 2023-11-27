// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindPoint.generated.h"

/**
 * 
 */
UCLASS()
class ZACHARYGIFFIN_06_END_API UBTTask_FindPoint : public UBTTaskNode
{
	GENERATED_BODY()

public:

	UBTTask_FindPoint();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float radius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBlackboardKeySelector DestinationKey;
};
