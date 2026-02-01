// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PerlinProcTerrain.generated.h"

class UProceduralMeshComponent;
class UMaterialInterface;

UCLASS()
class GAM_415_FINAL_API APerlinProcTerrain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APerlinProcTerrain();

	// Variables that allows us to change the size of landscape
	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))
		int XSize = 0;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))
		int YSize = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ClampMin = 0))
		float ZMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))
		float NoiseScale = 1.0f;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0.000001))
		float Scale = 0;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0.000001))
		float UVScale = 0;

	UPROPERTY(EditAnywhere)
		float radius;

	UPROPERTY(Editanywhere)
		FVector Depth;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Material to apply
	UPROPERTY(EditAnywhere)
		UMaterialInstance* Mat;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Alter the Mesh when called
	UFUNCTION()
		void AlterMesh(FVector impactPoint);

private:
	UProceduralMeshComponent* ProcMesh;
	TArray<FVector> Vertices;
	TArray<int> Triangles;
	TArray<FVector2D> UV0;
	TArray<FVector> Normals;
	TArray<FColor> UpVertexColors;

	int sectionID = 0;

	void CreateVertices();
	void CreateTriangles();

};
