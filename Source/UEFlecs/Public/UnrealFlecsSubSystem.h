// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "flecs.h"
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UnrealFlecsSubSystem.generated.h"

/**
 * 
 */
UCLASS()
class UEFLECS_API UUnrealFlecsSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	public:
		virtual void Initialize(FSubsystemCollectionBase& Collection) override;
		virtual void Deinitialize() override;

		flecs::world* GetEcsWorld() const;

	protected:
		FTickerDelegate OnTickDelegate;
		FTSTicker::FDelegateHandle OnTickHandle;
		flecs::world* ECSWorld = nullptr;

	private:
		bool OnTick(float DeltaTime);
};
