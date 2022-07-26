#ifndef MIDNIGHT_H
#define MIDNIGHT_H
#include "player.h"

class Midnight {
public:
	Midnight() {}
	Midnight(int numOfPlayers);
	void welcome();
	void nextPlayer();
	void reset(); 
	void displayMemory();
	void displayWinnings(); 
	~Midnight();
private:
	Player* player;
	int m_numOfPlayers;
	int gamesPlayed; 
	int index; 
	bool choice; 
};
#endif // !MIDNIGHT_H

