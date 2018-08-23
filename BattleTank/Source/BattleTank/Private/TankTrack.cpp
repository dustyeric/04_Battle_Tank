// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"




void UTankTrack::SetThrottle(float Throttle)
{
    
    auto Name = GetName();
    UE_LOG(LogTemp, Warning, TEXT("%s Throttles at %f"), *Name,Throttle);
    //TODO : Clamp actual throttle value so player can not over drive here
}
