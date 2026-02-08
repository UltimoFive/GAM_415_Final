// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Components/BoxComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Components/ArrowComponent.h"
#include "Portal.generated.h"


class GAM_415_FinalCharacter;

UCLASS()
class GAM_415_FINAL_API APortal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APortal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Setting Mesh
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh;

	// Setting Scene Capture
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneCaptureComponent2D* sceneCapture;

	// Setting Arrow Component
	UPROPERTY(EditAnywhere)
	UArrowComponent* rootArrow;

	// Setting Public Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTextureRenderTarget2D* renderTarget;

	// Setting Box Component
	UPROPERTY(EditAnywhere)
		UBoxComponent* boxComp;

	// Allows Connection to other portals
	UPROPERTY(EditAnywhere)
		APortal* OtherPortal;

	// Setting Material
	UPROPERTY(EditAnywhere)
		UMaterialInterface* mat;

	// When Player overlaps with the Portal it will call the Teleport
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	// Setting Boolean
	UFUNCTION()
		void SetBool(AGAM_415_FinalCharacter* playerChar);

	// Update Portal Function
	UFUNCTION()
		void UpdatePortals();
};
