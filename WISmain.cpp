/*
Name: Pawel Chowdhury
Class: CS 236
Semester: Spring 2024
*/

#include <iostream>
#include "WISheader.h"
#include <iomanip>

int main() {
	int input =-1;
	std::cout<<"\n++++ Weighted Interval Scheduling with Bottom up dynamic programming ++++";
	do{
		std::cout<<"\nPlease enter a valid number of intervals: ";
		std::cin>>input;
	}while(input<0);

	WIS schedule(input);
	schedule.sort();
	schedule.computeP();
	schedule.output();
	return 0;
}