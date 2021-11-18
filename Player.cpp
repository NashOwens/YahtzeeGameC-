#include "Player.h"
#include <iostream>
#include <string>
#include <fstream>

Player::Player(string playerName, string password, int playerHighscore) : playerName(playerName), password(password), playerHighscore(playerHighscore)  {};
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
	ifstream file("playerCards.txt");
	//for (int i=0;i<5;i++)
	file >> *this;
	file.close();
}
void Player::writefile()
{
	ofstream file("playerCards.txt");
	for (int i = 0; i < 5; i++)
	{
		file << *this;
	}
	file.close();
};




