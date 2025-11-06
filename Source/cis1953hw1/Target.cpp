// Fill out your copyright notice in the Description page of Project Settings.


#include "Target.h"

// Sets default values
ATarget::ATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	
    StartPosition = GetActorLocation();

    UStaticMeshComponent* CubeMesh = FindComponentByClass<UStaticMeshComponent>();
    CubeMesh->SetNotifyRigidBodyCollision(true);
    CubeMesh->SetGenerateOverlapEvents(true);
    CubeMesh->OnComponentHit.AddDynamic(this, &ATarget::OnHit);
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    ActiveTime += DeltaTime;

    float HoverPosition = FMath::Sin(ActiveTime * HoverSpeed) * HoverAmount;
    FVector Position = StartPosition;
    Position.Z += HoverPosition;
    SetActorLocation(Position);

    FRotator Rotation = GetActorRotation();
    Rotation.Yaw += RotateSpeed * DeltaTime;
    SetActorRotation(Rotation);

}

void ATarget::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    Destroy();
}


