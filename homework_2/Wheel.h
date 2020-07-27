#pragma once
#include<vector>
#include<random>
using namespace std;

class Wheel {

public:
	Wheel(int max);
	Wheel();
	void newRangeOfValues(int stop = 10);
	int spin();

private:
	vector<int>	rangeOfVals = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
};