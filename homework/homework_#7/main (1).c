//**compila el programa en el GDB compilador que es online y despues pon los archivos main.c, jelp.h y fwork.c--el archivo .txt aparecera de manera automatica--**//
//**al dar run al sistema, selecciona primero la forma de administradorJEFE, y de PIN utiliza el numero 0. Al añadir un userTRABAJADOR desde administradorJEFE por primera vez la accion porfavor pon que su PIN sera 1**//
#include "jelp.h"
int main(){
FILE *flx;
int tePin,
teTime,
flag = 1,
pin,
optn,
bucle = 1, 
user_system;
    
time_t temp = time(0);
struct tm *tlocal = localtime(&temp);
char output[128],
buffer[32];
    
   printf("Hi, WELCOME...The actual date is %2d/%2d/%d", tlocal->tm_mday,tlocal->tm_mon+1,tlocal->tm_year+1900); 
   printf("\nThe exact time is (o´clock) %d:%d:%2d",tlocal->tm_hour-5,tlocal->tm_min,tlocal->tm_sec); 
   printf("\nDo you want to enter to the system as administradorJEFE or userTRABAJADOR?\nIf you are userTRABAJADOR, put 1... If you are administradorJEFE, put 2...\n");
scanf("%d", &optn);
if (optn == 1){ 
    optn = 0;
   printf("Nice, introduce your pin down: \n");
scanf("%d", &pin);
if (checkpinn(pin) != 1){ 
    printf("This PIN does not exists in the program, please check again the register of the valid pin in system.tx or create a new user as administradorJEFE\n");
    printf("Bye, have a SUCCESSFUL day of job!\n");
exit(1);
    }
    printf("Hi! #%d  -- This is the register!-- \nWhat would you do now?\n", pin);
    printf("*PUT 1 for Enter todays job-\n*PUT 2 for EXIT todays job-\n");
scanf("%d", &optn);
    
switch (optn){
            
 case 1: 
flx = fopen("log.txt", "a");
    printf("pin of enter sucessful:%d Date of tday:%s %s\n", pin, output, buffer);                   //Credits,collab. Marcela Montserrat. She also explained me this code because I didn't undestand very well
    fprintf(flx, "e%d %lu %s %s\n", pin, (unsigned long)time(NULL), output, buffer);
    printf("Think in BIG THINGS! Is you!");
    fflush(flx);
    fclose(flx);
break;
            
  case 2: 
flx = fopen("times.txt", "r+");
 while (flag != 0){
fscanf(flx, "%d %d", &tePin, &teTime);
  if (tePin == pin){
teTime += seeTimeWork(pin);
fseek(flx, -3, SEEK_CUR);
fprintf(flx, "%d %d", pin, teTime);
fflush(flx);
fclose(flx);
flag = 0;
     }
}
flx = fopen("log.txt", "a");
printf("pin of exit sucessful:%d Date of tday:%s %s\n", pin, output, buffer);
fprintf(flx, "s%d %lu %s %s %d\n", pin, (unsigned long)time(NULL), output, buffer, seeTimeWork(pin));
printf("\n worked for %d seconds \n See you, Thank you!\n", seeTimeWork(pin));
fflush(flx);
fclose(flx);
fprintf(flx, "%d %d\n", pin, seeTimeWork(pin));
    break;
        }
    }
    
else if (optn == 2) { 
        optn = 0;
   printf("Hi!  introduce your pin: \n");
scanf("%d", &pin);
if (pin != 000){
   printf("This is NOT AN administradorJEFE\n");
        EOF;
     }
else {
while (bucle == 1){
      optn= 0;
printf("\nHi!, administradorJEFE, what are you going to do right now?\n");
printf("PUT 5 to see the assistance of an userTRABAJADOR\t PUT 4 to CREATE a userTRABAJADOR\n");
printf("PUT 3 to see the hours worked of userTRABAJADOR\tPUT 6 to EXIT\n");
fflush(stdin);
 scanf("%d", &optn);
 switch (optn){ 
            
case 5: 
printf("PUT the pin of the userTRABAJADOR to see their assistance:\n");
fflush(stdin);
scanf("%d", &pin);
if (checkpinn(pin) != 1){ 
printf("this pin does not exixt in this program, check again the register of the valid PINS in system.tx  or create an userTRABAJADOR as administradorJEFE \n");
printf("Bye, have a cool day of job-\n");
        exit(1);
}
seeAssistance(pin);
    break;
case 4:
creaRegist();
    break;
case 3:
printf("PUT the pin of the userTRABAJADOR to see their hours of work til now: \n");
fflush(stdin);
scanf("%d", &pin);
    if (checkpinn(pin) != 1) 
 { 
printf("this pin does not exixt in this program, check again the register of the valid PINS in system.tx or create an userTRABAJADOR as administradorJEFE \n");
printf("See you later, have a nice day!\n");
    exit(1);
}
printf("the userTRABAJADOR with pin...: %d,  worked for %d seconds \n", pin, calcuHoursJob(pin));
 break;
case 6: 
exit(1); 
 break;
                }
            }
        }
    }
else{
printf("Sorrryyyy, we cant assist you right now man, you did not write a valid opt. PUT ENTER to EXIT\n");
        exit(1);
    }
}
