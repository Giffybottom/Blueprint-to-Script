// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "IronSightsEventGraph.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAnimationPlay);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FReloadAction);
/**
 * 
 */
UCLASS()
class ZACHARYGIFFIN_06_END_API UIronSightsEventGraph : public UAnimInstance
{
	GENERATED_BODY()
public:
	void NativeUpdateAnimation(float DeltaSeconds) override;
	UFUNCTION(BlueprintCallable)
	void AttackAnimation();
	UFUNCTION(BlueprintCallable)
	void HurtAnimation(float ratio);
	UFUNCTION(BlueprintCallable)
	void DeathAnimation();

	float LengthOfFireAttackAnimation();
	UFUNCTION(BlueprintCallable)
	void ReloadAnimation();

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Speed;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Direction;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables|AttackAsset")
		UAnimSequence* AttackAsset;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables|HurtAsset")
		UAnimSequence* HurtAsset;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables|DeathAsset")
		TArray<UAnimSequence*> DeathAssets;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables|DeathAsset")
		UAnimSequence* currDeathAsset;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables|ReloadAsset")
		UAnimSequence* ReloadAsset;
public:
	FAnimationPlay AnaimationPlay;
	FReloadAction ReloadAction;
};
