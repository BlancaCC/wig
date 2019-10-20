
/**
   Variables de configuración 
modificar de un fichero o de variables de entorno ???
 */


#ifndef __CONFIGURACION__
#define __CONFIGURACION__

#include<iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Config {

  map <string,string> dict; 
  

public:
  
  Config( string fileName, const char delimiter='=') {
    //read config file information
    ifstream file(fileName);
    string line;
    string name, content;
    while(getline(file,name, delimiter) && getline(file,content) ) {

      dict[name]=content;
    }
      
    file.close();  
  }

  string lookup( string name) {
    return dict[name];
  }
    
};
  
//_________ basis dates____________
const string PATH_CONFG_FILE="wig2.conf"; //"/home/blanca/.config/wig.conf";  //"~/.config/wig.conf"; //".wig"; /home/blanca/repositorios/escriturias/
Config cfg(PATH_CONFG_FILE); 
//path to save files
const string ROOT="/home/blanca/repositorios/escriturias/"; 
//cfg.lookup("PATH");//"/home/blanca/repositorios/escriturias/"; 

//editor to open files
const string EDITOR=cfg.lookup("EDITOR");//"emacs";

//statistics file's name
const string STAT_FIL_NAM="allStatistics.csv";//cfg.lookup("HISTORY"); //"allStatistics.csv"; 
const string GIT_STAT="last_statistics.csv"; //cfg.lookup("RECENT_ACTIONS");//"last_statistics.csv";
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
