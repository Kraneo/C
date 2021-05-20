#include <stdio.h>
#include <string.h>
#include "header.h"

typedef struct
 {
	char tittle[50];                                //Using char to represent or contain a single character, this is very improtant in this code
	char author[50];
	int fixed;
}
book;

typedef struct 
{
	char tittle[50];
	int fixed;
	book books[50];
}
library;
library libraries[50];


int main()                                                        //declared function
{
	int option,carry;
	
	takeoff();
	
	do 
	{
		do
		 {
			printf("Select an option:\n\n");
			printf("[1] - Add a new section.\n");
			printf("[2] - Add a new book.\n");
			printf("[3] - Ask for a book.\n\n");
			printf("Option: ");
			scanf("%i",&option);
			printf("\n");
		} 
		while(option < 1 || option > 3);
		switch(option) 
		{                                               //Using a switch-case struct to acomodate the options
			case 1:
			 {
				newsection(option);
				break;
			}
			case 2: 
			{
				newbook(option);
				break;
			}
			case 3:
			 {
				askforabook(option);
				break;
			}
		}                                                          //print the options of the program to select one and continue with the functionality
		printf("Do you want to continue?\n\n");
		printf("[1] - Yes, why not.\n");
		printf("[2] - Take me out of here.\n\n");
		printf("Option: ");
		scanf("%i",&carry);
		printf("\n");
	}
	 while(carry == 1);
	
	system("pause");
	return 0;
}
void newsection()
 {
	int i,focboing;
	
	focboing = 0;
	
	for(i = 0; i < 50 && focboing == 0; i++) 
	{
		if(libraries[i].fixed == 0)
		 {
			printf("Give to the section a cool name: ");
			fflush(stdin);
			fgets(libraries[i].tittle,50,stdin);
			trade(libraries[i].tittle);
			printf("\n");
			printf("We already have %i sections\n\n",i+1);
			libraries[i].fixed = 1;
			focboing = 1;
		}
	}
}
void newbook()                                                     //declared function
 {
	int i,j,focboing,option;
	
	focboing = 0;
	
	do
	 {
		printf("Where is going to be this book?\n\n");
		for(i = 0; i < 50; i++)
		 {
			if(libraries[i].fixed == 1)
			 {
				printf("%i - %s.\n\n",i,libraries[i].tittle);
			}
		}
		printf("Option: ");
		scanf("%i",&option);
		printf("\n");
	} 
	while(option < 0 || option > 50);
	
	for(i = 0; i < 50; i++) 
	{
		for(j = 0; j < 50 && focboing == 0; j++)
		 {
			if(libraries[option].books[j].fixed == 0) 
			{
				printf("What's book's name?: ");
				fflush(stdin);
				fgets(libraries[option].books[j].tittle,50,stdin);
				trade(libraries[option].books[j].tittle);
				printf("\n");
				printf("Who wrote this book?: ");
				fflush(stdin);
				fgets(libraries[option].books[j].author,50,stdin);
				trade(libraries[option].books[j].author);
				printf("\n");
				printf("We already registered %i at the momment.\n\n",j+1);
				libraries[option].books[j].fixed = 1;
				focboing = 1; 
			}
		}
	}
}
void askforabook()                                                               //declared function
{
	int i,j,focboing,comparar;
	char comprobar[50];
	
	focboing = 0;
	
	printf("What are you looking for?: ");
	fflush(stdin);
	fgets(comprobar,50,stdin);
	trade(comprobar);
	printf("\n");
	
	for(i = 0; i < 50; i++) 
	{
		for(j = 0; j < 50 && focboing == 0; j++)
		 {
			comparar = strcmp(comprobar, libraries[i].books[j].tittle);
			if(comparar == 0) 
			{
				printf("You can find %s on '%s' section. Written by %s.\n\n",libraries[i].books[j].tittle,libraries[i].tittle,libraries[i].books[j].author);
			    focboing = 1;
			}
		}
	}
	
}
void takeoff()                                       //declared function
{
	int i,j;
	
	for(i = 0; i < 50; i++) 
	{
		for(j = 0; j < 50; j++) 
		{
			libraries[i].fixed = 0;
			libraries[i].books[j].fixed = 0; 
		}
	}
}
void trade(char libraries[50])                           //declared function
 {
	int i,j,focboing;
	
	focboing = 0;
	
	for(i = 0; i < 50; i++) 
	{
		if(libraries[i] == '\n') 
		{
			libraries[i] = '\0';
		}
	}
}
