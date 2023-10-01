// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "flecs.h"
#include "CoreMinimal.h"
#include "FlecsModuleBase.h"
#include "ISMControler.h"
#include "MainGameplay_Components.generated.h"



struct Transform 
{
	FTransform Transform;
};

struct ISM_Map
{
	TMap<uint32, AISMControler*> ISMS;
};

struct ISM_ControllerRef
{
	AISMControler* Value;
};

struct ISM_Hash
{
	int32 Value;
};

struct ISM_Index
{
	int Value;
};

struct ISM_AddInstance
{
	int32 Hash;
	flecs::entity Prefab;
	FTransform Transform;
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
