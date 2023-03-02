// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeatherManager.generated.h"
class AWeatherConditions;
UENUM()
enum EWeatherComponents
{
	EThunder,
	ERain,
	ESnow,
	ECloud
};
UCLASS()
class WEATHERAPPLICATION_API AWeatherManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeatherManager();
	AWeatherConditions* GetWeatherComponent(EWeatherComponents WeatherComponentIndex) const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TMap<TEnumAsByte<EWeatherComponents>,TSubclassOf<AWeatherConditions>> WeatherComponentsAssets;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	TMap<TEnumAsByte<EWeatherComponents>, AWeatherConditions*> WeatherComponentsCache;
};
