// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


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
          UE_LOG(LogTemp, Warning, TEXT("the current location is %s") , *HitLocation.ToString());
        
        //tell the controlled tank to aim at this point
    }
    
    
}
//get world location if linetrace through cross hair, return true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
    OutHitLocation = FVector(1.0);
    return false;
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
    
}
