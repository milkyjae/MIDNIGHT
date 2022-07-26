#include "midnight.h"

Midnight::Midnight(int numOfPlayers) {
	index = 0;
	gamesPlayed = 1;
	choice = true;
	m_numOfPlayers = numOfPlayers;
	player = new Player[m_numOfPlayers];
	for (int i = 0; i < m_numOfPlayers; i++) {
		player[i].matchPoints = 0;
		player[i].totalWins = 0;
		player[i].numOfRolls = 6;
		for (int j = 0; j < 2; j++) {
			player[i].qualifiers[j] = 0;
		}
		for (int j = 0; j < 6; j++) {
			player[i].dice[j] = 0;
		}
	}
}

Midnight::~Midnight() {
	delete[]player;
}

void Midnight::reset() {
	index = 0;
	gamesPlayed = 1;
	choice = true;
	player = new Player[m_numOfPlayers];
	for (int i = 0; i < m_numOfPlayers; i++) {
		player[i].matchPoints = 0;
		player[i].totalWins = 0;
		player[i].numOfRolls = 6;
		for (int j = 0; j < 2; j++) {
			player[i].qualifiers[j] = 0;
		}
		for (int j = 0; j < 6; j++) {
			player[i].dice[j] = 0;
		}
	}
}

// sort of my main function right now 

void Midnight::welcome() {
	for (int i = 0; i < m_numOfPlayers; i++) {
		index = i + 1; 
		cout << "Enter Player " << index << "'s name: ";
		player[i].storeName();
	}
	//displayMemory();

	cout << "Game " << gamesPlayed << "! " << endl;
	nextPlayer();
	//  displayWinnings();

	cout << "Would you like to play again? (1 for Yes / 0 for No)";
	cin >> choice;
	if (choice == 1) {
		reset();
		displayMemory();
		nextPlayer();
	}
	else {
		// main menu 
	}
}

void Midnight::nextPlayer() {
	//cout << "nextPlayer(): called; ";

	for (int i = 0; i < m_numOfPlayers; i++) {
		gamesPlayed++;
		if (player[i].numOfRolls == 6) {
			cout << player[i].name << "'s roll ..." << endl << endl;
			player[i].roll();
		}
	}
}

void Midnight::displayWinnings() {
	for (int i = 0; i < m_numOfPlayers; i++) {
		for (int j = i + 1; j < m_numOfPlayers; j++) {
			if (player[j].matchPoints > player[i].matchPoints) {
				int temp = player[i].matchPoints;
				player[i].matchPoints = player[j].matchPoints;
				player[j].matchPoints = temp;

				string temp2 = player[i].name;
				player[i].name = player[j].name;
				player[j].name = temp2;

				int temp3 = player[i].totalWins;
				player[i].totalWins = player[j].totalWins;
				player[j].totalWins = temp3;
			}
		}
	}
	for (int i = 0; i < m_numOfPlayers; i++) {
		index = i + 1;
		cout << index << "st place: " << player[i].name << ", " << player[i].matchPoints << " points." << endl;
	}

}



void Midnight::displayMemory() {
	cout << "Allocated Memory: " << endl;
	for (int i = 0; i < m_numOfPlayers; i++) {
		cout << "NAME:         " << player[i].name << ": " << &player[i].name << endl;
		cout << "MATCH POINTS: " << player[i].matchPoints << ": " << &player[i].matchPoints << endl;
		cout << "TOTAL WINS:   " << player[i].totalWins << ": " << &player[i].totalWins << endl;
		cout << "ROLLS:        " << player[i].numOfRolls << ": " << &player[i].numOfRolls << endl << endl;
		cout << "QUALIFERS:    " << endl;
		for (int j = 0; j < 2; j++) {
			cout << player[i].qualifiers[j] << ": " << &player[i].qualifiers[j] << endl;
		}
		cout << endl << "DICE:" << endl;
		for (int j = 0; j < player[i].numOfRolls; j++) {
			cout << player[i].dice[j] << ": " << &player[i].dice[j] << endl;
		}
	}
	
}