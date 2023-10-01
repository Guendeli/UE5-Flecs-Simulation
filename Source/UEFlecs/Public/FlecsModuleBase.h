// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "flecs.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FlecsModuleBase.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class UEFLECS_API UFlecsModuleBase : public UObject
{
	GENERATED_BODY()
	
	public:
		virtual void Initialize(flecs::world& ecs);
};
