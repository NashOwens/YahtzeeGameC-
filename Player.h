#pragma once
#include <string>
#include <iostream>
#include <fstream>

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
	void readfile();
	void writefile();
	void displayScorecards();
	virtual bool checkifTaken(string playername);
	

	friend istream& operator>>(istream& ins, Player& target)
	{
		char c;
		ins >> target.games;
		target.diceScores = new int*[target.games+1];
		for(int i=0; i<target.games; i++)
		{
			target.diceScores[i+1] = new int[6];
			for (int j = 0; j < 6; j++)
			{
				ins >> target.diceScores[i+1][j];
				//cout << target.diceScores[i][j];
				if (j == 5) 
				{
					break;
				}
				else 
				{
					ins >> c;
				}
			}
		}
		return ins;
	};
	friend ostream& operator<<(ostream& outs, Player& source)
	{
		char c=',';
		outs << source.games << "\n";
		for (int i = 0; i < source.games; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				outs << source.diceScores[i+1][j];
				//cout << source.diceScores[i][j];
				if (!(j == 5))
				{
					outs << c;
				}
			}
			outs << "\n";
		}
		return outs;
	}
	friend istream& operator>=(istream& ins, Player& target)
	{
		getline(ins, target.playerName, ',');
		getline(ins, target.password, ',');
		ins >> target.playerHighscore;
		ins.ignore();
		return ins;
	}
	friend ostream& operator<=(ostream& outs, Player& source)
	{
		char c = ',';
		outs << source.playerName << c;
		outs << source.password << c;
		outs << source.playerHighscore << "\n";
		return outs;
	}

private:
	string playerName;
	string password;
	int playerHighscore=0;
	int** diceScores;
	int games;
};

