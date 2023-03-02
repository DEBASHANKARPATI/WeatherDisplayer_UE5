// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkManager.h"
#include "Serialization/JsonSerializer.h"
// Sets default values
ANetworkManager::ANetworkManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANetworkManager::BeginPlay()
{
	Super::BeginPlay();
	if (auto Http = &FHttpModule::Get())
	{
		TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Http->CreateRequest();;
		//TODO : Replace the key and city name with it's own fields which can be configured (Mostly city ) by the player
		Request->SetURL("http://dataservice.accuweather.com/locations/v1/cities/search?apikey=JO7zMAvvprSOda7Gid91OGOhSNtOko3S&q=Bangalore");
		Request->SetVerb("GET");
		Request->SetHeader("Content-Type", "application/json");
		Request->OnProcessRequestComplete().BindUObject(this, &ANetworkManager::OnGetCityKeyRequestComplete);
		Request->ProcessRequest();
	}
}

// Called every frame
void ANetworkManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANetworkManager::OnGetCityKeyRequestComplete(FHttpRequestPtr InRequest, FHttpResponsePtr OutResponse, bool bConnectedSuccessfully)
{
	//if the query is successful
	if (OutResponse->GetResponseCode() == 200)
	{
		const FString ResponseString = OutResponse->GetContentAsString();
		if (ResponseString.Len())
		{
			TArray<TSharedPtr<FJsonValue>> OutArray;;

			TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(ResponseString);
			FJsonSerializer::Deserialize(JsonReader, OutArray);
			//auto Object = JsonObject->AsObject();
			if (OutArray.Num())
			{
				UE_LOG(LogTemp, Warning, TEXT("%d"), OutArray[0]->AsObject()->HasField("Key"));
				UE_LOG(LogTemp, Warning, TEXT("%s"), *OutArray[0]->AsObject()->GetStringField("Key"));
				/*FString CityKey = FString::Printf(TEXT("%s"), *Object->GetStringField("Key"));
				UE_LOG(LogTemp, Warning, TEXT("%s"), *CityKey);*/
			}
		}
	}
}