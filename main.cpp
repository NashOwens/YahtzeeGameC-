#include <iostream>
#include "Player.h"
#include "Menu.h"
#include <list>
#include <vector>
#include <fstream>

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
	string name, password, highScore;

	while (getline(file, name, ','))
	{
		getline(file, password, ',');
		getline(file, highScore);
		players.push_back(new Player(name, password, std::stoi(highScore)));
	}
	file.close();
	return players;
}
