// Fill out your copyright notice in the Description page of Project Settings.


#include "CurrentWeatherConditionResponse.h"

ACurrentWeatherConditionResponse::ACurrentWeatherConditionResponse()
{
}

ACurrentWeatherConditionResponse::~ACurrentWeatherConditionResponse()
{
}

void ACurrentWeatherConditionResponse::SetValues(FString InWeatherText, int16 InWeatherIcon, bool InIsDayTime, float InTemperature , FString InClockTime)
{
	WeatherText = InWeatherText;
	WeatherIcon = InWeatherIcon;
	IsDayTime = InIsDayTime;
	Temperature = InTemperature;
	CurrentTime =InClockTime;
}
