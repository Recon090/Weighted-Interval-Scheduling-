#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <algorithm>


#include "WISheader.h"

//define implementation of constructor
WIS::WIS(int n){
  inputInterval(n);
}
//define implementation of input interval
void WIS::inputInterval(const int &numInterval) {   //takes in
    JobIntervals job;         //temp variable to take intervals and put in class vector
    int start,finish,weight;  //Temp variables to put data into structure variables
    std::string s;            //input string
    int i=0;                  //index
    std::istringstream iss;   //Treats input as a stream
    while (i < numInterval) {

        do
        {

          std::cout << "Enter valid Start times(1-12), Finish times and Weight separated by a space:" << "\n";
          std::cout << "Si Fi Wi" << "\n";
          std::getline(std::cin >>std::ws, s);
          iss.clear();
          iss.str(s);

        }while(!(iss >> start >> finish >> weight) ||
        start < 1 || start > 12 ||
        finish <= start || finish > 12 ||
        weight <= 0); //checks if user put in a valid integer and valid range of numbers


        job.PrevJob =-1;
        job.start = start;
        job.finish = finish;
        job.weight = weight;
        //Message to confirm to user input was recieved
        std::cout<<"Valid Input recieved" << "\n";
        intervals.push_back(job);
        i++;
    }
}

void WIS::sort(){
  if(intervals.size()>1){           //checks to see if vector has enough elements to even need a sort
    std::sort(intervals.begin(), intervals.end(), WIS::compareIntervals); //uses STL sort and static function to sort vector
  }
}

bool WIS::compareIntervals(const JobIntervals &j1, const JobIntervals &j2){   //implemntation of a static function
      return (j1.finish < j2.finish);                                         //checks which Jobinterval has the highest finish time
}
//implementation to add interval
void WIS::add(JobIntervals interval){ 
  intervals.push_back(interval);       
}

//implementation to compute the previous job that is compatible
void WIS::computeP(){

  for(int i=0;i<intervals.size();i++){
    for(int j=0; j<i; j++){//loops until reach current job to find compatible ones, takes most recent
      if(intervals[j].finish<=intervals[i].start){
        intervals[i].PrevJob = j;
      }
    }
  }
}
//implementation of output, outputs all elements of vector in order based on finish times
void WIS::output(){
  std::cout<<"\nSorted Input Intervals by finishing time: \n" 
          <<std::right<<std::setw(17)<<"Index<i>"
          <<std::right<<std::setw(12)<<"S<i>"
          <<std::right<<std::setw(8)<<"F<i>"
          <<std::right<<std::setw(8)<<"W<i>"<<"\n";
  if(intervals.size()>=1){
    for(int i=0;i<intervals.size();i++)
    {
     std::cout<<std::right<<std::setw(10)<<i+1
              <<std::right<<std::setw(16)<<intervals[i].start
              <<std::right<<std::setw(8)<<intervals[i].finish
              <<std::right<<std::setw(8)<<intervals[i].weight <<"\n";
    }
  }else{
    std::cout<<"\nNo Intervals to Display \n";
  }
}
//implementation to maximize profits
void WIS::DPBottomupopt(){
  if(intervals.size() >=1)  //checks if interval is big enough to justify searching for max
  {    
    intervals[0].max = intervals[0].weight;
    int max = 0;
    for(int i=1; i<=intervals.size();i++){  
      int j = intervals[i].PrevJob;
      intervals[i].max = std::max((intervals[i].weight + intervals[j].max),intervals[i].weight);  //compares to see if the interval and its compatible are the max or just the interval
    }
    for(int i=0;i<intervals.size();i++){  //loops to find the max profit
      if(intervals[max].max<intervals[i].max){ 
        max = i;
      }
    }
    //outputs max profit
    std::cout<<"Maximum Profit of non-overlapping scheduling is " << intervals[max].max << "\n";
  }
}
//implementation to find the intervals which maximize profit
void WIS::findSoln(int n){
  if(n == -1)
  {
    //nothing
  }else if((intervals[n].weight+intervals[intervals[n].PrevJob].max) > intervals[n-1].max)
  {
    std::cout<< " (" << intervals[n].start << " " << intervals[n].finish << " " << intervals[n].weight << ")";
    findSoln(intervals[n].PrevJob);
  }
  else{
    findSoln(n-1);
  }
}
