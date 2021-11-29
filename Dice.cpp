#include "Dice.h"

Dice::Dice() : dice(0), isSelected(false) {}
Dice::~Dice() {}

void Dice::genNumber()
{
	int max = 6;
	int min = 1;
	dice = rand() % (max - min + 1) + min;
}
