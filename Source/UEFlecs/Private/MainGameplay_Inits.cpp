// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameplay_Inits.h"
#include "MainGameplay_Components.h"
#include "flecs.h"

void UMainGameplay_Inits::Initialize(flecs::world& ecs)
{
    //Create an entity with a transform component
    ecs.entity().set<Transform>({
        FTransform{
            FVector(10,20,-20)
        }
    });
}