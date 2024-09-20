### 
**Battleship Game - C++ Project**
![BattleShip](https://github.com/user-attachments/assets/60fb0afe-98cf-4f22-a83a-251cb67797de)

**Overview**

This project is a console-based Battleship game, where two players compete to sink each other's ships. The game follows the traditional Battleship gameplay, and this implementation allows for player vs. player (with one player being the CPU). The game is designed using C++ and involves a GameBoardManager class to manage the game boards of the players.

**Features**

- Turn-based gameplay: Players take turns to guess the location of the opponent's ships.
- Randomized ship locations: Ship positions are randomized at the start of each game.
- Input validation: The game ensures that players provide valid inputs.
- Win conditions: The game ends when one player sinks all the opponent's ships.
- CPU player: A simple AI (named "CPU") can play against the human player.

**Game Rules**

- Input: Players enter a character from 'A' to 'L' representing a location on the game board.
- Turn system: Player One and CPU take alternate turns, with Player One starting first.
- Win condition: The first player to sink all five of the opponent's ships wins the game.


**Code Structure**

- main.cpp: Contains the main game loop and logic.
- GameBoardManager.cpp: Handles the game board setup and management, including ship placement and input validation.

**Main Functions**

- Setup(): Initializes the game, sets up boards, and provides player instructions.
- ShowGameBoard(): Displays the current state of both players' game boards.
- StatePlayerTurn(): Manages the current player's turn.
- GetPlayerInput(): Collects and validates player input.
- validatePlayerInput(): Ensures that the player's input is within the allowed range of board locations.
- gameOver(): Checks if a player has won the game by sinking all the ships.
