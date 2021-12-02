#pragma once
#include <stdlib.h>
class Dice
{
public:
	Dice();
	~Dice();

	inline void select() { isSelected = true; };
	inline void deSelect() { isSelected = false; };
	void genNumber();

	inline int getDiceValue() { return dice; };
	
	inline virtual bool isDiceSelected() { return isSelected; };
	
private:
	int dice;
	bool isSelected;
};

