/* In a two's complement number system, x &= (x - 1) deletes the
   rightmost 1-bit in x. Explain why. Use this observation to wirte
   a faster version of bitcount.
*/

#include<stdio.h>

int bitcount(unsigned x);

int main()
{
    int r;
    unsigned x;

    x = 15;
    r = bitcount(x);
    printf("%u of 1 bits is : %d\n",x,r);
    return 0;
}

/* count 1 bits in x */
int bitcount(unsigned x)
{
    int count;
    
    count = 0;
    while(x != 0)
    {
        x &= (x - 1);
        ++count;
    }
    return count;
}

/*
1111 & 1110: 1110
1110 & 1101: 1100
1100 & 1011: 1000
1000 & 0111: 0000
*/