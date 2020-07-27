#include "Player.h"
#include <random>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  //srand(time(NULL));
	int max = 0;
	double money, bet = 0;
	char choice;
	//Asked for input values to play with
	
	do {
		cout << "Enter number of values for wheel (6 - 20): ";
		cin >> max;
	} while (max < 6 || max > 20);

	do {
		cout << "How much money do you have? ";
		cin >> money;
	} while (money <= 0);

	Wheel playerWheel(max);
	Player player(money, playerWheel);
	Wheel house(max);
	//Asked for input of money willing to put up for gambling
	//With a statement to check if user has enouhg money to bet	
	do {
		cout << "Enter your bet: ";
		cin >> bet;
		
		while (bet > player.getPlayerMoney()) {
			cout << "Invalid bet. Enter a new bet :";
			cin >> bet;
		}
 	   //output rolls and asked how they wanted to continue

		player.setNumberOutput();
		cout << "You rolled a " << player.getNumberOutput() << endl;

		cout << "Do you want to (d)ouble, (h)alf, or (k)eep your bet? ";
	  cin >> choice;
		int firstNum = house.spin(), secondNum = house.spin();
    while (choice == 'd' && bet * 2 > player.getPlayerMoney()) {
      cout << "You don't have enough money to do that! Please try again." << endl;
      cin >> choice;
    }
    //switch cases used to decide what to do with user input of what they want to do with
    //their bet
		switch (choice) {
		case 'd':
			bet *= 2;
			cout << "The house rolled a " << firstNum << " and a " << secondNum << endl;
			if (player.getNumberOutput() > firstNum || player.getNumberOutput() > secondNum)
				player.setPlayerMoney(player.getPlayerMoney() + bet);
			else
				player.setPlayerMoney(player.getPlayerMoney() - bet);
			break;
		case 'h':
			bet /= 2;
			cout << "The house rolled a " << firstNum << " and a " << secondNum << endl;
			if (player.getNumberOutput() < firstNum && player.getNumberOutput() < secondNum)
				player.setPlayerMoney(player.getPlayerMoney() - bet);
			break;
		case 'k':
			cout << "The house rolled a " << firstNum << endl;
			if (player.getNumberOutput() > house.spin())
				player.setPlayerMoney(player.getPlayerMoney() + bet);
			else
				player.setPlayerMoney(player.getPlayerMoney() - bet);
			break;
		default:
			break;
		}
		
	//output the amount of money left over after playing and asked if user
	//wanted to continue their gambling
		
		money = player.getPlayerMoney();
		cout << "You have $" << std::fixed << std::setprecision(2) << money << endl;
		cout << "Would you like to cash out? (y/n)" << endl;
		cin >> choice;
	} while (choice != 'y' && money > 0);
	
	//Then if the player lost all their money they would be informed
	//that they have no money left and lost
	
	if (money > 0) {
		cout << "You won $" << std::fixed << std::setprecision(2) << money << endl;
	} else {
		cout << "You are out of money :(" << endl;
		cout << "You won $" << std::fixed << std::setprecision(2) << money << endl;
	}
  cout << "Hit enter to exit." << endl;
	string s;
  getline(cin, s);
  getline(cin, s);
	return 0;
}
