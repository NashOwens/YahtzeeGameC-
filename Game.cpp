#include "Game.h"
#include "Dice.h"
#include "Player.h"
#include <iostream>

using namespace std;

Game::Game() : dices(nullptr), round(1) {};
Game::~Game() {};

//starts the yhatzee game:

void Game::Start(Player* player)
{

	dices = new Dice[5]; // declaring how many dice there are
	Score = new int[6]{ 0,0,0,0,0,0 };
	rollDice();
	int input;
	int rollsLeft = 3;
	do {
		cout << "Yahtzee Game\n----------------\nRound: " << this->round << "\nDice scores: \n";

		for (int i = 0; i < 6; i++) // Iterator for displaying dice
		{
			if (Score[i] == 0)
			{
				cout << "\nDice " << (i + 1) << ": " << Score[i] << "\n";
			}
		}; // setting new dice to use

		cout << "\n -------------------\nDices rolls:\n";

		//shows the currently selected dice with () in the game:

		for (int i = 0; i < 5; i++)	
		{
			if (dices[i].isDiceSelected())
			{
				cout << "  (" << dices[i].getDiceValue() << ")  ";
			}
			else {
				cout << "  " << dices[i].getDiceValue() << "  ";
			}
		}

		//game menu:

		cout << "\n" << rollsLeft << " Rolls left..." << "\n\n1. Roll Dice Again\n2. Select Dice\n3. Confirm dice + Next round\n0. Exit\n";
		cin >> input;
		switch (input)
		{
			case 1: if (rollsLeft != 0) { rollsLeft--; rollDice(); } break;
			case 2: selectDice(); break;
			case 3: nextRound(); rollDice(); rollsLeft = 3; break;
			default: break;
		}
	} while (input != 0 && round !=7);

	//once game is completed below is executed:

	if (round == 7)
	{
		int highScore=0;
		for (int i = 0; i < 6; i++)
		{
			highScore += Score[i];
		}
		cout << "\nGame Finished!!!\n\n Your Score: " << highScore <<"\n\n";
		if (player->getPlayerHighScore() < highScore)
		{
			player->setHighScore(highScore);
			cout << "\n\nNew HighScore!!!\n\n";			//sets new highscore
		}
		player->addGametoScorecard(Score);
	
		delete[] dices;
		delete[] Score;
	}
};

//rolls all 5 dice when called

void Game::rollDice()
{
	for (int i = 0; i < 5; i++)
	{
		int max = 6;
		int min = 1;
		dices[i].genNumber();	// generates a random int between 0-7
	}
}

//painful way of doing it but this stops different dice values being selected at once

void Game::selectDice()
{
	cout << "\nChoose which Dice to select(Enter 0 to return): ";
	int choice;
	cin >> choice;
	choice -= 1;
	int dice = dices[choice].getDiceValue();
	do {
		if (choice+1 == 0)
		{
			break;
		}
		if (!dices[choice].isDiceSelected() && (dices[choice].getDiceValue()==dice))
		{
			dices[choice].select();
			cout << "\nDice " << choice+1 << " Selected!\n\n";
		}
		else if (dices[choice].isDiceSelected())
		{
			dices[choice].deSelect();
			cout << "\nDice " << choice+1 << " deSelected!\n\n";
		}
		else 
		{			
			cout << "\n\nPlease select dice of the same value...\n";
		}
		cout << "\nChoose which Dice to select(Enter 0 to return): ";
		cin >> choice;
		choice = choice - 1;
	} while ((choice != 0) && choice>-1);
	
}

//progresses the game a round once confirmed

void Game::nextRound()
{
	int tempDice=0;
	round++;
	for (int i = 0; i < 5; i++)
	{
		if (dices[i].isDiceSelected())
		{
			dices[i].deSelect();
			int dice = dices[i].getDiceValue()-1;
			tempDice = tempDice + dices[i].getDiceValue();
			Score[dice] = tempDice;
		}
	}
}