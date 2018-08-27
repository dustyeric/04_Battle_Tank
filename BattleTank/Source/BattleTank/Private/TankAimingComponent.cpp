// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
void UTankAimingComponent::Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
    Barrel = BarrelToSet;
    Turret = TurretToSet;
}

FVector UTankAimingComponent::GetBarrelSocketLocation()
{
    if(!Barrel){
        return FVector(0);
    }
    return Barrel->GetSocketLocation(FName("Projectile"));
}

FRotator UTankAimingComponent::GetBarrelSocketRotation()
{
    if(!Barrel){
        return FRotator(0);
    }
    return Barrel->GetSocketRotation(FName("Projectile"));
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
    
    if(!Barrel){ return;}
    
    FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
    FVector OutTossVelocity;
    FCollisionResponseParams ResponseParam;
    bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this,
                                                                        OutTossVelocity,
                                                                        StartLocation,
                                                                        HitLocation,
                                                                        LaunchSpeed,
                                                                        false,
                                                                        0,
                                                                        0,
                                                                 ESuggestProjVelocityTraceOption::DoNotTrace);//parameter must be here to prevent bug
    if(bHaveAimSolution)
    {
        auto AimDirection = OutTossVelocity.GetSafeNormal();
        auto TankName = GetOwner()->GetName();
        MoveBarrelTowards(AimDirection);
        
    }
   
}


void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
    
    if(!Barrel || !Turret){return;}
    //work out the difference between the current position and the aim direction
    auto BarrelRotator = Barrel->GetForwardVector().Rotation();
    auto AimAsRotator = AimDirection.Rotation();
    auto DeltaRotator = AimAsRotator - BarrelRotator;
    
    auto TurretRotator = Turret->GetForwardVector().Rotation();
    auto TurretDeltaRotator = AimAsRotator - TurretRotator;
    
    //move the barrel right amount this frame
    Barrel->Elevate(DeltaRotator.Pitch);
    Turret->Rotate(TurretDeltaRotator.Yaw);
  
}






