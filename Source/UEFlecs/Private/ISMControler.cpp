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

	InstancedStaticMeshComponent->NumCustomDataFloats = 1;

}

int32 AISMControler::AddInstance(FVector location)
{
	int32 instanceIndex;
	if(indexPool.IsEmpty())
	{
		FTransform transform{location};
		instanceIndex = InstancedStaticMeshComponent->AddInstance(transform);
	}
	else
	{
		indexPool.Dequeue(instanceIndex);
		InstancedStaticMeshComponent->SetCustomDataValue(instanceIndex, 0, 0);
	}
	return instanceIndex;
}

int32 AISMControler::GetInstanceCount() const
{
	return InstancedStaticMeshComponent->GetInstanceCount();
}

void AISMControler::CreateOrExpandTransformArray()
{
	if(GetInstanceCount() != transforms.Num())
	{
		transforms.AddUninitialized(GetInstanceCount() - transforms.Num());
		for (auto i = 0; i < transforms.Num(); i++)
		{
			transforms[i] = FTransform{FVector::ZeroVector};
		}
	}
}

int32 AISMControler::AddInstance()
{
	return AddInstance(FVector::ZeroVector);
}

void AISMControler::RemoveInstance(int32 instanceIndex)
{
	//Add the index of a removed instanced to the pool
	indexPool.Enqueue(instanceIndex);
	
	//Pass the instance's index, custom data index, and custom data value
	//Value == 0 - an instance is shown (default value)
	//Value == 1 - an instance is hidden
	InstancedStaticMeshComponent->SetCustomDataValue(instanceIndex, 0, 1);
}

void AISMControler::SetTransform(int32 instanceIndex, const FTransform& transform)
{
	transforms[instanceIndex] = transform;
}

void AISMControler::BatchUpdateTransform() const
{
	if(transforms.Num() > 0)
	{
		InstancedStaticMeshComponent->BatchUpdateInstancesTransforms(0, transforms, true, true);
	}
}