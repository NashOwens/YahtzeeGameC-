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
	void displayPlayer(Player* players);
	Player* addPlayer();
	Player* selectPlayer(vector<Player*> players);
	
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

