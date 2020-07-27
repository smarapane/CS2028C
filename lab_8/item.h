#pragma once
#include <string>
#include <time.h>
#include <fstream>
#include <iostream>
using namespace std;
class item {
private:
	int sku;
	string description;
	double price;
	string unitOfMeas;
	int quantity;
	int leadTime;
	
public:
	item() {
		sku = 0;
		description = " ";
		price = 0.0;
		unitOfMeas = " ";
		quantity = 0;
		leadTime = 0;
	}
	item(int s, string descr, double prices, string uofm, int qoh = 0) {
		sku = s;
		description = descr;
		price = prices;
		unitOfMeas = uofm;
		quantity = qoh;
	}
	string GetPartInfo() {
		string partInfo = "SKU: " + to_string(sku) +  " " + "Description: " + description;
		return partInfo;
	}
	double GetPrice() { return price; }
	bool InStock() { return quantity > 0; }
	bool Available(string date) {
		if (InStock()) {
			//https://stackoverflow.com/questions/40278381/whats-the-alternative-to-the-getdate-function-in-c4-3-2
			string currentDate;
			time_t rawtime;
			time(&rawtime);
			struct tm timeinfo;
			//localtime_s(&timeinfo, &rawtime);
			currentDate = to_string(timeinfo.tm_mday) + '-' + to_string(timeinfo.tm_mon + 1) + '-' + to_string(timeinfo.tm_year + 1900);
			date = date + to_string(leadTime);
			return currentDate > date;
		}
		return false;
	}
	void display() {
			cout << "---------------------------" << endl;
			cout << "|                         |" << endl;
			cout << "|                         |" << endl;
			cout << "    SKU: " << sku << endl;
			cout << "    Quantity: " << quantity << endl;
			cout << "|                         |" << endl;
			cout << "|                         |" << endl;
			cout << "---------------------------" << endl;
	}
	bool operator>(item compItem) {
		if (compItem.sku < this->sku)
			return true;
		return false;
	}
	bool operator<(item compItem) {
		if (compItem.sku > this->sku)
			return true;
		return false;
	}
	bool operator==(item compItem) {
		if (sku == compItem.sku)
			return true;
		return false;
	}
};
