#include <iostream>
#include "Player.h"
#include "Menu.h"
#include <list>
#include <vector>
#include <fstream>
#include "playerCard.h"

using namespace std;

vector<Player*> readFile(string file_name);


int main() 
{

	#ifdef _DEBUG
		//  _CrtSetBreakAlloc(87);
		_onexit(_CrtDumpMemoryLeaks);
	#endif

	vector<Player*> playerData = readFile("PlayerDetails.txt");

	return Menu(playerData).Start();
}
vector<Player*> readFile(string file_name)
{
	vector<Player*> players;
	ifstream file;
	file.open(file_name);
	for (int i = 0; i < 5; i++)
	{
		players.push_back(new Player("", "", 0));
		file >= *players[i];
	}
	file.close();
	return players;
}

