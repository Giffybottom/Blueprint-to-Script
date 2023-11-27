// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BindVariables.generated.h"

UCLASS()
class ZACHARYGIFFIN_06_END_API ABindVariables : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABindVariables();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Read Only

	//Visible Anywhere (Can get, but not set in the blueprint)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Variable|ReadOnly")
	bool VisibleAnywhere;

	//Visible Defaults Only (Can get during runtime, but cannot access via editor)
	//Not in the bluepring at all
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Variable|ReadOnly")
		uint8 VisibleDefaultsOnlyOdd;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Variable|ReadOnly")
		int32 VisibleInstanceOnlyOdd;

	//This is incorrect and makes the variable unworkable...
	UPROPERTY(VisibleInstanceOnly, Category = "Variable|ReadOnly")
		int64 VisibleInstanceOnly;

	//Read/Write
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable|ReadWrite")
		float EditAnywhere;

	//Name, String, Text (All types of strings)
	//Name is a unique hash code to check int to int instead of each letter
	//String std::string
	//Text literal string "Hello"

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Variable|ReadWrite")
		FName EditDefaultsOnlyOdd;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Variable|ReadWrite")
		FString EditDefaultsOnly;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Variable|ReadWrite")
		FText EditInstanceOnlyOdd;

	UPROPERTY(EditInstanceOnly, Category = "Variable|ReadWrite")
		FVector EditInstanceOnly;

	void K2_DestroyActor() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable|Class Ref")
		TSubclassOf<class ACharacter> ClassType;

};
