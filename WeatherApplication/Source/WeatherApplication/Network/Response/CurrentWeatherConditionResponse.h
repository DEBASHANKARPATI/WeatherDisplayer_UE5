// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include <GameFrameWork/Actor.h>
#include "CurrentWeatherConditionResponse.generated.h"
/**
 * Response object to store response from current weather condition API 
 */
UCLASS()
class WEATHERAPPLICATION_API ACurrentWeatherConditionResponse:public AActor
{
	GENERATED_BODY()
public:
	ACurrentWeatherConditionResponse();
	~ACurrentWeatherConditionResponse();

	void SetValues(FString InWeatherText , int16 WeatherIcon , bool IsDayTime , float Temperature , FString InClockTime );

private:
	UPROPERTY()
	FString WeatherText;
	UPROPERTY()
	int16 WeatherIcon;
	UPROPERTY()
	bool IsDayTime;
	UPROPERTY()
	float Temperature;
	UPROPERTY()
	FString CurrentTime;
};
