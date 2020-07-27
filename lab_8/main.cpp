#include <iostream>
#include <string>
#include "DoubleLinkedList.h"
#include <iomanip>
#include "item.h"

using namespace std;
int main() {
	DoubledLinkedList<item>* list = new DoubledLinkedList<item>();
	char choice = ' ';
	while (choice != 'E') {
		cout << "Interact with the list by: (A)dd item, (G)etItem, (I)sInList, S(e)eNext, (S)eePrev, See A(t), or (E)xit" << endl;
		cin >> choice;
		switch (choice) {
		case 'A':
		{
			int sku = 0;
			string description;
			double price;
			string unitOfMeas;
			int quantity;

			cout << "Enter SKU: ";
			cin >> sku;
			cout << "Enter description: ";
			cin >> description;
			cout << "Enter price: ";
			cin >> price;
			cout << "Enter Unit of Measurement: ";
			cin >> unitOfMeas;
			cout << "Enter quantity if necessary: ";
			cin >> quantity;
			item newItem(sku, description, price, unitOfMeas, quantity);
			list->AddItem(newItem);
			cout << endl;
			break;
		}
		case 'G':
		{
			int sku = 0;
			cout << "Enter SKU: ";
			cin >> sku;
			item retItem(sku, " ", 0, " ", 0);
			retItem = list->GetItem(retItem);
			cout << retItem.GetPartInfo() << endl;
			break;
		}
		case 'I':
		{
			int sku = 0;
			cout << "Enter SKU: ";
			cin >> sku;
			item retItem(sku, " ", 0, " ", 0);
			if (list->IsInList(retItem))
				cout << "Found" << endl;
			else
				cout << "Not Found" << endl;
			break;
		}
		case 'e':
		{
			int loc = 0;
			cout << "Enter index: ";
			cin >> loc;
			item retItem(0, " ", 0, " ", 0);
			retItem = list->SeeNext(loc);
			cout << retItem.GetPartInfo() << endl;
			break;
		}
		case 'S':
		{
			int loc = 0;
			cout << "Enter SKU: ";
			cin >> loc;
			item retItem(0, " ", 0, " ", 0);
			retItem = list->SeePrev(loc);
			cout << retItem.GetPartInfo() << endl;
			break;
		}
		case 't':
		{
			int loc = 0;
			cout << "Enter Location ";
			cin >> loc;
			item retItem(0, " ", 0, " ", 0);
			retItem = list->SeeAt(loc);
			cout << retItem.GetPartInfo() << endl;
			break;
		}
		default:
			cout << "Wrong input, try again" << endl;
			break;
		}
	}
	return 0;
}
