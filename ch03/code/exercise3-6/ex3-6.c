/* Write a version of itoa that accepts three arguments instead
   of two. The third argument is a minimum field width; the converted
   number must be padded with blanks on the left if necessary to
   make it wide enough
*/
#include<stdio.h>
#include<limits.h>
#include<string.h>

#define MAXLEN 1000

void itoa(int n, char s[], int pad);
void reverse(char s[]);

int main()
{
    char s[MAXLEN];
    int n, pad;
    pad = 3;
    for(n = 7; n < 1000; n+=80)
    {
        itoa(n,s,pad);
        printf("%s\n",s);
    }
    return 0;
}

void itoa(int n, char s[], int w)
{
    int i, j, sign;
    unsigned int un;
    
    un = n;
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

    while(i <= w)
    {
        s[i++] = ' ';
    }

    s[i]='\0';
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