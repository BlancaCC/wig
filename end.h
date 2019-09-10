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

const string END="end"; //definity
const string CLOSE="close";
const string REMOVE="remove";


/**
   @brief find the file @param file
   @param file to find and move 
   @param toPath : path where the file is moved 
   @return
   -1: ROOT could not be opened
   1: file found and move 
   0: file not found
*/
int end ( string file, string & toPath, bool definitive ) {
  
  int salida;
  string path;
  string destiny;

  if(definitive)
    destiny = CARPETAS[1];
  else
    destiny = CARPETAS[2];
  
  if( (salida=buscaFichero(file,path)) == 1 ) {
    
    toPath=path;
    toPath.replace(path.find(CARPETAS[0]),CARPETAS[0].length(), destiny); 

    string mv="mv "+path+" "+toPath;
    
    system(mv.c_str()); 

    cout << "File: "<< file<< " has been considered ended"<< endl;
  }
  else
    cout << "No se ha encontrado " << file << endl; 

  return salida; 
  
}

/** 
    @brief end multiple files with a swith standar output
    
    @return like end:
   -1: ROOT could not be opened
   1: file found and move 
   0: file not found
 */

int endSwitch( bool definitive ) {

  int ret=0;

  vector<string> files =vector<string>();

  switchFiles(files);
  string globalPath; 

  if(definitive)
    for( auto &fil: files) {
      ret=end(fil, globalPath,definitive);
    }
    
  return ret;
}

//crear un remove



#endif
