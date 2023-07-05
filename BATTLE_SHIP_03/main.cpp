
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <ctype.h>
#include<ctime>
#include <cstdlib>
#include "GameBoardManager.h"

int const PLAYERONETURN = 0;
int PlayerOneLives;
int PlayerTwoLives;
int PlayerOneScore;
int PlayerTwoScore;
char playerOneInput;
char playerInput;
char playerTwoInput;
int playerInputCount;
int playerInputCountTwo;
int turnCount = 0;
std::string fiveSpaces = "     ";
std::vector<char> battleShipGameBoard(12, 'N');
std::vector<char> PlayerOneShipLocations(12, 'N');
std::vector<char>::iterator POSLIter;
std::vector<char> PlayerTwoShipLocations(12, 'N');
std::vector<char>::iterator PTSLIter;





void Setup(GameBoardManager& playerOneBoard, GameBoardManager& playerTwoBoard, std::vector<char>& shipLocation, std::vector<char>& shipLocationTwo);
void ShowGameBoard(GameBoardManager& playerOneBoard, GameBoardManager& playerTwoBoard);
bool StatePlayerTurn(int turnCount);
char GetPlayerInput(const bool& PLAYERONETURN, bool isCurrentTurn, GameBoardManager& gameBoardObj);
char validatePlayerInput(char& playerInput, GameBoardManager& gameBoardObject);
bool gameOver(GameBoardManager gameBoardObject1, GameBoardManager gameBoardObject2);


int main()
{
	std::vector<char> shipLocation(12, 'N');
	std::vector<char> shipLocationTwo(12, 'N');
	GameBoardManager PlayerOnegameBoard("Thamsanqa");
	GameBoardManager PlayerTwogameBoard("CPU");




	//set's up  the proties of the game and outputs player instructions 
	Setup(PlayerOnegameBoard, PlayerTwogameBoard, shipLocation, shipLocationTwo);

	do
	{

		if (PLAYERONETURN != StatePlayerTurn(turnCount))
		{
			// reads the player input
			playerInput = GetPlayerInput(PLAYERONETURN, StatePlayerTurn(turnCount), PlayerTwogameBoard);

		}
		else
		{
			//reads the player input 
			playerInput = GetPlayerInput(PLAYERONETURN, StatePlayerTurn(turnCount), PlayerOnegameBoard);
		}


		if (PLAYERONETURN != StatePlayerTurn(turnCount))
		{
			PlayerTwogameBoard.setBoardValue(playerInput, shipLocationTwo);

		}
		else
		{

			PlayerOnegameBoard.setBoardValue(playerInput, shipLocation);

		}

		system("cls");
		//if its player two's turn then change to player ones turn otherwise if its player ones turn cahnge to player turn.
		turnCount = (turnCount > 0) ? 0 : 1;
		ShowGameBoard(PlayerOnegameBoard, PlayerTwogameBoard);

	} while (!gameOver(PlayerOnegameBoard, PlayerTwogameBoard));

	system("pause");
};

//sets the rules and conditions for the game 
void Setup(GameBoardManager& playerOneBoard, GameBoardManager& playerTwoBoard, std::vector<char>& shipLocation, std::vector<char>& shipLocationTwo) {

	//initialise varibales
	std::string letters;
	PlayerOneScore = 0;
	PlayerTwoScore = 0;
	PlayerOneLives = 0;
	PlayerTwoLives = 0;
	PlayerOneScore = 0;
	PlayerTwoScore = 0;
	playerOneInput = 0;
	playerInput = 0;
	playerTwoInput = 0;
	playerInputCount = 0;
	playerInputCountTwo = 0;




	//output player instructions 
	std::cout << "--------------------------------------Battle_Sihip------------------------------\n";
	std::cout << "Welcome to the Battle captain you have been called upon to destroy the\nenemy that stands in midst of our victory\n\n";
	std::cout << "We have dected that the the enemy fleet to be scatered around this location\nguide us on where we should fire our missles\n\n";
	std::cout << "Your wisdom should surely bring us victory its your move captain\n\n";

	playerOneBoard.initRandSeed();
	playerOneBoard.initGameBoard(shipLocation);
	playerTwoBoard.initGameBoard(shipLocationTwo);

	playerOneBoard.shuffleShipLocations(shipLocation);
	playerTwoBoard.shuffleShipLocations(shipLocationTwo);

	ShowGameBoard(playerOneBoard, playerTwoBoard);

}

void ShowGameBoard(GameBoardManager& playerOneBoard, GameBoardManager& playerTwoBoard)
{
	playerOneBoard.showGameBoard();
	std::cout << "\n  ----------------------------\n";
	playerTwoBoard.showGameBoard();
	std::cout << "\n";
}

bool StatePlayerTurn(int turnCount)
{
	bool isCurrentTurn = false;

	isCurrentTurn = (turnCount % 2 != 0) ? true : false;

	return isCurrentTurn;
}

//checks to see which player's turn it is and then asks them for input
char GetPlayerInput(const bool& PLAYERONETURN, bool isCurrentTurn, GameBoardManager& gameBoardObj)
{
	/*if it is not player ones turn then it
	must be player two's turn otherwise it is player ones turn*/
	if (PLAYERONETURN != isCurrentTurn)
	{
		std::cout << "Player Two:";
	}
	else
	{
		std::cout << "Player One:";

	}
	std::cin >> playerInput;
	std::cout << "\n";

	//check to see if the the player input is valid before returning it 
	playerInput = validatePlayerInput(playerInput, gameBoardObj);
	return playerInput;
}

//checks to see if the the player Input matches our rules for what is considered legal input
char validatePlayerInput(char& playerInput, GameBoardManager& gameBoardObject) {
	bool inputIsValid = false;

	//if player input is bigger than L and less than A  it can not be a value on our board 
	while (::toupper(playerInput) < 'A' || ::toupper(playerInput) > 'L')
	{
		std::cout << "That location does not exisit please pick alocation on the map \n";
		std::cin >> playerInput;
	}
	do
	{



		for (gameBoardObject.m_gameBoardIter = gameBoardObject.m_gameBoard.begin(); gameBoardObject.m_gameBoardIter != gameBoardObject.m_gameBoard.end(); ++gameBoardObject.m_gameBoardIter) {

			if (::toupper(playerInput) == *gameBoardObject.m_gameBoardIter)
			{
				std::cout << "Input is valid \n";
				inputIsValid = true;
				break;

			}
			else if (::toupper(playerInput) != *gameBoardObject.m_gameBoardIter && gameBoardObject.m_gameBoardIter == gameBoardObject.m_gameBoard.end() - 1)
			{
				std::cout << "Input is invalid\n";
				std::cout << "Please type in a value from the board\n";
				std::cin >> playerInput;

			}

		}

	} while (inputIsValid != true);

	return playerInput;
}

bool gameOver(GameBoardManager gameBoardObject1, GameBoardManager gameBoardObject2)
{
	bool isGameOver = false;
	if (gameBoardObject1.m_score == 5)
	{
		std::cout << gameBoardObject1.getName() << " has Won!!!!!";
		isGameOver = true;
	}
	if (gameBoardObject2.m_score == 5)
	{
		std::cout << gameBoardObject2.getName() << " has Won!!!!!";
		isGameOver = true;
	}

	return isGameOver;
}
