#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socketvar.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#define puerto 5000

//////para que se pueda ejecutar 


#define REQUEST "ADIOS_DESDE_SERVIDOR"
 

 
int main(int argc, char *argv[]){
	int MAX_DATA=900;
	//////aqui la esctructura para que acepte los sockets
	struct sockaddr_in Socket_Servidor;
	struct sockaddr_in  Socket_Cliente;
	struct lsock;
	socklen_t longc;
	int conexion_servidor, conexion_cliente;
	int opt =1;
	char Cadena[MAX_DATA];  
	///// condicional para que lea el puerto

	/////escucha en que puerto esta enlazado

	//Rellena toda la estructura de 0's
	bzero((char *)&Socket_Servidor, sizeof((char *)&Socket_Servidor));



	///Socket_Servidor = Abre_Socket_Inet_Puerto(atoi(argv[1]));
	/////// en la variable conexion de tipo int  es para la creacion del zoket 
	conexion_servidor= socket(AF_INET, SOCK_STREAM,0);

	



////aqui asigna al socket un puerto 
	if(bind(conexion_servidor, (struct sockaddr *)&Socket_Servidor, sizeof(Socket_Servidor)) < 0){ //asignamos un puerto al socket
    printf("Error al asociar el puerto a la conexion\n");
	close (conexion_servidor);
    return 1;
  }

		//// estos son los parametros para que acepte los puertos localhost 
	Socket_Servidor.sin_family= AF_INET;
	Socket_Servidor.sin_port=htons(puerto);
	Socket_Servidor.sin_addr.s_addr=INADDR_ANY;
	////////escuchamos
	listen(conexion_servidor,3);
	printf("A la escucha en el puerto %d\n", ntohs(Socket_Servidor.sin_port));

	/*
	* Se espera un cliente que quiera conectarse
	*/
	
	int numbytes = recv(conexion_cliente, Cadena, MAX_DATA,0);
	printf("\t\nNum_Bytes recibidos desde CLIENTE = [%d]\n", numbytes);
	printf("\tstrlen(Cadena) = [%lu]\n", strlen(Cadena));
	/*
	* Se escribe en pantalla la informacion que se ha recibido del
	* cliente
	*/
	printf ("\n\t--> Soy Servidor, He recibido desde CLIENTE:\n %s\n", Cadena);
	

	printf("\tTamaño de cadena a enviar a CLIENTE [%lu]\n", strlen(REQUEST));
	strcpy(Cadena, REQUEST);
	send(conexion_cliente, Cadena, strlen(Cadena),0);

	/*
	* Se cierran los sockets
	*/
	close (conexion_cliente);
	close (conexion_servidor);
	return 0;
}