/* Write a function rightrot(x,n) that returns the value of the integer
   x totated to the right by n bit positions. */

#include<stdio.h>

unsigned rightrot(unsigned x, int n);

int main()
{
    unsigned r;
    r = 0;

    r = rightrot(11,3);
    printf("result :%d\n",r);
    return 0;
}
unsigned rightrot(unsigned x, int n)
{
    unsigned bitSize, flag;
    bitSize = flag = 1 ;

    while((flag = flag << 1) != 0)
    {
        ++bitSize;
    }

    printf("unsigned bit size:%u\n",bitSize);

    return (x >> n) | (((~(~0 << n)) & x) << (bitSize - n));
}