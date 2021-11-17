#include "playerCard.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;



playerCard::playerCard() {};
playerCard::~playerCard() {};

void playerCard::readfile()
{
	ifstream file;
	file.open("playerCards.txt");
	string name, password, highScore;
	int i = 0;
	int j = 0;

	while (getline(file, diceScores[i][j], ','))
	{
		cout << diceScores;
	}
	file.close();
}

void playerCard::displayCard()
{
	readfile();
}