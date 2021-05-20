#!/bin/bash
ROOT_UID=0
SUCCESS=0

if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "ROOT PARA SCRIPT"
  exit $E_NOTROOT
fi  

file=$1

if [ "${file}X" = "X" ];
then
   echo "INDICA EL ARCHIVO DEL USUARIO A AGREGAR..."
   exit 1
fi
ingresarUsuario(){
	
	eval user="$1"
	eval password="$2"
	eval userid="$3"
	eval grupoid="$4"
	eval info="$5"
	eval home="$6"
	eval shell="$7"

	if grep -q ${grupoid} /etc/group
	then
		
		if grep -q ${user} /etc/passwd 
		then
		echo "--->USUARIO EXISTENTE        =${user}<---"
		else
		
		useradd -c "${info}" -p "${password}" -d "${home}${user}" -		s "${shell}" "${user}"  -g "${grupoid}" 			
		if [ $? -eq $SUCCESS ];
		then
				
		echo "--->USUARIO CREADO  USUARIO= ${user}   CONTRASEÑA= $		{password}<---"
		echo "[${user}:${password}:${userid}:$
		{grupoid}:${info}:${home}${user}:${shell}]"
		else
		 	echo "USUARIO NO CREADO"
		fi
			
		fi
		else
		echo "NO ESTA EL GRUPO"
		echo "CREAR GRUPO  ${grupoid} ANTES DEL USUARIO ${user}"
		fi
}

while IFS=: read -r f1 f2 f3 f4 f5 f6 f7
do
	ingresarUsuario "\${f1}" "\${f2}" "\${f3}" "\${f4}" "\${f5}" "\${f6}" "\${f7}"
done < ${file}
exit 0
