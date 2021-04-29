#include <stdio.h>
int main(){
	int x,y;
	
	y=2;
	printf("Introduce un valor para x:");
	scanf("%i",&x);
	if(x%y==0){
		printf("Este numero es par\n");
	}
	else {
		printf("Este numero es impar\n");
	}
	return 0;
}
