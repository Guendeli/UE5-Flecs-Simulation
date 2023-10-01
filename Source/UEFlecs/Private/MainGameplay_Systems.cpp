// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameplay_Systems.h"
#include "MainGameplay_Components.h"

#include "flecs.h"

// void TestSystem(flecs::world& ecs)
// {
//     auto test_system = ecs.system<Transform>("Test System")
//         .iter([](flecs::iter it, Transform* trans){
//             for(int i : it){
//                 UE_LOG(
//                     LogTemp,
//                     Warning,
//                     TEXT("Entity %s with Position %s"),
//                     *FString::FormatAsNumber(it.entity(i).id()),
//                     *FString(trans[i].Value.ToString())
//                 );
//             }
//         }
//         );
// }


void UMainGameplay_Systems::Initialize(flecs::world& ecs)
{
    //TestSystem(ecs);
}