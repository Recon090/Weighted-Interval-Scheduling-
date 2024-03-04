/*
Name: Pawel Chowdhury
Class: CS 236
Semester: Spring 2024
*/

#include <iostream>
#include <limits>
#include "WISheader.h"

int main() {
	int input =-1;
	bool valid = false;
	std::cout<<"\n++++ Weighted Interval Scheduling with Bottom up dynamic programming ++++";

	//Takes input and error checks it
	do{
		std::cout<<"\nPlease enter a valid number of intervals: ";
		if(!(std::cin>>input)){
			std::cout<<"Input must be an integer \n";	
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}else{
			if(input >= 0 ){
				valid = true;
			}
		}

	}while(!valid);

	//Input Intervals and leads user to class functions which outputs Weighted Interval Scheduling
	WIS schedule(input);
	schedule.sort();
	schedule.computeP();
	schedule.output();
	schedule.DPBottomupopt();
	if(input != 0)
	std::cout<<"The jobs involved in the maximum profit are";
	schedule.findSoln(input-1);
	return 0;
}