// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;
class UTankTurret;
class AProjectile;
class UTankMovementComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
    
private:
    
    UPROPERTY(EditDefaultsOnly, Category="Setup")
    TSubclassOf<AProjectile> ProjectileBlueprint;
    
    UPROPERTY(EditDefaultsOnly, Category="Firing")
    float LaunchSpeed = 4000;
    
    UPROPERTY(EditDefaultsOnly, Category="Firing")
    float ReloadTimeInSeconds = 3;
    
    double LastFireTime = 0;

protected:
    UPROPERTY(BlueprintReadOnly, Category="Movement")
    UTankAimingComponent* TankAimingComponent = nullptr;
    UPROPERTY(BlueprintReadOnly, Category="Movement")
    UTankMovementComponent* TankMovementComponent = nullptr;
    virtual void BeginPlay() override;

public:
    
    UFUNCTION(BlueprintCallable, Category="Setup")
    void Initialise(UTankAimingComponent* TankAimingComponentToSet, UTankMovementComponent* TankMovementComponentToSet);
    
    void AimAt(FVector HitLocation);
    
    UFUNCTION(BlueprintCallable, Category = Firing)
    void Fire();
	
	
};
