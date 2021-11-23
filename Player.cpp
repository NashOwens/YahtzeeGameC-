#include "Player.h"
#include <iostream>
#include <string>
#include <fstream>

Player::Player(string playerName, string password, int playerHighscore) : playerName(playerName), password(password), playerHighscore(playerHighscore), diceScores(nullptr), games(0)  {};
Player::~Player() {}

bool sortAlphabet(Player* fp, Player* sp);

void Player::printSummary() const
{
	cout << playerName;
	for (unsigned int i = 0; i < 30-playerName.length(); i++)
		cout << " ";
	cout << playerHighscore << "\n";
}
bool Player::isUserCorrect(string user) 
{
	return (playerName == user);
}
bool Player::isPassCorrect(string userpassword) 
{
	return (password == userpassword);
}
void Player::readfile()
{
	ifstream file((this->playerName + ".txt"));
	file >> *this;
	file.close();
}
void Player::writefile()
{
	ofstream file(this->playerName + ".txt");
	file << *this;
	file.close();
	for (int i = 1; i < games + 1; i++)
	{
		delete this->diceScores[i];
	}
}
bool Player::checkifTaken(string playername)
{
	return(playerName == playername);
}
void Player::displayScorecards()
{
	cout << "\nScoreCard History\n------------------------\n";
	for (int i = 1; i < this->games+1; i++)
	{
		cout << "\n       Game " << i << ":\n";
		for (int j=0; j<6; j++)
		{
		switch (j)
				{
		case 1: cout << "\nOnes: " << this->diceScores[i][j]; break;
		case 2:	cout << "\nTwos: " << this->diceScores[i][j]; break;
		case 3: cout << "\nThrees: " << this->diceScores[i][j]; break;
		case 4: cout << "\nFours: " << this->diceScores[i][j]; break;
		case 5: cout << "\nFives: " << this->diceScores[i][j]; break;
		case 6: cout << "\nSixes: " << this->diceScores[i][j]; break;
		default: break;
		}
		}
	}
}




