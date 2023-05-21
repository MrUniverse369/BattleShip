
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <ctype.h>
#include<ctime>
#include <cstdlib>
#include "GameBoardManager.h"



//initialise battleShipGameBoard objects
GameBoardManager::GameBoardManager()
{

	m_boardPlayerName = " ";
	m_gameBoardIter = m_gameBoard.begin();
	m_gameBoard.push_back(' ');
}

//initialise battleShipGameBoard objects
GameBoardManager::GameBoardManager(std::string playerName) {
	m_boardPlayerName = playerName;
	m_gameBoardIter = m_gameBoard.begin();
	m_gameBoard.push_back(' ');
}

void GameBoardManager::initRandSeed() {
	//randomise the location of the player ships 
	std::srand(static_cast<unsigned int>(time(0)));
}
std::string GameBoardManager::getName()
{
	return m_boardPlayerName;
}
//randomise the postion of the ships on the board
void GameBoardManager::shuffleShipLocations(std::vector<char>& shipLocation) {
	std::random_shuffle(shipLocation.begin(), shipLocation.end());
}

void GameBoardManager::initGameBoard(std::vector<char>& shipLocation) {

	//initialise the playerboards 
	std::string letters = "A";
	int i = 0;
	m_shipLocationIter = shipLocation.begin();
	//makes sure the board is empty before intialising it
	m_gameBoard.erase(m_gameBoard.begin(), m_gameBoard.end());
	//stores the baord with values A - L which describe locations players can select
	for (int i = 0; i < 12; i++) m_gameBoard.push_back(letters[0]++);

	m_shipLocationIter[0] = '*';
	m_shipLocationIter[1] = '*';
	m_shipLocationIter[2] = '*';
	m_shipLocationIter[3] = '*';
	m_shipLocationIter[4] = '*';



}


//prints the Battleship board 
void GameBoardManager::showGameBoard() {
	std::cout << m_boardPlayerName << "'s Board\n";
	std::cout << "Score:" << m_score<<"\n";
	std::cout << m_fiveSpaces << " _____________________\n";
	std::cout << m_fiveSpaces << "|  " << m_gameBoard[0] << " |  " << m_gameBoard[1] << "  |  " << m_gameBoard[2] << "  |  " << m_gameBoard[3] << " |\n";
	std::cout << m_fiveSpaces << "|____|_____|_____|____|\n";
	std::cout << m_fiveSpaces << "|  " << m_gameBoard[4] << " |  " << m_gameBoard[5] << "  |  " << m_gameBoard[6] << "  |  " << m_gameBoard[7] << " |\n";
	std::cout << m_fiveSpaces << "|____|_____|_____|____|\n";
	std::cout << m_fiveSpaces << "|  " << m_gameBoard[8] << " |  " << m_gameBoard[9] << "  |  " << m_gameBoard[10] << "  |  " << m_gameBoard[11] << " |\n";
	std::cout << m_fiveSpaces << "|____|_____|_____|____|\n";


}

//change the value of a element on the board 
void GameBoardManager::setBoardValue(char playerInput, std::vector<char>& shipLocation) {
	std::cout << m_gameBoard.size() << "\n\n" << shipLocation.size() << "\n\n";


	for (size_t i = 0; i < m_gameBoard.size(); i++)
	{
		/*
		p = PlayerInput eqauls an element on our baord
		q = player has selected an element on our board
		r = our gameBoard is set to the matching value in ship location
		if playerInput eqauls an element on our board then player has selected an element on our board

		p->q

		if player has selected an element on our board then  our gameBoard is set to the matching value in ship location

		q->r

		*/
		if (m_gameBoard[i] == ::toupper(playerInput))
		{
			std::cout << "Player has selected an element on our board\n";
			m_gameBoard[i] = shipLocation[i];
			if (m_gameBoard[i] == '*')
			{
				m_score = m_score + 1;
			}
		}

	}
}

