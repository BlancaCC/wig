#!/bin/bash 

echo "¿cual es el path dónde se encuentra su repositorio?"
read path

if [ -d "$path" ]; then 
   echo "Creado todo en orden"
   sudo cp wig /usr/bin/
   sudo cp wigit /usr/bin/
   cp lazyGit.out $path
   else
       echo "el directorio no existe :( se aborta la instalación"
fi
   
