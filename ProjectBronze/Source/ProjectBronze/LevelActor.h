// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LevelScriptActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelActor.generated.h"

UCLASS()
class PROJECTBRONZE_API ALevelActor : public ALevelScriptActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
