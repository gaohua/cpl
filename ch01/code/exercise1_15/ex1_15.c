/* this program use the formula C = (5/9)(F - 32)
   to print the following table of Fahrenheit 
   temperatures and their centigrade or Celsius equivalents:
   0    -17
   20   -6
   40   4
   60   15
   80   26
   100  37
   120  48
   140  60
   160  71
   180  82
   200  93
   220  104
   240  115
   260  126
   280  137
   300  148
   */
#include<stdio.h>

float Fahr2Celsius()
{
    float fahr, celsius;
    int lower, upper, step;
    
    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while(fahr <= upper){
        celsius = (5.0/9.0)*(fahr - 32.0);
        printf("%3.0f %6.1f\n",fahr,celsius);
        fahr = fahr + step;
    } 
}
int main()
{
    Fahr2Celsius();
    return 0;
}