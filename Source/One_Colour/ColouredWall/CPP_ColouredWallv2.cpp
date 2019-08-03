// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_ColouredWallv2.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"

// Sets default values
ACPP_ColouredWallv2::ACPP_ColouredWallv2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);
	RootComponent = StaticMesh;
	OnMaterial = CreateDefaultSubobject<UMaterialInterface>(TEXT("OnMaterial"));
	OffMaterial = CreateDefaultSubobject<UMaterialInterface>(TEXT("OffMaterial"));
}

// Called when the game starts or when spawned
void ACPP_ColouredWallv2::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("%s is "), this);
	CurrentGameMode = Cast<AOne_ColourGameMode>(GetWorld()->GetAuthGameMode());
	CurrentGameMode->ColourChanged.AddUObject(this, &ACPP_ColouredWallv2::GlobalColourChanged);
}

void ACPP_ColouredWallv2::GlobalColourChanged()
{
	if (ensure(StaticMesh))
	{	
		if (CurrentGameMode->GlobalColour == ColourOfThisWall)
		{
		UE_LOG(LogTemp, Warning, TEXT("Its the colour!"));
		StaticMesh->SetMaterial(0, OnMaterial);
		return;
		}
	UE_LOG(LogTemp, Warning, TEXT("It is glass"));
	StaticMesh->SetMaterial(0, OffMaterial);
	return;
	}
	UE_LOG(LogTemp, Warning, TEXT("Failed to find static mesh component of this actor."));
}

// Called every frame
void ACPP_ColouredWallv2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}