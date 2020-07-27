#pragma once
#include <iostream>
#include <string>
using namespace std;

class Show {
private:
	string title;
	string description;

public:
	Show();
	Show(string t, string d);
	virtual void Play() {};
	void Details();
	string getTitle() { return title; }
	void setTitle(char t) { title = t; }
	string getDescription() { return description; }
	void setDescription(char d) { description = d; }

};
