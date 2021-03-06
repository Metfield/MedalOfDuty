// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"

/**
* Holds a set of points in the scene to guide patrol AI
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MEDALOFDUTY_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor *> PatrolPoints;

public: 
	const TArray<AActor *> &GetPatrolPoints();
};
