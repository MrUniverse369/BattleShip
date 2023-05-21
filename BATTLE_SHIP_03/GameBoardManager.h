#ifndef GameBoardManager_H
#define GameBoardManager_H

#include<iostream>
#include<vector>
#include<string>


//class manages everything that has to do with the Gameboard
class GameBoardManager {
public:
	GameBoardManager();
	GameBoardManager(std::string playerName);
	int m_score;
	std::vector<char> m_gameBoard;
	std::vector<char>::iterator m_gameBoardIter;
	std::vector<char>::iterator m_shipLocationIter;
	std::string m_fiveSpaces = "     ";




	//initialise the gameboard 
	void initGameBoard(std::vector<char>& shipLocation);

	//change the value of a element on the board 
	void setBoardValue(char playerInput, std::vector<char>& shipLocation);
	//print the the board 
	void showGameBoard();
	//randomise the postion of the ships on the board
	void shuffleShipLocations(std::vector<char>& shipLocation);
	void initRandSeed();
	std::string getName();

private:
	//store the name of the player the board belongs to
	std::string m_boardPlayerName;
};
#endif GameBoardManager_H