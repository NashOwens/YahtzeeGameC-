#include "Player.h"
#include <iostream>
#include <string>
#include <fstream>

Player::Player(string playerName, string password, int playerHighscore) : playerName(playerName), password(password), playerHighscore(playerHighscore), diceScores(nullptr), games(0)  {};
Player::~Player() {}

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
}
void Player::readPlayers()
{
	ifstream file("PlayerDetails.txt");
	file >= *this;
	file.close();
}




