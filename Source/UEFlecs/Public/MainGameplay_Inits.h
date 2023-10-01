// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "flecs.h"
#include "CoreMinimal.h"
#include "FlecsModuleBase.h"
#include "MainGameplay_Inits.generated.h"

/**
 * 
 */
UCLASS()
class UEFLECS_API UMainGameplay_Inits : public UFlecsModuleBase
{
	GENERATED_BODY()
	
	virtual void Initialize(flecs::world& ecs) override;
};
