/* Write a function setbits(x,p,n,y) that returns x with the n
   bits that begin at position p set to the rightmost n bits of
   y, leaving the other bits unsigned.
*/

#include<stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    int r;
    r = 0;
    r = setbits(1024,8,3,4);
    printf("%d\n",r);
}
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return (x >> (p + 1 - n) & (~0 << n) | (y & ~(~0 << n))) << (p + 1 - n) | (~(~0 << (p + 1 - n)) & x); 
}