/**
   @file statistics.h
   @brief each valid intructions is save in a statistics file
   csv structure:
   name | day |month | year | hour | minute
   @author Blanca
   @date August 2019
 */


#ifndef __STATISTICS__
#define __STATISTICS__


#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "configuration.h" //STAT_FILE,  SPC

using namespace std;


int recordRegister( string order, int number, string longName) {

  fstream fout;
  
  time_t now=time(0); // current date/time based on current system
  //"Number of sec since January 1,1970:" << now 
  tm *mytime=localtime( &now); 

  fout.open( STAT_FILE, ios::out | ios::app );

  
  fout << order << SPC
       << mytime->tm_mday << SPC //day
       << mytime->tm_mon + 1 << SPC //month
       << mytime->tm_year + 1900 << SPC //year
       << mytime->tm_hour + 1 << SPC //hours
       << mytime->tm_min << SPC //minures
       << number << SPC  //0=new 1==existed
       << longName << endl; //path location + name

  fout.close(); 
  
  return 0; 
}

#endif
