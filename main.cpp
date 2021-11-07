#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

const int MENU_EXIT					= 0;
const int MENU_CHOOSE_PLAYER		= 1;
const int MENU_ADD_PLAYER			= 2;
const int MENU_REMOVE_PLAYER		= 3;
const int MENU_SORT_ALPHABETICALLY	= 4;
const int MENU_SORT_HIGHSCORE		= 5;
const int NO_OF_ACCOUNTS			= 3;


void displayMenu();
int getMenuChoice();
void displayPlayers();


int main() {

	#ifdef _DEBUG
		//  _CrtSetBreakAlloc(87);
		_onexit(_CrtDumpMemoryLeaks);
	#endif

		Player* players[NO_OF_ACCOUNTS] =
		{
			new Player("Nash Owens-kerr", "nash", 0),
			new Player("John Smith", "John", 0),
			new Player("Testing", "Test", 0)
		};

		int choice;

		Player currentPlayer = Player();

		do 
		{
			cout << "\nWelcome to Yahtzee the Game\n";
			cout << "********************************\n";
			cout << "Player Name              Hishest Score\n";
			cout << "------------            ---------------\n";
			for (int i = 0; i < NO_OF_ACCOUNTS; i++)
				players[i]->printSummary();
			displayMenu();
			choice = getMenuChoice();

			switch (choice)
			{
			case MENU_CHOOSE_PLAYER: currentPlayer = selectPlayer(*players); break;

			default:
				break;
			}
		} while (choice != MENU_EXIT);

		for (int i = 0; i < NO_OF_ACCOUNTS; i++)
			delete players[i];


	return 0;
}
void displayMenu() 
{
	cout << MENU_CHOOSE_PLAYER << ". Choose Player\n";
	cout << MENU_ADD_PLAYER << ". Add Player\n";
	cout << MENU_REMOVE_PLAYER << ". Remove Player\n";
	cout << MENU_SORT_ALPHABETICALLY << ". Sort Players Alphabetically\n";
	cout << MENU_SORT_HIGHSCORE << ". Sort Players by HighScore\n";
	cout << MENU_EXIT << ". Exit\n";
}
int getMenuChoice() 
{
	int choice=0;
	cout << "Choose option: ";
	cin >> choice;
	while (choice < MENU_EXIT || choice > MENU_SORT_HIGHSCORE)
	{
		cout << "Invalid option. try again...";
		cin >> choice;
	}
	return choice;
}
Player selectPlayer(Player* players) 
{
	Player player;
	string password;
	string playerChoice;

	cout << "Enter a player name: ";
	cin >> playerChoice;
	for (int i = 0; i < NO_OF_ACCOUNTS; i++)
	{
		cout << players->getPlayerName();
			if (players->isUserCorrect(playerChoice) && i < NO_OF_ACCOUNTS)
			{
				cout << "Player selected: " << players[i].getPlayerName();
				cout << "\nEnter Password for this Player: ";
				cin >> password;
				for (int trys = 0; trys < 3; trys++) {
					cout << "Incorrect Password... \n Try again (" << trys << "): ";
					cin >> password;
					if ((players->isPassCorrect(password)))
					{
						cout << "Login Successful!\n";
						player.printSummary();
					}
				}
			}
			else {
				cout << "Incorrect";
			}
	}
	return player;
}