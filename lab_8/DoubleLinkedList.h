#pragma once
#include "item.h"
#include "EmptyList.h"
#include "OutOfBounds.h"
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class DoubledLinkedList {
private:
	int size;
	Node<T>* head ,*cNext = head,*cPrev = head;
public:
	T DoubleLinkedList() {
		size = 0;
	}
	~DoubledLinkedList() {
		Node<T>* del;
		while (head != nullptr) {
			del = head;
			head = head->next;
			delete del;
		}
		delete head;
		delete prev;
		//delete back;
		delete next;
	}

//	template <class T>
	void AddItem(T item) {
		if (isEmpty()) {
			Node<T>* temp = new Node<T>();
			head = temp;
			head->data = item;
			head->next = nullptr;
		}
		else {
			Node<T>* temp = head;
			Node<T>* insert = new Node<T>();
			insert->data = item;
			if (insert->data < head->data) {
				head = insert;
				temp->prev = head;
				head->next = temp;
			}
			else {
				while (temp->next != nullptr && item > temp->next->data)
					temp = temp->next;
			//got help from https://www.geeksforgeeks.org/insert-value-sorted-way-sorted-doubly-linked-list/			
				insert->next = temp->next;
				if (temp->next != nullptr)
					insert->next->prev = insert;		
				insert->prev = temp;
				temp->next = insert;
			}
		}
		size++;
	}
//	template <class T>
	T GetItem(T item) {
		if (isEmpty()) throw EmptyList();
		Node<T>* temp = head;
		while(temp != nullptr && !(temp->data == item)) temp = temp->next;
		if (temp == nullptr) throw OutOfBounds();
		else {
			Node<T> retVal = *temp;
			if (temp != head) temp->prev->next = temp->next;
			else if (temp == head || temp->next == nullptr) {}
			else temp->prev->next = temp->next;
			delete temp;
			return retVal.data;
		}
	}
//	template <class T>
		bool IsInList(T item) {
		if (isEmpty()) return false;
		Node<T> *temp = head;
		while (temp->next != nullptr && !(temp->data == item)) temp = temp->next;
		return temp->data == item;
	}
	bool isEmpty() { return size == 0; }
	int Size() { int index; }

	T SeeAt(int location) {
		if (isEmpty()) throw EmptyList();
		Node<T>* temp = head;
		for (int i = 1; i < location && temp != nullptr; i++) temp = temp->next;
		if (temp == nullptr) throw OutOfBounds();
		else {
			return temp->data;
		}

	}

	T SeeNext(int index) {
		if(isEmpty()) throw EmptyList();
		Node<T>* temp = head;
		if (cNext == nullptr)
			cNext = head;
		if (index > this->size)
			return T();
		if (cNext->data == head->data) {
			for (int i = 1; temp != nullptr && i < index; i++) temp = temp->next;
			cNext = temp->next;
			return temp->data;
		}
		else {
			*temp = *(cNext);
			cNext = head;
		}
		return temp->data;
	}

	T SeePrev(int index) {
		if(isEmpty()) throw EmptyList();
		Node<T>* temp = head;
		if (cPrev == nullptr)
			cPrev = head;
		if (index < 1)
			return T();
		if (cPrev->data == head->data) {
			for (int i = 1; temp != nullptr && i < index; i++) temp = temp->next;
			cPrev = temp->prev;
			return temp->data;
		}
		else {
			*temp = *(cPrev);
			cPrev = head;
		}
		return temp->data;
	}

	void Reset() {
		cNext = head;
		cPrev = head;;
	}

};
