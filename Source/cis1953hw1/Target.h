// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Target.generated.h"

UCLASS()
class CIS1953HW1_API ATarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	FVector StartPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float HoverAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float HoverSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float RotateSpeed;

private:

	float ActiveTime;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
