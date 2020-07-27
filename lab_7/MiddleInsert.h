#pragma once
#include "OrderedList.h"
#include "NoItemExisting.h"
#include "Overflow.h"
#include "Underflow.h"

template <class T>
class MiddleInsert : public OrderedList<T> {

private:
public:
	MiddleInsert<T>(int item) : OrderedList<T>(item) {
		OrderedList<T>::comp = 0;
		OrderedList<T>::move = 0;
	}

	void AddItem(T* data) {
		if (OrderedList<T>::isFull())
			throw Overflow();
		if (OrderedList<T>::isEmpty()) {
			OrderedList<T>::Data[ARRAY_SIZE / 2] = data;
			OrderedList<T>::items++;
			return;
		}

		if (!OrderedList<T>::isFull()) {
			T* temp = OrderedList<T>::Data[0];
			T* temp2 = OrderedList<T>::Data[0];
			int i = ARRAY_SIZE / 2;
			//go left if less than middle
			if (*data < *OrderedList<T>::Data[i]) {
				OrderedList<T>::comp++;
				for (; OrderedList<T>::Data[i] != nullptr && i > 0 && *data < *OrderedList<T>::Data[i];i--) {
					OrderedList<T>::comp++;
				}
				//swap
				temp = OrderedList<T>::Data[i];
				OrderedList<T>::Data[i] = data;
				OrderedList<T>::move++;
				OrderedList<T>::items++;

				//check boundary
				if (OrderedList<T>::Data[0] != nullptr && OrderedList<T>::Data[ARRAY_SIZE - 1] == nullptr ) {
					for (; OrderedList<T>::Data[i] != nullptr; i++) {
						temp2 = OrderedList<T>::Data[i + 1];
						OrderedList<T>::Data[i + 1] = temp;
						if (i + 1 == ARRAY_SIZE - 1)
							break;
						else
							temp = temp2;
						OrderedList<T>::move++;
					}		
				}
				else {
					for (; OrderedList<T>::Data[i - 1] != nullptr && i - 1 > 0; i--) {
						temp2 = OrderedList<T>::Data[i - 1];
						OrderedList<T>::Data[i - 1] = temp;
						temp = temp2;
						OrderedList<T>::move++;
					}
					// add item
					OrderedList<T>::Data[i - 1] = temp;
					OrderedList<T>::move++;
				}
			}
			//greater than
			else {
				for (; OrderedList<T>::Data[i + 1] != nullptr && *data > *OrderedList<T>::Data[i + 1]; i++) {
					//check for end boundary while iterating
					OrderedList<T>::comp++;
					if (i + 1 >= ARRAY_SIZE - 1) {
						temp = OrderedList<T>::Data[i+1];
						OrderedList<T>::Data[i+1] = data;
						int j = 0;
						for (j = i; OrderedList<T>::Data[j - 1] != nullptr; j--) {
							temp2 = OrderedList<T>::Data[j - 1];
							OrderedList<T>::Data[j - 1] = temp;
							temp = temp2;
							OrderedList<T>::move++;
						}
						OrderedList<T>::Data[j - 1] = temp;
						OrderedList<T>::items++;
						return;
					}
				}
				//check boundary for shitfting
				if (OrderedList<T>::Data[ARRAY_SIZE - 1] != nullptr){
					temp = OrderedList<T>::Data[i];
					OrderedList<T>::Data[i] = data;
					OrderedList<T>::move++;
					OrderedList<T>::comp++;
					int j = 0;
					for (j = i; OrderedList<T>::Data[j - 1] != nullptr; j--) {
						temp2 = OrderedList<T>::Data[j - 1];
						OrderedList<T>::Data[j - 1] = temp;
						temp = temp2;
						OrderedList<T>::move++;
					}
					//add item
					OrderedList<T>::Data[j - 1] = temp;
					OrderedList<T>::items++;
					OrderedList<T>::move++;
				}
				else {
					temp = OrderedList<T>::Data[i + 1];
					OrderedList<T>::Data[i + 1] = data;
					i++;
					OrderedList<T>::move++;
					for (; OrderedList<T>::Data[i + 1] != nullptr && i + 1 < ARRAY_SIZE -1; i++) {
						temp2 = OrderedList<T>::Data[i + 1];
						OrderedList<T>::Data[i + 1] = temp;
						temp = temp2;
						OrderedList<T>::move++;
					}
					//add item
					if(i + 1 >= ARRAY_SIZE)
						OrderedList<T>::items++;
					else {
						OrderedList<T>::Data[i + 1] = temp;
						OrderedList<T>::move++;
						OrderedList<T>::items++;
					}
				}
			}
		}
	}

	//void RemoveItem(T* data) {
	//	if (OrderedList<T>::isEmpty())
	//		throw Underflow();

	////	int i = ARRAY_SIZE / 2;
	////	//remove data is less than middle
	////	if (*data < *OrderedList<T>::Data[i - 1]) {
	////		OrderedList<T>::comp++;
	////		for (; *OrderedList<T>::Data[i] != *data; i--) {
	////			OrderedList<T>::comp++;
	////			if (OrderedList<T>::Data[i] == nullptr)
	////				throw NoItemExisting();
	////			if (OrderedList<T>::Data[i - 1] == nullptr) {
	////				return;
	////			}

	////		}
	////		OrderedList<T>::Data[i] = nullptr;//delete
	////		//adjust
	////		if(i != ARRAY_SIZE- 1 - OrderedList<T>::items){
	////			for (; OrderedList<T>::Data[i - 1] != nullptr && i - 1 > 0; i--) {
	////				OrderedList<T>::Data[i] = OrderedList<T>::Data[i - 1];
	////				OrderedList<T>::move++;
	////				OrderedList<T>::comp++;
	////			}
	////			OrderedList<T>::Data[i] = OrderedList<T>::Data[i - 1];
	////			OrderedList<T>::move++;
	////		}
	////	}
	////	else {
	////		//remove data is greater than middle
	////		for (; *OrderedList<T>::Data[i] != *data; i++) {
	////			OrderedList<T>::comp++;
	////			if (OrderedList<T>::Data[i] == nullptr)
	////				throw NoItemExisting();
	////		}
	////		OrderedList<T>::Data[i] = nullptr;
	////		//check to see if adjustment is required

	////		if (OrderedList<T>::Data[i +1] != nullptr) {
	////			for (; OrderedList<T>::Data[i + 1] != 0 && i < ARRAY_SIZE-1; i++) {
	////				OrderedList<T>::comp++;
	////				OrderedList<T>::move++;
	////				OrderedList<T>::Data[i] = OrderedList<T>::Data[i + 1];
	////			}
	////			OrderedList<T>::Data[i] = nullptr;
	////		}
	////	}
	////	OrderedList<T>::items--;
	////}
};