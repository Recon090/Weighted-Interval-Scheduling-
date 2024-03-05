#pragma once
#include <iostream>
#include <vector>

//Defines a structure for Job intervals
struct JobIntervals {
	int start;		  //Start time for Job
	int finish;		  //Finish Time for Job
	int weight;		  //Total Weight(Profit) for Job
	int PrevJob;		//Value to store the latest compatible job based on index
	int max;
};

class WIS{
	private:
	//Vector to Store all Jobs
	std::vector<JobIntervals> intervals;
	//int to represent max profit
	int maxProfit;
public:
	//Default Constructor
	WIS();
	//Constructor
	WIS(int n);
	//Sorting For Vector
	void sort();

	//Adds intervals
	void add(JobIntervals interval);

	//Takes in a number of intervals and fills vector
	void inputInterval(const int &numInterval);

	//Finds previous job compatible with the current in focus
	void computeP();

	//Calculates the m
	void DPBottomupopt();

	//Finds the maximzed profit based off of DP
	void findSoln(int n);

	//Outputs WIS
	void output();

	//Static Function used for Sort()
	static bool compareIntervals(const JobIntervals &j1, const JobIntervals &j2);
};
