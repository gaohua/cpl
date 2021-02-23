/* Write the function itob(n,s,b) that converts the iteger n
   into a base b character representation in the string s. In
   particular, itob(n,s,16) formats n as a hexadecimal integer 
   in s.
*/
#include<stdio.h>
#include<limits.h>

void itob(int n, char s[], int base);

void itob(int n, char s[], int base)
{
    const char s[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
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
        s[i++] = s[un%base];
    }while((un /= base) > 0);

    if(sign < 0)
        s[i++] = '-';
        
    s[i++] = '\0';
    reverse(s);
}