#pragma once
#include <stdlib.h>
class Dice
{
public:
	Dice();
	~Dice();
	inline int getDiceValue() { return dice; };
	inline void select() { isSelected = true; };
	inline void deSelect() { isSelected = false; };
	inline bool isDiceSelected() { return isSelected; };
	void genNumber();
private:
	int dice;
	bool isSelected;
};

