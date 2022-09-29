//////////////////////////////////////////////////////////////////////////////
// cave.cpp
// Base of the dungeon. Allows user interaction and gameplay of game.
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
#include"cave.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////
// Constructs cave to be playable by adding pits and bats
//////////////////////////////////////////////////////////////////////////////
Cave::Cave( int nB, int nP, int wT) {
    srand( time(NULL));
	currentRoom = 0;
	bat.batHealth = 1;
	arrows = 2;
	alive = true;

	bat.setnumBats(nB);
	bat.setBats();
	pit.setnumPits(nP);
	pit.setPits();
	wumpus.setwumpusTiredness(wT);
	wumpus.setWumpus(19, 1);

	play();
}

//////////////////////////////////////////////////////////////////////////////
// Play the game until Wumpus is dead or user is dead.
//////////////////////////////////////////////////////////////////////////////
void Cave::play() {
	while( alive == true && arrows != 0) {
		wumpus.printWumpus();
		surroundings();
		cout << "Enter Choice :";
		cin >> choice;
		cout << endl;
		// Manually ends the program
		if( choice == -1 ) {
			alive = false;
			cout << "You've exited the game by putting '-1'" << endl;
			break;
		} 
		// Room is valid. You continue
		if( validAdjacentRooms(choice) == true) {
			// When room choice is a bat and Wumpus
			if( bat.isBat(choice) == true && wumpus.isWumpus(choice) == true) {
			cout << "You are in room ";
				cout << choice << endl;
				choice = bat.travel(choice);
				cout << "	A giant bat picks you up and drops you in Room " << choice << endl << endl;
				bat.batHealth = 0;
				currentRoom = choice;
				cout << "	The Wumpus hears the bat. Wumpus goes somewhere else" << endl;
				wumpus.setWumpus(20, 0);
			}
			// When room choice is a bat OR is a bat and pit
			if( bat.isBat(choice) == true || bat.isBat(choice) == true && pit.isPit(choice) == true) {
				cout << "You are in room ";
				cout << choice << endl;
				choice = bat.travel(choice);
				cout << "	A giant bat picks you up and drops you in Room " << choice << endl << endl;
				bat.batHealth = 0;
				currentRoom = choice;
			}
			// When room choice is only pit
			if( pit.isPit(choice) == true) {
				alive = false;
				cout << "You are in room ";
				cout << choice << endl;
				cout << "	You have fallen into a pit.  You are dead" << endl;
				break;
			}
			// When room choice is only Wumpus
			if( wumpus.isWumpus(choice) == true) {
				srand( time(NULL));
				cout << "You are in room ";
				cout << choice << endl;
				if( wumpus.wumpusTiredness == 0 || rand() % wumpus.wumpusTiredness == 0) {
					alive = false;
					cout << "	The Wumpus has killed you.  You are dead";
				} else {
					cout << "	The Wumpus ignores you. Wumpus goes somewhere else" << endl;
					currentRoom = choice;
					wumpus.setWumpus(20, 0);
				}
			// when room choice is empty
			} else {
				bat.batHealth++;
				wumpus.wumpusTiredness--;
				if( wumpus.wumpusTiredness < 0) {
					wumpus.wumpusTiredness = 0;
				}
			currentRoom = choice;
			}
		// Shoot arrow in a chosen adjacent room
		} else if( choice == 20) {
			cout << "What direction do you want to shoot your arrow?" << endl;
			cout << "Enter Room number :";
			cin >> choice;
			cout << endl;
			// Wumpus is dead. You win
			if(choice == wumpus.wumpusRoom) {
				alive = false;
				cout << "You have killed the Wumpus.  You win." << endl;
			// Arrow is lost
			} else {
				arrows--;
				cout << "	Nothing was there.  You lose an arrow." << endl;
				// All arrows lost. You die
				if( arrows == 0) {
					cout << "You have no more arrows.  You are dead.";
					break;
				}
			}
		} else {
			cout << "	Room is not adjacent" << endl;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////
// Check the surroundings of current room. Warns via hints of nearby pits,
// bats, or wumpus. informs what rooms are available to travel to.
//////////////////////////////////////////////////////////////////////////////
void Cave::surroundings() {
	cout << "You are in room ";
    cout << currentRoom << endl;
	// Near a pit
	if( pit.nearPit(currentRoom) == true) {
		cout << "	You feel a cold draft" << endl;
	}
	// Near a bat
	if( bat.nearBat(currentRoom) == true) {
		cout << "	You hear the wings of a bat fluttering" << endl;
	}
	// Near the Wumpus
	if( wumpus.nearWumpus(currentRoom) == true) {
		cout << "	You smell a Wumpus nearby" << endl;
	}
    cout << "you may go to ";
    cout << "room " << ADJACENTROOMS[currentRoom][0] << ", ";
	cout << "room " << ADJACENTROOMS[currentRoom][1] << ", ";
	cout << "room " << ADJACENTROOMS[currentRoom][2] << endl;
}

//////////////////////////////////////////////////////////////////////////////
// Check if the choice room is valid. Only 3 options for current room
//////////////////////////////////////////////////////////////////////////////
bool Cave::validAdjacentRooms(int choice) {
	if( choice == ADJACENTROOMS[currentRoom][0] || choice == ADJACENTROOMS[currentRoom][1] || choice == ADJACENTROOMS[currentRoom][2]) {
		return true;
	}
	return false;
}