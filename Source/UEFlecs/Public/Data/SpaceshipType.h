// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "Engine/DataAsset.h"
#include "SpaceshipType.generated.h"

/**
 * 
 */
UCLASS()
class UEFLECS_API USpaceshipType : public UDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere)
   UStaticMesh* Mesh = nullptr;
   UPROPERTY(EditAnywhere)
   UMaterial* Material = nullptr;
   UPROPERTY(EditAnywhere)
   UWeapon* Weapons = nullptr;
   UPROPERTY(EditAnywhere)
   float MaxSpeed;
};
