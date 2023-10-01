// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "flecs.h"
#include "CoreMinimal.h"
#include "FlecsModuleBase.h"
#include "MainGameplay_Systems.generated.h"

/**
 * 
 */
UCLASS()
class UEFLECS_API UMainGameplay_Systems : public UFlecsModuleBase
{
	GENERATED_BODY()
	
	virtual void Initialize(flecs::world& ecs) override;

};
