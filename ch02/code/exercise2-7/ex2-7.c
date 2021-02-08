/* Write a function invert(x,p,n) that returns x with the n bits that
   begin at position p inverted(i.e., 1 changed into 0 and vice versa),
   leaving the other unchanged.
*/
#include<stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
    unsigned r;
    r = 0;
    
    r = invert(1024, 7, 2);
    printf("result :%d\n",r);
    return 0;
}

/*
unsigned invert(unsigned x, int p, int n)
{
    unsigned tail =  x & (~(~0 << (p + 1 - n)));
    unsigned target = (x >> (p + 1 - n)) & ~(~0 << n);
    unsigned invert = (~target) & (~(~0 << n));
    
    return ((((x >> (p + 1 -n))&(~0 << n)) | invert) << (p + 1 - n)) | tail; 
}
*/


unsigned invert(unsigned x, int p, int n)
{
    unsigned mask = (~(~0 << n)) << (p + 1 - n);
    
    return x ^ mask;
}