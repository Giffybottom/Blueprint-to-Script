// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Core/IronSightsEventGraph.h"
#include "EndOfAnimation.generated.h"

/**
 * 
 */
UCLASS()
class ZACHARYGIFFIN_06_END_API UEndOfAnimation : public UAnimNotify
{
	GENERATED_BODY()
	
public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
private:
	UIronSightsEventGraph* IronSightsEventGraph;
};
