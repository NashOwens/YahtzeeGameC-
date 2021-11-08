#include <iostream>
#include <string>
#include "Player.h"
#include <list>
#include <iterator>
#include <vector>
#include <algorithm>

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
Player addPlayer();
Player selectPlayer(vector<Player*> players);
Player removePlayer(vector<Player*> players);
bool sortHighscore(Player* player, Player* secondplayer);


int main() {

	#ifdef _DEBUG
		//  _CrtSetBreakAlloc(87);
		_onexit(_CrtDumpMemoryLeaks);
	#endif

		int choice;

		vector<Player*> playerData;
		playerData.push_back(new Player("Testing", "Test", 1));
		playerData.push_back(new Player("lmao", "lmao", 25));
		playerData.push_back(new Player("nash", "nash", 50));

		Player currentPlayer = Player("Guest", "123", 0);

		do 
		{
			cout << "\nWelcome to Yahtzee the Game\n";
			cout << "********************************\n";
			cout << "Player Name              Hishest Score\n";
			cout << "------------            ---------------\n";
			for (int i = 0; i < playerData.size(); ++i)
				playerData[i]->printSummary();
			//for_each(playerData.begin(), playerData.end(), displayPlayer(playerData));
			displayMenu();
			choice = getMenuChoice();

			switch (choice)
			{
			case MENU_CHOOSE_PLAYER: currentPlayer = selectPlayer(playerData); currentPlayer.printSummary(); break;
			case MENU_ADD_PLAYER: playerData.push_back(new Player(addPlayer()));   break;
			case MENU_REMOVE_PLAYER: playerData.clear();// need more work here
			case MENU_SORT_HIGHSCORE: sort(playerData.begin(), playerData.end(), sortHighscore); break;


			default:
				break;
			}
		} while (choice != MENU_EXIT);

		for (int i = 0; i > playerData.size(); i++)
		{
			delete playerData[i];
		}


	return 0;
}
bool sortHighscore(Player* firstplayer, Player* secondplayer) 
{
	if (firstplayer->getPlayerHighScore() > secondplayer->getPlayerHighScore())
	{
		firstplayer->printSummary();
		return true;
	}
	return false;
}
void displayPlayer(Player* players) 
{
	players->printSummary();
}
Player removePlayer(vector<Player*> players) 
{
	Player x;
	string password;
	string playerChoice;

	cout << "Player removal\n-----------------\nEnter a player name: ";
	cin >> playerChoice;
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i]->isUserCorrect(playerChoice))
		{
			cout << "Player selected: " << players[i]->getPlayerName();
			cout << "\nEnter Password for this Player: ";
			cin >> password;
			for (int trys = 0; trys < 3; trys++) {
				if ((players[i]->isPassCorrect(password)))
				{	
					x = *players[i];
					return x;
				}
				cout << "Incorrect Password... \n Try again (" << trys << "): ";
				cin >> password;
			}
		}
		else if (i == players.size() - 1 && !(players[i]->isUserCorrect(playerChoice))) {
			cout << "\nNo Players found...";
		}
	}
	return x;
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
Player addPlayer() 
{
	string Name, Pass;
	cout << "Enter your name: ";
	cin >> Name;
	cout << "Enter your password: ";
	cin >> Pass;
	return Player(Name, Pass, 0);
}

Player selectPlayer(vector<Player*> players) 
{
	Player player;
	string password;
	string playerChoice;

	cout << "Enter a player name: ";
	cin >> playerChoice;
	for (int i = 0; i < players.size(); i++)
	{	
		if (players[i]->isUserCorrect(playerChoice))
		{
			cout << "Player selected: " << players[i]->getPlayerName();
			cout << "\nEnter Password for this Player: ";
			cin >> password;
			for (int trys = 0; trys < 3; trys++) {
				if ((players[i]->isPassCorrect(password)))
				{
					cout << "Login Successful!\n";
					player = *players[i];
					cout << "Player Details:\n--------------\n";
					break;
					// Add game initiation sequence here!
				}
				cout << "Incorrect Password... \n Try again (" << trys << "): ";
				cin >> password;
			}
		}
		else if (i == players.size() -1 && !(players[i]->isUserCorrect(playerChoice))){
			cout << "\nNo Players found...";
		}
	}
	return player;
}