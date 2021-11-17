#pragma once
class playerCard
{
public:
	playerCard();
	~playerCard();
	void displayCard();
	void readfile();
private:
	int** diceScores;
};

