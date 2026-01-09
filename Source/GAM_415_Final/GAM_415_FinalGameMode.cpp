// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAM_415_FinalGameMode.h"
#include "GAM_415_FinalCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGAM_415_FinalGameMode::AGAM_415_FinalGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
