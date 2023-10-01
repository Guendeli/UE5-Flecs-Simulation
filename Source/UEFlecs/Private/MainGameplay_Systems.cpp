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

void SystemAddInstace(flecs::world& ecs)
{
    auto spawn_instance_system = ecs.system<ISM_AddInstance, ISM_Map>("Spawn Instance System")
        .iter([](flecs::iter it, ISM_AddInstance* cAdd, ISM_Map* cMap)
        {
            auto world = it.world();
            for(int i : it){
		        auto controller = *(cMap->ISMS.Find(cAdd[i].Hash));
                if(controller != nullptr)
                {
                    auto instanceIndex = controller->AddInstance();
                    world.entity()
                    .is_a(cAdd[i].Prefab)
                    .set<ISM_ControllerRef>({controller})
                    .set<ISM_Index>({instanceIndex})
                    .set<ISM_Hash>({cAdd[i].Hash})
                    .set<Transform>({cAdd[i].Transform});
                }
                it.entity(i).destruct();
            }

            for(auto& data : cMap->ISMS){
                data.Value->CreateOrExpandTransformArray();
            }
        }  
        );
}

void SystemCopyInstanceTransform(flecs::world& ecs)
{
    auto system_copy_instance_transform = ecs.system<Transform, ISM_Index, ISM_ControllerRef>("Copy Instance Transform System")
    .iter([](flecs::iter it, Transform* cTransform, ISM_Index* cISMIndex, ISM_ControllerRef* cISMController)
    {
        for(auto i : it)
        {
            auto index = cISMIndex[i].Value;
            cISMController[i].Value->SetTransform(index, cTransform[i].Transform);
        }
    }
    );
}

void SystemBatchUpdateTransforms(flecs::world& ecs)
{
    auto system_batch_update = ecs.system<ISM_Map>("Batch Update System")
    .iter([](flecs::iter it, ISM_Map* cMap)
    {
        for(auto& data : cMap->ISMS)
        {
            data.Value->BatchUpdateTransform();
        }
    }
    );
}

void UMainGameplay_Systems::Initialize(flecs::world& ecs)
{
    //TestSystem(ecs);
    SystemAddInstace(ecs);

    SystemCopyInstanceTransform(ecs);

    SystemBatchUpdateTransforms(ecs);
}