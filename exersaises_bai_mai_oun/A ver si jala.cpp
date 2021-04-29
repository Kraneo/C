#include <stdio.h>

int main(){
	int x,y;
	
	x=4;
	
	printf("Acierta el numero x!!\nIntroduce un valor:");
	scanf("%i",&y);
	
	if(x==y){
		printf("Nice work, son of a bitch\n");
	}
	else {
		printf("You've failed assold\n");
	}
	return 0;
}
