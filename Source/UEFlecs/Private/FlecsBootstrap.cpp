// Fill out your copyright notice in the Description page of Project Settings.


#include "FlecsBootstrap.h"
#include "UnrealFlecsSubSystem.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFlecsBootstrap::AFlecsBootstrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFlecsBootstrap::BeginPlay()
{
	UGameInstance* gameInstance = UGameplayStatics::GetGameInstance(GetWorld());
	UUnrealFlecsSubSystem* subSystem = gameInstance->GetSubsystem<UUnrealFlecsSubSystem>();

	Bootstrap(*subSystem->GetEcsWorld());
	
	Super::BeginPlay();
}

// Called every frame
void AFlecsBootstrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFlecsBootstrap::Bootstrap(flecs::world& ecs)
{

}

