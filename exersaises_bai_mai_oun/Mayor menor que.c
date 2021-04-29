#include <stdio.h>
int main() {
	int x,y,z;
	int max,min;
	
	printf("Introduzca un valor para x:");
	scanf("%i",&x);
	
	printf("Introduzca un valor para y:");
	scanf("%i",&y);
	
	printf("Introduzca un valor para z:");
	scanf("%i",&z);
	
	if (x > y){
		if (x > z){
			max = x;
		}
		else {
			max = z;
		}
	}
	else {
		if (y > z){
			max = y;
		}
		else {
			max = z;
		}
	}
	if (x < y){
		if (x < z) {
			min = x;
		}
		else {
			min = z;
		}
	}
	else {
		if(y < z){
			min = y;
		}
		else {
			min = z;
		}
	}
	printf("El numero mas grande de aqui es %i\n", max);
	printf("El numero menor de aqui es %i\n", min);
}
