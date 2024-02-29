#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "WISheader.h"



void WIS::inputInterval(const int &numInterval){
    std::vector<char> input;
    std::string s;
    for(int i=0; i<numInterval;i++)
    {
      do
      {
      std::cout<<"Enter Start time, Finish time and Weight seperate by a space: \n Si Fi Wi"; 
      std::getline(std::cin, s);
      }while(!checkInput(input));
    }
}

bool WIS::checkInput(std::vector<char> s)
  {
    bool valid = true;
    for(int i=0;i<s.size();i++){
      if(!isdigit(s[i]) && i==1){
        std::cout<<"\nInvalid output, please input a number";
        return false;
      }
    }
    return valid;
  }

