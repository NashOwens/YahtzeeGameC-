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
	void readPlayers();
	

	friend istream& operator>>(istream& ins, Player& target)
	{
		char c;
		ins >> target.games;
		target.diceScores = new int*[target.games+1];
		for(int i=1; i<target.games+1; i++)
		{
			target.diceScores[i] = new int[6];
			for (int j = 0; j < 6; j++)
			{
				ins >> target.diceScores[i][j];
				cout << target.diceScores[i][j];
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
		for (int i = 1; i < source.games+1; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				outs << source.diceScores[i][j];
				cout << source.diceScores[i][j];
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
		return ins;
	}

private:
	string playerName;
	string password;
	int playerHighscore=0;
	int** diceScores;
	int games;
};

