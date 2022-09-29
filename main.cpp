//////////////////////////////////////////////////////////////////////////////
// main.cpp
// Used to run Hunt the Wumpus. Takes in and applies user parameters to game.
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
#include <iostream>
#include "cave.h"

using namespace std;

int main(int argc, char ** argv) {
	if( argc != 4) {
		cout << "Incorrect number of parameters.  Provide  NumBats, NumPits, wumpusTiredness" << endl;
		return 0;
	} else if( stoi(argv[1]) >= 20 || stoi(argv[1]) < 0) {
		cout << "NumBats parameter is out of bounds.  0 < numBats < 20" << endl;
		return 0;
	} else if( stoi(argv[2]) >= 20 || stoi(argv[2]) < 0) {
		cout << "NumPits parameter is out of bounds.  0 < numPits < 20" << endl;
		return 0;
	} else if( stoi(argv[3]) < 0) {
		cout << "wumpusTiredness parameter is out of bounds.  0 < wumpusTiredness" << endl;
		return 0;
	} else {
		Cave c( stoi(argv[1]), stoi(argv[2]), stoi(argv[3]));
	}

}