// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "One_ColourGameMode.generated.h"

<<<<<<< HEAD
UENUM()
enum class EColour : uint8
{
	Red		UMETA(DisplayName = "Red"),
	Green	UMETA(DisplayName = "Green"),
	Blue	UMETA(DisplayName = "Blue")
};

=======

UENUM(BlueprintType)
enum class EColour : uint8
{
	Red     UMETA(DisplayName = "Red"),
	Green      UMETA(DisplayName = "Green"),
	Blue   UMETA(DisplayName = "Blue"),
};


>>>>>>> e746c3098396a91d07ba3a9e69beea85dad04846
UCLASS(minimalapi)
class AOne_ColourGameMode : public AGameModeBase
{
	GENERATED_BODY()


public:
	AOne_ColourGameMode();
<<<<<<< HEAD
=======

	UPROPERTY(BlueprintReadWrite)
	EColour GlobalColour;//this is the global colour
	UFUNCTION(BlueprintCallable)
	void IncrementColour();
	//void DecrementColour();
};


>>>>>>> e746c3098396a91d07ba3a9e69beea85dad04846

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActiveColour)
	EColour ActiveColour = EColour::Red;
};