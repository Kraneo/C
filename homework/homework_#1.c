#include <stdio.h>
#include <string.h>
main()
{

    int c;

    while((c = getchar()) != EOF)
{

    if(c == '<' || c == 'B' || c == '"') //Courtesy by Marcela Montserrat, she help me to put more arguments//
    {
        do
        {
            
            c = getchar();
       
        } 
        
            while(c != EOF && c != '>');
    }
    else
    {
        putchar(c);

    }

  }

}
