// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAM_415_FinalPickUpComponent.h"

UGAM_415_FinalPickUpComponent::UGAM_415_FinalPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UGAM_415_FinalPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UGAM_415_FinalPickUpComponent::OnSphereBeginOverlap);
}

void UGAM_415_FinalPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AGAM_415_FinalCharacter* Character = Cast<AGAM_415_FinalCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
