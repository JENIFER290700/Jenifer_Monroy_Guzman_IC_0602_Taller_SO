#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

//Funcion main

int main(int argc, char **argv){

if (argc >1){

	//1.- variables
	int fd, fd2, longitud_cliente, puerto;
	puerto = atoi(argv[1]);

	//estructuras de tipo sokaddr
	struct sockaddr_in server;
	struct sockaddr_in client;

	//bin o asiggnar IP y Puerto
	server.sin_family = AF_INET;
	server.sin_port = htons(puerto);
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(&(server.sin_zero),8); //rellena con ceros

	//2.-Definir socket
	if ((fd=socket(AF_INET, SOCK_STREAM,0) )<0){
		perror("Error de apertura");
		exit(-1);
	}

	//3.-Crear socket
	if (bind(fd,(struct sockaddr*)&server, sizeof(struct sockaddr))==-1){
		printf("Error en bind \n");
		exit(-1);
	}

	//4.- Listen, modo escuha activa
	if (listen(fd,5)==-1){
		printf("Error en listen \n");
		exit(-1);
	}

	//5.- Accept, aceptar la conexiones de clients
	while(1){
		longitud_cliente = sizeof(struct sockaddr_in);

		if ((fd2 = accept(fd,(struct sockaddr *)&client,&longitud_cliente))==-1){
			printf("Error en accept\n");
			exit(-1);
		}
	send(fd2,"Bienvenido al Servidor \n",26,0);
	close(fd2);
	}
	close(fd);
	}else{
		printf("No se ingreso puerto \n");
		}

	return 0;
}
