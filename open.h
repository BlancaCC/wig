#ifndef __OPEN__
#define __OPEN__

#include<unistd.h>
#include<sys/types.h>  	/* Primitive system data types for abstraction\
			   of implementation-dependent data types.
			   POSIX Standard: 2.6 Primitive System Data Types
			   <sys/types.h>
			*/
#include<sys/stat.h>
#include<fcntl.h>
#include<dirent.h>
#include<time.h>

#include<iostream>
#include <string>

//___cabeceras propias ___
#include "configuration.h"  
#include "initial.h"
#include "sistemaCarpetas.h" //buscaFichero


using namespace std; 

//argumento con el que invocar

const string OPEN="open";


int openFile(string file_name) {

  if( access((FECHA_ACTUAL +"/acabados/"+file_name).c_str() , (R_OK && W_OK) ) != -1  ) {

    //cout << "El fichero existe tanto en modo lectura como de escritura en la carpeta de acabados y se prodece a abrir " << endl;
    system( (EDITOR+" "+FECHA_ACTUAL +"/acabados/"+file_name+ " &").c_str() ); 
  }
   
  else { // el proyecto no se encuentra en acabados 
    //cout << "Se trada de un fichero " << endl;
    system( (EDITOR+" "+FECHA_ACTUAL +"/proyectos/"+file_name+ "& ").c_str() ); 
      
  }

  return 0;
}

/**
   @brief busca si el archivo en cuestión ya ha sido creado 
   si es así lo devuelve
   @param file_name: nombre del fichero a encontrar 
   @return
   -1: no se ha podido abrir el directorio ROOT
   1: Se ha encontrado el archivo y se ha abierto 
   0: no se ha encontrado el archivo 
*/

int busca (string file_name) {

  string global_name; //path desde la carpeta home + nombre
  int salida;

  salida=buscaFichero( file_name, global_name);
  //si se ha encontrado 
  if( salida== 1) system( (EDITOR+" "+global_name+ " &").c_str() );

  return salida; 
}


#endif
