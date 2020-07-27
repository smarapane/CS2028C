
#include <string>
#include <iostream>
#include "EntertainmentCollection.h"
#include "Show.h"
#include "FullShelf.h"
#include "EmptyShelf.h"
using namespace std;

int main() {
	EntertainmentCollection<Show> collection;
	Show *show = nullptr;
	bool exit = false;
	char choice;
	string showN, showD;

	do {
		cout << "Press 1 to add a show to the shelf." << endl;
		cout << "Press 2 remove a board game from the shelf." << endl;
		cout << "Press 3 see how many board games are currently on the shelf." << endl;
		cout << "Press 4 to quit" << endl << endl;
		cin >> choice;
		switch (choice) {
		case '1':
		{
			cout << "Enter show title : " << endl;
			cin >> showN;
			cout << "Enter show description: " << endl;
			cin >> showD;
			show = new Show(showN,showD);
			try {
				collection.addEntertainment(*show);
				cout << "Success!" << endl;
			}
			catch (FullShelf ex) {
				cout << "Shelf is already at max capacity" << endl;
			}
			cout << endl;
			break;
		}
		case '2':
		{
			try {
				if (show == nullptr) throw exception();
				*show = collection.removeFromColl();
				cout << "Removed: " << show->getTitle() << endl;
			}
			catch (EmptyShelf &ex) {
				cout << "The shelf is empty" << endl;
			}
			cout << endl;
			break;
		}
		case '3':
		{
			cout << "There are " << collection.getNumCollection() << " things on the shelf" << endl;
			cout << endl;

			break;
		}
		case '4':
		{
			exit = true;
			break;
		}
		cout << endl;
		default:
		{
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
		}
	} while (!exit);
	return 0;
}
