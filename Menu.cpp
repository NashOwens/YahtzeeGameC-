#include "Menu.h"
#include "string"
#include <iostream>
#include <list>
#include <algorithm>


const int MENU_EXIT = 0;
const int MENU_CHOOSE_PLAYER = 1;
const int MENU_ADD_PLAYER = 2;
const int MENU_REMOVE_PLAYER = 3;
const int MENU_SORT_ALPHABETICALLY = 4;
const int MENU_SORT_HIGHSCORE = 5;

using namespace std;

Menu::Menu(vector<Player*> players) : players(players) {};
Menu::~Menu() {};

bool sortHighscore(Player* fp, Player* sp);
bool sortAlphabet(Player* fp, Player* sp);

Menu::playerMenu::playerMenu(Player* player) : player(*player) {};
Menu::playerMenu::~playerMenu() {};



int Menu::Start()
{
	int choice;
	do
	{
		cout << "\nWelcome to Yahtzee the Game\n";
		cout << "********************************\n";
		cout << "Player Name              Highest Score\n";
		cout << "------------            ---------------\n";
		vector<Player*>::iterator it(players.begin());
		while (it != players.end()) {
			(*it++)->printSummary();
		}
		cout << "\n";
		displayMenu();
		choice = getMenuChoice();

		Player* currentPlayer = new Player("","",0);

		switch (choice)
		{
		case MENU_CHOOSE_PLAYER: *currentPlayer = selectPlayer(players); playerMenu(currentPlayer).playerStart(currentPlayer); break; // need player menu here after!!
		case MENU_ADD_PLAYER: players.push_back(addPlayer()); break;
		case MENU_REMOVE_PLAYER: players.erase(players.begin(), players.end(), selectPlayer(players)); break;// need more work here
		case MENU_SORT_ALPHABETICALLY: sort(players.begin(), players.end(), sortAlphabet); break;
		case MENU_SORT_HIGHSCORE: sort(players.begin(), players.end(), sortHighscore); break;

		default:
			break;
		}

		delete currentPlayer;

	} while (choice != MENU_EXIT);

	vector<Player*>::iterator it(players.begin());
	while (it != players.end()) {
		delete *(it++);
	}

	return 0;
};
int Menu::playerMenu::playerStart(Player* player)
{
	const int MENU_EXIT = 0;
	const int MENU_PLAY_GAME = 1;
	const int MENU_SHOW_GAME_HISTORY = 2;
	const int MENU_LOGOUT = 3;
	int choice=-1;

	while (choice != MENU_LOGOUT) 
	{
		cout << "Welcome to Yhatzee " << player->getPlayerName() << "\n----------------------";
		cout << "\n1. Start New Game\n2. Show Game History\n3. Logout\n 0. EXIT\n";

		cin >> choice;
		switch (choice) 
		{
		case MENU_PLAY_GAME: break;
		case MENU_SHOW_GAME_HISTORY: break;
		case MENU_LOGOUT: break;
		case MENU_EXIT: return 0;
		default: 
			break;
		}
	}
	return 0;
}
bool sortAlphabet(Player* fp, Player* sp)
{
	string fc = fp->getPlayerName();
	string sc = sp->getPlayerName();
	return (int(fc.at(0)) < int(sc.at(0)));
}
bool sortHighscore(Player* fp, Player* sp)
{
	return (fp->getPlayerHighScore() > sp->getPlayerHighScore());
}
Player Menu::selectPlayer(vector<Player*> players)
{
	string password;
	string playerChoice;

	cout << "Player removal\n-----------------\nEnter a player name: ";
	cin >> playerChoice;
	vector<Player*>::iterator it(players.begin());
	while (it!=players.end())//for (int i = 0; i < (int)players.size(); i++)
	{
		if ((*it)->isUserCorrect(playerChoice))
		{
			cout << "Player selected: " << (*it)->getPlayerName();
			cout << "\nEnter Password for this Player: ";
			cin >> password;
			for (int trys = 0; trys < 3; trys++) {
				if (((*it)->isPassCorrect(password)))
				{
					return *(*it);
				}
				cout << "Incorrect Password... \n Try again (" << trys << "): ";
				cin >> password;
			}
		}
		else if (it==players.end() && (*it)->isUserCorrect(playerChoice)) {
			cout << "\nNo Players found...";
		}
	}
}
void Menu::displayMenu()
{
	cout << MENU_CHOOSE_PLAYER << ". Choose Player\n";
	cout << MENU_ADD_PLAYER << ". Add Player\n";
	cout << MENU_REMOVE_PLAYER << ". Remove Player\n";
	cout << MENU_SORT_ALPHABETICALLY << ". Sort Players Alphabetically\n";
	cout << MENU_SORT_HIGHSCORE << ". Sort Players by HighScore\n";
	cout << MENU_EXIT << ". Exit\n";
}
int Menu::getMenuChoice()
{
	int choice = 0;
	cout << "Choose option: ";
	cin >> choice;
	while (choice < MENU_EXIT || choice > MENU_SORT_HIGHSCORE)
	{
		cout << "Invalid option. try again...";
		cin >> choice;
	}
	return choice;
}
Player* Menu::addPlayer()
{
	string Name, Pass;
	cout << "Enter your name: ";
	cin >> Name;
	cout << "Enter your password: ";
	cin >> Pass;
	return new Player(Name, Pass, 0);
}

//Player Menu::selectPlayer(vector<Player*> players)
//{
//	Player* player = new Player("","",0);
//	string password;
//	string playerChoice;
//
//	cout << "Enter a player name: ";
//	cin >> playerChoice;
//	for (int i = 0; i < (int)players.size(); i++)
//	{
//		if (players[i]->isUserCorrect(playerChoice))
//		{
//			cout << "Player selected: " << players[i]->getPlayerName();
//			cout << "\nEnter Password for this Player: ";
//			cin >> password;
//			for (int trys = 0; trys < 3; trys++) {
//				if ((players[i]->isPassCorrect(password)))
//				{
//					cout << "Login Successful!\n";
//					player = players[i];
//					cout << "Player Details:\n--------------\n";
//					players[i]->printSummary();
//					break;
//				}
//				cout << "Incorrect Password... \n Try again (" << trys << "): ";
//				cin >> password;
//			}
//		}
//		else if (i == players.size() && !(players[i]->isUserCorrect(playerChoice))) {
//			cout << "\nNo Players found...";
//		}
//	}
//	return *player;
//}