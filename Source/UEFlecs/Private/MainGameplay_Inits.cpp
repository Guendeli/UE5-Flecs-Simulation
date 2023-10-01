// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameplay_Inits.h"
#include "MainGameplay_Components.h"
#include "flecs.h"
#include "Math/Vector.h"

uint32 CreateISMController(UWorld* InWorld, UStaticMesh* InMesh, UMaterialInterface* InMaterial, ISM_Map& InMap)
{
    auto hash = HashCombine(GetTypeHash(InMaterial), GetTypeHash(InMesh));
    auto find = InMap.ISMS.Find(hash);
    if(find == nullptr){
        FVector location = FVector::ZeroVector;
        FRotator rotation = FRotator::ZeroRotator;
        FActorSpawnParameters SpawnInfo;

        auto controller = Cast<AISMControler>(InWorld->SpawnActor(AISMControler::StaticClass(), &location, &rotation, SpawnInfo));

        controller->Initialize(InMesh, InMaterial);

        InMap.ISMS.Add(hash, controller);
    }

    return hash;
}

void UMainGameplay_Inits::Initialize(flecs::world& ecs)
{
    //Create an entity with a transform component

}