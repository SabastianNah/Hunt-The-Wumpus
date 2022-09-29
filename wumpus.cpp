//////////////////////////////////////////////////////////////////////////////
// wumpus.cpp
// Wumpus class
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
#include"wumpus.h"

using namespace std;

Wumpus::Wumpus() {
}

//////////////////////////////////////////////////////////////////////////////
// Sets wumpusTiredness for the duration of game
//////////////////////////////////////////////////////////////////////////////
void Wumpus::setwumpusTiredness(int wT) {
	wumpusTiredness = wT;
}

//////////////////////////////////////////////////////////////////////////////
//  Randomizes placement of Wumpus from rooms min through max
//////////////////////////////////////////////////////////////////////////////
void Wumpus::setWumpus(int max, int min) {
	srand( time(NULL));
	wumpusRoom = rand() % max + min;
}

//////////////////////////////////////////////////////////////////////////////
// Prints a readable display of the current room Wumpus occupies
//////////////////////////////////////////////////////////////////////////////
void Wumpus::printWumpus() {
	cout << "	WUMPUS LOCATION: " << wumpusRoom << endl;
}

//////////////////////////////////////////////////////////////////////////////
// Check if user is nearby the room Wumpus occupies
//////////////////////////////////////////////////////////////////////////////
bool Wumpus::nearWumpus(int currentRoom) {
	for( int i = 0; i < 3; i++) {
		if( ADJACENTROOMS[currentRoom][i] == wumpusRoom) {
			return true;
		}
	} 
	return false;
}

//////////////////////////////////////////////////////////////////////////////
// Check if the chosen room is the room Wumpus occupies
//////////////////////////////////////////////////////////////////////////////
bool Wumpus::isWumpus(int choice) {
	if( choice == wumpusRoom) {
		return true;
	}
	return false;
}