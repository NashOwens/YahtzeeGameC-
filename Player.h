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
	

	friend istream& operator>>(istream& ins, Player& target)
	{
		char c;
		int length = filelength();
		for(int i=0; i<length; i++)
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
		//for (int j = 0; j < 11; j++)
		//{
		//	for (int i = 0; i < 2; i++)
		//	{
		//		outs << source.diceScores[i][j] << c;
		//		cout << source.diceScores[i][j];
		//	}
		//}
		return outs;
	}
	static int filelength() 
	{
		ifstream file;
		file.open("playerCards.txt");
		string temp;
		int counter=0;
		while (getline(file, temp, ','))
		{
			for (int i = 0; i < 4; i++)
			{
				getline(file, temp, ',');
			}
			getline(file, temp);
			counter++;
		}
		file.close();
		return counter;
	}

private:
	string playerName;
	string password;
	int playerHighscore=0;
	int** diceScores = new int*[filelength()];
	int ones, twos, threes, fours, fives, sixes;
};

