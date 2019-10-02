
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
const string STAT_FIL_NAM="allStatistics.csv"; 
const string GIT_STAT="last_statistics.csv";
//Don't edit these
const string STAT_FILE=ROOT+STAT_FIL_NAM;
const string SPC=","; //csv delimiter

//___________ default files status _________

vector<string> CARPETAS={"proyectos","definitivos","cerrados"};

//help file name
const string HELP_FILE="INSTRUCTIONS.txt"; 
//proyectos to in proccess file
//definitivos: to finishes
//cerrados:no finishes but neither working


#endif
