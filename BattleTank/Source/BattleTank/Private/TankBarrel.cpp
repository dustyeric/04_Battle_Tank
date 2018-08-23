// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
    auto Time = GetWorld()->GetTimeSeconds();
    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
    //given a max elevation speed and the frame time
    auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto RawNewElevation = ElevationChange + RelativeRotation.Pitch;
    
    auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);
    
    SetRelativeRotation(FRotator(Elevation, 0, 0));
}
