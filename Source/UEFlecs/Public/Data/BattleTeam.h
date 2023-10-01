// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpaceshipType.h"
#include "UObject/Object.h"
#include "Engine/DataAsset.h"
#include "BattleTeam.generated.h"

/**
 * 
 */
UCLASS()
class UEFLECS_API UBattleTeam : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	USpaceshipType* SpaceshipType = nullptr;
	UPROPERTY(EditAnywhere)
	int32 NumShips;
};
