// Fill out your copyright notice in the Description page of Project Settings.


#include "SkySphere.h"

// Sets default values
ASkySphere::ASkySphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASkySphere::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASkySphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASkySphere::RefreshSkyMaterial_Implementation()
{
	// Has to be overwritten by skysphere Blueprint
}

void ASkySphere::UpdateSunAngle_Implementation(float InSunAngle)
{
	// Has to be overwritten by skysphere Blueprint 
}