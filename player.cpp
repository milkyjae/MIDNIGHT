#include "player.h"



string Player::storeName() {
	cin >> name;
	return name;
}

int Player::roll() {
	srand(time(NULL));
	for (int i = 0; i < numOfRolls; i++) {
		dieValue = rand() % 6 + 1;
		dice[i] = dieValue;
	}
	if (qualifiers[0] == 0 && qualifiers[1] == 0) {
		qualify1();
		qualify4();
	}
	else if (qualifiers[0] == 1 && qualifiers[1] == 0) {
		qualify4();
	}
	else if (qualifiers[0] == 0 && qualifiers[1] == 4) {
		qualify1();
	}
	else if (qualifiers[0] == 1 && qualifiers[1] == 4) {}
	
	displayScore();
	return numOfRolls;
}

int Player::qualify1() {
	for (int i = 0; i < numOfRolls; i++) {
		if (dice[i] == 1) {
			qualifiers[0] = 1;
			cout << name << " rolled a One!" << endl;
			for (int j = i; j < numOfRolls; j++) {
				dice[j] = dice[j + 1];
			}
			numOfRolls--;
			break;
		}
	}
	return numOfRolls;
}

int Player::qualify4() {
	for (int i = 0; i < numOfRolls; i++) {
		if (dice[i] == 4) {
			qualifiers[1] = 4;
			cout << name << " rolled a Four!" << endl;
			for (int j = i; j < numOfRolls; j++) {
				dice[j] = dice[j + 1];
			}
			numOfRolls--;
			break;
		}
	}
	return numOfRolls;
}
void Player::displayScore() {
	if (matchPoints != 0) {
		cout << "Match Points: " << matchPoints << endl;
	}
	if ( numOfRolls != 0) {
		cout << "Qualifiers: ";
		for (int i = 0; i < 2; i++) {
			cout << qualifiers[i] << " ";
		}
		cout << endl << "Numer of rolls left: " << numOfRolls << endl;
		cout << "Dice left on the table: ";
		for (int i = 0; i < numOfRolls; i++) {
			cout << dice[i] << " ";
		}
		cout << endl;
		cout << "Select dice to add to your score or 0 (zero) to roll again: ";
		select();
	}
}
int Player::select() {
	cin >> element;
	cout << endl;
	if (numOfRolls != 0) {
		for (int i = 0; i < numOfRolls; i++) {
			if (dice[i] == element) {
				matchPoints += element;
				for (int j = i; j < numOfRolls - 1; ++j) {
					dice[j] = dice[j + 1];
				}
				numOfRolls--;
				displayScore();
			}
			else if (element == 0) {
				roll();
			}
			else if (element == 9) {
				return 0;
			}
		}
	}
	return numOfRolls;
};