// Layout Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <stdlib.h> 
#include <time.h> 
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
	int startRoom[2] = { 15,15 };
	srand(time(NULL));
	//the number of rooms you want on the level
	int numOfRoom = 20;
	int counter = 0;
	int temp;
	bool cont = true;


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

		/*cout << endl << "Array of positions " << endl;
		for (int i = 0; i < counter; i++) {
			for (int j = 0; j < 2; j++) {
				if (spawnable[i][j] != NULL) {
					cout << spawnable[i][j] << " ";
				}
			}
			cout << endl;
		}*/

		//randomly pick a position that can spawn a room and spawn a room
		temp = getNewRoomCoords(Layout, counter);

		Layout[spawnable[temp][0]][spawnable[temp][1]] = 3;

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

	//print out the layout
	printLayout(Layout);
	displayMap(Layout);

	system("pause");

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

	cout << "Number: " << Layout[x][y] << endl;
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	cout << "left: " << Layout[x - 1][y] << " right: " << Layout[x + 1][y] << " up: " << Layout[x][y - 1] << " down: " << Layout[x][y + 1] << endl;

	if (Layout[x][y] != 0 && Layout[x - 1][y] != 0 && Layout[x][y - 1] != 0 && Layout[x][y + 1] != 0 && Layout[x + 1][y] != 0) {
		cout << "x - 1: " << Layout[x - 1][y] << " x + 1: " << Layout[x + 1][y] << " y - 1: " << Layout[x][y - 1] << " y + 1: " << Layout[x][y + 1] << endl;
		cout << "// 5 //" << endl;
		return 5;
	}
	//3 left = 6
	else if (Layout[x][y] != 0 && Layout[x - 1][y] != 0 && Layout[x][y - 1] != 0 && Layout[x][y + 1] != 0 && Layout[x + 1][y] == 0) {
		cout << "x - 1: " << Layout[x - 1][y] << " x + 1: " << Layout[x + 1][y] << " y - 1: " << Layout[x][y - 1] << " y + 1: " << Layout[x][y + 1] << endl;
		cout << "// 6 //" << endl;

		return 6;
	}
	//3 down = 7
	else if (Layout[x][y] != 0 && Layout[x - 1][y] != 0 && Layout[x][y + 1] != 0 && Layout[x + 1][y] != 0 && Layout[x][y - 1] == 0) {
		cout << "x - 1: " << Layout[x - 1][y] << " x + 1: " << Layout[x + 1][y] << " y - 1: " << Layout[x][y - 1] << " y + 1: " << Layout[x][y + 1] << endl;
		cout << "// 7 //" << endl;

		return 7;
	}
	//3 up = 8
	else if (Layout[x][y] != 0 && Layout[x - 1][y] != 0 && Layout[x][y - 1] != 0 && Layout[x + 1][y] != 0 && Layout[x][y + 1] == 0) {
		cout << "x - 1: " << Layout[x - 1][y] << " x + 1: " << Layout[x + 1][y] << " y - 1: " << Layout[x][y - 1] << " y + 1: " << Layout[x][y + 1] << endl;
		cout << "// 8 //" << endl;

		return 8;
	}
	//3 right = 9
	else if (Layout[x][y] != 0 && Layout[x][y - 1] != 0 && Layout[x][y + 1] != 0 && Layout[x + 1][y] != 0 && Layout[x - 1][y] == 0) {
		cout << "x - 1: " << Layout[x - 1][y] << " x + 1: " << Layout[x + 1][y] << " y - 1: " << Layout[x][y - 1] << " y + 1: " << Layout[x][y + 1] << endl;
		cout << "// 9 //" << endl;

		return 9;
	}
	//2 horizontal = 10
	else if (Layout[x][y] != 0 && Layout[x - 1][y] != 0 && Layout[x + 1][y] != 0 && Layout[x][y - 1] == 0 && Layout[x][y + 1] == 0) {
		cout << "x - 1: " << Layout[x - 1][y] << " x + 1: " << Layout[x + 1][y] << " y - 1: " << Layout[x][y - 1] << " y + 1: " << Layout[x][y + 1] << endl;
		cout << "// 10 //" << endl;

		return 10;
	}
	//2 vertical = 11
	else if (Layout[x][y] != 0 && Layout[x][y - 1] != 0 && Layout[x][y + 1] != 0 && Layout[x - 1][y] == 0 && Layout[x + 1][y] == 0) {
		cout << "x - 1: " << Layout[x - 1][y] << " x + 1: " << Layout[x + 1][y] << " y - 1: " << Layout[x][y - 1] << " y + 1: " << Layout[x][y + 1] << endl;
		cout << "// 11 //" << endl;

		return 11;
	}
	//2 top left = 12
	else if (Layout[x][y] != 0 && Layout[x - 1][y] != 0 && Layout[x][y - 1] != 0 && Layout[x + 1][y] == 0 && Layout[x + 1][y] == 0) {
		cout << "x - 1: " << Layout[x - 1][y] << " x + 1: " << Layout[x + 1][y] << " y - 1: " << Layout[x][y - 1] << " y + 1: " << Layout[x][y + 1] << endl;
		cout << "// 12 //" << endl;

		return 12;
	}
	//2 top right = 13
	else if (Layout[x][y] != 0 && Layout[x][y - 1] != 0 && Layout[x + 1][y] != 0 && Layout[x - 1][y] == 0 && Layout[x][y + 1] == 0) {
		cout << "x - 1: " << Layout[x - 1][y] << " x + 1: " << Layout[x + 1][y] << " y - 1: " << Layout[x][y - 1] << " y + 1: " << Layout[x][y + 1] << endl;
		cout << "// 13 //" << endl;

		return 13;
	}
	//2 bottom right = 14
	else if (Layout[x][y] != 0 && Layout[x][y + 1] != 0 && Layout[x + 1][y] != 0 && Layout[x - 1][y] == 0 && Layout[x][y - 1] == 0) {
		cout << "x - 1: " << Layout[x - 1][y] << " x + 1: " << Layout[x + 1][y] << " y - 1: " << Layout[x][y - 1] << " y + 1: " << Layout[x][y + 1] << endl;
		cout << "// 14 //" << endl;

		return 14;
	}
	//2 bottom left = 15
	else if (Layout[x][y] != 0 && Layout[x - 1][y] != 0 && Layout[x][y + 1] != 0 && Layout[x + 1][y] == 0 && Layout[x][y - 1] == 0) {
		cout << "x - 1: " << Layout[x - 1][y] << " x + 1: " << Layout[x + 1][y] << " y - 1: " << Layout[x][y - 1] << " y + 1: " << Layout[x][y + 1] << endl;
		cout << "// 15 //" << endl;

		return 15;
	}
	//1 left = 16
	else if (Layout[x][y] != 0 && Layout[x - 1][y] != 0 && Layout[x + 1][y] == 0 && Layout[x][y - 1] == 0 && Layout[x][y + 1] == 0) {
		cout << "x - 1: " << Layout[x - 1][y] << " x + 1: " << Layout[x + 1][y] << " y - 1: " << Layout[x][y - 1] << " y + 1: " << Layout[x][y + 1] << endl;
		cout << "// 16 //" << endl;

		return 16;
	}
	//1 up = 17
	else if (Layout[x][y] != 0 && Layout[x][y - 1] != 0 && Layout[x][y + 1] == 0 && Layout[x - 1][y] == 0 && Layout[x + 1][y] == 0) {
		cout << "x - 1: " << Layout[x - 1][y] << " x + 1: " << Layout[x + 1][y] << " y - 1: " << Layout[x][y - 1] << " y + 1: " << Layout[x][y + 1] << endl;
		cout << "// 17 //" << endl;

		return 17;
	}
	//1 right = 18
	else if (Layout[x][y] != 0 && Layout[x + 1][y] != 0 && Layout[x][y + 1] == 0 && Layout[x][y - 1] == 0 && Layout[x - 1][y] == 0) {
		cout << "x - 1: " << Layout[x - 1][y] << " x + 1: " << Layout[x + 1][y] << " y - 1: " << Layout[x][y - 1] << " y + 1: " << Layout[x][y + 1] << endl;
		cout << "// 18 //" << endl;

		return 18;
	}
	//1 down = 19
	else if (Layout[x][y] != 0 && Layout[x][y + 1] != 0 && Layout[x][y - 1] == 0 && Layout[x + 1][y] == 0 && Layout[x - 1][y] == 0) {
		cout << "x - 1: " << Layout[x - 1][y] << " x + 1: " << Layout[x + 1][y] << " y - 1: " << Layout[x][y - 1] << " y + 1: " << Layout[x][y + 1] << endl;
		cout << "// 19 //" << endl;

		return 19;
	}
	else {
	//cout << Layout[x][y] << " I am broken and stupid" << endl;
	//cout << "x: " << x << " y: " << y << endl;
		return 0;
	}
}

