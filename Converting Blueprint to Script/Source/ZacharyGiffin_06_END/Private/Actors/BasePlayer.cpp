// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BasePlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<APlayerController>(this->GetController());
	UserWidget = CreateWidget(PlayerController, HUDBase);
	UserWidget->AddToViewport();

	PlayerHUD = Cast<UHUDBase>(UserWidget);

	HealthComponent->OnDamage.AddDynamic(PlayerHUD, &UHUDBase::SetHealth);
	HealthComponent->OnDeath.AddDynamic(PlayerHUD, &UHUDBase::SetHealth);
	HealthComponent->OnHeal.AddDynamic(PlayerHUD, &UHUDBase::SetHealth);

	PlayerHUD->SetHealth(1.0f);

	if (PlayerHUD != nullptr && SpawnRifle != nullptr)
	{
		SpawnRifle->UpdateAmmo.AddDynamic(PlayerHUD, &UHUDBase::SetAmmo);
		SpawnRifle->Reload();
	}

	SetGenericTeamId(FGenericTeamId(CurrTeamID));

}

FRotator ABasePlayer::GetBaseAimRotation() const
{
	FVector BulletDirection = (PlayerHUD->GetEndPoint() - SpawnRifle->GetRifleMuzzleSocketLocation());
	return FRotationMatrix::MakeFromX(BulletDirection).Rotator();
}

ABasePlayer::ABasePlayer()
{
	//Created Spring Arm Subobject
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->SetRelativeLocation(FVector(0.0f, 80.0f, 90.0f));
	SpringArmComponent->TargetArmLength = 210.0f;
	SpringArmComponent->bUsePawnControlRotation = true;

	//Camera Setup
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
}

void ABasePlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	//Anytime you call your parents function make sure to do this!
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//"this is used because BasePlayer is a "Pawn"
	PlayerInputComponent->BindAxis(FName("LookToTheSide"), this, &ABasePlayer::AddControllerYawInput);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &ABasePlayer::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ABasePlayer::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ABasePlayer::MoveRight);

	//If standard attack do character attack funtion
	PlayerInputComponent->BindAction(FName("StandardAttack"), EInputEvent::IE_Pressed, this, &ABasePlayer::CharacterAttack);
	PlayerInputComponent->BindAction(FName("Reload"), EInputEvent::IE_Pressed, this, &ABasePlayer::Reload);
}

void ABasePlayer::CharacterDeath(float ratio)
{
	Super::CharacterDeath(ratio);

	DisableInput(PlayerController);
	UserWidget->RemoveFromParent();
}

bool ABasePlayer::CanPickup()
{
	return true;
}

bool ABasePlayer::ShouldPickup()
{   
	//If I dont have full hp
	if (!HealthComponent->doIHaveFullHP())
	{
		return true;
	}

	return false;
}

void ABasePlayer::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector(), AxisValue, false);
}

void ABasePlayer::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector(), AxisValue, false);
}

void ABasePlayer::CharacterAttack()
{
	//Do BaseCharacter "CharacterAttack"
	Super::CharacterAttack();
}

void ABasePlayer::Reload()
{
	SpawnRifle->CanReload();
}

void ABasePlayer::SetGenericTeamId(const FGenericTeamId& TeamID)
{
	if (PlayerTeamID != TeamID)
	{
		PlayerTeamID = TeamID;
	}
}

FGenericTeamId ABasePlayer::GetGenericTeamId() const
{
	return PlayerTeamID;
}

