// Fill out your copyright notice in the Description page of Project Settings.

#include "PatrolRoute.h"

const TArray<AActor*> &UPatrolRoute::GetPatrolPoints()
{
	return PatrolPoints;
}