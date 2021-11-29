#include <iostream>
#include "Player.h"
#include "Menu.h"
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include "playerCard.h"

using namespace std;

int main() 
{

	#ifdef _DEBUG
	//	_CrtSetBreakAlloc(318);
		_onexit(_CrtDumpMemoryLeaks);
	#endif

	return Menu().Start();
}
//vector<Player*> readFile(string file_name)
//{
//	vector<Player*> players;
//	ifstream file;
//	file.open(file_name);
//	for (int i = 0; i < file.get(); i++)
//	{
//		players.push_back(new Player("", "", 0));
//		file >= *players[i];
//	}
//	players.erase(players.begin() + 0);
//	file.close();
//	return players;
//}

