//////////////////////////////////////////////////////////////////////////////
// bat.cpp
// Bat class
// ⦁	 A modified version of the classic "Hunt The Wumpus" game.
// ⦁	 User generated amount of pits, bats, and wumpus tiredness.
// ⦁	 Creation of a cave with 20 rooms. The rooms are arranged in a dodecahedron.
// ⦁	 User will wander and be given hints of anything nearby and react.
// ⦁	 If you use up all of your arrows(total: 2), you die and lose the game.
// ⦁ If the Wumpus(tiredness: 0) eats you, you die and lose the game.
// ⦁ If you fall into a pit, you die and lose the game.
// ⦁ To shoot an arrow you enter room #20 as the room you want to move to. 
// ⦁ You can fire the arrow into an adjacent room.  
// ⦁ If the Wumpus is in the room you kill it and win the game.
//////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include"bat.h"

using namespace std;

Bat::Bat() {
}

//////////////////////////////////////////////////////////////////////////////
// Sets total amount of bats in cave when given int
//////////////////////////////////////////////////////////////////////////////
void Bat::setnumBats(int nP) {
	numBats = nP;
}
//////////////////////////////////////////////////////////////////////////////
// Randomizes bat placement
//////////////////////////////////////////////////////////////////////////////
void Bat::setBats() {
	vector<int> random;
	for( int i = 1; i < 20; i++) {
		random.push_back(i);
	}
	random_shuffle(random.begin(), random.end());
	for( int i = 0; i < numBats; i++) {
		batRooms.push_back(random.at(i));
	}
}
//////////////////////////////////////////////////////////////////////////////
// Uses batHealth to find how many rooms to travel. Rooms that are traveled are
// adjecent to choice which changes depending on allowed rooms to travel
//////////////////////////////////////////////////////////////////////////////
int Bat::travel(int choice) {
	srand( time(NULL));
	for( int i = 0; i < (batHealth % 3) + 1; i++) {
		choice = ADJACENTROOMS[choice][rand() % 3];
	}
	return choice;
}
//////////////////////////////////////////////////////////////////////////////
// Testing purposes. Displays all current bat rooms in cave
//////////////////////////////////////////////////////////////////////////////
void Bat::printBats() {
	cout << "	BAT LOCATIONS: ";
	for( int i : batRooms) {
		cout << i << " ";
	}
	cout << endl;
}

//////////////////////////////////////////////////////////////////////////////
// Check if the current room is nearby a bat
//////////////////////////////////////////////////////////////////////////////
bool Bat::nearBat(int currentRoom) {
	for( int i = 0; i < 3; i++) {
		for( int j = 0; j < numBats; j++) {
			if( ADJACENTROOMS[currentRoom][i] == batRooms.at(j)) {
				return true;
			}
		}
	} 
	return false;
}

//////////////////////////////////////////////////////////////////////////////
// Check if the choice room is one of the bat rooms
//////////////////////////////////////////////////////////////////////////////
bool Bat::isBat(int choice) {
	for( int j = 0; j < numBats; j++) {
		if( choice == batRooms.at(j)) {
			return true;
		}
	}
	return false;
}