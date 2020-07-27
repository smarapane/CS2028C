#pragma once
#include "OrderedList.h"
#include "NoItemExisting.h"
#include "Overflow.h"
#include "Underflow.h"

template <class T>
class BlankSpot : public OrderedList<T> {
public:
	BlankSpot() {
		OrderedList::moves = 0;
		OrderedList::comps = 0;
	}
	template <class T>
	void AddItem(T* data) {
		if (OrderedList::isEmpty()) {
			OrderedList::Data[0] = data;
			OrderedList::items++;
		}
		else if (!OrderedList::isFull()) {
			int firstNum = 0, secondNum = 0;
			for (int i = 1; i < ARRAY_SIZE - 1; i++) {
				if (OrderedList::Data[i] != nullptr && OrderedList::Data[i] < data)
					firstNum = i;
				if (OrderedList::Data[i] > data) {
					secondNum = i;
					OrderedList::moves++;
					break;
				}
				OrderedList::moves++;
			}
			int dist = (firstNum + secondNum) / 2;
			T* temp = OrderedList[dist];
			T* temp2 = temp;
			if (temp == nullptr) {
				OrderedList::Data[dist] = data;
				break;
			}
			else {																					//i give up
				for (int j = 1; dist + j + 1 < 25 && OrderedList::Data[dist + j] != nullptr; j++) {
					temp = OrderedList::Data[dist + j + 1];
					OrderedList::Data[dist + j + 1] = OrderedList::Data[dist + j];
					*OrderedList::Data[dist + i] = *temp;
					temp = newTemp;
				}
			}
			
		}
		else {
			throw Overflow();
		}
	}

	template <class T>
	void RemoveItem(T* data) {
		if (!OrderedList::isEmpty()) {
			int i = 0;
			while (OrderList::Data[i] != data) {
				if (OrderedList::Data[i] == nullptr) {
					throw NoItemExisting();
				}
				i++;
			}

			OrderedList::Data[i] = nullptr;
			OrderedList::items--;
		}
		else {
			throw Underflow();
		}
	
	}
};