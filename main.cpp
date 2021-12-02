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
		//_CrtSetBreakAlloc(311);
		_onexit(_CrtDumpMemoryLeaks);
	#endif

		srand(time(nullptr)); //better randomness

		//Menu.start launches the program

	return Menu().Start();
}

