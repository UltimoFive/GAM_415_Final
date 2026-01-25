// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GAM_415_FinalProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UNiagaraSystem;

UCLASS(config=Game)
class AGAM_415_FinalProjectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

	// Reference to Static Mesh, called ballMesh
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* ballMesh;

	// Material for baseMat
	UPROPERTY(EditAnywhere)
		UMaterial* baseMat;

	// Setting up Color
	UPROPERTY()
		FLinearColor randColor;

	// Setting Projectile Material
	UPROPERTY(EditAnywhere)
		UMaterialInterface* projMat;

	// Setting dmi Mat
	UPROPERTY()
		UMaterialInstanceDynamic* dmiMat;

	// Setting the Property for the Niagara System
	UPROPERTY(EditANywhere)
		UNiagaraSystem* colorP;

public:
	AGAM_415_FinalProjectile();

protected:
	virtual void BeginPlay();

public:
	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};

