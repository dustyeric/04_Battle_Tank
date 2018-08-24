// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
    auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
    auto AIForwardIntention = MoveVelocity.GetSafeNormal();
    
    //dot product is a cosine function
    float ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
    IntendMoveForward(ForwardThrow);
    
    FVector CrossProduct = FVector::CrossProduct(TankForward, AIForwardIntention);
    IntentTurnRight(CrossProduct.Z);
}

void UTankMovementComponent::IntentTurnRight(float Throw)
{
    if(!LeftTrack || !RightTrack){return;}
    LeftTrack->SetThrottle(-Throw);
    RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
    if(!LeftTrack || !RightTrack){return;}
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
}
