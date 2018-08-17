// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("begin play called for tank controller"));
    
    ATank* ControlledTank = GetControlledTank();
    if(ControlledTank){
        UE_LOG(LogTemp, Warning, TEXT("player controller possessing : %s"), *(ControlledTank->GetName()));
    }else{
         UE_LOG(LogTemp, Warning, TEXT("player controller no tank possessed"));
    }
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    //Aim Towards Cross hair
    AimTowardsCrosshair();
    
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if(!GetControlledTank()) {return;}
    
    FVector HitLocation; //OUT Parameter
    if(GetSightRayHitLocation(HitLocation)){
        //tell the controlled tank to aim at this point
        GetControlledTank()->AimAt(HitLocation);
    }
    
    
}
//get world location if linetrace through cross hair, return true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
    //find the cross hair screen location
    int32 ViewPortSizeY, ViewPortSizeX;
    GetViewportSize(ViewPortSizeX, ViewPortSizeY);
    FVector2D ScreenLocation = FVector2D(ViewPortSizeY*CrossHairXLocation, ViewPortSizeY*CrossHairYLocation);
        //De-project the screen location to world coordinates
    FVector LookDirection;
    
    if(GetLookDirection(ScreenLocation, LookDirection))
    {
        FHitResult OutHitResult;
        //line trace and see what we hit up to a max range
        if(GetLookVectorHitLocation(LookDirection, OutHitLocation)){
            return true;
        }
        
    }
    return false;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
    
    auto StartLocation = PlayerCameraManager->GetCameraLocation();
    FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);
    
    FHitResult OutHitResult;
    if(GetWorld()->LineTraceSingleByChannel(OutHitResult,
                                            StartLocation,
                                            EndLocation,
                                            ECollisionChannel::ECC_Visibility))
    {
        OutHitLocation = OutHitResult.Location;
        return true;
    }
    
    OutHitLocation = FVector(0.0);
    
    return false;
    
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
    FVector WorldLocation;
    
    return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
}


ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
    
}
