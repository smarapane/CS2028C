#pragma once
#include "linkedList.h"

class BubbleSort {
public:
	BubbleSort(int sort[], int size) {
		int i = 0;
		for (; i < size; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (sort[j] > sort[j + 1]) {
					int temp = sort[j + 1];
					sort[j + 1] = sort[j];
					sort[j] = temp;
				}
			}
		}
	}
	~BubbleSort() {};
};
class InsertSort {
public:
	InsertSort(int sort[], int size) {
		int i = 0,j = 0, key = 0;
		for (; i < size - 1; i++) {
			key = sort[i+1];
			j = i;
			for (; key < sort[j] && j >= 0;j--) {
				sort[j + 1] = sort[j];
				sort[j] = key;		
			}
		}
	}
	~InsertSort() {};
};
class MergeSort {
public:
	void merge(int sort[], int left, int middle, int right) {
		int size1 = middle - left + 1;
		int size2 = right - middle;
		int* copyArrayLeft = new int[size1];
		for (int i = 0; i < size1; i++)copyArrayLeft[i] = 0;
		int* copyArrayRight = new int[size2];
		for (int i = 0; i < size2; i++)copyArrayRight[i] = 0;
		for (int i = 0; i < size1; i++)
			copyArrayLeft[i] = sort[left + i];
		for (int i = 0; i < size2; i++)
			copyArrayRight[i] = sort[middle + 1 + i];
		int i = 0, j = 0, k = left;
		while (i < size1 && j < size2) {
			if (copyArrayLeft[i] <= copyArrayRight[j]) {
				sort[k] = copyArrayLeft[i];
				i++;
			}
			else {
				sort[k] = copyArrayRight[j];
				j++;
			}
			k++;
		}
		while (i < size1) {
			sort[k] = copyArrayLeft[i];
			i++; k++;
		}
		while (j < size2) {
			sort[k] = copyArrayRight[j];
			j++; k++;
		}
	}
	void mergeSort(int sort[], int leftIndex, int rightIndex) {
		if (leftIndex < rightIndex) {
			mergeSort(sort, leftIndex, leftIndex + (rightIndex - leftIndex) / 2);
			mergeSort(sort, leftIndex +(rightIndex - leftIndex) / 2 + 1, rightIndex);
			merge(sort, leftIndex, leftIndex + (rightIndex - leftIndex) / 2, rightIndex);
		}
	}
	MergeSort(int sort[], int leftIndex,int rightIndex) {
		mergeSort(sort, leftIndex, rightIndex);
	}
	~MergeSort() {};
};
class QuickSort {
public:
	int partition(int sort[], int low, int high) {
		int pivot = sort[high];
		int index = low - 1;
		for (int i = low; i <= high - 1; i++) {
			if (sort[i] < pivot) {
				index++;
				int temp = sort[index];
				sort[index] = sort[i];
				sort[i] = temp;
			}
		}
		int temp = sort[index + 1];
		sort[index + 1] = sort[high];
		sort[high] = temp;
		return index + 1;
	}
	QuickSort(int sort[], int low, int high) {
		if (low < high) {
			int div = partition(sort, low, high);
			QuickSort(sort, low, div - 1);
			QuickSort(sort, div + 1, high);
		}
	}
	~QuickSort() {};
};
class CountingSort {
public:
	CountingSort(int sort[], int size) {
		int max = sort[0];
		for (int i = 1; i <= size - 1; i++) {
			if (max < sort[i]) max = sort[i];
		}
		
		int* countArray = new int[max + 1];
		for (int i = 0; i < max + 1; i++)countArray[i] = 0;
	
		for (int i = 0; i <= size - 1; i++) {
			int s = sort[i];
			countArray[s]++;
		}
		for (int i = 1; i <= max; i++)
			countArray[i] = countArray[i] + countArray[i - 1];
		int* outputArray = new int[size];
		for (int i = 0; i < size; i++)outputArray[i] = 0;
		for (int i = 0; i <= size - 1; i++)
			outputArray[countArray[sort[i]] - 1] = sort[i];
		for (int i = 0; i < size; i++)sort[i] = outputArray[i];

	}
	~CountingSort(){};
};
class RadixSort{
public:
	void countSort(int sort[], int size, int place) {
		int* output = new int[size];
		int count[10] = { 0 };
		for (int i = 0; i <= size - 1; i++)
			count[(sort[i] / place) % 10]++;
		for (int i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (int i = size - 1; i >= 0; i--) {
			output[count[(sort[i] / place) % 10] - 1] = sort[i];
			count[(sort[i] / place) % 10]--;
		}
		for (int i = 0; i <= size - 1; i++)
			sort[i] = output[i];
	}
	RadixSort(int sort[], int size) {
		int max = 0;
		for (int i = 1; i <= size - 1; i++)
			if (max > sort[i]) max = sort[i];
		for (int place = 1; max / place > 0; place *= 10)
			countSort(sort, size, place);
	}
	~RadixSort() {};
};
class BubbleSortLL {
public:
	BubbleSortLL(LinkedList* sortName) {
		student* tempHead = sortName->head;
		student* tempTail = nullptr;
		for (; tempHead->next != tempTail; tempHead = tempHead->next) {
			if (tempHead->getLastName() > tempHead->next->getLastName()) {
				student temp = *tempHead->next;
				*tempHead->next = *tempHead;
				temp.next = tempHead;
			}
			tempTail = tempHead;
		}
	}
	~BubbleSortLL() {};
};
class InsertSortLL {
public:
	InsertSortLL(LinkedList* sortName){
		student* tempHead = sortName->head;
		student* key = nullptr;
		for (; tempHead->next != nullptr; tempHead = tempHead->next) {
			key = tempHead->next;
			student* tempStop = tempHead;
			student* tempBeg = sortName->head;
			while(tempBeg != tempStop){
				if (tempBeg->getFirstName() > key->getFirstName()) {
					*tempBeg->next = *tempBeg;
					*tempBeg = *key;
				}
				tempBeg = tempBeg->next;
			}
		}
	}
	~InsertSortLL() {};
};
class QuickSortLL {
public:
	student* partition(LinkedList* students, student* low, student* high) {
		student* pivot = low;
		student* temp = students->head;
		while (temp->next != nullptr && temp->next != low) temp = temp->next;

		for (student *j = low; j != high; j = j->next)
		{
			if (j->getM() <= high->getM())
			{ 
				temp = (temp == nullptr) ? low : temp->next;

				student temp2 = *temp;
				*temp = *j;
				*j = temp2;
			}
		}
		temp = (temp == nullptr) ? low : temp->next; 
		student* temp2 = temp;
		*temp = *high;
		*high = temp2;
		return temp;
	}
	QuickSortLL(LinkedList* students, student* low, student* high) {
		if (low < high) {
			student* div = partition(students, low, high);
			QuickSortLL(students, low, div - 1);
			QuickSortLL(students, div + 1, high);
		}
	}
};