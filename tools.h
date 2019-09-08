#ifndef __TOOLS__
#define __TOOLS__

#include <iostream>
#include <string>

using namespace std; 

/**
   @return if @param s  is a number
 */
bool is_number(const  string& s)  {
    
  auto it=s.begin();
  bool is_dig=true; 
    
  while (is_dig && it != s.end() ) {
    is_dig = isdigit(*it)? true : false;
    it++; 
  }
  return is_dig; 
}

/**
   @return if @param s  is a number avoiding @param exception characterers
 */
bool is_numberE(const  string& s, const char exception ='0')  {
    
  auto it=s.begin();
  bool is_dig=true; 
    
  while ((is_dig || (*it)==exception) && it != s.end() ) {
    is_dig = isdigit(*it)? true : false;
    it++; 
  }
  return is_dig; 
}

#endif
