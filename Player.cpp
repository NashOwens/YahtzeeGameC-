#include "Player.h"
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

Player::Player(string playerName, string password, int playerHighscore) : playerName(playerName), password(password), playerHighscore(playerHighscore), diceScores(nullptr), games(0)  {};
Player::~Player() {}

using namespace std;

//displays all players at main menu

void Player::printSummary() const
{
	cout << playerName;
	for (unsigned int i = 0; i < 30-playerName.length(); i++)
		cout << " ";
	cout << playerHighscore << "\n";
}

//security checks for log in

bool Player::isUserCorrect(string user) 
{
	return (playerName == user);
}
bool Player::isPassCorrect(string userpassword) 
{
	return (password == userpassword);
}

//reads Scorecard of player to the player variables

void Player::readfile()
{
	ifstream file(playerName + ".txt");
	file >> *this;
	file.close();
}

//writes to dice scores to the playernames text file

void Player::writefile()
{
	ofstream file(playerName + ".txt");
	file << *this;							//Opperator overloading here
	file.close();
	for (int i = 0; i < games; i++)
	{
		delete[] diceScores[i];				//deletes contents of array (int arrays)
	}
	delete[] diceScores;					//deletes array
}
bool Player::checkifTaken(string playername)
{
	return(playerName == playername);
}

//displays scorecards:

void Player::displayScorecards()
{
	cout << "\nScoreCard History\n------------------------\n";
	for (int i = 0; i < games; i++)
	{
		cout << "\n       Game " << i+1 << ":\n";
		i-1;
		for (int j=0; j<6; j++)
		{
		switch (j)
				{
		case 0: cout << "\nOnes: " << diceScores[i][j]; break;
		case 1:	cout << "\nTwos: " << diceScores[i][j]; break;
		case 2: cout << "\nThrees: " << diceScores[i][j]; break;
		case 3: cout << "\nFours: " << diceScores[i][j]; break;
		case 4: cout << "\nFives: " << diceScores[i][j]; break;
		case 5: cout << "\nSixes: " << diceScores[i][j]; break;
		default: break;
		}
		}
	}
}

//This function inserts the new game score into the current player scorecard:

void Player::addGametoScorecard(int* gameScore)
{	
	diceScores[games] = new int[6];					
	for (int i = 0; i < 6; i++)
	{
		diceScores[games][i] = gameScore[i];
	}
	games++;
}





