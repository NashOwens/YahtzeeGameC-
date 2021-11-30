#include "Game.h"
#include "Dice.h"
#include "Player.h"
#include <iostream>

using namespace std;

Game::Game() : dices(nullptr), round(1) {};
Game::~Game() {};

void Game::Start()
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
		cout << "\n" << rollsLeft << " Rolls left..." << "\n\n1. Roll Dice Again\n2. Select Dice\n3. Confirm dice + Next round\n0. Exit\n";
		cin >> input;
		switch (input)
		{
			case 1: if (rollsLeft != 0) { rollsLeft--; rollDice(); } break;
			case 2: selectDice(); break;
			case 3: nextRound(); rollDice(); rollsLeft = 3; break;
			case 0: delete[] dices; delete[] Score;
			default: break;
		}
		//put stuff here
	} while (input != 0 && round !=8);
};
void Game::rollDice()
{
	for (int i = 0; i < 5; i++)
	{
		int max = 6;
		int min = 1;
		dices[i].genNumber();
	}
}
void Game::selectDice()
{
	cout << "\nChoose which Dice to select(Enter 0 to return): ";
	int choice;
	cin >> choice;
	choice -= 1;
	int dice = dices[choice].getDiceValue();
	do {
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
	} while (choice != 0 && choice>-1);
}
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