// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

private:
    ATank* GetControlledTank() const;
    
    //start the tank barrel moving so that a it hits the item in the cross hair when fired
    void AimTowardsCrosshair();
    
public:
    void BeginPlay() override;
    // Called every frame
    virtual void Tick(float DeltaTime) override;
	
};
