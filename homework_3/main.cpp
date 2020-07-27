#include "sidePile.h"
#include "deck.h"
#include <iostream>
#include <string>
#include <random>
#include <time.h>
using namespace std;

void setUp(Deck* pDeck, Deck* cDeck, string listOfCards[52]) {
	for (int i=0; i < 26; i++) {
		int choice = rand() % 52;
		while (listOfCards[choice] == "")
			choice = rand() % 52;
		pDeck->addCard(listOfCards[choice]);
		listOfCards[choice] = "";
	}
	for (int i = 0; i < 26; i++) {
		int choice = rand() % 52;
		while (listOfCards[choice] == "")
			choice = rand() % 52;
		cDeck->addCard(listOfCards[choice]);
		listOfCards[choice] = "";
	}
}
bool determineWhoWins(Card roundOfCards[], Deck pDeck, Deck cDeck, bool three) {
	int player = 0, comp = 0;
	if ( three == true) {
		cout << "You drew " << roundOfCards[0].getData() << " " << "and " << roundOfCards[1].getData() << " ";
		cout << "They drew " << roundOfCards[2].getData() << " " << endl;;
		if (roundOfCards[0].getData().size() > 3)
			player = 10;
		if (roundOfCards[0].getData()[0] == 'J')
			player = 11;
		if ((roundOfCards[0].getData()[0] == 'K'))
			player = 12;
		if ((roundOfCards[0].getData()[0] == 'Q'))
			player = 13;
		if ((roundOfCards[0].getData()[0] == 'A'))
			player = 1;
		else
			player = atoi(&(roundOfCards[0].getData())[0]);

		if (roundOfCards[1].getData()[0] == 'J')
			player += 11;
		if ((roundOfCards[1].getData()[0] == 'K'))
			player += 12;
		if ((roundOfCards[1].getData()[0] == 'Q'))
			player += 13;
		if ((roundOfCards[1].getData()[0] == 'A'))
			player += 1;
		if (roundOfCards[1].getData().size() > 3)
			player += 10;
		else
			player += atoi(&(roundOfCards[1].getData())[0]);

		if (roundOfCards[2].getData()[0] == 'J')
			comp += 11;
		if ((roundOfCards[2].getData()[0] == 'K'))
			comp += 12;
		if ((roundOfCards[2].getData()[0] == 'Q'))
			comp += 13;
		if ((roundOfCards[2].getData()[0] == 'A'))
			comp += 1;
		if (roundOfCards[2].getData().size() > 3)
			comp += 10;
		else
			comp = atoi(&(roundOfCards[1].getData())[0]);
	}
	else {
		cout << "You drew " << roundOfCards[0].getData() << " ";
		cout << "They drew " << roundOfCards[1].getData() << " ";
		if (roundOfCards[0].getData().size() > 3)
			player = 10;
		if (roundOfCards[0].getData()[0] == 'J')
			player = 11;
		if ((roundOfCards[0].getData()[0] == 'K'))
			player = 12;
		if ((roundOfCards[0].getData()[0] == 'Q'))
			player = 13;
		if ((roundOfCards[0].getData()[0] == 'A'))
			player = 1;
		else
			player += atoi(&(roundOfCards[0].getData())[0]);


		if (roundOfCards[1].getData()[0] == 'J')
			comp += 11;
		if ((roundOfCards[1].getData()[0] == 'K'))
			comp += 12;
		if ((roundOfCards[1].getData()[0] == 'Q'))
			comp += 13;
		if ((roundOfCards[1].getData()[0] == 'A'))
			comp += 1;
		if (roundOfCards[1].getData().size() > 3)
			comp += 10;
		else
			comp += atoi(&(roundOfCards[1].getData())[0]);
	}

	if (player > comp)
		return true;
	else
		return false;
}

int main() {
	bool gameOver = false;
	bool playerWin = false;
	srand(time(NULL));
	string listOfCards[52] = { "2d" ,"3d" ,"4d" ,"5d" ,"6d","7d" ,"8d" ,"9d" ,"10d" ,"Jd" ,"Kd","Qd","Ad",
									"2s" ,"3s" ,"4s" ,"5s" ,"6s","7s" ,"8s" ,"9s" ,"10s" ,"Js" ,"Ks","Qs","As",
									"2c" ,"3c" ,"4c" ,"5c" ,"6c","7c" ,"8c" ,"9c" ,"10c" ,"Jc" ,"Kc","Qc","Ac",
									"2h" ,"3h" ,"4h" ,"5h" ,"6h","7h" ,"8h" ,"9h" ,"10h" ,"Jh" ,"Kh","Qh","Ah" };
	Deck playerDeck;
	sidePile pSidePile;
	Deck computerDeck;
	setUp(&playerDeck, &computerDeck, listOfCards);
	int numOfRounds = 0;
	cout << "Welcome to war." << endl;
	char choicePlay = 'w';
	while (choicePlay != 'r' && choicePlay != 'p') {
		cout << "Play for 25 (r)ounds or until a (p)layer runs out of cards" << endl;
		cin >> choicePlay;
	}
	do {
		
		if (choicePlay == 'p') {
			if (playerDeck.isEmpty() && pSidePile.isEmpty()) {
				cout << " You lose war :(" << endl;
				break;
			}
			if (computerDeck.isEmpty()) {
				cout << " You win war :(" << endl;
				break;
			}
		}
		if (choicePlay == 'r') {
			if (numOfRounds == 25) {
				if (playerDeck.length() > computerDeck.length())
					cout << " You win war :(" << endl;
				else
					cout << " You lose war :(" << endl;
				break;
			}
		}

		char choice;
		cout << "(p)eek or p(l)ay top card" << endl;
		cin >> choice;
		switch (choice) {
		case 'p':
			{
			cout << playerDeck.peek() << endl;
			cout << "(p)ut on side pile or (t)ake from side pile" << endl;
			cin >> choice;
			while (pSidePile.getSize() == 0 && choice == 't') {
				cout << "Side pile is empty! Putting card on side pile!" << endl;
				choice = 'p';
			}
			while (pSidePile.isFull() && choice == 'p') {
				cout << "Sidce pile is full! Taking from side pile!";
				choice = 't';
			}

			if (choice == 'p') {
				Card roundOfCards[2]{ playerDeck.takeCard(), computerDeck.takeCard() };

				pSidePile.addCard(roundOfCards[0]);
				playerDeck.loseCards();
				roundOfCards[0] = playerDeck.takeCard();

				if (true == determineWhoWins(roundOfCards, playerDeck, computerDeck, false)) {
					cout << "You Win" << endl;
					for (int i = 0; i < 2; i++)
						playerDeck.addCard(roundOfCards[i].getData());
				}
				else {
					cout << "You lose" << endl;
					for (int i = 0; i < 1; i++)
						computerDeck.addCard(roundOfCards[i].getData());
				}
			}
			else if (choice == 't') {
				Card roundOfCards[3]{ playerDeck.takeCard(),pSidePile.takeCard(), computerDeck.takeCard() };
				if (true == determineWhoWins(roundOfCards, playerDeck, computerDeck, true)) {
					cout << "You Win" << endl;
					for(int i = 0; i < 3; i++)
						playerDeck.addCard(roundOfCards[i].getData());

				}
				else {
					cout << "You lose" << endl;
					for (int i = 0; i < 3; i++)
						computerDeck.addCard(roundOfCards[i].getData());
				}
			}
			break;
			}
		case 'l':
			{
			Card roundOfCards[2]{ playerDeck.takeCard(), computerDeck.takeCard() };
			if (true == determineWhoWins(roundOfCards, playerDeck, computerDeck, false)) {
				cout << "You Win" << endl;
				for (int i = 0; i < 2; i++)
					playerDeck.addCard(roundOfCards[i].getData());
			}
			else {
				cout << "You lose" << endl;
				for (int i = 0; i < 2; i++)
					computerDeck.addCard(roundOfCards[i].getData());
			}
			break;
			}
		}
		//
		numOfRounds++;
	} while (!gameOver);
	return 0;
}
