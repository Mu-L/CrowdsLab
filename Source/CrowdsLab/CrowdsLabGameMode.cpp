// Copyright Epic Games, Inc. All Rights Reserved.

#include "CrowdsLabGameMode.h"
#include "CrowdsLabCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACrowdsLabGameMode::ACrowdsLabGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
