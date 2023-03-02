// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "WeatherApplicationGameInstance.generated.h"
class AWeatherManager;
/**
 *  Global instance to store global states and classes for Weather application
 */
UCLASS()
class WEATHERAPPLICATION_API UWeatherApplicationGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	AWeatherManager* GetWeatherManager() const;

protected:
	virtual void Init() override;
    
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AWeatherManager> WeatherManagerAsset;

private:
	UPROPERTY(VisibleAnywhere)
	AWeatherManager* WeatherManager;

};
