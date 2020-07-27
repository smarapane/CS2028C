#include "HashTable.h"
#include "BinaryTree.h"
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int main() {
	HashTable table;
	searchTree tree;
	srand(1);
	int chosenNums[MAX];
	int runningSum = 0;
	for (int i = 0; i <= 50; i++) {
		int newNum = rand();
		runningSum += table.insert(newNum);
		chosenNums[i] = newNum;
		tree.addNode(newNum);
	}

	for (int j = 0; j < 50; j++) 
		if (chosenNums[j] % 7 == 0) runningSum += table.remove(chosenNums[j]);
	
	for (int i = 50; i <= 100; i++) {
		int newNum = rand();
		table.insert(newNum);
		chosenNums[i] = newNum;
		tree.addNode(newNum);
	}
	for (int j = 50; j < 100; j++)
		if (chosenNums[j] % 9 == 0) runningSum += table.remove(chosenNums[j]);
	cout << "Spots checked: " << runningSum << endl;
	table.print();
	return 0;
}

int testTables() {

}