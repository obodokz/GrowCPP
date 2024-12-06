// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Crow.generated.h"

class UCapsuleComponent;
class USkeletalMeshComponent;
class UInputMappingContext;

UCLASS()
class CPP_CROW_API ACrow : public APawn
{
	GENERATED_BODY()

public:
	ACrow();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	UInputMappingContext* CrowMappingContext;

private:
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Capsule;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* CrowMesh;

};
