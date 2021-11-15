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
	
	class playerMenu {
	public:
		playerMenu();
		~playerMenu();
		int playerStart(Player* player);
	private:
	};

private:
	vector<Player*> players;

};

