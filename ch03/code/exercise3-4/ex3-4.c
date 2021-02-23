/* In a two's complement number representation, our version of
   itoa does not handle the largest negative number, that is,
   the value of n equal to -(2^(wordsize-1)). Explain why not.
   Modify it to print that value correctly, regardless of the 
   mathine on which it runs.
*/

/* explain: in our version statement n = -n, when n is min of int
   it's will overflow.
*/
#include<stdio.h>
#include<limits.h>
#include<string.h>

#define MAXLINE 1000

void reverse(char s[]);
void itoa(int n, char s[]);

int main()
{
    char s[MAXLINE];
    itoa(INT_MIN,s);
    printf("test itoa with min int value %s\n",s);
    return 0;
}

void itoa(int n, char s[])
{
    int i, sign;
    unsigned int un;

    if((sign = n) < 0)
    {
        if(n == INT_MIN)
            un = n;
        else
            un = -n;
    }
    i = 0;
    do{
        s[i++] = un % 10 + '0';
    }while((un /= 10) > 0);
    if(sign < 0)
        s[i++] = '-';
    s[i++]='\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
