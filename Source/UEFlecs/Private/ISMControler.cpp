// Fill out your copyright notice in the Description page of Project Settings.


#include "ISMControler.h"
#include "Components/InstancedStaticMeshComponent.h"

// Sets default values
AISMControler::AISMControler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	InstancedStaticMeshComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("ISM"));

	RootComponent = InstancedStaticMeshComponent;
}

// Called when the game starts or when spawned
void AISMControler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AISMControler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AISMControler::Initialize(UStaticMesh* InMesh, UMaterialInterface* InMaterial) const
{
	InstancedStaticMeshComponent->SetStaticMesh(InMesh);
	InstancedStaticMeshComponent->SetMaterial(0, InMaterial);
}


