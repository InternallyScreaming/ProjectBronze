// Layout Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h> 
#include <time.h> 
#include <math.h>
#include <cmath>
using namespace std;

int main();
int getPossibleRooms(int Layout[30][30], int counter);
int getNewRoomCoords(int Layout[30][30], int counter);
void printLayout(int Layout[30][30]);
int changeRooms(int Layout[30][30], int x, int y);
void displayMap(int Layout[30][30]);
// 0 = no room
// 1 = Starting Room
// 2 = Space For Room
// 3 = Room


int spawnable[100][2];

int main()
{
	int Layout[30][30];
	int Layout2[30][30];
	int startRoom[2] = { 15,15 };
	srand(time(NULL));
	//the number of rooms you want on the level
	int numOfRoom = 20;
	int counter = 0;
	int temp;
	bool cont = true;
	int temp2;
	int roomCount = 0;


	//fill the layout with 0
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			Layout[i][j] = 0;
		}
	}

	//fill in coordinates of spawnables with incorrect coordinates
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 2; j++) {
			spawnable[i][j] = NULL;
		}
	}

	
	Layout[startRoom[0]][startRoom[1]] = 1;

	//set the rooms around it as available to fit a room
	Layout[startRoom[0] + 1][startRoom[1]] = 2;
	Layout[startRoom[0] - 1][startRoom[1]] = 2;
	Layout[startRoom[0]][startRoom[1] + 1] = 2;
	Layout[startRoom[0]][startRoom[1] - 1] = 2;


	//print out the starting room location
	cout << "starting room location " << startRoom[0] << "," << startRoom[1] << endl;

	//print out the layout
	printLayout(Layout);

	//loop through for the number of rooms wanted in the layout
	for (int i = 0; i < numOfRoom; i++) {

		//call the function to find out which spaces can spawn rooms
		counter = getPossibleRooms(Layout, counter);

		//randomly pick a position that can spawn a room and spawn a room
		temp = getNewRoomCoords(Layout, counter);

		//make the rooms spawn further away the more rooms you generate
		cont = true;
		temp2 = (startRoom[0] - spawnable[temp][0]) + (startRoom[1] - spawnable[temp][1]);
		while (cont) {
			if (roomCount >= 0 && roomCount <= 6) {
				Layout[spawnable[temp][0]][spawnable[temp][1]] = 3;
				cont = false;
			}
			else if (roomCount > 6 && roomCount <= 12) {
				if (sqrt(pow(temp2, 2)) < 3) {
temp = getNewRoomCoords(Layout, counter);
temp2 = (startRoom[0] - spawnable[temp][0]) + (startRoom[1] - spawnable[temp][1]);
cout << "boop" << endl;
				}
				else {
				Layout[spawnable[temp][0]][spawnable[temp][1]] = 3;
				cont = false;
				}
			}
			else if (roomCount > 12) {
			if (sqrt(pow(temp2, 2)) < 5) {
				temp = getNewRoomCoords(Layout, counter);
				temp2 = (startRoom[0] - spawnable[temp][0]) + (startRoom[1] - spawnable[temp][1]);
				cout << "boop" << endl;
			}
			else {
				Layout[spawnable[temp][0]][spawnable[temp][1]] = 3;
				cont = false;
			}
			}
		}
		roomCount++;



		//add the spaces around the new room as possible rooms
		if (Layout[spawnable[temp][0] + 1][spawnable[temp][1]] == 0) {
			Layout[spawnable[temp][0] + 1][spawnable[temp][1]] = 2;
		}
		if (Layout[spawnable[temp][0] - 1][spawnable[temp][1]] == 0) {
			Layout[spawnable[temp][0] - 1][spawnable[temp][1]] = 2;
		}
		if (Layout[spawnable[temp][0]][spawnable[temp][1] + 1] == 0) {
			Layout[spawnable[temp][0]][spawnable[temp][1] + 1] = 2;
		}
		if (Layout[spawnable[temp][0]][spawnable[temp][1] - 1] == 0) {
			Layout[spawnable[temp][0]][spawnable[temp][1] - 1] = 2;
		}
	}

	//print out the layout
	printLayout(Layout);


	//Add the boss room
	temp = getNewRoomCoords(Layout, counter);

	//check for distance from starting room
	cont = true;
	temp2 = (startRoom[0] - spawnable[temp][0]) + (startRoom[1] - spawnable[temp][1]);
	while (cont) {
		//make it so the boss room doesnt spawn too close to the starting room
		if (sqrt(pow(temp2, 2)) < 7) {
			cout << "uh oh, stinky!" << endl;
			//cout << startRoom[0] << " " << spawnable[temp][0] << " " << startRoom[1] << " " << spawnable[temp][1] << endl;

			//try again
			temp = getNewRoomCoords(Layout, counter);
			temp2 = (startRoom[0] - spawnable[temp][0]) + (startRoom[1] - spawnable[temp][1]);
		}
		else if (sqrt(pow(temp2, 2)) >= 5) {
			cont = false;
		}
	}
	Layout[spawnable[temp][0]][spawnable[temp][1]] = 4;


	//clean up all the possible spots for rooms and make them back into blank spaces
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			if (Layout[i][j] == 2) {
				Layout[i][j] = 0;
			}
		}
	}

	//print out the layout
	printLayout(Layout);

	//convert the rooms into the room types
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			temp = changeRooms(Layout, i, j);
			if (temp != 0) {
				Layout[i][j] = temp;
			}
		}
	}

	//loop back throug thr array and change it back
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			Layout2[i][j] = Layout[i][j];
		}
	}
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			if (Layout2[i][j] != 0) {
				Layout2[i][j] = 3;
			}
		}
	}

	//print out the layout
	printLayout(Layout);
	displayMap(Layout);

	printLayout(Layout2);

}

int getPossibleRooms(int Layout[30][30], int counter) {
	//cout << "SPAWNING ROOM" << endl;
	counter = 0;

	//loop through the layout and pick all the spaces that can spawn a room
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			//find out how many possible spaces there are
			if (Layout[i][j] == 2) {
				//cout << "Found One" << endl << i << " " << j << " " << endl;
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
		if (Layout[spawnable[temp][0]][spawnable[temp][1]] == 1 || Layout[spawnable[temp][0]][spawnable[temp][1]] == 3) {

		}
		else {
			cont = false;
		}
	}

	return temp;
}

void printLayout(int Layout[30][30]) {
	cout << endl;
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			if (Layout[i][j] == 0) {
				//cout << "-";
				cout << char(255);
				//cout << Layout[i][j];
			}
			else {
				cout << Layout[i][j];
			}
		}
		cout << endl;
	}
}

void displayMap(int Layout[30][30]) {

	cout << endl;
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			if (Layout[i][j] == 0) {
				//cout << "-";
				cout << char(255);
				//cout << Layout[i][j];
			}
			else if (Layout[i][j] == 5) {
				cout << char(206);
			}
			else if (Layout[i][j] == 6) {
				cout << char(185);
			}
			else if (Layout[i][j] == 7) {
				cout << char(203);
			}
			else if (Layout[i][j] == 8) {
				cout << char(202);
			}
			else if (Layout[i][j] == 9) {
				cout << char(204);
			}
			else if (Layout[i][j] == 10) {
				cout << char(205);
			}
			else if (Layout[i][j] == 11) {
				cout << char(186);
			}
			else if (Layout[i][j] == 12) {
				cout << char(188);
			}
			else if (Layout[i][j] == 13) {
				cout << char(200);
			}
			else if (Layout[i][j] == 14) {
				cout << char(201);
			}
			else if (Layout[i][j] == 15) {
				cout << char(187);
			}
			else if (Layout[i][j] == 16) {
				cout << char(180);
			}
			else if (Layout[i][j] == 17) {
				cout << char(193);
			}
			else if (Layout[i][j] == 18) {
				cout << char(195);
			}
			else if (Layout[i][j] == 19) {
				cout << char(194);
			}
			else {
				cout << Layout[i][j];
			}
		}
		cout << endl;
	}
}

int changeRooms(int Layout[30][30], int x, int y) {
	//all four = 5
	int num;
	int North = Layout[x][y - 1];
	int South = Layout[x][y + 1];
	int East = Layout[x + 1][y];
	int West = Layout[x - 1][y];
	int currentPos = Layout[x][y];



	/*cout << "Number: " << Layout[x][y] << endl;
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	cout << "left: " << Layout[x - 1][y] << " right: " << Layout[x + 1][y] << " up: " << Layout[x][y - 1] << " down: " << Layout[x][y + 1] << endl;*/

	if (currentPos != 0 && North != 0 && South != 0 && East != 0 && West != 0) {

		num = 5;
	}
	//3 left = 6
	else if (currentPos != 0 && North != 0 && South == 0 && East != 0 && West != 0) {

		num = 6;
	}
	//3 down = 7
	else if (currentPos != 0 && North != 0 && South != 0 && East != 0 && West == 0) {


		num = 7;
	}
	//3 up = 8
	else if (currentPos != 0 && North != 0 && South != 0 && East == 0 && West != 0) {

		num = 8;
	}
	//3 right = 9
	else if (currentPos != 0 && North == 0 && South != 0 && East != 0 && West != 0) {

		num = 9;
	}
	//2 horizontal = 10
	
	else if (currentPos != 0 && North != 0 && South != 0 && East == 0 && West == 0) {

		num = 10;
	}
	//2 vertical = 11
	else if (currentPos != 0 && North == 0 && South == 0 && East != 0 && West != 0) {

		num = 11;
	}
	//2 top left = 12
	else if (currentPos != 0 && North != 0 && South == 0 && East == 0 && West != 0) {

		num = 12;
	}
	//2 top right = 13
	else if (currentPos != 0 && North == 0 && South != 0 && East == 0 && West != 0) {

		num = 13;
	}
	//2 bottom right = 14
	else if (currentPos != 0 && North == 0 && South != 0 && East != 0 && West == 0) {

		num = 14;
	}
	//2 bottom left = 15
	
	else if (currentPos != 0 && North != 0 && South == 0 && East != 0 && West == 0) {

		num = 15;
	}
	//1 left = 16
	else if (currentPos != 0 && North != 0 && South == 0 && East == 0 && West == 0) {

		num = 16;
	}
	//1 up = 17
	
	else if (currentPos != 0 && North == 0 && South == 0 && East == 0 && West != 0) {

		num = 17;
	}
	//1 right = 18
	else if (currentPos != 0 && North == 0 && South != 0 && East == 0 && West == 0) {

		num = 18;
	}
	//1 down = 19
	
	else if (currentPos != 0 && North == 0 && South == 0 && East != 0 && West == 0) {

		num = 19;
	}
	else {
		num = 0;
	}

	return num;
}

