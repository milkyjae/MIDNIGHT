#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

using std::cout;
using std::cin;
using std::endl;
using std::string;

using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;

struct Player{
	int numOfRolls;
	int matchPoints;
	int totalWins;
	int qualifiers[2];
	int dice[6];
	int dieValue;
	int element;
	string name;

	Player() {
		dieValue = 0;
		element = 0;
	}
	string storeName();
	int roll();
	int qualify1();
	int qualify4();
	void displayScore();
	int select();
	
};

#endif