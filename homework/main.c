<<<<<<< HEAD
#include <stdio.h>                                    
#include <stdlib.h>                               
#include <ctype.h> 
#include "calc.h"
#define MAXOP 100 

int main(){
    int type;
    int cant_lett=0; 
    int cant_numb=0; 
    int cant_errs=0; 


    double op2;
    char s[MAXOP];
    int fnd_lett=0;
    int question=0;
    int assign=0;
    int fnd_numb=0;
    int move=0;
    int answer_no=0;
    int answer_yes=0;
    int error=0;

    int abc[26]={0};     
    int contador[26]={0}; 

              printf("Introduce the variable you wish with the value you prefer---EXAMPLE: f=9 ");

     while ((type = getop(s)) != EOF) {
        if (move==0) {
        switch (tolower(type)) {
            case NUMBER:
            push(atof(s));
            fnd_numb = atof(s);
            cant_numb++;
            break;
            case '+':
            push(pop() + pop());
            break;
            case '*':
            push(pop() * pop());
            break;
            case '-':
            op2 = pop();
            push(pop() - op2);
            break;
            case '/':
            op2 = pop();
            if (op2 != 0.0)
            push(pop() / op2);
            else
            printf("error founded: 0 divisor\n");
            break;
            case '\n':
            if (!assign&&!question){ 
            printf("\t%.1f\n", pop());

            assign=0;                    
            fnd_lett=0;
            question=0;
            fnd_numb =0;
            cant_numb=0;
            cant_lett=0;
            cant_errs=0;
            }
            
           else if (assign==1&&!question&&cant_numb==1&&cant_lett==1){ 
            if (contador[fnd_lett]==0){
                abc[fnd_lett]=fnd_numb;
                printf("assign made it\n");
                contador[fnd_lett]++;

                assign=0;      
                fnd_lett=0;
                question=0;
                pop();
                pop();
                fnd_numb=0;
                cant_numb=0;
                cant_lett=0;
                cant_errs=0;

            }

             else{

                move=1;
                printf("You will write again the value of the variable? YES-> y NO->n\n");
                pop();
                pop();
            }
            }

            else if (assign==1&&question==1&&cant_numb==1&&cant_lett==1){
                abc[fnd_lett]=fnd_numb;
                pop();
                pop();
                printf("assign made it\n");
                contador[fnd_lett]++;           

                assign=0;
                fnd_lett=0;
                question=0;
                fnd_numb=0;
                cant_numb=0;
                cant_lett=0;
                cant_errs=0;
            }
                else{
                printf("error founded: check again the input\n");
                assign=0;                               
                fnd_lett=0;
                question=0;
                fnd_numb=0;
                cant_numb=0;
                cant_lett=0;
                pop();
                pop();
                cant_errs=0;
            }

            break;
            case '=':
            assign=1;
            break;
            case ':':
            question=1;
            break;
            
            default:
            if (type>=97&&type<=122){
                push(abc[type-97]);    
                fnd_lett=type-97;  
                cant_lett++;    

            }
            else {
            cant_errs++;
            printf("error founded: it has been detected an unknown command %s\n", s);
            }
            break;
        }

     }

     else{

     switch (tolower(type)){
     case 'e':
     answer_yes++;
     push(0); 
     break;
     case 'p':
     answer_no++;
     push(0); 
     break;
     case '\n':

     if (answer_yes==1&&answer_no==0&&error==0){
        abc[fnd_lett]=fnd_numb;
        pop();
        printf("assign made it\n");

        contador[fnd_lett]++;

        assign=0;                     
        fnd_lett=0;
        question=0;
        fnd_numb=0;
        answer_no=0;
        answer_yes=0;
        error=0;
        move=0;
        cant_numb=0;
        cant_lett=0;
        cant_errs=0;

     }
     else if (answer_yes==0&&answer_no==1&&error==0){
        pop();
        printf("assign doesnt work, check that, please.\n");

        assign=0;                       
        fnd_lett=0;
        question=0;
        fnd_numb=0;
        answer_no=0;
        answer_yes=0;
        move=0;
        error=0;
        cant_numb=0;
        cant_lett=0;
        cant_errs=0;

     }
     else{
        pop();
        printf("error founded: Check the input here\n\n");
        printf("You will write again the value of the variable? YES-> y NO->n\n");
        answer_no=0;
        answer_yes=0;
        error=0;
        cant_numb=0;
        cant_lett=0;
        cant_errs=0;
     }
     break;
     default:
     error++;
     break;
     }
     }
    }
    return 0;
=======
#include <stdio.h>                                    
#include <stdlib.h>                               
#include <ctype.h> 
#include "calc.h"
#define MAXOP 100 

int main(){
    int type;
    int cant_lett=0; 
    int cant_numb=0; 
    int cant_errs=0; 


    double op2;
    char s[MAXOP];
    int fnd_lett=0;
    int question=0;
    int assign=0;
    int fnd_numb=0;
    int move=0;
    int answer_no=0;
    int answer_yes=0;
    int error=0;

    int abc[26]={0};     
    int contador[26]={0}; 

              printf("Introduce the variable you wish with the value you prefer---EXAMPLE: f=9 ");

     while ((type = getop(s)) != EOF) {
        if (move==0) {
        switch (tolower(type)) {
            case NUMBER:
            push(atof(s));
            fnd_numb = atof(s);
            cant_numb++;
            break;
            case '+':
            push(pop() + pop());
            break;
            case '*':
            push(pop() * pop());
            break;
            case '-':
            op2 = pop();
            push(pop() - op2);
            break;
            case '/':
            op2 = pop();
            if (op2 != 0.0)
            push(pop() / op2);
            else
            printf("error founded: 0 divisor\n");
            break;
            case '\n':
            if (!assign&&!question){ 
            printf("\t%.1f\n", pop());

            assign=0;                    
            fnd_lett=0;
            question=0;
            fnd_numb =0;
            cant_numb=0;
            cant_lett=0;
            cant_errs=0;
            }
            
           else if (assign==1&&!question&&cant_numb==1&&cant_lett==1){ 
            if (contador[fnd_lett]==0){
                abc[fnd_lett]=fnd_numb;
                printf("assign made it\n");
                contador[fnd_lett]++;

                assign=0;      
                fnd_lett=0;
                question=0;
                pop();
                pop();
                fnd_numb=0;
                cant_numb=0;
                cant_lett=0;
                cant_errs=0;

            }

             else{

                move=1;
                printf("You will write again the value of the variable? YES-> y NO->n\n");
                pop();
                pop();
            }
            }

            else if (assign==1&&question==1&&cant_numb==1&&cant_lett==1){
                abc[fnd_lett]=fnd_numb;
                pop();
                pop();
                printf("assign made it\n");
                contador[fnd_lett]++;           

                assign=0;
                fnd_lett=0;
                question=0;
                fnd_numb=0;
                cant_numb=0;
                cant_lett=0;
                cant_errs=0;
            }
                else{
                printf("error founded: check again the input\n");
                assign=0;                               
                fnd_lett=0;
                question=0;
                fnd_numb=0;
                cant_numb=0;
                cant_lett=0;
                pop();
                pop();
                cant_errs=0;
            }

            break;
            case '=':
            assign=1;
            break;
            case ':':
            question=1;
            break;
            
            default:
            if (type>=97&&type<=122){
                push(abc[type-97]);    
                fnd_lett=type-97;  
                cant_lett++;    

            }
            else {
            cant_errs++;
            printf("error founded: it has been detected an unknown command %s\n", s);
            }
            break;
        }

     }

     else{

     switch (tolower(type)){
     case 'e':
     answer_yes++;
     push(0); 
     break;
     case 'p':
     answer_no++;
     push(0); 
     break;
     case '\n':

     if (answer_yes==1&&answer_no==0&&error==0){
        abc[fnd_lett]=fnd_numb;
        pop();
        printf("assign made it\n");

        contador[fnd_lett]++;

        assign=0;                     
        fnd_lett=0;
        question=0;
        fnd_numb=0;
        answer_no=0;
        answer_yes=0;
        error=0;
        move=0;
        cant_numb=0;
        cant_lett=0;
        cant_errs=0;

     }
     else if (answer_yes==0&&answer_no==1&&error==0){
        pop();
        printf("assign doesnt work, check that, please.\n");

        assign=0;                       
        fnd_lett=0;
        question=0;
        fnd_numb=0;
        answer_no=0;
        answer_yes=0;
        move=0;
        error=0;
        cant_numb=0;
        cant_lett=0;
        cant_errs=0;

     }
     else{
        pop();
        printf("error founded: Check the input here\n\n");
        printf("You will write again the value of the variable? YES-> y NO->n\n");
        answer_no=0;
        answer_yes=0;
        error=0;
        cant_numb=0;
        cant_lett=0;
        cant_errs=0;
     }
     break;
     default:
     error++;
     break;
     }
     }
    }
    return 0;
>>>>>>> ba4ad7c25cada891ea3dd84e55c25aca0a400540
}