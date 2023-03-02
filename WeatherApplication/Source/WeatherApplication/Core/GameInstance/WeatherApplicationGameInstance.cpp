// Fill out your copyright notice in the Description page of Project Settings.


#include "WeatherApplicationGameInstance.h"
#include <WeatherApplication/Environment/WeatherManager.h>

AWeatherManager* UWeatherApplicationGameInstance::GetWeatherManager() const
{
	return WeatherManager;
}
void UWeatherApplicationGameInstance::Init()
{
	if (UWorld* World  = GetWorld())
	{ 
		WeatherManager = World->SpawnActor<AWeatherManager>(WeatherManagerAsset);
	}
}
