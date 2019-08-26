
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

//_________ basis dates____________

//path to save files
const string ROOT="/home/blanca/repositorios/escriturias/"; 

//editor to open files
const string EDITOR="emacs";

//statistics file's name
const string STAT_FIL_NAM="last_statistics.csv";
//Don't edit these
const string STAT_FILE=ROOT+STAT_FIL_NAM;
const string SPC=","; //csv delimiter

//___________ default files status _________

vector<string> CARPETAS={"proyectos","definitivos"}; 


#endif
