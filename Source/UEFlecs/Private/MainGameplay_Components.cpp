// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameplay_Components.h"
#include "flecs.h"

void UMainGameplay_Components::Initialize(flecs::world& ecs)
{
    // REGISTER COMPONENTS HERE
    ecs.component<Transform>();
}