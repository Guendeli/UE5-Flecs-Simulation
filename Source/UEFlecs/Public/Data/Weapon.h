// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Weapon.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Cannon = 0, // Winmatar
	Beam = 1,	// Amarr
};


UCLASS()
class UEFLECS_API UWeapon : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	UStaticMesh* Mesh = nullptr;
	UPROPERTY(EditAnywhere)
	UMaterialInterface* Material = nullptr;
	UPROPERTY(EditAnywhere)
	EWeaponType WeaponType;
	UPROPERTY(EditAnywhere)
	float Cooldown;
	UPROPERTY(EditAnywhere, Category=Projectile)
	float Lifetime;
	UPROPERTY(EditAnywhere, Category=Projectile)
	float Speed;
	UPROPERTY(EditAnywhere, Category=Projectile)
	float ProjectileScale;
	//Some value that needs to calculate the beam scale correctly
	UPROPERTY(EditAnywhere, Category=Projectile)
	float BeamMeshLength;
	
};
