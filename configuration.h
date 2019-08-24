
/**
   Variables de configuración 
modificar de un fichero o de variables de entorno ???
 */


#ifndef __CONFIGURACION__
#define __CONFIGURACION__

#include<iostream>
#include <string>
#include <vector>


using namespace std;

//_________ datos básicos____________

// ruta donde se almacenan los archivos 
const string ROOT="/home/blanca/repositorios/escriturias/"; 

//editor en el que abrir el programa 
const string EDITOR="emacs";



//___________ carpetas a crear _________

vector<string> CARPETAS={"proyectos","definitivos"}; 


#endif
