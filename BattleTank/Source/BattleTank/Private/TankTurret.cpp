// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed)
{
    auto Time = GetWorld()->GetTimeSeconds();
    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
    //given a max elevation speed and the frame time
    auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto RawNewYaw = RotationChange + RelativeRotation.Yaw;
    
    SetRelativeRotation(FRotator(0, RawNewYaw, 0));
}
