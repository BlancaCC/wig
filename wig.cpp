#include<iostream>
#include <string>

//_____ficheros propios _____
#include "initial.h"
#include "sistemaCarpetas.h"
#include "open.h"
#include "end.h"
#include "info.h"


using namespace std; 

int main( int argc, char *argv []) {

  string initialBashOrder="find "+ROOT+" -type f -name '*~' -delete";
  system( initialBashOrder.c_str() );

  
  if( ! (argc > 2) ) { // no se han introducido los datos correctos
    cout <<"holi aquí hay un errorcillo \n" << ERROR << endl;    
  }
  else if (  OPEN.compare( argv[1]) == 0 ) {
    if (busca(argv[2]) == 0) {  // se encuentra y se abre
      consistenciaDirectorio(); // creamos el directorio de éste mes si no estaba 
      openFile(argv[2]);  // se crea
    }
  }
  else if (  END.compare( argv[1]) == 0 ) {
    end( argv[2]); 
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
