#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include <fstream>
#include <string>
using namespace std;						

int main(void) {
            
	ifstream infile;
	infile.open("text.txt");
	string word = "";
    	int stackSize = 0;
    	int queueSize = 0;
	while (infile >> word) {
        	queueSize++;
        	if (word.size() > stackSize)
            		stackSize = word.size();
    	}

	Queue<Stack<char>> queue(queueSize);										
	Stack<char> tempStack[100] = { 100 };//store the stacks in a non-dynamically allocated area to avoid overwrite
	string words[100];

	infile.clear();
	infile.seekg(0, ios::beg);
	for (int i = 0; i < queueSize; i++) {
		infile >> word;
		words[i] = word;
		for (int j = 0; j < word.size(); j++){
			tempStack[i].Push(&words[i].at(j));
		}
		queue.Enqueue(&tempStack[i]);
	}

	int queueIteration = queue.Length();
	for (int i = 0; i < queueIteration; i++) {
		Stack<char> *tempStack2 = new Stack<char>(100);
        	tempStack2 = queue.Dequeue<Stack<char>>();
		int length = tempStack2->Length();
		for (int j = 0; j < length; j++) {
			char * letter = tempStack2->Pop<char>();			
			cout << *letter;
		}
		cout << " ";
	}
	return 0;
}


/*




*/
