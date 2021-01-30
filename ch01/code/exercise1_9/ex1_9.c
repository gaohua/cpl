#include<stdio.h>

/* copy input to output,replacing each string of 
   one or more blanks by a single blank */

int main()
{
    int c,blankin;
    
    blankin = 0;

    while((c = getchar()) != EOF)
    {
        if(c != ' ' || blankin != 1)
        {
            putchar(c);
        }
        blankin = c == ' ' ? 1 : 0;
    }
    return 0;
}