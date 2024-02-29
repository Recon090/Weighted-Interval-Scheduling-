#pragma once
#include <iostream>
#include <iomanip>
#include <string>
struct JobIntervals {
	int start;
	int finish;
	int weight;
	int PrevJob = -1;
};

class WIS{
public:
	WIS(const int &numInterval);
	void Sort();








private:

};