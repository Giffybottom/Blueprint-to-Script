// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Core/Components/HealthComponent.h"
#include "Interfaces/PickupInterface.h"
#include "Core/Components/EffectsComponent.h"
#include "Actors/BaseRifle.h"

#include "BaseCharacter.generated.h"

//Changed (Abstract added)
UCLASS(Abstract)
class ZACHARYGIFFIN_06_END_API ABaseCharacter : public ACharacter, public IPickupInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UChildActorComponent* ChildActorComponent;
	class UIronSightsEventGraph* AnimInstance;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UHealthComponent* HealthComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UEffectsComponent* EffectsComponent;

	UInputComponent* userInput;
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Varible|Weapon")
		TSubclassOf<class ABaseRifle> InClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		ABaseRifle* SpawnRifle;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FTimerHandle rifleTimerHandle;
	FTimerDelegate rifleTimerDelegate;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void CharacterAttack();

	UFUNCTION()
	virtual void CharacterDeath(float ratio);

	//Interface Code Start
	virtual bool CanPickup() override;

	virtual bool ShouldPickup() override;
	virtual void Reload();
	//Interface Code End
};

