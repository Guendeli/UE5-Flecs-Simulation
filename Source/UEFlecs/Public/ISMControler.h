// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "ISMControler.generated.h"

UCLASS()
class UEFLECS_API AISMControler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AISMControler();

	UPROPERTY(EditAnywhere, Category=ISM)
	UInstancedStaticMeshComponent* InstancedStaticMeshComponent = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Initialize(UStaticMesh* InMesh, UMaterialInterface* InMaterial) const;


private:
	TArray<FTransform> transforms;
};
