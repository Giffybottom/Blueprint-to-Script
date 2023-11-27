// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseCharacter.h"
#include "HUDBase.h"
#include "GenericTeamAgentInterface.h"
#include "BasePlayer.generated.h"

/**
 * 
 */
UCLASS()
class ZACHARYGIFFIN_06_END_API ABasePlayer : public ABaseCharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class USpringArmComponent* SpringArmComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UCameraComponent* CameraComponent;

public:
	ABasePlayer();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable|Class")
		TSubclassOf<UHUDBase> HUDBase;
	virtual void CharacterDeath(float ratio) override;
	bool CanPickup() override;
	bool ShouldPickup() override;
	virtual FRotator GetBaseAimRotation() const override;
private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	virtual void CharacterAttack() override;
	void Reload() override;

	UUserWidget* UserWidget;
	UHUDBase* PlayerHUD;
	APlayerController* PlayerController;

	FGenericTeamId PlayerTeamID;
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Team|Player_ID")
		uint8 CurrTeamID = 8;
	virtual void SetGenericTeamId(const FGenericTeamId& TeamID) override;
	virtual FGenericTeamId GetGenericTeamId() const override;
};
