#include <iostream>
#include "Player.h"
#include "Menu.h"
#include <list>
#include <vector>

using namespace std;

int main() {

	#ifdef _DEBUG
		//  _CrtSetBreakAlloc(87);
		_onexit(_CrtDumpMemoryLeaks);
	#endif

	vector<Player*> playerData;
	playerData.push_back(new Player("testing", "test", 1));
	playerData.push_back(new Player("lmao", "lmao", 25));
	playerData.push_back(new Player("xyz", "xyz", 75));
	playerData.push_back(new Player("nash", "nash", 50));
	playerData.push_back(new Player("abc", "abc", 100));
		
	return Menu(playerData).Start();
}