#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

#include "WISheader.h"


WIS::WIS(int n){
  inputInterval(n);
}
void WIS::inputInterval(const int &numInterval) {
    JobIntervals job;
    int start,finish,weight;
    std::string s; 
    int i=0;
    std::istringstream iss;
    while (i < numInterval) {

        do
        {
          std::cout << "Enter valid Start times, Finish times and Weight separated by a space:" << "\n";
          std::cout << "Si Fi Wi" << "\n";
          std::getline(std::cin >>std::ws, s);
          iss.clear();
          iss.str(s);
        }while(!(iss >> start >> finish >> weight) ||
        start < 1 || start > 12 ||
        finish <= start || finish > 12 ||
        weight <= 0);
        job.PrevJob =0;
        job.start = start;
        job.finish = finish;
        job.weight = weight;
        std::cout<<"Valid Input recieved: " << job.start << " " << job.finish << " " << job.weight << "\n";
        intervals.push_back(job);

        i++;
    }
}

void WIS::sort(){
  std::sort(intervals.begin(), intervals.end(), WIS::compareIntervals); 
  for(int i=0; i<intervals.size();i++){
    std::cout<<"\nStart: " << intervals[i].start
            << "\nEnd: " << intervals[i].finish
            <<"\nWeight: "<< intervals[i].weight;
  }
}

bool WIS::compareIntervals(const JobIntervals &j1, const JobIntervals &j2){
      return (j1.finish < j2.finish); 
}
void WIS::add(JobIntervals interval){
  intervals.push_back(interval);
}

void WIS::computeP(){
  for(int i=0;i<intervals.size();i++){
    for(int j=0; j<i; j++){
      if(intervals[j].start<=intervals[i].finish){
        intervals[i].PrevJob = j+1;
      }
    }
  }
    for(int i=0; i<intervals.size();i++){
    std::cout<<"\nPrevious job: " << intervals[i].PrevJob;
  }
}

void WIS::output(){
  std::cout<<"\nSorted Input Intervals by finishing time: \n" 
          <<std::right<<std::setw(17)<<"Index<i>"
          <<std::right<<std::setw(12)<<"S<i>"
          <<std::right<<std::setw(8)<<"F<i>"
          <<std::right<<std::setw(8)<<"W<i>"<<"\n";
  
  for(int i=0;i<intervals.size();i++){
    std::cout<<std::right<<std::setw(10)<<i+1
            <<std::right<<std::setw(16)<<intervals[i].start
            <<std::right<<std::setw(8)<<intervals[i].finish
            <<std::right<<std::setw(8)<<intervals[i].weight <<"\n";
  }
}