//////////////////////////////////////////////////////////////////////////////
// pit.h
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
#ifndef PIT_H 
#define PIT_H

#include<iostream>
#include<vector>

class Pit {
	public:
		Pit();
		// Set total pit rooms
		void setnumPits(int);
		// Randomize pit placement
		void setPits();
		// Display pit rooms
		void printPits();
		// Checks if near pit room
		bool nearPit(int);
		// Check if currently in a pit room
		bool isPit(int);
	private:
		friend class Cave;
		int numPits;
		std::vector<int> pitRooms;
		const int ADJACENTROOMS[20][3] = {
			{19, 13, 16},	//0 (technically room 20) no event
			{2, 8, 5},		//1 
			{3, 10, 1},		//2
			{4, 12, 2},		//3  
			{5, 14, 3},		//4
			{6, 1, 4},		//5
			{7, 5, 15},		//6
			{8, 17, 6},		//7
			{9, 1, 7},		//8
			{10, 18, 8},	//9
			{11, 2, 9},		//10
			{12, 19, 10},	//11
			{13, 3, 11},	//12
			{14, 0, 12},	//13
			{15, 4, 13},	//14
			{16, 6, 14},	//15
			{17, 15, 0},	//16
			{18, 7, 16},	//17
			{19, 9, 17},	//18
			{0, 11, 18}		//19
		};
};
#endif 