// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "flecs.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FlecsBootstrap.generated.h"

UCLASS()
class UEFLECS_API AFlecsBootstrap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlecsBootstrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Bootstrap(flecs::world& ecs);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
