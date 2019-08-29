/**
   @file end.h :  Mueve un proyecto de carpeta 
 */

//buscamso el archivo
//ovemso de carpeta

#ifndef __END__
#define __END__

#include<iostream>
#include <string>


//___cabeceras propias ___
#include "configuration.h"  //ROOT, EDITOR, CARPETAS
#include "sistemaCarpetas.h" //buscaFichero



using namespace std;

const string END="end";


/**
   @brief find the file @param file
   @param file to find and move 
   @param toPath : path where the file is moved 
   @return
   -1: ROOT could not be opened
   1: file found and move 
   0: file not found
*/
int end ( string file, string & toPath ) {
  
  int salida;
  string path;
  
  if( (salida=buscaFichero(file,path)) == 1 ) {
    
    //string toPath=path; //path de destino
    toPath=path;
    toPath.replace(path.find(CARPETAS[0]),CARPETAS[0].length(), CARPETAS[1]); 

    string mv="mv "+path+" "+toPath;
    
    system(mv.c_str()); 

    cout << "File: "<< file<< " has been considered ended"<< endl;
  }
  else
    cout << "No se ha encontrado " << file << endl; 

  return salida; 
  
}




#endif
