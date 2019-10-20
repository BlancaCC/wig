#!/bin/bash 

echo "¿cual es el path dónde se encuentra su repositorio?"
read path

if [ -d "$path" ]; then
    
   #move program to configuration side
   sudo cp wig /usr/bin/    #main programe
   sudo cp wigit /usr/bin/  #bash script to lazygit

   cp wig.conf $HOME/.config/
   echo "PATH="$path >>$HOME/.config/wig.conf
   #cp wig $HOME/.config/    # configuration file
   
   cp .lazyGit.out $path
   echo "Creado todo en orden"
   else
       echo "el directorio no existe :( se aborta la instalación"
fi
   
