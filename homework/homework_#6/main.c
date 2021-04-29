//To execute this code correctly just put the name "olmodeperas.h" to the other code, and everything it's going to be ok
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> 
#include "olmodeperas.h"

 {
size_t tamano = sizeof(chavo); 
size_t omitirta = sizeof(chavo);
chavo *nodal = (chavo *)malloc(tamano);                 //Credits to Marcela Montserrat
chavo *omitenodal = (chavo *)malloc(omitirta);
strcpy(nodal->username, username);
strcpy(nodal->password, password);
nodal->zurdo = nodal->diestro = NULL;
return nodal;
}

void incluir (chavo *nodal, char *estring, char *password) {

if (strcmp(estring, nodal->username) > 0) {

if (nodal->diestro == NULL) {
nodal->diestro = nvonodal(estring, password);
 }
else {
incluir (nodal->diestro, estring, password);
  }
 }
else {

if (nodal->zurdo == NULL) {
nodal->zurdo = nvonodal(estring, password);
 }
else {
incluir (nodal->zurdo, estring, password);
  }
 }
}

chavo *buscachavos(chavo *nodal, char *estring) {

if (nodal == NULL) {
return NULL;
}
if (strcmp(estring, nodal->username) == 0) {
return nodal;
}
else if (strcmp(estring, nodal->username) > 0) {
return buscachavos(nodal->diestro, estring);
}
else {
return buscachavos(nodal->zurdo, estring);
  }
}
chavo * buscacontra(chavo *nodal, char *estring, char *passw)
{
if (nodal == NULL) {
return NULL;
}
if (strcmp(estring, nodal ->username) == 0) {
if (strcmp(passw, nodal->password) == 0) {
*nodal ->username = NULL;
*nodal ->password=NULL;
return NULL;
  }
}
else if (strcmp(estring, nodal->username) > 0) {
return buscacontra (nodal->diestro, estring, passw);
}
else {
return buscacontra (nodal->zurdo, estring, passw);
  }
}
void acomodar (chavo *nodal) { 
if (nodal != NULL) {
acomodar (nodal->zurdo);
printf("%s,", nodal->username);
acomodar (nodal->diestro);
  }
}

int main(int argc, char const *argv[]) { 
char user[superestring];
char pass[superestring];
chavo *jengibre = NULL;
printf("\nHi,Hallo,Bonjour,Hola,Aloha,Ni Hao\n\nCreate an account first\n");
printf("Enter the user to continue:\n");
fflush(stdin);
scanf("%s", &user[0]);
printf("Now enter the password:\n");
fflush(stdin);
scanf("%s", &pass[0]);
jengibre = nvonodal(user,pass);
int add = 0, terminate = 0, ordenacion = 0;
char option, m;

while ((m = getchar()) != EOF){

printf("\n*Enter letter o if you want to add a new user:\n*Enter letter h to terminate an user:\n*Enter letter z to see al users:\n\n");
fflush(stdin);
scanf("%c", &option);

switch (option) { 
case 'o':
add = 1;
break;
case 'h':
terminate = 1;
break;
case 'z':
ordenacion = 1;
break;
default:
printf("Ohh no, it seems you've done something wrong. Don't do that again, seriousley, try another thing");
break;
}

if (add != 0 || terminate != 0 || ordenacion != 0) {

if (add == 1) {
char user[superestring];
char pass[superestring];
printf("Enter the user you want to add:\n");
fflush(stdin);
scanf("%s", &user[0]);
struct estringnodal *waveusuario = buscachavos(jengibre, user);

if (waveusuario != NULL) {
printf("\n\tDamn it the user '%s' is already in the system\n", user);
}

else {
printf("Enter the password of the user:\n");
fflush(stdin);
scanf("%s", &pass[0]);
incluir(jengibre, user, pass);
printf("\n\t Nice now '%s' is in the system \n", user);
  }
}

else if (terminate == 1) {
char user[superestring];
char pass[superestring];
printf("Enter the password of the user you want to terminate:\n");
fflush(stdin);
scanf("%s", &user[0]);
struct estringnodal *waveusuario = buscachavos(jengibre, user);
if (waveusuario != NULL) {
printf("Enter the password of the user:\n");
fflush(stdin);
scanf("%s", &pass[0]);
struct estringnodal *waveusuario = buscacontra(jengibre, user, pass);
if (waveusuario == NULL) {
printf("\n The user %s has been terminated \n", user);
}
else {
printf("\t Fuck, this is not the password, write again\n");
  }
}
else {
printf("\n This user isn't in the system\n");
  }
}
else if (ordenacion == 1) {

acomodar(jengibre);
printf("\nPress ENTER to continue\n");
getchar();
  }
}
add = 0;
terminate = 0;
ordenacion = 0;
  }
}
