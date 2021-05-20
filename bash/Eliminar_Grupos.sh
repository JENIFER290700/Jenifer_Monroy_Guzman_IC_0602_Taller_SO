#!/bin/bash
ROOT_UID=0
SUCCESS=0
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "EJECUTAR SCRIPT"
  exit $E_NOTROOT
fi  

file=$1

if [ "${file}X" = "X" ];
then
   echo "INDICAER EL GRUPO A ELIMINAR ..."
   exit 1
fi
eliminarGrupo(){
	eval nombreGrupo="$1"
	if grep -q ${nombreGrupo} /etc/group  
    then  
        groupdel "${nombreGrupo}"
		echo "EL GRUPO [${nombreGrupo}] FUE ELIMINADO CON EXITO..."
	else .
		echo "EL GRUPO [${nombreGrupo}] NO ES POSIBLE ELIMINARLO..."
	fi
}

while IFS=: read -r f1
do
	eliminarGrupo "\${f1}"	
done < ${file}

exit 0
