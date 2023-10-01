// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealFlecsSubSystem.h"

void UUnrealFlecsSubSystem::Initialize(FSubsystemCollectionBase& Collection)
{
    OnTickDelegate = FTickerDelegate::CreateUObject(this, &UUnrealFlecsSubSystem::OnTick);
	OnTickHandle = FTSTicker::GetCoreTicker().AddTicker(OnTickDelegate);

    //Create the Flecs world immediately after initialization of Game Instance
	ECSWorld = new flecs::world();
	
	UE_LOG(LogTemp, Warning, TEXT("UUnrealFlecsSubsystem has started!"));
	
	Super::Initialize(Collection);
}

void UUnrealFlecsSubSystem::Deinitialize()
{
    FTSTicker::GetCoreTicker().RemoveTicker(OnTickHandle);
    //Destroying the Flecs world as part of the deinitialization of Game Instance
	if(!ECSWorld) delete(ECSWorld);
    UE_LOG(LogTemp, Warning, TEXT("UUnrealFlecsSubsystem has shut down!"));
	
	Super::Deinitialize();
}

flecs::world* UUnrealFlecsSubSystem::GetEcsWorld() const
{
	return ECSWorld;
}

bool UUnrealFlecsSubSystem::OnTick(float DeltaTime)
{
	// Every Tick we progress Flcs system 
	// and pass the value of Delta Time to the Flecs World
	if(ECSWorld) ECSWorld->progress(DeltaTime);
	return true;
}