#pragma once
#include <string>
#include "Show.h"
using namespace std;

class Movie : public Show {
private:
	string openCredits;

public:
	Movie(string t, string d, string c);
	Movie();
	string getCredits() { return openCredits; }
	void setCredits(string c) { openCredits = c; }
	void Play();
};


