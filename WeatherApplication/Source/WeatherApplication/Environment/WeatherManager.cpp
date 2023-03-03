// Fill out your copyright notice in the Description page of Project Settings.
#include "WeatherManager.h"
#include <WeatherApplication/Environment/WeatherConditions.h>
#include <WeatherApplication/Network/NetworkManager/NetworkManager.h>
#include <Kismet/GameplayStatics.h>
#include <WeatherApplication/Environment/SkySphere.h>
#include <WeatherApplication/Core/GameInstance/WeatherApplicationGameInstance.h>
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

void AWeatherManager::OnCurrentWeatherConditionParsedSuccessfully(ACurrentWeatherConditionResponse* WeatherResponseObject)
{
	if (WeatherResponseObject)
	{ 
		UE_LOG(LogTemp, Warning, TEXT("%s"), *WeatherResponseObject->GetActorNameOrLabel());
		// calulate the sun pitch with time from response obejct 
		// refresh the skysphere
		// access the datatable using the weather icon id then activate and deactivate the weathercomponents in weathercomponentscache 
	}
}

// Called when the game starts or when spawned
void AWeatherManager::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> SkySphereArray;
	if (auto World = GetWorld())
	{
		UGameplayStatics::GetAllActorsOfClass(World, ASkySphere::StaticClass(), SkySphereArray);
		if (SkySphereArray.Num())
		{
			SkySphere = Cast<ASkySphere>(SkySphereArray[0]);
		}
		if (WeatherComponentsAssets.Num() > 0)
		{
			WeatherComponentsCache.Add(EWeatherComponents::ECloud, World->SpawnActor<AWeatherConditions>(WeatherComponentsAssets[EWeatherComponents::ECloud], FVector(0, 0, 900), FRotator::ZeroRotator));
			WeatherComponentsCache.Add(EWeatherComponents::ERain, World->SpawnActor<AWeatherConditions>(WeatherComponentsAssets[EWeatherComponents::ERain], FVector(0, 0, 900), FRotator::ZeroRotator));
			WeatherComponentsCache.Add(EWeatherComponents::EThunder, World->SpawnActor<AWeatherConditions>(WeatherComponentsAssets[EWeatherComponents::EThunder], FVector(0, 0, 900), FRotator::ZeroRotator));
			WeatherComponentsCache.Add(EWeatherComponents::ESnow, World->SpawnActor<AWeatherConditions>(WeatherComponentsAssets[EWeatherComponents::ESnow], FVector(0, 0, 900), FRotator::ZeroRotator));
			
		}
		if (auto GameInstance = Cast<UWeatherApplicationGameInstance>(World->GetGameInstance()))
		{
			GameInstance->GetNetworkManager()->OnCurrentWeatherConditionResponseDelegate.AddUObject(this, &AWeatherManager::OnCurrentWeatherConditionParsedSuccessfully);
		}
	}
}

// Called every frame
void AWeatherManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}