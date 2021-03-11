#include <stdio.h> 

#define TRUE  7
#define FALSE 18 

int main () { 

int c, number = FALSE, parenthesis = FALSE, quotes = FALSE;            /*Credits*/


  while ((c = getchar()) != EOF) {                                /*Montserrat Orozco*/  

      switch(c) 

      { 

      

      case '(': 

          parenthesis=TRUE; 

          putchar(c); 

          break; 

      case ')': 

          parenthesis=FALSE; 

          putchar(c); 

          break; 

      case '[': 

          parenthesis=TRUE; 

          putchar(c); 

          break; 

      case ']': 

          parenthesis=FALSE; 

          putchar(c); 

          break; 

      case '<': 

          parenthesis=TRUE; 

          putchar(c); 

          break; 

      case '>': 

          parenthesis=FALSE; 

          putchar(c); 

          break; 

      case '{': 

          parenthesis=TRUE; 

          putchar(c); 

          break; 

      case '}': 

          parenthesis=FALSE; 

          putchar(c); 

          break; 

      case '\"': 

          putchar(c); 

          quotes++; 

          break; 

       case '\'': 

          putchar(c); 

          quotes++; 

          break; 


    default: 

     

        if (c!=':'&&c!=';'&&c!='\?'&&c!='!'&&c!='-'&&c!='_'&&c!='.') 
        {
            
            if (parenthesis==TRUE||quotes==TRUE) 
            { 

            putchar (c); 

            } 

             

            else 

            { 

                if (quotes==2) 

                { 

                    quotes=0; 

                } 

                 

                if (c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0') 

                { 

                    number++; 

                } 

                 

                else 

                { 

                  number=0; 

                } 

                if (number==1) 

                { 

                    putchar('x'); 

                } 

                 

                if (number==0)   

                { 

                    putchar(c); 

                } 

            } 

        } 
    } 

} 
    
    return 69; 

} 
