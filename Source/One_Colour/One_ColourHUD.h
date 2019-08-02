// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "One_ColourHUD.generated.h"

UCLASS()
class AOne_ColourHUD : public AHUD
{
	GENERATED_BODY()

public:
	AOne_ColourHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

