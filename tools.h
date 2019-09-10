#ifndef __TOOLS__
#define __TOOLS__

#include <iostream>
#include <string>
#include <vector>

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


/** 
    @brief collect cin number while they are number between @param inf and @param sup
    @param v : list of integer
    @return number of elements in @param v
 */

int numCollect( vector<int> & v, int sup, int inf=0) {
  
  int cnt = 0;
  string s;
  bool in_range=true;
  int n;

  cout << "To select a file write a number then press ENTER" << endl
    << "press another thing to leave:  " << endl; 
  
  while (in_range) {
    cin >> s;
    in_range=false;
    
    if( is_number(s) ) {
      n = atoi( s.c_str() );
      
      if ( n >= inf && n<sup ) {
	v.push_back(n);
	cnt++;
	in_range=true;
      }
	
    }
    
  }

  return cnt;
}


#endif
