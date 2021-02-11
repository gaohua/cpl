/* rewrite the function lower, which converts upper case letters to
   lower case, with a conditional expression instead of if-else.
*/ 

#include<stdio.h>

int lower(int c);

int main()
{
    int c;
    c = 'F';
    printf("F to lower is: %c\n",lower(c));
    return 0;
}

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c; 
}