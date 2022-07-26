#include "midnight.h"

int main() {
	int players = 0;
	cout << "No more than 4 players allowed: "; 
	cin >> players;

	Midnight Play(players);
	Play.welcome();
}