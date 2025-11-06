// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

    UStaticMeshComponent* CubeMesh = FindComponentByClass<UStaticMeshComponent>();
    CubeMesh->SetNotifyRigidBodyCollision(true);
    CubeMesh->SetGenerateOverlapEvents(true);
    CubeMesh->OnComponentHit.AddDynamic(this, &ADoor::OnHit);
}

void ADoor::ToggleDoor()
{
    bIsOpen = !bIsOpen;
    bIsOpening = bIsOpen;
    bIsClosing = !bIsOpen;
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FRotator NewRotation = GetActorRotation();

    if (bIsOpening && CurrentRotation < 90.f)
    {
        NewRotation.Yaw += RotateSpeed * DeltaTime;
        CurrentRotation += RotateSpeed * DeltaTime;

        if (CurrentRotation >= 90.f)
        {
            bIsOpening = false;
            bIsOpen = true;
        }

        SetActorRotation(NewRotation);
    }
    else if (bIsClosing && CurrentRotation > 0.f)
    {
        NewRotation.Yaw -= RotateSpeed * DeltaTime;
        CurrentRotation -= RotateSpeed * DeltaTime;

        if (CurrentRotation <= 0.f)
        {
            bIsClosing = false;
            bIsOpen = false;
        }

        SetActorRotation(NewRotation);
    }
}

void ADoor::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    //ToggleDoor();
}