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
    
    //get world location if linetrace through cross hair
        //if it hits the landscape
            //tell the controlled tank to aim at this point
}


ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
    
}
