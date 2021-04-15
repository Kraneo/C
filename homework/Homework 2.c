#include<stdio.h>
#include<math.h>
#define K 21

void prime(int n);                                      /*Credits*/
void binary(int m);

int main() {
  prime(K);
  return 0;
}

void binary(int m)                              /*Ignister codec, algorithm to trnasform from decimal to binary*/
{
    int i=0; 
    int base[10]={0};
    while(m>0)
    {
        
	base[i]= m%2;
	m/=2;
	++i; 
    }

    for(int x=9;x>=0;--x)
    {
       printf("%01d",base[x]);
    }
     printf("\n");
}


void prime(int k)                                   /*Abel Guitian, alrogithm to obtain my first K numbers*/
{
  int count, i, flag, sr;
  int n=1;
  count = 1;

  while(count <= k){
    sr = sqrt(n);
    flag = 0;
    for(i=2; i<= sr; i++){
      if(n%i==0){
        flag = 1;
        break;
      }

    }

    if(flag==0){

      binary(n);
      count++; 
    }

    n++;                                            /*Raúl Chavez, how to combinate the algorithms*/

  }
}


