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
	class playerMenu {
	public:
		playerMenu(Player* player);
		~playerMenu();
		int playerStart(Player* player);
	private:
		Player player;
	};
private:
	vector<Player*> players;

};

