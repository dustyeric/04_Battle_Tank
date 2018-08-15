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

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
    
}
