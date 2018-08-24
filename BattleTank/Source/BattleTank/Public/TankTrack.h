// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank Track is used to set the maximum  driving force and to add forces to the tank
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
    UFUNCTION(BlueprintCallable, Category = "Input")
    void SetThrottle(float Throttle);
    
    //max driving force per track
	UPROPERTY(EditDefaultsOnly)
    float TrackMaxDrivingForce = 40000000; //assuming tank of 40 tons and 1g acceleration
};
