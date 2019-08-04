// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "One_ColourGameMode.h"
#include "BaseEnemy.generated.h"

UCLASS()
class ONE_COLOUR_API ABaseEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseEnemy();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EColour Colour;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* Body;
	//reference to player
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ACharacter* playerRef;

	UPROPERTY(VisibleAnywhere)
		float KnockBack;

	UPROPERTY(VisibleAnywhere)
		bool inAttackRange;

	UPROPERTY(VisibleAnywhere)
		bool canAttack;

	UPROPERTY(VisibleAnywhere)
		bool isStunned;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool tryAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float startingHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float currentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isDead;

	UPROPERTY(EditAnywhere)
		UAnimSequence *Anim;

	FVector startPos;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay();
	void OnHit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime);

	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);
	
	UFUNCTION(BlueprintCallable)
		void TakeDamage(float dmg);

	UFUNCTION(BlueprintCallable)
		void KillEnemy();
	UFUNCTION(BlueprintCallable)
		void SetPlayerRef();
};
