#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
struct JobIntervals {
	int start;
	int finish;
	int weight;
	int PrevJob;
};

class WIS{
	private:
	std::vector<WIS> intervals;
public:
	WIS(){
		inputInterval(0);
	}
	WIS(int n){
		inputInterval(n);
	}
	void sort();
	void add(JobIntervals interval);
	void inputInterval(const int &numInterval);
	bool checkInput(std::string s);
	void computeP();
	void DPBottomupopt();
	void FindSoln();
};