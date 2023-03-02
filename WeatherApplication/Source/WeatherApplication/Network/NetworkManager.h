// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Http.h>
#include <HttpModule.h>
#include <HTTP/Public/Interfaces/IHttpRequest.h>
#include <HTTP/Public/Interfaces/IHttpResponse.h>
#include "NetworkManager.generated.h"


UCLASS()
class WEATHERAPPLICATION_API ANetworkManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANetworkManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	void OnGetCityKeyRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);

};
