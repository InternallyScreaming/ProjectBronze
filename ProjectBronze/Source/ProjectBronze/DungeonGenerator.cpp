// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonGenerator.h"
int spawnable[100][2];
int getTilePool(int Layout[30][30]);
int getNewRoomCoords(int Layout[30][30], int counter);

// Sets default values
ADungeonGenerator::ADungeonGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

}

// Called when the game starts or when spawned
void ADungeonGenerator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADungeonGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



int getTilePool(int Layout[30][30]) {
	int counter = 0;

	//loop through the layout and pick all the spaces that can spawn a room
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			//find out how many possible spaces there are
			if (Layout[i][j] == 2) {
				//insert the coordinates into the array 
				spawnable[counter][0] = i; spawnable[counter][1] = j;
				counter++;
			}
		}
	}

	return counter;
}

int getNewRoomCoords(int Layout[30][30], int counter) {
	bool cont = true;
	int temp;

	while (cont) {
		temp = rand() % counter;
		//empty if statement.
		//supposed to be like that according to braeden

		if (Layout[spawnable[temp][0]][spawnable[temp][1]] == 1 || Layout[spawnable[temp][0]][spawnable[temp][1]] == 3) {}
		else {
			cont = false;
		}
	}

	return temp;
}