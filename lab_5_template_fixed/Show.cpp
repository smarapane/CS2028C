#include "Show.h"
#include <iostream>
#include <string>

using namespace std;
// The following funcs are used to get the shows name, title, and description and just output them
Show::Show() {
	title = "";
	description = "";
}

Show::Show(string t, string d) {
	title = t;
	description = d;
}

void Show::Details() {
	cout << "Title: " << getTitle() << endl;
	cout << "Description: " << getDescription() << endl;
}
