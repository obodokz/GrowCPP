// Fill out your copyright notice in the Description page of Project Settings.


#include "Crow.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
ACrow::ACrow()
{
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetCapsuleHalfHeight(20.f);
	Capsule->SetCapsuleRadius(15.f);
	SetRootComponent(Capsule);

	CrowMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CrowMesh"));
	CrowMesh->SetupAttachment(GetRootComponent());

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ACrow::BeginPlay()
{
	Super::BeginPlay();

	
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem <UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(CrowMappingContext, 0);
		}
	}
}


// Called every frame
void ACrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACrow::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

