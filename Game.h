#pragma once
#include "Player.h"
#include "Dice.h"

class Game
{
public:
	Game();
	~Game();

	void Start(Player* player);
	void rollDice();
	void selectDice();
	void nextRound();
	
private:
	Dice* dices;
	int* Score;
	int round;
};

