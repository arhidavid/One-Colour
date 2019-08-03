// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "One_ColourGameMode.h"
#include "One_ColourHUD.h"
#include "One_ColourCharacter.h"
#include "UObject/ConstructorHelpers.h"

AOne_ColourGameMode::AOne_ColourGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AOne_ColourHUD::StaticClass();
	GlobalColour = EColour::Red;
	
}

void AOne_ColourGameMode::IncrementColour()
{
	switch (GlobalColour)
	{
	case EColour::Red: GlobalColour = EColour::Green; break;
		case EColour::Green: GlobalColour = EColour::Blue; break;
		case EColour::Blue: GlobalColour = EColour::Red; break;
	}
	ColourChanged.Broadcast();
}