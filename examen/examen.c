#include <stdio.h>

int  main(){
char x;
char *p;
char y;
char *puntero;
x='x';
p=&x;
printf("\nEL CONTENIDO DEL PUNTERO P ES: %c",*p);
p++;
printf("\nEL CONTENIDO DEL PUNTERO P + 1 ES: %c",*p);
p+=2;
printf("\nEL CONTENIDO DEL PUNTERO P + 2 ES: %c",*p);
y='y';
puntero=&y;
printf("\nEL CONTENIDO DEL PUNTERO ES: %c\n",*puntero);
return 0;
}
