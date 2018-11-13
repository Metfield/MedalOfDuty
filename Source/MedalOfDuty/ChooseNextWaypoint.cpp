// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"

#include "AIController.h"
#include "PatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* aiController = OwnerComp.GetAIOwner();
	APawn* controlledPawn = aiController->GetPawn();

	// Get patrol route
	UPatrolRoute* patrolRoute = controlledPawn->FindComponentByClass<UPatrolRoute>();
	if (!ensure(patrolRoute))
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot find PatrolRoute component in actor %s"), *controlledPawn->GetName());
		return EBTNodeResult::Failed;
	}

	// Get patrol points
	TArray<AActor *> patrolPoints = patrolRoute->GetPatrolPoints();
	if (patrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("PatrolPoints are empty in actor %s"), *controlledPawn->GetName());
		return EBTNodeResult::Failed;
	}

	// Set next waypoint
	UBlackboardComponent* blackboardComponent = OwnerComp.GetBlackboardComponent();
	int index = blackboardComponent->GetValueAsInt(IndexKey.SelectedKeyName);
	blackboardComponent->SetValueAsObject(WaypointKey.SelectedKeyName, patrolPoints[index]);

	index = (index + 1) % patrolPoints.Num();
	blackboardComponent->SetValueAsInt(IndexKey.SelectedKeyName, index);

	return EBTNodeResult::Succeeded;
}