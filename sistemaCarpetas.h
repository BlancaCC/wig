
#ifndef __SISTEMA_CARPETAS__
#define __SISTEMA_CARPETAS__

#include<unistd.h>
#include<sys/types.h>  	/* Primitive system data types for abstraction\
			   of implementation-dependent data types.
			   POSIX Standard: 2.6 Primitive System Data Types
			   <sys/types.h>
			*/
#include<sys/stat.h>
#include<fcntl.h>
#include<dirent.h>


#include<iostream>
#include <string>
#include <vector>
#include <algorithm>    // std::find

//___ mis includes ___

#include "initial.h"
#include "tools.h" //isNumber


using namespace std;

///_____________________

/**
   Crea directorio de clasificación de las fechas 
*/
int consistenciaDirectorio() {

  
  //comprobamos si se ha creado la carpeta fecha de este mes 
  DIR *midir;
  struct dirent *entrada;  // mi_dirent es un puntero a una estructura

  if( (midir=opendir(FECHA_ACTUAL.c_str())) == NULL) { // si nfo existe el directorio
    cout << "No existe el directorioo " << FECHA_ACTUAL << endl;

    //crear directorio
    if ( mkdir(FECHA_ACTUAL.c_str() , 0777 ) ) {
      cout << "El directorio no ha podido ser creado" << endl;
      return 2; 
    }
    else
      cout << "El directorio de la fecha se ha creado con éxito" << endl; 

    //creamos árbol de directorios

    for ( auto & dir : CARPETAS ) {
      if ( mkdir( (FECHA_ACTUAL +"/"+dir).c_str() , 0777 )) { 
	cout << "El directorio" << dir << " no ha podido ser creado" << endl;
	return -1; 
      }


      cout << "Se ha creado la carpeta mensual con éxito" << endl;
    }
    
    return 0; 
  } // end de si la carpeta de éste mes no existía 
 
}


/**
   @brief busca si el archivo, si lo encuentra devuelve en la variabe path el nombre de la ruta global donde ha sido encontrado
   @param file_name: nombre del fichero a encontrar 
   @return
   -1: no se ha podido abrir el directorio ROOT
   1: Se ha encontrado el archivo y se ha abierto 
   0: no se ha encontrado el archivo 
*/

int buscaFichero( string file_name, string & path) {


  
  DIR *midir;
  struct dirent *entrada;  // dirent es un puntero a una estructura

  if( (midir = opendir(ROOT.c_str()))== NULL ) {
    cout << "No se ha podido abrir " << ROOT<< endl;
    return -1;
  }

  while( (entrada= readdir( midir) ) != NULL) {

    string ruta= entrada->d_name; 
    //vamos comprobando si tal combinación existe
      
    if( ruta[0] == '2') for( auto & dir: CARPETAS) {

	if( access(( ROOT+ruta+"/"+dir+"/"+file_name).c_str() , F_OK) == 0  ) {
	  
	  path = ROOT+ruta+"/"+dir+"/"+file_name; 
	  
	  return 1;  //se acaba de abrir el fichero en cuestión 
	}
      } //for directorios
    
  } // leer entradas

  return 0; // no se ha encontrado  

}


/**
   @brief chearch for spacially dir to dig its contents 
   @param stop: dir to stop 
   @param contents: save dirs' names
   @param auxiliar variable to implemnt recursive DON'T USE
   @return 0 always
 */
int dig( vector<string>& stop, string path, vector<string>& contents, bool last=false) {
  DIR *dir; 
  struct dirent *entry;
  
  if( (dir = opendir(path.c_str()))!= NULL ) {
    while( (entry= readdir(dir) ) != NULL) {
     
      string elem = entry->d_name;
      
      if( elem != "." && elem != ".." ) {
	//save elem
	if( last == true) { 
	  contents.push_back(elem); 
	}
	//is not end dir
	else if( find( stop.begin(), stop.end(), elem) == stop.end()) {
	  dig( stop, (path+elem+"/"), contents, false); 
	} //we are in last path
	else { 
	  dig( stop, (path+elem), contents, true);
	} 
      }
    }
  }

 return 0; 
} //int dig


/**
   @brief Like dig + absolutes path chearch for spacially dir to dig its contents 
   @param stop: dir to stop 
   @param names: save dirs' names
   @param auxiliar variable to implemnt recursive DON'T USE
   @return 0 always
 */
int dig( vector<string>& stop, string path, vector<string>& names, vector<string>& absPath ,bool last=false) {
  DIR *dir; 
  struct dirent *entry;
  
  if( (dir = opendir(path.c_str()))!= NULL ) {
    while( (entry= readdir(dir) ) != NULL) {
     
      string elem = entry->d_name;
      
      if( elem != "." && elem != ".." ) {
	//save elem
	if( last == true) { 
	  names.push_back(elem);
	  absPath.push_back(path+"/"+elem);
	}
	//is not end dir
	else if( find( stop.begin(), stop.end(), elem) == stop.end()) {
	  dig( stop, (path+elem+"/"), names, absPath, false); 
	} //we are in last path
	else { 
	  dig( stop, (path+elem), names, absPath, true);
	} 
      }
    }
  }

 return 0; 
} //int dig


/**
   @brief show index and file default out, demand one index open it file
   @return return 1 if no option selected
 */
int switchFile( string & selectFile ) {

  int ret = 0; //return 0 if opened correct
  
  //show avaibles files
  vector<string> stopv=vector<string>();
  stopv.push_back(CARPETAS[0]); //open files only
  
  vector< string > filesv = vector<string>();
  vector< string > paths = vector<string>();
  int index=0;

  dig( stopv, ROOT, filesv, paths);

  cout << "Files: " << endl;
  for( auto & myfile : filesv) {
    cout <<" " <<index << "\t" << myfile << endl;
    index++;
  }

  //get number
  string n;
  cout << "write number file to be open: " ;
  cin >> n;

  if ( ! is_number(n) )
    ret = 1;
  else {
    
    int num= atoi(n.c_str());
    if ( num >=0 && num < index ) {
      selectFile= paths[num]; 
    }
    else
      ret=1; 
  }
        
  return ret; 
}

int switchFiles(vector<string> & selectFile ) {
  
  int ret = 0; //return 0 if opened correct
  
  //show avaibles files
  vector<string> stopv=vector<string>();
  stopv.push_back(CARPETAS[0]); //open files only
  
  vector< string > filesv = vector<string>();
  vector< string > paths = vector<string>();
  int index=0;

  dig( stopv, ROOT, filesv, paths);

  cout << "Files: " << endl;
  for( auto & myfile : filesv) {
    cout <<" " <<index << "\t" << myfile << endl;
    index++;
  }

  //get numbers
  vector<int>numbers=vector<int>();
  if (numCollect(numbers,index,0) == 0)
    ret = 1;

  //asign files-numbers

  for (auto & i :numbers){
    selectFile.push_back( filesv[i]);
  }

  return ret; 
}


#endif  
