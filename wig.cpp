#include<iostream>
#include <string>

//_____ficheros propios _____
#include "initial.h"
#include "sistemaCarpetas.h"
#include "open.h"
#include "end.h"
#include "info.h"
#include "statistics.h"  //recordRegister
#include "git.h" //gitPush

using namespace std; 

int main( int argc, char *argv []) {

  string initialBashOrder="find "+ROOT+" -type f -name '*~' -delete";
  system( initialBashOrder.c_str() );

  
  if( ! (argc > 2) ) {
    if ( argc == 2 ) {
      if(GIT.compare(argv[1]) == 0 ) {
      gitPush(); 
      }
      else if (OPEN.compare(argv[1]) == 0 ){
	openSwitch(); 
      }
    }
    else
      cout <<"holi aquí hay un errorcillo \n" << ERROR << endl;    
  }
  else if (  OPEN.compare( argv[1]) == 0 ) {
    string globalPath;
    if (busca(argv[2],globalPath) == 0) {  // not found
      consistenciaDirectorio(); // make sure, the month dir is created
      openFile(argv[2]);  //we create the file

      recordRegister( argv[2], 0, FECHA_ACTUAL+"/"+CARPETAS[0]+"/"+argv[2]);  
    }
    else {
      recordRegister( argv[2], 1, globalPath ); 
    }
  }
  else if ( END.compare( argv[1]) == 0 ) {
    string globalPath;
    if( end(argv[2],globalPath,true) == 1) { // if file founded and moved
      
      recordRegister( argv[2], 2, globalPath ); 
    }
    
  }
  else if( CLOSE.compare(argv[1]) == 0 ) {
      string globalPath;
    if( end(argv[2],globalPath, false) == 1) { // if file founded and moved
      
      recordRegister( argv[2], 3, globalPath ); 
    }
    }
  else if (INFO.compare(argv[1]) == 0) {
    files( argv[2]); 
  }

  else {

    //buscamos carpeta donde se encuentre 
    cout << "Ninguna de las opcines está contemplada " << endl << ERROR<< endl;
    
  }
  
  

  return(0); 
}
