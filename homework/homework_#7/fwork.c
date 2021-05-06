#include "jelp.h"                                 

int creaRegist(void)
{
int newpinn = 1,
pin, 
flag = 0;
char houre[30],
hourS[30], 
dayS [40];
FILE *fiche;
fiche = fopen("system.txt", "a");
if (fiche == NULL){
printf("WARNING: The doc system.txt could not be created---\n");
    }
else{
while (1){
if (checkpinn(newpinn)){
    newpinn++;
    }
else{
break;                                    
     }
}
fiche = fopen("system.txt", "a");
    printf("The new pin generated it is : %d\n", newpinn);
    printf("Introduce the days that works, (NO spaces) (example: TuesdayFriday\n");
    fflush(stdin);
    scanf("%s", dayS);
    printf("Introduce the hour of Enter of the userTRABAJADOR, please (example: 14:15, etc)\n");
    fflush(stdin);
    scanf("%s", houre);
    printf("Introduce the hour of Exit of the userTRABAJADOR (example: 15:30  etc)\n");
    fflush(stdin);
    scanf("%s", hourS);
    fprintf(fiche, "c%d e%s s%s d%s\n", newpinn, houre, hourS, dayS);
    printf("Congrats it is added, thank you");
    fflush(fiche);
    fclose(fiche);
fiche = fopen("times.txt", "a");
    fprintf(fiche, "%d 0 \n", newpinn);
    fflush(fiche);
    fclose(fiche);
    printf("\n");
    }
}
int checkpinn(int pin){
int pinS[9], 
j = 0;
int m;
FILE *fiche;
fiche = fopen("system.txt", "r");
if (fiche == NULL){
printf("WARNING: The doc system.txt could not be created---\n");
}
else{
while ((m = fgetc(fiche)) != EOF){
if (m == 'm'){
m = fgetc(fiche);
pinS[j] = m - '0';
if (pin == pinS[j])
{
fflush(fiche);
fclose(fiche);
     return 1;
        }
j = +1;
            }
        }
    }
fflush(fiche);
fclose(fiche);
}
int seeAssistance(int pin){
int m, assist = 0;
FILE *fiche;
fiche = fopen("log.txt", "r");
while ((m = fgetc(fiche)) != EOF){
if (m == 's'){
m = fgetc(fiche) - '0';
if (m == pin){
assist++;
        }
      }
}
fflush(fiche);
fclose(fiche);
printf("\nThe userTRABAJADOR %d have : %d assistance\n", pin, assist);
}
int seeTimeWork(int pin){
char tim1[20], 
tim2[20];
int t1, t2, tem;
int m, assist = 0;
FILE *fiche;
fiche = fopen("log.txt", "r");
while ((m = fgetc(fiche)) != EOF){
if (m == 'e'){
    m = fgetc(fiche) - '0';
    if (m == pin){
        m = fgetc(fiche) - '0';
        fgets(tim1, 11, fiche);
        t1 = atoi(tim1);
            }
        }
    }
tem= (unsigned long)time(NULL) - t1;
fflush(fiche);
fclose(fiche);
return tem;
}
int calcuHoursJob(int pin){
int hourS, m, pinarch;
FILE *fiche;
fiche = fopen("times.txt", "r");
while (1){
fscanf(fiche, "%d %d", &pinarch, &hourS);
if (pinarch == pin){
return hourS;
 break;
    }
 }
}
 //**Credit Collab.Montserrat O., she explain me the hw7 and i got based on that code struct(functions form)**//