#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>//la requiere hostent

int main(int argc, char *argv[]){
	if (argc > 2){
		//1.- variables
		char *ip;
		int fd, numbytes, puerto;
		char buf[100];
		puerto = atoi(argv[2]);
		ip =argv[1];

		//variables de la suma
		int n1,n2;
		int suma = n1 +n2;;
		//printf("Ingrese un numero: ");

		struct hostent *he; //recibira informacion el nodo remoto
		struct sockaddr_in server; //info del servidor

		if ((he = gethostbyname(ip))== NULL){
			//llamada a gethostname
			printf("gethostbyname() error\n");
			exit(-1);
		}

		//2.- Definir socket
		if((fd=socket(AF_INET, SOCK_STREAM,0))== -1){
			//llamda a socket
			printf("socket() ERROR \n");
			exit(-1);
		}

		//datos del servidor
		server.sin_family = AF_INET;
		server.sin_port = htons(puerto);
		server.sin_addr = *((struct in_addr *)he->h_addr);
		//he->h_addr pasa la info de ''*he'' a "h_addr"
		bzero(&(server.sin_zero),8); //rellena con ceros

		//3.-Conectarse al servidor
		if (connect(fd,(struct sockaddr *)&server, sizeof(struct sockaddr))==-1){
			printf("connect() ERROR \n");
			exit(-1);
		}

		if ((numbytes=recv(fd,buf,100,0)) ==-1){
			//llamda a recv()
			printf("ERROR en recv() \n");
			exit(-1);
		}
		buf[numbytes]= '\0';
		printf("Mensaje Server: %s\n",buf);
		printf("Ingrese un numero: ");
		scanf("%i",&n1);
		printf("Ingrese otro numero: ");
		scanf("%i",&n2);
		//muestra el mensaje que manda el servidor
		close(fd);		
	}else{
		printf("No se ingreso IP Y PUERTO por parametro \n");
	}
	return 0;
}