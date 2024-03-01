#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include "WISheader.h"



void WIS::inputInterval(const int &numInterval){
    std::vector<char> input;
    JobIntervals job;
    std::string s; 
    for(int i=0; i< numInterval;++i)
    {
      std::cout << "Enter Start time, Finish time and Weight seperate by a space:" << "\n";

      std::cout<<"Si Fi Wi"<<"\n";

      std::getline(std::cin, s);
       
      std::stringstream ss(s);
      ss >> job.start >> job.finish >> job.weight;
      std::cout << "First: " << job.start << std::endl;
      std::cout << "Second: " << job.finish << std::endl;
      std::cout << "Third: " << job.weight << std::endl;      




    }
}

bool WIS::checkInput(std::string s)
  {
    bool valid = true;
 /*   for (int i = 0; i<s.size(); i++) {
      if(!isdigit(s[i]) && i==1){
        std::cout<<"\nInvalid output, please input a number";
        return false;
      }
    }*/
    return valid;
  }

