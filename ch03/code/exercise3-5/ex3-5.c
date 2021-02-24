/* Write the function itob(n,s,b) that converts the iteger n
   into a base b character representation in the string s. In
   particular, itob(n,s,16) formats n as a hexadecimal integer 
   in s.
*/
#include<stdio.h>
#include<limits.h>
#include<string.h>

#define MAXLEN 1000

void itob(int n, char s[], int base);
void reverse(char s[]);

int main()
{
    char s[MAXLEN];
    int n, base;
    n = INT_MIN + 1;
    base = 16;
    itob(n,s,base);
    printf("%d base %d repretation is: %s\n",n,base,s);
    return 0;
}

void itob(int n, char s[], int base)
{
    const char sbase[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int i, sign;
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
        s[i++] = sbase[un%base];
    }while((un /= base) > 0);

    if(sign < 0)
        s[i++] = '-';
        
    s[i++] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;
    for(i = 0, j = strlen(s)-1; i < j; ++i,--j)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}