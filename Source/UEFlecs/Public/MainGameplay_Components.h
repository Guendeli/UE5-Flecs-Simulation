// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "flecs.h"
#include "CoreMinimal.h"
#include "FlecsModuleBase.h"
#include "MainGameplay_Components.generated.h"


struct Transform
{
	FTransform Value;
};


/**
 *   FLECS auto registration doesnt work un UE, so you have to register them manually
 */

UCLASS()
class UEFLECS_API UMainGameplay_Components : public UFlecsModuleBase
{
	GENERATED_BODY()

	virtual void Initialize(flecs::world& ecs) override;
	
};
