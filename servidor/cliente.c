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
/*
  printf("Escribe un mensaje: ");
  fgets(buffer, 100, stdin);
  send(conexion, buffer, 100, 0); //envio
  bzero(buffer, 100);
  recv(conexion, buffer, 100, 0); //recepción
  printf("%s", buffer);
*/

#define REQUEST "CADENA ENVIADA DESDE CLIENTE..."  

int main(int argc, char *argv[]){

	/*
	* Descriptor del socket y buffer para datos
	*/
	int MAX_DATA=999;
	int Socket_Con_Servidor;
	char Cadena[MAX_DATA];
	struct sockaddr_in serv_addr; //Declaración de la estructura con información para la conexión
  	 //Declaración de la estructura con información del host

	////puerto=(atoi(argv[2]));
	serv_addr.sin_family = AF_INET; //asignacion del protocolo
  	serv_addr.sin_port = htons(puerto); //asignacion del puerto

	Socket_Con_Servidor = socket(AF_INET, SOCK_STREAM, 0);

	 // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
	/*if (Socket_Con_Servidor == 1){
		printf ("No puedo establecer conexion con el servidor\n");
		exit (-1);
	}*/

   if (connect(Socket_Con_Servidor, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

	printf("\tTamaño de cadena a enviar a SERVIDOR [%lu]\n", strlen(REQUEST));
	strcpy(Cadena, REQUEST);
	send(Socket_Con_Servidor, Cadena, strlen(Cadena),0);

	int numbytes = recv(Socket_Con_Servidor, Cadena, MAX_DATA,0);
	printf("\t\n\nNum_Bytes recibidos desde SERVIDOR = [%d]\n", numbytes);
	printf("\tstrlen(Cadena) = %lu\n", strlen(Cadena));
	
	/*
	* Se escribe en pantalla la informacion recibida del servidor
	*/
	printf ("\n\t--> Soy cliente, He recibido desde SERVIDOR :\n %s\n", Cadena);

	/*
	* Se cierra el socket con el servidor
	*/
	close(Socket_Con_Servidor);
	return 0;
}
