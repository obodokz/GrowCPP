// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPP_CrowGameMode.h"
#include "CPP_CrowCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACPP_CrowGameMode::ACPP_CrowGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
