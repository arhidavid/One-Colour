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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	EColour CurrentColour;

};
