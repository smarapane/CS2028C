#include "OrderedList.h"
#include "MiddleInsert.h"
#include "BlankSpot.h"
#include <random>
#include <time.h>
#include <iostream>
using namespace std;

int main() {
	OrderedList<int> oList(0);
	MiddleInsert<int> mList(0);
	BlankSpot<int> bList();
	srand(1);
	int listOfNums[ARRAY_SIZE];
	for (int count = 0; count < 100; count++) {
		for (int i = 0; i < 25; i++) {
			int* temp = new int();
			*temp = rand();
			listOfNums[i] = *temp;
			oList.AddItem(temp);
		}
		cout << "Moves: " << oList.getMoves() << " " << "Comparisons: " << oList.getComps() << endl;
		oList.setMoves(0);
		oList.setComp(0);
		for (int i = 0; i < 25; i++) {
			int numToChoose = rand() % 25;
			while (listOfNums[numToChoose] == NULL) {
				numToChoose = rand() % 25;
			}
			oList.RemoveItem(&listOfNums[numToChoose]);
			listOfNums[numToChoose] = NULL;
		}
		cout << "Moves: " << oList.getMoves() << " " << "Comparisons: " << oList.getComps() << endl;
		oList.setMoves(0);
		oList.setComp(0);
	}
/*	for (int count = 0; count < 100; count++) {
		for (int i = 0; i < 25; i++) {
			int* temp = new int();
			*temp = rand();
			listOfNums[i] = *temp;
			mList.AddItem(temp);
		}
		cout << mList.getMoves() << " " << mList.getComps() << endl;
		mList.setMoves(0);
		mList.setComp(0);
		for (int i = 0; i <= 24; i++) {
			int numToChoose = rand() % 25;
			for (; listOfNums[numToChoose] == NULL;) {
				numToChoose = rand() % 25;
			}
			mList.RemoveItem(&listOfNums[numToChoose]);
			listOfNums[numToChoose] = NULL;
		}
		cout << mList.getMoves() << " " << mList.getComps() << endl;
		mList.setMoves(0);
		mList.setComp(0);
		mList.MakeEmpty();
	}
	*/
	return 0;
}