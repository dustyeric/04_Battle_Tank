// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Public/TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
    
private:
    UPROPERTY(EditAnywhere, Category = Firing)
    float LaunchSpeed = 100000; //TODO Find Sensible Default

protected:
    UTankAimingComponent* TankAimingComponent = nullptr;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
    void AimAt(FVector HitLocation);
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetBarrelReference(UTankBarrel* BarrelToSet);

	
	
};
