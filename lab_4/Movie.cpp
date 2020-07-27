#include "Movie.h"
#include <iostream>
#include <string>
using namespace std;
// The following funcs are used to get the movies credits and output
Movie::Movie() {
	openCredits = "";
}

Movie::Movie(string t, string d, string c) : Show(t, d) {
	openCredits = c;
}

void Movie::Play() {
	cout << openCredits << endl;
}

