// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
class ATank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
    
private:
    //how close can the ai get to the ai
    UPROPERTY(EditDefaultsOnly)
    float AcceptanceRadius = 3000;

public:
    void BeginPlay() override;
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    
	
};
