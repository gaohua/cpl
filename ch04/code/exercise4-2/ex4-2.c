/* Extend atof to handle scientific notation of the form
        123.45e-6
   where a floating-point number may be followed by e or
   E and an optionally signed exponent.
*/

#include<stdio.h>
#include<ctype.h>

double atof(char s[]);

int main()
{
    char s[] = {"123.45"}, s2[]={"123.45e-6"};
    printf("string \"%s\" convert to float point is: %lf\n",s,atof(s));
    printf("string \"%s\" convert to float point is: %lf\n",s2,atof(s2));
    return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power, ePower;
    int i, sign, eSign, eVal;

    for(i = 0; isspace(s[i]); i++)
        ;
    
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if(s[i] == '.')
        i++;
    for(power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    
    /* extend */
    if(s[i] == 'e' || s[i] == 'E')
        i++;
    
    eSign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for(eVal = 0; isdigit(s[i]); i++){
        eVal = 10.0 * eVal + (s[i] - '0');
    }
    for(ePower = 1.0; eVal > 0; eVal--)
        ePower *= 10;
    if(ePower > 1.0)
        power = eSign > 0 ? ePower / power : ePower * power; 

    return sign * val / power;
}