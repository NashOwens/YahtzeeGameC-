#include "Menu.h"
#include "playerCard.h"
#include <string>
#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>



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

int counter;

Menu::playerMenu::playerMenu() {};
Menu::playerMenu::~playerMenu() {};



int Menu::Start()
{
	readFile("PlayerDetails.txt");
	int choice;
	do
	{
		cout << "\nWelcome to Yahtzee the Game\n";
		cout << "********************************\n";
		cout << "Player Name              Highest Score\n";
		cout << "------------            ---------------\n";
		vector<Player*>::iterator it(players.begin());
		while (it != players.end()) 
		{
			(*it++)->printSummary();
		}
		cout << "\n";
		displayMenu();
		choice = getMenuChoice();

		switch (choice)
		{
		case MENU_CHOOSE_PLAYER: { try { playerMenu().playerStart(selectPlayer()); } catch (string* error) { cout << *error; delete error; } break; }
		case MENU_ADD_PLAYER: { try { players.push_back(addPlayer()); } catch (string* error) { cout << *error; delete error; } break; }
		case MENU_REMOVE_PLAYER: { try { removePlayer(); } catch (string* error) { cout << *error; delete error; } break; }
		case MENU_SORT_ALPHABETICALLY: sort(players.begin(), players.end(), sortAlphabet); break;
		case MENU_SORT_HIGHSCORE: sort(players.begin(), players.end(), sortHighscore); break;
		case MENU_EXIT: writeFile("PlayerDetails.txt");
		default:
			break;
		}

	} while (choice != MENU_EXIT);
	vector<Player*>::iterator it(players.begin());
	while (it != players.end()) 
	{
		delete *(it++);
	}
	return 0;
}
void Menu::readFile(string file_name)
{
	ifstream file;
	file.open(file_name);
	file >> amountofPlayers;
	for (int i = 0; i < amountofPlayers; i++)
	{
		players.push_back(new Player(".", ".", 0));
		file >= *players[i];
	}
	file.close();
}
void Menu::writeFile(string file_name)
{
	ofstream file;
	file.open(file_name);
	file << amountofPlayers << "\n";
	for (int i = 0; i < amountofPlayers; i++)
	{
		file <= *players[i];
	}
	file.close();
}
void Menu::removePlayer()
{
	int count = 0;
	Player* temp = selectPlayer();
	vector<Player*>::iterator it(players.begin());
	while (it != players.end())
	{
		if (temp == (*it))
		{
			players.erase(players.begin() + count);
			cout << "\nPlayer removed successfully!!\n";
			delete temp;
			amountofPlayers--;
			break;
		}
		else
		{
			count++;
		}
		it++;
	}
}
int Menu::playerMenu::playerStart(Player* player)
{
	player->readfile();
	const int MENU_PLAY_GAME = 1;
	const int MENU_SHOW_GAME_HISTORY = 2;
	const int MENU_LOGOUT = 3;
	int choice=-1;


	while (choice != MENU_LOGOUT) 
	{
		cout << "\n\nWelcome to Yhatzee " << player->getPlayerName() << "\n----------------------";
		cout << "\n1. Start New Game\n2. Show Game History\n3. Logout\nOption: ";

		cin >> choice;
		switch (choice) 
		{
		case MENU_PLAY_GAME: break;
		case MENU_SHOW_GAME_HISTORY: player->displayScorecards(); break;
		case MENU_LOGOUT: player->writefile();
		default: break;
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
Player* Menu::selectPlayer()
{
	string password;
	string playerChoice;

	cout << "Player selection\n-----------------\nEnter a player name: ";
	cin >> playerChoice;
	vector<Player*>::iterator it(players.begin());
	while (it!=players.end())
	{
		if ((*it)->isUserCorrect(playerChoice))
		{
			cout << "Player selected: " << (*it)->getPlayerName();
			cout << "\nEnter Password for this Player: ";
			cin >> password;
			for (int trys = 0; trys < 3; trys++) 
			{
				if (((*it)->isPassCorrect(password)))
				{
					return (*it);
				}
				cout << "Incorrect Password... \n Try again (" << trys +1 << "): ";
				cin >> password;
			}
		}
		it++;
		counter++;
	}
	string* error = new string("\nNo Players found...\n");
 	throw error;
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
	string Name;
	string Pass;
	cout << "Enter your name: ";
	cin >> Name;
	vector<Player*>::iterator it(players.begin());
	while (it!=players.end())
	{
		if ((*it++)->checkifTaken(Name))
		{
			string* error = new string("\nUsername Taken!\n");
			throw error;
		}
	}
	cout << "Username valid!\n" << "Enter your password: ";
	cin >> Pass;
	amountofPlayers++;
	return new Player(Name, Pass, 0);
}
