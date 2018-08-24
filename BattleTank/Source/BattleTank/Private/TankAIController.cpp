// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "../Tank.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    //Aim Towards Player
    auto ControlledTank = Cast<ATank>(GetPawn());
    auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    
    if(PlayerTank){
        
        //TODO Check radius is in cm
        MoveToActor(PlayerTank, AcceptanceRadius);
        
        ControlledTank->AimAt(PlayerTank->GetActorLocation());
       // ControlledTank->Fire(); //Limit firing rate
    }
    
    
    
}


