#ifndef __INITIAL__
#define __INITIAL__

#include<time.h>

#include<iostream>
#include <string>

//_____ficheros propios _____
#include "configuration.h" //quizás habría que hacer que lea de un solo fichero

using namespace std;



// manejo de fechas 
time_t current = time(0); //get time now
tm * now = localtime( &current);


string FECHA_ACTUAL = ROOT+to_string(now->tm_year + 1900) +"_"+ to_string( now->tm_mon +1 ); 


const string ERROR="No se ha introducido en número correcto de elementos\n"
  "Las opciones son: \n"
  "open <NOMBRE DEL FICHERO NUEVO O A ABRIR> \n"
  "end <FICHERO QUE SE TIENE QUE DAR POR TERMINADO> \n";

  
#endif
