// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "One_ColourGameMode.h"
#include "CPP_ColouredWallv2.generated.h"

UCLASS()
class ONE_COLOUR_API ACPP_ColouredWallv2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_ColouredWallv2();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	EColour	ColourOfThisWall;

	UPROPERTY(EditAnywhere, Category = "Setup")
	UMaterialInterface* OnMaterial;

	UPROPERTY(EditAnywhere, Category = "Setup")
	UMaterialInterface* OffMaterial;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	EColour GlobalColour;

	UFUNCTION()
	void GlobalColourChanged();

	AOne_ColourGameMode *CurrentGameMode;
};