#pragma once
#include <string>

using namespace std;

class Player
{
public:
	Player(string PlayerName, string password, int playerHighscore);
	~Player();
	void printSummary();
	string getPlayerName() { return playerName; };
	int getPlayerHighScore() { return playerHighscore; };
	virtual bool isPassCorrect(string password);
	virtual bool isUserCorrect(string user);

protected:
	string getPassword() { return password; };

private:
	string playerName;
	string password;
	int playerHighscore=0;
};

