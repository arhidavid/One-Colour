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
	Super::Tick(DeltaTime);
	auto CurrentGameMode = Cast<AOne_ColourGameMode>(GetWorld()->GetAuthGameMode());
	EColour CurrentColour = CurrentGameMode->ActiveColour;
	if (CurrentColour == EColour::Red)
	{
		UE_LOG(LogTemp, Warning, TEXT("Current colour is red"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("It is not red"));
	return;
}