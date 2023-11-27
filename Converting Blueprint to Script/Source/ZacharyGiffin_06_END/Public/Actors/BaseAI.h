// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseCharacter.h"
#include "Interfaces/EnemyInterface.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BaseAI.generated.h"

/**
 * 
 */
UCLASS()
class ZACHARYGIFFIN_06_END_API ABaseAI : public ABaseCharacter, public IEnemyInterface
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ABaseAI();
	UFUNCTION()
		void AttackActionEnds();
	UFUNCTION()
		void ReloadActionEnds();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void AIAttak() override;
	void AIReload() override;
	UFUNCTION()
		void UpdateBlackBoard(float maxAmmo, float currentAmmo);
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Team|AI_ID")
		uint8 AITeamID = 7;
};
