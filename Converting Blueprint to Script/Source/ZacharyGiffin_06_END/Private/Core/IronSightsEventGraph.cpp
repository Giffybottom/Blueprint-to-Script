// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/IronSightsEventGraph.h"

void UIronSightsEventGraph::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	APawn* Pawn = TryGetPawnOwner();
	if (nullptr != Pawn)
	{
		Speed = Pawn->GetVelocity().Size();
		Direction = CalculateDirection(Pawn->GetVelocity(), Pawn->GetActorRotation());
	}
	else
	{

	}
}

void UIronSightsEventGraph::AttackAnimation()
{
	PlaySlotAnimationAsDynamicMontage(AttackAsset, FName("Action"));
}

void UIronSightsEventGraph::HurtAnimation(float ratio)
{
	if (!IsPlayingSlotAnimation(HurtAsset, FName("Action")))
	{
		//Play animation when able to be played
		PlaySlotAnimationAsDynamicMontage(HurtAsset, FName("Action"));

	}
}

void UIronSightsEventGraph::DeathAnimation()
{
	int32 deathAssetIndex = FMath::RandRange(0, 1);

	currDeathAsset = DeathAssets[deathAssetIndex];
}

float UIronSightsEventGraph::LengthOfFireAttackAnimation()
{
	return AttackAsset->GetPlayLength();
}

void UIronSightsEventGraph::ReloadAnimation()
{
	PlaySlotAnimationAsDynamicMontage(ReloadAsset, FName("Action"));
}
