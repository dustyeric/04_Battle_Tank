// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("begin play called for tank AI controller"));
    
    ATank* playerTank = GetPlayerTank();
    if(playerTank){
        UE_LOG(LogTemp, Warning, TEXT("tank AI found the tank  : %s"), *(playerTank->GetName()));
    }else{
        UE_LOG(LogTemp, Warning, TEXT("unable to find player tank"));
    }
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
    
}

ATank* ATankAIController::GetPlayerTank() const
{
    APawn* playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if(playerPawn){
        return Cast<ATank>(playerPawn);
    }else{
        UE_LOG(LogTemp, Warning, TEXT("can not find the first player controller"));
    }
    
    return nullptr;
}
