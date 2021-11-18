#include "playerCard.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

playerCard::playerCard() : diceScores(diceScores) {};
playerCard::~playerCard() {};

istream& operator>>(istream& ins, playerCard& target);
ostream& operator<<(ostream& outs, const playerCard* source);

void playerCard::readfile(int index)
{
	ifstream file("playerCards.txt");
	for (int i = 0; i < 5; i++)
	{
		file >> this->diceScores[index][i];
	}
	file.close();
}
void playerCard::writefile()
{
	ofstream file("playerCards.txt");
	//file << this;
	file.close();
};
istream& operator>>(istream& ins, playerCard& target)
{
	char c;
	for (int j = 0; j < 5; j++)
	{
		//ins >> target.diceScores[0][j];
		ins >> c;
	}
	return ins;
}
ostream& operator<<(ostream& outs, playerCard& source)
{
	outs << source.getdiceScores();
	return outs;
}
