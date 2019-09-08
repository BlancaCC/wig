#ifndef __OPEN__
#define __OPEN__

#include<iostream>
#include <string>
#include <vector>

//___cabeceras propias ___
#include "configuration.h"  
#include "initial.h"
#include "sistemaCarpetas.h" //buscaFichero
#include "tools.h" //is_number


using namespace std; 

//argumento con el que invocar

const string OPEN="open";


/**
   @brief search for a file name @param file_name, if it exist, it will be ipened
  
   @param file_name to be searched
   @return
   -1: directory ROOT can not be opened 
   1: file found and opened
   0: file has not been found
*/

int busca (string file_name, string & globalPath) {

  string global_name; //path desde la carpeta home + nombre
  int salida;

  salida=buscaFichero( file_name, global_name);
  globalPath=global_name;
  //si se ha encontrado 
  if( salida== 1) system( (EDITOR+" "+global_name+ " &").c_str() );

  return salida; 
}


/**
   @brief: create the file
   @return always return system order 

 */
int openFile(const string file_name) {

  return system( (EDITOR+" "+FECHA_ACTUAL +"/"+CARPETAS[0] +"/"+file_name+ "& ").c_str() );

}

/**
   @brief execute shell order editor path
   @return system orden
 */
int openFileAbs (const string absFileName) {
  
  return system( (EDITOR+" "+absFileName+" & ").c_str() );
}

/**
   @brief show index and file defoult out, demand one index open it file
   @return return 0 if ok
 */
int openSwitch() {
  int ret; 
  string selectFile;
  
  if( (ret=switchFile(selectFile)) == 0) {

    ret=openFileAbs(selectFile); 
  }

  return ret;

}

#endif


  /**
  if( access((FECHA_ACTUAL +"/"+ CARPETAS[1]+"/"+file_name).c_str() , (R_OK && W_OK) ) != -1  ) {

    //cout << "El fichero existe tanto en modo lectura como de escritura en la carpeta de acabados y se prodece a abrir " << endl;
    system( (EDITOR+" "+FECHA_ACTUAL +"/"+CARPETAS[1]+"/"+file_name+ " &").c_str() ); 
  }
   
  else { // el proyecto no se encuentra en acabados 
    //cout << "Sesystem( (EDITOR+" "+FECHA_ACTUAL +"/"+CARPETAS[0] +"/"+file_name+ "& ").c_str() );  trada de un fichero " << endl;
    system( (EDITOR+" "+FECHA_ACTUAL +"/"+CARPETAS[0] +"/"+file_name+ "& ").c_str() ); 
      
  }
  */
/**
  if( access((FECHA_ACTUAL +"/"+ CARPETAS[1]+"/"+file_name).c_str() , (R_OK && W_OK) ) != -1  ) {

    //cout << "El fichero existe tanto en modo lectura como de escritura en la carpeta de acabados y se prodece a abrir " << endl;
    system( (EDITOR+" "+FECHA_ACTUAL +"/"+CARPETAS[1]+"/"+file_name+ " &").c_str() ); 
  }
   
  else { // el proyecto no se encuentra en acabados 
    //cout << "Sesystem( (EDITOR+" "+FECHA_ACTUAL +"/"+CARPETAS[0] +"/"+file_name+ "& ").c_str() );  trada de un fichero " << endl;
    system( (EDITOR+" "+FECHA_ACTUAL +"/"+CARPETAS[0] +"/"+file_name+ "& ").c_str() ); 
      
  }
  */
