// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AIPerceptionComponent.h"
#include "BaseAIController.generated.h"

/**
 * 
 */
UCLASS()
class ZACHARYGIFFIN_06_END_API ABaseAIController : public AAIController
{
	GENERATED_BODY()

public:
	ABaseAIController();
	virtual void OnPossess(APawn* InPawn) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Perception|BehaviorTree")
		UBehaviorTree* aiControllerBTree;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UAIPerceptionComponent* AIPerceptionSight;

	UFUNCTION()
		void HandleDetectPlayer(AActor* Actor, FAIStimulus Stimulus);
	virtual void SetGenericTeamId(const FGenericTeamId& TeamID) override;
};
