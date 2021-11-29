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
	Score = new int[5];
	rollDice();
	int input;
	do {
		cout << "Yahtzee Game\n----------------\nRound: " << this->round << "\nDice scores: \n";

		for (int i = 0; i < 5; i++) // Iterator for displaying dice
		{
			cout << "\nDice " << i + 1 << ": " << Score[i] << "\n";
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

		cout << "\n\n1. \n2. \n0. Exit\n";
		cin >> input;
		switch (input)
		{
			case 1: rollDice(); break;
			case 2: selectDice(); break;
			case 3: nextRound(); break;
			case 0: delete[] dices; delete[] Score;
			default: break;
		}

		//put stuff here
	} while (input != 0);

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
	cout << "\nChoose which dice: ";
	int choice;
	cin >> choice;
	choice -= 1;
	if (0 < choice < 6) {
		if (!dices[choice].isDiceSelected())
		{
			dices[choice].select();
		}
		else if (dices[choice].isDiceSelected())
		{
			dices[choice].deSelect();
		}
	}
}
void Game::nextRound()
{

}