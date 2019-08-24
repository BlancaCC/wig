/**
   @file info
   @brief Get information about file structure

   Order avaible:  (argv)
   -e || -end : Only show ended files
   -o ||  -open : Only show opened files
   -a ||-all : show all the filles
   (add time control)
   
 */


#ifndef __INFO__
#define __INFO__

#include<unistd.h>
#include<sys/types.h>

#include <iostream>
#include <string>
#include <stack>


//____ includes propios ___

#include "sistemaCarpetas.h" //recorreTodo(bool isOpen,bool isEnd, vector<string>& open, vector<string>& end)bool isOpen,bool isEnd, vector<string>& open, vector<string>& end

using namespace std;

string INFO="info"; 
string INFO_MS = "-e || -end : Only show ended files\n"
   "-o ||  -open : Only show opened files\n"
  "-a ||-all : show all the filles\n"; 

  /**
     @brief show in console information about file structure
   */

int files( string mode="" ) {

  //start selecting mode label
  vector<string> objetives=vector<string>(); 

  if( mode =="-e" || mode =="-end") { //show ended files hide open 
    objetives.push_back( CARPETAS[1]);
  }
  else if ( mode =="-o" || mode == "-open") {
    objetives.push_back( CARPETAS[0]); 
  }
  else if (mode =="" || mode =="-a" || mode == "-all") {
    objetives.push_back( CARPETAS[1]);
    objetives.push_back( CARPETAS[0]);
  }
  else {
    cout << INFO_MS << endl;
    return 1; 
  }

  //queremos que empiece a mostrar por el final

  vector< string > filesv = vector<string>(); 

  escaba( objetives, ROOT, filesv); 

  cout << "Files: " << endl;
  for( auto & myfile : filesv)
    cout << myfile << endl;
  
      
  return 0;  
  
}




#endif
