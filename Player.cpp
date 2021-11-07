#include "Player.h"
#include <iostream>
#include <string>

Player::Player(string playerName, string password, int playerHighscore) : playerName(playerName), password(password), playerHighscore(playerHighscore)  {};
Player::~Player() {};

void Player::printSummary() 
{
	cout << playerName;
	for (unsigned int i = 0; i < playerName.length(); i++)
		cout << " ";
	cout << playerHighscore << "\n";
}
bool Player::isUserCorrect(string user) 
{
	if (playerName == user) 
	{
		return true;
	}
	else return false;
}
bool Player::isPassCorrect(string password) 
{
	if (password == getPassword())
	{
		return true;
	}
	else return false;
}
