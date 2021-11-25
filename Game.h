#pragma once
class Game
{
public:
	Game(int** diceScores);
	~Game();
	class Dice
	{
	public:
		Dice();
		~Dice();
		int selectDice(int i) { return dice[i]; };
	private:
		int* dice;
		bool isSelected;
	};
private:
	int** tempScore;
	int round;
};

