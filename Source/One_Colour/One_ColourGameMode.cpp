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

FVector AOne_ColourGameMode::GetColourVector(EColour Colour)
{
	FVector VColour;
	switch (Colour)
	{
	case EColour::Red: VColour = FVector(1, 0, 0);
		break;
	case EColour::Green: FVector(0, 1, 0);
		break;
	case EColour::Blue: FVector(0, 0, 1);
		break;
	default:	VColour = FVector(1, 0, 0);
		break;
	}
	return VColour;
}