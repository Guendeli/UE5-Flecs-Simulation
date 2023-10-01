// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "flecs.h"
#include "FlecsModuleBase.h"
#include "CoreMinimal.h"
#include "FlecsBootstrap.h"
#include "MainGameplay.generated.h"

/**
 * 
 */
UCLASS()
class UEFLECS_API AMainGameplay : public AFlecsBootstrap
{
	GENERATED_BODY()

	public:

		UPROPERTY(EditAnywhere)
		TArray<TSubclassOf<UFlecsModuleBase>> FlecsModules; // Similar to Entitas Contexts

	protected:
		virtual void Bootstrap(flecs::world& ecs) override;
};
