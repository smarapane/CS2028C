#pragma once
#include <string>
using namespace std;
class student {
public:
	student(string fName, string lName, int m) {
		firstName = fName;
		lastName = lName;
		mNumber = m;
	}
	student* next, *prev;
	void operator =(student* temp) {
		mNumber = temp->getM();
		firstName = temp->getFirstName();
		lastName = temp->getLastName();
	}
	int getM() {
		return mNumber;
	}
	string getFirstName() {
		return firstName;
	}
	string getLastName() {
		return lastName;
	}
private:
	string firstName;
	string lastName;
	int mNumber;
};
class LinkedList {
private:
	int size;
public:
	student* head;
	LinkedList() {
		size = 0;
	}
	~LinkedList() {
		student* del;
		while (head != nullptr) {
			del = head;
			head = head->next;
			delete del;
		}
		delete head;
	}

	void AddItem(student* items) {
		if (size == 0) {
			head = items;
			head->next = nullptr;
		}
		else {
			student* temp = head;
			student* insert = items;
			while (temp->next != nullptr)temp = temp->next;
			temp->next = items;
			temp->next->prev = temp;
		}
		size++;
	}

	student* GetItem(int index) {
		if (size == 0) return nullptr;
		student* temp = head;
		for (int i = 0; i <= index && temp != nullptr; i++) temp = temp->next;
		if (temp == nullptr) return nullptr;
		else return temp;
	}
};