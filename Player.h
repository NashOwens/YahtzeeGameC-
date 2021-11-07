#pragma once
#include <string>

using namespace std;

class Player
{
public:
	Player() = default;
	Player(string PlayerName, string password, int playerHighscore);
	~Player();
	void printSummary();
	string getPlayerName() { return playerName; };
	int getPlayerHighScore() const { return playerHighscore; };
	virtual bool isPassCorrect(string password);
	virtual bool isUserCorrect(string user);

	string playerName;
protected:
	string getPassword() { return password; };

private:

	string password;
	int playerHighscore=0;
};

