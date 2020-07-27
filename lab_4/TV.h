#pragma once
#include <vector>
#include "Show.h"
class TV : public Show {
private:
	string seasonsAndEp[100][100];
	int numSeasons;
	int numEpisodes;
public:
	TV();
	TV(int numEp, int numSeas, vector <vector <string> > seasonsAndEpis, string t, string d);
	string getEp(int s, int e) { return seasonsAndEp[s][e]; }
	void setEp(int s, int e, string episode) { seasonsAndEp[s][e] = episode; }
	int getNumSeasons() { return numSeasons; }
	int getNumEpisodes() { return numEpisodes; }
	void Play();
	void Details();
};



