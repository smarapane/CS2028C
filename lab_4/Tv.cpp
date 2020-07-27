
#include "TV.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

TV::TV() {
	
}

TV::TV(int numEp, int numSeas, vector <vector <string> > seasonsAndEpis, string t, string d ) : Show(t, d){
	for (int i = 0; i < numSeas; i++) {
		for (int j = 0; j < numEp; j++) {
			seasonsAndEp[i][j] = seasonsAndEpis[i][j];
		}
	}
  numSeasons = numSeas;
  numEpisodes = numEp;
}
// seperates the inputs and places them into each corressponding output
void  TV::Play() {
	int season, episode;
	string temp;
	do {
		cout << "Enter season: ";
		cin >> season;
	} while (season > getNumSeasons());
	
	do {
		cout << "Enter episode: ";
		cin >> episode;
	} while (season > getNumEpisodes());
  getline(cin, temp);
	cout << "S" << season << "E" << episode << " title: " << seasonsAndEp[season - 1][episode - 1] << endl;
}
// show season #
void TV::Details() {
	Show::Details();
	cout << "Number of seasons: " << getNumSeasons();
}

