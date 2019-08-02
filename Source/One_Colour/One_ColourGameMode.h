// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "One_ColourGameMode.generated.h"


UENUM(BlueprintType)
enum class EColour : uint8
{
	Red     UMETA(DisplayName = "Red"),
	Green      UMETA(DisplayName = "Green"),
	Blue   UMETA(DisplayName = "Blue"),
};


UCLASS(minimalapi)
class AOne_ColourGameMode : public AGameModeBase
{
	GENERATED_BODY()


public:
	AOne_ColourGameMode();

	UPROPERTY(BlueprintReadWrite)
	EColour GlobalColour;//this is the global colour
	UFUNCTION(BlueprintCallable)
	void IncrementColour();
	//void DecrementColour();
};



