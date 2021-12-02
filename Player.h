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

	void printSummary() const;
	void readfile();
	void writefile();
	void displayScorecards();
	void addGametoScorecard(int* gameScore);

	inline string getPlayerName() { return playerName; };
	inline int getPlayerHighScore() { return playerHighscore; };

	inline void setHighScore(int highscore) { playerHighscore = highscore; };

	virtual bool isPassCorrect(string password);
	virtual bool isUserCorrect(string user);
	virtual bool checkifTaken(string playername);

	//could not find a way to get op overloading in cpp file so left in header.
	//used 2 different op overloading one for player Score cards and one for 
	//player details.

	inline friend istream& operator>>(istream& ins, Player& target)
	{
		char c;
		ins >> target.games;						//first number in file is num of games
		target.diceScores = new int*[target.games+30];  //create space for 30 games in one
		for(int i=0; i<target.games; i++)				//program instance
		{
			target.diceScores[i] = new int[6];			//allocates memory for data store
			for (int j = 0; j < 6; j++)
			{
				ins >> target.diceScores[i][j];
				if (j == 5) 
				{
					break;
				}
				else 
				{
					ins >> c;					//absorbs the comma
				}
			}
		}
		return ins;
	};
	inline friend ostream& operator<<(ostream& outs, Player& source)
	{
		char c=',';
		outs << source.games << "\n";			//number of games at start of file
		for (int i = 0; i < source.games; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				outs << source.diceScores[i][j];	//stores dice scores in file
				if (!(j == 5))
				{
					outs << c;				//reapplys the comma in txt file
				}
			}
			outs << "\n";
		}
		return outs;
	}

	//reads and writes player info to the playerinfo file

	inline friend istream& operator>=(istream& ins, Player& target)
	{
		getline(ins.ignore(), target.playerName, ',');
		getline(ins, target.password, ',');
		ins >> target.playerHighscore;
		return ins;
	}
	inline friend ostream& operator<=(ostream& outs, Player& source)
	{
		char c = ',';
		outs << source.playerName << c;
		outs << source.password << c;
		outs << source.playerHighscore << "\n";
		return outs;
	}

private:
	string playerName="";
	string password="";
	int playerHighscore=0;
	int** diceScores=nullptr;
	int games=0;
};

