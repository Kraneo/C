//codigo que cree el factorial de un numero tecleado
#include <stdio.h>
int main () {
	int x,i,k;
	
	printf ("Introduce un numero:");//3
	scanf ("%i",&x);//3
	
	k = 1;
	
	for (i = 1 ; i <= x ; i++ ) {
		k = k * i;
	}
	printf ("El factorial de %i es: %",x,k);
	
	return 0;
}
