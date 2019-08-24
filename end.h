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
   @brief busca si el archivo en cuestión y lo mueve 
   @param file_name: nombre del fichero a encontrar 
   @return
   -1: no se ha podido abrir el directorio ROOT
   1: Se ha encontrado el archivo y se ha abierto 
   0: no se ha encontrado el archivo 
*/
int end ( string file ) {
  
  int salida;
  string path;

  if( (salida=buscaFichero(file,path)) == 1 ) {
    
    string toPath=path; //path de destino 
    toPath.replace(path.find(CARPETAS[0]),CARPETAS[0].length(), CARPETAS[1]);

    string mv="mv "+path+" "+toPath;
    
    system(mv.c_str()); 

    cout << "Ya debería de haberse producido el cambio"<< endl;
  }
  else
    cout << "No se ha encontrado " << file << endl; 

  return salida; 
  
}




#endif
