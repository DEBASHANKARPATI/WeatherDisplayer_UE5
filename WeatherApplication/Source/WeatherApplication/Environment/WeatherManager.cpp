// Fill out your copyright notice in the Description page of Project Settings.
#include "WeatherManager.h"
#include <WeatherApplication/Environment/WeatherConditions.h>
// Sets default values
AWeatherManager::AWeatherManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

AWeatherConditions* AWeatherManager::GetWeatherComponent(EWeatherComponents WeatherComponentIndex) const
{
	return WeatherComponentsCache[WeatherComponentIndex];
}

// Called when the game starts or when spawned
void AWeatherManager::BeginPlay()
{
	Super::BeginPlay();

	if (WeatherComponentsAssets.Num() > 0)
	{
		if (auto World = GetWorld())
		{
			WeatherComponentsCache.Add(EWeatherComponents::ECloud , World->SpawnActor<AWeatherConditions>(WeatherComponentsAssets[EWeatherComponents::ECloud], FVector(0, 0, 900), FRotator::ZeroRotator));
			WeatherComponentsCache.Add(EWeatherComponents::ERain, World->SpawnActor<AWeatherConditions>(WeatherComponentsAssets[EWeatherComponents::ERain], FVector(0, 0, 900), FRotator::ZeroRotator));
			WeatherComponentsCache.Add(EWeatherComponents::EThunder, World->SpawnActor<AWeatherConditions>(WeatherComponentsAssets[EWeatherComponents::EThunder], FVector(0, 0, 900), FRotator::ZeroRotator));
			WeatherComponentsCache.Add(EWeatherComponents::ESnow, World->SpawnActor<AWeatherConditions>(WeatherComponentsAssets[EWeatherComponents::ESnow], FVector(0, 0, 900), FRotator::ZeroRotator));
		}
	}
	
}

// Called every frame
void AWeatherManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}