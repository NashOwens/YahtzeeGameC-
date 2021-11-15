#pragma once
#include <string>

using namespace std;

class Player
{
public:
	Player(string PlayerName, string password, int playerHighscore);
	~Player();
	virtual void printSummary() const;
	string getPlayerName() { return playerName; };
	int getPlayerHighScore() { return playerHighscore; };
	virtual bool isPassCorrect(string password);
	virtual bool isUserCorrect(string user);

private:
	string playerName;
	string password;
	int playerHighscore=0;
};
class Scorecard : Player
{
public:
	//Scorecard(string PlayerName, string password, int playerHighscore)
};

