/**
   @brief Help file with all the program instruccion 
   @author Blanca Cano 
   @date September 2019
 */
#ifndef __HELP__
#define __HELP__

#include <iostream>
#include <string>

using namespace std;

#include "configuration.h"
const string HELP="help";

int printInstructions() {
  string order="cat " +HELP_FILE; 
  return system( order.c_str() ); 
}



#endif
