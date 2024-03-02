#pragma once

struct JobIntervals {
	int start;
	int finish;
	int weight;
	int PrevJob;
};

class WIS{
	private:
	std::vector<JobIntervals> intervals;
public:
	WIS();
	WIS(int n);
	void sort();
	void add(JobIntervals interval);
	void inputInterval(const int &numInterval);
	void computeP();
	void DPBottomupopt();
	void findSoln();
	void output();
	static bool compareIntervals(const JobIntervals &j1, const JobIntervals &j2);
};