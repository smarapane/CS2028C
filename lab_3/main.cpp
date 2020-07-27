#include <iostream>
#include "ComplexNumber.h"
#include <string>
using namespace std;

int main(int argc, char ** argv) {		//Call ComplexNums then has user input P/C if not valid entry defaults C
	ComplexNums ronaldo, neymar;
	double temp;
	char c;
	bool cont = true;
	std::cout << "Enter (p)olar or (c)artesian: ";
	cin >> c;
	ronaldo.setPolar(c == 'p');
	if (c != 'p' and c != 'c')
		cout << "Unrecognized character. Assuming cartesian." << endl;
	cout << "Enter x or r: ";
	while (!(cin >> temp)) {		 //Checks to see if user input is a valid number if not loops and keeps asking for a value for X
		string ansr;
		cin.clear();
		getline(cin, ansr);
		cout << ansr << " Isn't a correct value please enter a number: " << endl;
	}
	if (ronaldo.getPolar())
		ronaldo.setR(temp);
	else
		ronaldo.setReal(temp);
	cout << "Enter y or theta: ";	//Checks to see if user input is a valid number if not loops and keeps asking for a value for Y
	while (!(cin >> temp)) {
		string ansr;
		cin.clear();
		getline(cin, ansr);
		cout << ansr << " Isn't a correct value please enter a number: " << endl;
	}
	if (ronaldo.getPolar())
		ronaldo.setTheta(temp);
	else
		ronaldo.setImag(temp);
	ronaldo.print();	
	do {
		cout << "Select (a)dd (s)ubtract (m)ultiply (d)ivide (e)quality (q)uit: ";		//Gets user input for which operation to do
		cin >> c;
		switch (c) {
		case 'a':				//Then goes through six cases and decides on input what operation to do prints it out and breaks from switch
			cout << "Enter x value: ";
			while (!(cin >> temp)) {
				string ansr;
				cin.clear();
				getline(cin, ansr);
				cout << ansr << " Isn't a correct value please enter a number: " << endl;
			}
			neymar.setReal(temp);
			cout << "Enter y value: ";
			while (!(cin >> temp)) {
				string ansr;
				cin.clear();
				getline(cin, ansr);
				cout << ansr << " Isn't a correct value please enter a number: " << endl;
			}
			neymar.setImag(temp);
			if (ronaldo.getPolar() == true)
				neymar.setPolar(true);
			(neymar + ronaldo).print();
			break;
		case 's':
			cout << "Enter x value: ";
			while (!(cin >> temp)) {
				string ansr;
				cin.clear();
				getline(cin, ansr);
				cout << ansr << " Isn't a correct value please enter a number: " << endl;
			}
			neymar.setReal(temp);
			cout << "Enter y value: ";
			while (!(cin >> temp)) {
				string ansr;
				cin.clear();
				getline(cin, ansr);
				cout << ansr << " Isn't a correct value please enter a number: " << endl;
			}
			neymar.setImag(temp);
			(ronaldo - neymar).print();
			break;
		case 'm':
			cout << "Enter scalar: ";
			while (!(cin >> temp)) {
				string ansr;
				cin.clear();
				getline(cin, ansr);
				cout << ansr << " Isn't a correct value please enter a number: " << endl;
			}
			(ronaldo * temp).print();
			break;
		case 'd':
			cout << "Enter scalar: ";
			while (!(cin >> temp)) {
				string ansr;
				cin.clear();
				getline(cin, ansr);
				cout << ansr << " Isn't a correct value please enter a number: " << endl;
			}
			(ronaldo / temp).print();
			break;
		case 'e':
			cout << "Enter x value: ";
			while (!(cin >> temp)) {
				string ansr;
				cin.clear();
				getline(cin, ansr);
				cout << ansr << " Isn't a correct value please enter a number: " << endl;
			}
			neymar.setReal(temp);
			cout << "Enter y value: ";
			while (!(cin >> temp)) {
				string ansr;
				cin.clear();
				getline(cin, ansr);
				cout << ansr << " Isn't a correct value please enter a number: " << endl;
			}
			neymar.setImag(temp);
			if (ronaldo == neymar)
				cout << "They are equal" << endl;
			else
				cout << "They are not equal" << endl;
			break;
		case 'q':		//If user input isn't found in cases output error code and asks for operation and resets
			cont = false;
			break;
		default:
			cout << "Unrecognized operation";
			break;
		}
	} while (cont);
}
