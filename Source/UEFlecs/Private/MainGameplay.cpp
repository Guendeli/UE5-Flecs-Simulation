// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameplay.h"
#include "flecs.h"

void AMainGameplay::Bootstrap(flecs::world& ecs)
{
    for(auto moduleType : FlecsModules)
    {
        auto module = NewObject<UFlecsModuleBase>(this, moduleType);
        module->Initialize(ecs);
    }
}
