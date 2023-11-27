// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Animation/EndOfAnimation.h"

void UEndOfAnimation::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	IronSightsEventGraph = Cast<UIronSightsEventGraph>(MeshComp->GetAnimInstance());

	if (IronSightsEventGraph != nullptr)
	{
		IronSightsEventGraph->AnaimationPlay.Broadcast();
	}
}
