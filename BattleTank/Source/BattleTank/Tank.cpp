// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "Public/Projectile.h"
#include "Public/TankAimingComponent.h"
#include "Public/TankMovementComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    UE_LOG(LogTemp, Warning, TEXT("C++ tank constructor"));
}

void ATank::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("C++ begin play from c++"));
}


void ATank::Initialise(UTankAimingComponent* TankAimingComponentToSet, UTankMovementComponent* TankMovementComponentToSet)
{
    TankAimingComponent = TankAimingComponentToSet;
    TankMovementComponent = TankMovementComponentToSet;
}


void ATank::Fire()
{
    bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
    
    if(TankAimingComponent && isReloaded)
    {
        //spawn a projectile at the location of the barrel socket
        UWorld* World = GetWorld();
        auto Projectile = World->SpawnActor<AProjectile>(ProjectileBlueprint,
                                                         TankAimingComponent->GetBarrelSocketLocation(), TankAimingComponent->GetBarrelSocketRotation());
        if(Projectile){
            Projectile->LaunchProjectile(LaunchSpeed);
            LastFireTime = FPlatformTime::Seconds();
        }
        
    }
   
}


void ATank::AimAt(FVector HitLocation)
{
    if(!TankAimingComponent){return;}
    TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}




