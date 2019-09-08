/**
   @brief : do:
   git add .
   git commit -F <archivo>
   git push origen master 
 */


#include <iostream>
#include <fstream>
#include <string>

#include "configuration.h"
#include "tools.h"

using namespace std;



/**
   @brief Change head of GIT_STAT FILE 
   @requeriment GIT_STAT FILE starts with a number, it is suppost to be a count of commits
   @return number of push
 */
int readableHead() {

  int timesPush;

  //read timesPush
  ifstream readFile (ROOT+GIT_STAT);
  
  string readout;

  getline(readFile,readout);
  cout << "El dato leído es " << readout << endl;
  if (is_number(readout)) {
    timesPush = stoi(readout);
  }
  else
    timesPush=0; 

  readFile.close();

  //Write head commit file

  ofstream outFile(ROOT+GIT_STAT);
  outFile << "Commit nº " << timesPush;
  outFile.close(); 

  
  return timesPush; 
}

/**
   @brief Try to commit and push
   @return !0: something get wrong in sytem funcion
   @return 0: ok
 */
int gitOrder() {

  int ret; //system return  0 if ok
  string commit="git commit -F "+ROOT+GIT_STAT;
  
  ret = system("git add .");
  ret = (ret== 0)? system(commit.c_str()) : ret;
  ret = (ret== 0)? system("git push"):ret;
  
  return ret; 

}


int newStat( int num) {
  ofstream ofs;
  ofs.open( GIT_STAT, ios::out | ios::trunc);

  ofs<<num<<endl;

  ofs.close();

  return 0; 
}




int main( int argc, char* argv[]) {
  
  //open the file and change
  int timesPush = readableHead(); 

  timesPush++; 

  //system order
  if ( gitOrder() !=0) {
    cout << "No se ha podido subir " << endl; 
  }
  else
    cout << "Se ha actualizado el repositorio con éxito" << endl; 

  //clear stat file
  newStat(timesPush); 
  
  return 0; 
}
