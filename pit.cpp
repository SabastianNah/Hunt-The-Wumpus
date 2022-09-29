//////////////////////////////////////////////////////////////////////////////
// pit.cpp
// Pit Class
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
#include"pit.h"

using namespace std;

Pit::Pit() {
}

//////////////////////////////////////////////////////////////////////////////
// Sets total amount of pits in cave when given int
//////////////////////////////////////////////////////////////////////////////
void Pit::setnumPits(int nP) {
	numPits = nP;
}

//////////////////////////////////////////////////////////////////////////////
// Randomizes pit placement
//////////////////////////////////////////////////////////////////////////////
void Pit::setPits() {
	vector<int> random;
	for( int i = 1; i < 20; i++) {
		random.push_back(i);
	}
	random_shuffle(random.begin(), random.end());
	for( int i = 0; i < numPits; i++) {
		pitRooms.push_back(random.at(i));
	}
}

//////////////////////////////////////////////////////////////////////////////
// Testing purposes. Displays all current pit rooms in cave
//////////////////////////////////////////////////////////////////////////////
void Pit::printPits() {
	cout << "	PIT LOCATIONS: ";
	for( int i : pitRooms) {
		cout << i << " ";
	}
	cout << endl;
}

//////////////////////////////////////////////////////////////////////////////
// Check if the current room is nearby a pit
//////////////////////////////////////////////////////////////////////////////
bool Pit::nearPit(int currentRoom) {
	for( int i = 0; i < 3; i++) {
		for( int j = 0; j < numPits; j++) {
			if( ADJACENTROOMS[currentRoom][i] == pitRooms.at(j)) {
				return true;
			}
		}
	} 
	return false;
}

//////////////////////////////////////////////////////////////////////////////
// Check if the choice room is one of the pit rooms
//////////////////////////////////////////////////////////////////////////////
bool Pit::isPit(int choice) {
	for( int j = 0; j < numPits; j++) {
		if( choice == pitRooms.at(j)) {
			return true;
		}
	}
	return false;
}