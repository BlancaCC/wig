/**
   @brief remove files 
   @author Blanca Cano 
   @date September 2019

 */

#ifndef __REMOVE__
#define __REMOVE__

#include <iostream>
#include "sistemaCarpetas.h"
#include "statistics.h"

using namespace std;

const string REMOVE="remove"; 
/**
   @brief remove simple instruction
   @return system return 
 */
int removeInstruction( const string name) {
  int ret;
  
  if ( (ret=system ( ("rm "+name).c_str() ))== 0 ) {
    recordRegister( "rm", 4, name);
  }

  return ret; 
}

/**
   @brief search for a file name @param file_name, if it exist it will be remvo
  
   @param file_name to be searched
   @return
   -1: directory ROOT can not be removed 
   1: file found and removed
   0: file has not been found
*/

int remove (string file_name, string & globalPath) {

  string global_name; //path desde la carpeta home + nombre
  int salida;

  salida=buscaFichero( file_name, global_name);
  globalPath=global_name;
  //si se ha encontrado 
  if( salida== 1)
    salida = removeInstruction(global_name);

  return salida; 
}



/**
   @brief show index and file default out, demand one index open it file
   @return return 0 if ok
 */
int removeSwitch() {
  int ret; 
  string selectFile;
  
  if( (ret=switchFile(selectFile)) == 0) {

    ret=removeInstruction(selectFile); 
  }

  return ret;

}


#endif
