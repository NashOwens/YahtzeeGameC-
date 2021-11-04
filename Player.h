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
	const string getPlayerName() const { return playerName; };
	int getPlayerHighScore() const { return playerHighscore; };
	virtual bool isPassCorrect(string password);
protected:
	string getPassword() { return password; };

private:
	string playerName;
	string password;
	int playerHighscore=0;
};

