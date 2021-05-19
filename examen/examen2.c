#include <stdlib.h>


int main(){
char arrayChar[5];

int i=0;
for (i=0;i<=5;i++){
arrayChar[i++]='A';
arrayChar[i++]='B';
arrayChar[i++]='C';
arrayChar[i++]='D';
arrayChar[i++]='E';
} for (i=0;i<=4;i++){
	printf("LETRAS :%c \n",arrayChar[i]);
}
		char *punteroChar;
		punteroChar=&arrayChar[0];
	
		char *punteroCharDos;
		punteroCharDos=&arrayChar[0];
	
			printf("%c\n\t",arrayChar[0]);
	
			printf("%c\n\t",*punteroChar);
			
			printf("%c\n\t",*punteroCharDos);
	
			printf("%c\n\t",arrayChar[4]);
	
			printf("%c\n\t",*(punteroChar+4));
	
			printf("%c\n\t",*(punteroCharDos+4));
	
		for (i = 0; i < 5; ++i)
		{
			printf("%c", *(punteroCharDos+i));
		}	
			printf("\n\t");
	
		for (i = 0; i < 5; ++i)
		{
			printf("%c", *(punteroCharDos+i)); 
		}
	printf("\n");
    return 0;
    	}
