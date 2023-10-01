// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BattleTeam.h"
#include "Engine/DataAsset.h"
#include "GameplayConfig.generated.h"

/**
 * 
 */
UCLASS()
class UEFLECS_API UGameplayConfig : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<UBattleTeam*> Teams;
	UPROPERTY(EditAnywhere)
	FVector2D SpawnRange;
	UPROPERTY(EditAnywhere)
	float ShootingCellSize;
	
	UPROPERTY(EditAnywhere, Category=BoidSettings)
	float SeparationWeight;
	UPROPERTY(EditAnywhere, Category=BoidSettings)
	float CohesionWeight;
	UPROPERTY(EditAnywhere, Category=BoidSettings)
	float AlignmentWeight;
	UPROPERTY(EditAnywhere, Category=BoidSettings)
	float CageAvoidWeight;
	UPROPERTY(EditAnywhere, Category=BoidSettings)
	float CellSize;
	UPROPERTY(EditAnywhere, Category=BoidSettings)
	float CageSize;
	UPROPERTY(EditAnywhere, Category=BoidSettings)
	float CageAvoidDistance;	
};
