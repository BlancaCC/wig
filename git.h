 /**
   @brief push to github 
   @requeriment ROOT dir must be a git dir
 */

#ifndef __GIT__
#define __GIT__

#include <iostream>
#include <string>

using namespace std;

const string GIT="git";
const string programName="lazyGit.out"; 

void gitPush() {
  string order=ROOT+programName;
  system (("cd " + ROOT).c_str() ); //cd ~/repositorios/escriturias/
  system( order.c_str() ); 
}

#endif
