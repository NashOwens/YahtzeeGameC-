#pragma once
#include "Player.h"
#include <vector>

class Menu
{
public:
	Menu() = default;
	Menu(vector<Player*> players);
	~Menu();
	int Start();
	void displayMenu();
	int getMenuChoice();
	Player* addPlayer();
	Player* selectPlayer();

	friend istream& operator>>(istream& ins, Player* target);
	
	class playerMenu {
	public:
		playerMenu();
		~playerMenu();
		int playerStart(Player* player);
	};

private:
	vector<Player*> players;

};

