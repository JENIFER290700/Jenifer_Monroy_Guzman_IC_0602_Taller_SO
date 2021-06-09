#include <stdio.h>
#include <string.h>

#define tam_nombre 100
#define tam_lectura 100


int crea_arch(char *nom_arch);
int datos_archivo(char *nom_arch);

FILE *abrir_arch(char *nom_arch); {
	FILE *ptrArch;
	ptrArch = fopen(nom_arch, "r");
	if (ptrArch == NULL) {
		printf("\n\t El archivo no pudo abrirse : %s\n", nom_arch);
	}
	else{
		printf ("\n\t Archivo abierto : %s", nom_arch);
	
	}
	return ptrArch;
}
void c_archivo(FILE *ptrArch,char *nom_arch){
fclose(ptrArch);
printf("\n\tArchivo cerrado\n\t")
}

int exis_Arch(char *nom_arch) {
	FILE *ptrArch;
	int ex = 0;
	ptrArch = fopen(nom_arch, "r");
	if(ptrArch != NULL) {
	existe=1;
	c_archivo(ptrArch, nom_arch);
	}
	return existe;
}


int main(int argc, char const *argv[]) {
	
	char or[TAM_NOMBRE];
	char dest [TAM_NOMBRE];
	int total_Palabras = 0, cont;	
	
	
	if (argc != 3){
		printf("No existen los argumentos revisalos \n");
		return 1;
	}
	printf("%s, origen %s, destino %s\n", argv[0], argv[1], argv[2]);	
	
	for(cont = 0; cont < argc; cont++){
		printf("ARFUMENTOS[%d] = %s\n", cont, argv[cont]);
	}	

	strcpy(or, argv[1]);
	strcpy(dest, argv[2]);

	if(exi_arch(or)){
	printf("\t ARCHIVO : %s \n", or);
	if(archivo(or)){
	printf("\tEL ARCHIVO CONTIENE DATOS : %s\n", or);
	total_Palabras = archivo(or);	
	printf("TODOS LOS ELEMENTOS [%d]\n\n",total_Palabras);

	arrypalabra(or);			
	printf("\n DATOS : \n");
	for(int i = 0; i < total_Palabras; i++){
		printf("=>%d, %s\n", i, p[i]);
	}
	
	sort(p, total_Palabras);
	
	printf("\nORDEN\n");
		for(int i = 0; i < total_Palabras; i++){
		       printf("=>%d, %s\n", i, p[i]);
		    }

}
}		
} 
