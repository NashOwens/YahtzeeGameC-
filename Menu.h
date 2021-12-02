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
	int getMenuChoice();

	void displayMenu();
	void removePlayer();
	void readFile(string);
	void writeFile(string);

	Player* addPlayer();
	Player* selectPlayer();

	//used a subclass for identification purposes, not using it for its
	//intended purpose just to clarify

	class playerMenu {
	public:
		playerMenu();
		~playerMenu();
		int playerStart(Player* player);
	};

private:
	vector<Player*> players;
	int amountofPlayers;

};

