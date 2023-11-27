// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseRifle.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FShootMee);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUpdateAmmo, float, current, float, max);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FReloadAnimation);

UCLASS()
class ZACHARYGIFFIN_06_END_API ABaseRifle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseRifle();
	FVector GetRifleMuzzleSocketLocation();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USkeletalMeshComponent* SkeletalMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable|Bullet")
	TSubclassOf<class ABaseBullet> BaseBullet;
	FVector SpawnTransformLocation;
	FRotator SpawnTransformRotation;
	FActorSpawnParameters OwnerAndInstigator;
	APawn* Pawn;
public:	

	void Attack();
	UFUNCTION()
	void ResetAnimation();
	bool animatingCheck; //would like to put this in private, but unreal crashes even though the only references are in rifle...

	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Delegates")
	FShootMee SayShoot;
	FUpdateAmmo UpdateAmmo;
	FReloadAnimation ReloadAnimation;
	bool CanShoot();

	void OwnerDied();
	UFUNCTION()
		void Reload();
	void UseAmmo();
	void CanReload();
	float GetMaxAmmo();
	float GetCurrentAmmo();
private:
	//Death Stuff
	bool DeathCheck;
	float MaxAmmo;
	float CurrentAmmo;

};
