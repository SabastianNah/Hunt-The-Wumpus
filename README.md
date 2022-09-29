# Hunt-The-Wumpus
Wumpus is a text-based adventure game with an adventurer in a cave with 20 rooms. The rooms are arranged in a dodecahedron with each room having three exits to other rooms. Some of the rooms have a bottomless pit, a colony of super bats, and somewhere in the maze, there is a sleeping Wumpus. The adventurer's job is to kill the Wumpus before it kills them, or they fall into a pit.

When starting the game you take three parameters in the command line: number of bats, number of pits, and Wumpus tired level. The player starts in room 0 where no bats, pits, or Wumpus should start at. The location of bats, pits, and wumpus will be randomized.

⦁ If you enter a room with a bat, you will be picked up by the bat and carried to a new room. 
⦁ If you enter a room with a pit, you will fall into the pit and die ( unless a bat picks you up and moves you to a new room) 
⦁ If you enter a room with a bat and a wumpus – the bat will take you away before the Wumpus eats you. 
⦁ If you enter a room with a Wumpus – the wumpus will either move to a new room or eat you. The probability of eating or leaving is based on Wumpus's tiredness.

Whenever you enter a room, the program will give you the following warning of one of the adjacent rooms

⦁ If there is a Wumpus in an adjacent room you will be told “You smell a Wumpus nearby” 
⦁ If there is a bat in an adjacent room you will be told “You hear the wings of a bat fluttering” 
⦁ If there is a pit in an adjacent room you will be told “You feel a cold draft”

The adventurer has two arrows that can be fired into an adjacent room. If the Wumpus is in the room the adventurer wins, else they lose the arrow. If all arrows are gone the adventurer loses.

Bats:

⦁ Movement is based on the equation(batHealth % 3) + 1 
⦁ Every turn the bat gains 1 health
⦁ Bats can drop in any type of room including pit and wumpus locations

Wumpus: 

⦁ The Wumpus will kill or wander off if encountered by the adventurer 
⦁ Able to go into a Pit room 
⦁ Every turn decreases the tired level. the lower the number the higher the chance the adventurer is killed when an encounter happens
