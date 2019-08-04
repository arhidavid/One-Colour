// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_ColouredWallv2.h"
#include "Runtime/Engine/Classes/Engine/World.h"

// Sets default values
ACPP_ColouredWallv2::ACPP_ColouredWallv2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_ColouredWallv2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_ColouredWallv2::Tick(float DeltaTime)
{
	if (CurrentGameMode->GlobalColour == ColourOfThisWall)
		{
			UE_LOG(LogTemp, Warning, TEXT("Its the colour!"));
			ColorMatches = true;
			this->MatchedColorIsSelected(ColorMatches);
			return;
		}
	UE_LOG(LogTemp, Warning, TEXT("It is glass"));
	ColorMatches = false;
	this->MatchedColorIsSelected(ColorMatches);
	return;
}

