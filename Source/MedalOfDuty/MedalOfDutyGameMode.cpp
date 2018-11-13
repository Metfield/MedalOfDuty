// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MedalOfDutyGameMode.h"
#include "MedalOfDutyHUD.h"
#include "MedalOfDutyCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMedalOfDutyGameMode::AMedalOfDutyGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMedalOfDutyHUD::StaticClass();
}
