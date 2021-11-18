#pragma once
#include <cstddef>
//#include <istream>
class playerCard
{
public:
	playerCard();
	~playerCard();
	void readfile(int index);
	void writefile();
	int** getdiceScores() { return diceScores; };
private:
	int** diceScores;
};

