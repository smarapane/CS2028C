#include <iostream>
#include <chrono>
#include <ctime>
#include <random>
#include "Sorts.h"
#include "linkedList.h"
using namespace std;
typedef std::chrono::high_resolution_clock Clock;
void sortLinkedList() {
	srand(time(NULL));
	string fNames[50] = { "Addie","Ayana","Brooklyn","Grace","Sha","Ig","Jorgie","Taiba","Will" ,"Wasim","Clare","Jim","Dor","Oriana","Jazmyn","Nikkita","Lily" ,"Prest","Anastazja" ,"Kadie","Will","Thalia","Rafferty","Sofi","Ruth","Ana"
		,"Mia","Colin" ,"Iosi","Lula","Shuai","Fleur" ,"Bryc","Layl","Nuala","Aiesha","AyyJuno","Madelein","Bill","Andr","Aditya", "Gr","Abdullah","Nathan","Tanner","Wilson","Koa","Balraj","Rhian","Mirun" };
	string lNames[50] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","AB","BC","CD","DE","EF","FG","GH","HI","JK","LM","MN","NO","OP","PQ","QR","RS","ST","TU","UV","VW","XW","WZ","ZA","AZ" };
	LinkedList* list = new LinkedList();
	for (int i = 0; i < 50; i++){
		student* temp = new student(fNames[i], lNames[i], rand() % 100000 * 100);
		list->AddItem(temp);
	}
	int choice = 0;
	cout << "Enter the option for sorting the students (1)Bubble sort,(2)Insert sort,(3) Quick sort: " << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		BubbleSortLL sort(list);
		break;
	}
	case 2:
	{
		InsertSortLL sort(list);
		break;
	}
	case 3:
	{
		student* temp = list->head;
		while (temp->next != nullptr) temp = temp->next;
		QuickSortLL sort(list,list->head,temp);
		break;
	}
	default:
		break;
	}
}
int main(){
	srand(time(NULL));

	int first[10] = { 0 }, second[100], third[500], fourth[5000], fifth[25000];
	int cfirst[10] = { 0 }, csecond[100], cthird[500], cfourth[5000], cfifth[25000];
	for(int i = 0; i < sizeof(first)/sizeof(first[0]) - 1;i++)first[i] = rand() % (2 * sizeof(first) / sizeof(first[0]));
	for (int i = 0; i < sizeof(first) / sizeof(first[0]) - 1; i++) cfirst[i] = first[i];

	for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++) second[i] = rand() % (2 * sizeof(second) / sizeof(second[0]));
	for (int i = 0; i < sizeof(first) / sizeof(first[0]) - 1; i++) csecond[i] = second[i];

	for (int i = 0; i < sizeof(third) / sizeof(third[0]) - 1; i++) third[i] = rand() % (2 * sizeof(third) / sizeof(third[0]));
	for (int i = 0; i < sizeof(first) / sizeof(first[0]) - 1; i++) cthird[i] = third[i];

	for (int i = 0; i < sizeof(fourth) / sizeof(fourth[0]) - 1; i++) fourth[i] = rand() % (2 * sizeof(fourth) / sizeof(fourth[0]));
	for (int i = 0; i < sizeof(first) / sizeof(first[0]) - 1; i++) cfourth[i] = fourth[i];

	for (int i = 0; i < sizeof(fifth) / sizeof(fifth[0]) - 1; i++) fifth[i] = rand() % (2 * sizeof(fifth) / sizeof(fifth[0]));
	for (int i = 0; i < sizeof(first) / sizeof(first[0]) - 1; i++) cfifth[i] = fifth[i];
	
	int opt = 0;
	while (opt != 5) {
		switch (opt) {
		case 0:
		{
			auto t1 = Clock::now();
			BubbleSort bubba(cfirst, sizeof(cfirst) / sizeof(cfirst[0]));
			auto t2 = Clock::now();
			std::cout << "Bubble:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(first) / sizeof(first[0]) - 1; i++)cfirst[i] = first[i];

			auto t3 = Clock::now();
			InsertSort ins(cfirst, sizeof(cfirst) / sizeof(cfirst[0]));
			auto t4 = Clock::now();
			std::cout << "Insert:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(first) / sizeof(first[0]) - 1; i++)cfirst[i] = first[i];

			auto t5 = Clock::now();
			MergeSort mer(cfirst, 0, sizeof(cfirst) / sizeof(cfirst[0]) - 1);
			auto t6 = Clock::now();
			std::cout << "Merge:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t6 - t5).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(first) / sizeof(first[0]) - 1; i++)cfirst[i] = first[i];

			auto t7 = Clock::now();
			QuickSort quick(cfirst, 0, sizeof(cfirst) / sizeof(cfirst[0] - 1));
			auto t8 = Clock::now();
			std::cout << "Quick:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t8 - t7).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(first) / sizeof(first[0]) - 1; i++)cfirst[i] = first[i];

			auto t9 = Clock::now();
			CountingSort count(cfirst, sizeof(cfirst) / sizeof(cfirst[0]));
			auto t10 = Clock::now();
			std::cout << "Count:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t10 - t9).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(first) / sizeof(first[0]) - 1; i++)cfirst[i] = first[i];

			auto t11 = Clock::now();
			RadixSort radix(cfirst, sizeof(cfirst) / sizeof(cfirst[0]));
			auto t12 = Clock::now();
			std::cout << "Radix:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t12 - t11).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(first) / sizeof(first[0]) - 1; i++)cfirst[i] = first[i];
			break;
		}
		case 1:
		{
			//second
			auto t13 = Clock::now();
			BubbleSort bubba2(csecond, sizeof(csecond) / sizeof(csecond[0]));
			auto t14 = Clock::now();
			std::cout << "Bubble:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t14 - t13).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t15 = Clock::now();
			InsertSort ins2(csecond, sizeof(csecond) / sizeof(csecond[0]));
			auto t16 = Clock::now();
			std::cout << "Insert:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t16 - t15).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t17 = Clock::now();
			MergeSort mer2(csecond, 0, sizeof(csecond) / sizeof(csecond[0]));
			auto t18 = Clock::now();
			std::cout << "Merge:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t18 - t17).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t19 = Clock::now();
			QuickSort quick2(csecond, 0, sizeof(csecond) / sizeof(csecond[0] - 1));
			auto t20 = Clock::now();
			std::cout << "Quick:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t20 - t19).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t21 = Clock::now();
			CountingSort count2(csecond, sizeof(csecond) / sizeof(csecond[0]));
			auto t22 = Clock::now();
			std::cout << "Count:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t22 - t21).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t23 = Clock::now();
			RadixSort radix2(csecond, sizeof(csecond) / sizeof(csecond[0]));
			auto t24 = Clock::now();
			std::cout << "Radix:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t24 - t23).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];
			break;
		}
		case 2:
		{
			//three
			auto t25 = Clock::now();
			BubbleSort bubba3(csecond, sizeof(csecond) / sizeof(csecond[0]));
			auto t26 = Clock::now();
			std::cout << "Bubble:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t26 - t25).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t27 = Clock::now();
			InsertSort ins3(csecond, sizeof(csecond) / sizeof(csecond[0]));
			auto t28 = Clock::now();
			std::cout << "Insert:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t28 - t27).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t29 = Clock::now();
			MergeSort mer3(csecond, 0, sizeof(csecond) / sizeof(csecond[0]));
			auto t30 = Clock::now();
			std::cout << "Merge:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t30 - t29).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t31 = Clock::now();
			QuickSort quick3(csecond, 0, sizeof(csecond) / sizeof(csecond[0] - 1));
			auto t32 = Clock::now();
			std::cout << "Quick:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t32 - t31).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t33 = Clock::now();
			CountingSort count3(csecond, sizeof(csecond) / sizeof(csecond[0]));
			auto t34 = Clock::now();
			std::cout << "Count:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t34 - t33).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t35 = Clock::now();
			RadixSort radix3(csecond, sizeof(csecond) / sizeof(csecond[0]));
			auto t36 = Clock::now();
			std::cout << "Radix:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t36 - t35).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];
			break;
		}
		case 3:
		{
			//fourth
			auto t37 = Clock::now();
			BubbleSort bubba4(csecond, sizeof(csecond) / sizeof(csecond[0]));
			auto t38 = Clock::now();
			std::cout << "Bubble:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t38 - t37).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t39 = Clock::now();
			InsertSort ins4(csecond, sizeof(csecond) / sizeof(csecond[0]));
			auto t40 = Clock::now();
			std::cout << "Insert:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t40 - t39).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t41 = Clock::now();
			MergeSort mer4(csecond, 0, sizeof(csecond) / sizeof(csecond[0]));
			auto t42 = Clock::now();
			std::cout << "Merge:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t42 - t41).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t43 = Clock::now();
			QuickSort quick4(csecond, 0, sizeof(csecond) / sizeof(csecond[0] - 1));
			auto t44 = Clock::now();
			std::cout << "Quick:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t44 - t43).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t45 = Clock::now();
			CountingSort count4(csecond, sizeof(csecond) / sizeof(csecond[0]));
			auto t46 = Clock::now();
			std::cout << "Count:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t46 - t45).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t47 = Clock::now();
			RadixSort radix4(csecond, sizeof(csecond) / sizeof(csecond[0]));
			auto t48 = Clock::now();
			std::cout << "Radix:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t48 - t47).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];
			break;
		}
		case 4:
		{
			//fifth

			auto t49 = Clock::now();
			BubbleSort bubba5(csecond, sizeof(csecond) / sizeof(csecond[0]));
			auto t50 = Clock::now();
			std::cout << "Bubble:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t50 - t49).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t51 = Clock::now();
			InsertSort ins5(csecond, sizeof(csecond) / sizeof(csecond[0]));
			auto t52 = Clock::now();
			std::cout << "Insert:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t52 - t51).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t53 = Clock::now();
			MergeSort mer5(csecond, 0, sizeof(csecond) / sizeof(csecond[0]));
			auto t54 = Clock::now();
			std::cout << "Merge:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t54 - t53).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t55 = Clock::now();
			QuickSort quick5(csecond, 0, sizeof(csecond) / sizeof(csecond[0] - 1));
			auto t56 = Clock::now();
			std::cout << "Quick:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t56 - t55).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t57 = Clock::now();
			CountingSort count5(csecond, sizeof(csecond) / sizeof(csecond[0]));
			auto t58 = Clock::now();
			std::cout << "Count:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t58 - t57).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];

			auto t59 = Clock::now();
			RadixSort radix5(csecond, sizeof(csecond) / sizeof(csecond[0]));
			auto t60 = Clock::now();
			std::cout << "Radix:" << std::chrono::duration_cast<std::chrono::nanoseconds>(t60 - t59).count() << " nanoseconds" << std::endl;
			for (int i = 0; i < sizeof(second) / sizeof(second[0]) - 1; i++)csecond[i] = second[i];
			break;
		}
		
		}
		opt++;
	}
	sortLinkedList();
	return 0;
}