// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
class ATank;
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
    UFUNCTION(BlueprintCallable, Category="Setup")
    ATank* GetControlledTank() const;
    
private:
    
    UPROPERTY(EditDefaultsOnly)
    float CrossHairXLocation = 0.5;
    UPROPERTY(EditDefaultsOnly)
    float CrossHairYLocation = 0.33333;
    UPROPERTY(EditDefaultsOnly)
    float LineTraceRange = 1000000.0;
    
    bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
    
    bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
   
    //return an out parameter and return bool when hit
    bool GetSightRayHitLocation(FVector& OutHitLocation) const;
    
    //start the tank barrel moving so that a it hits the item in the cross hair when fired
    void AimTowardsCrosshair();
    
public:
    void BeginPlay() override;
    // Called every frame
    virtual void Tick(float DeltaTime) override;
	
};
