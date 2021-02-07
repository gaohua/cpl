/* Write a program to determine the ranges of char, short, int,
   and long variables, both signed and unsigned, by printting
   appropriate values from standard headers and by direct computaion.
   
   Harder if you compute them: determine the ranges of the various 
   floating-point types.
*/

#include<stdio.h>
#include<limits.h>

int main()
{
    printf("from standard headers constants:\n");
    // range of char
    printf("range of char:(%d, %d)\n",CHAR_MIN,CHAR_MAX);
    printf("range of unsigned char:(%d, %d)\n",0,UCHAR_MAX); 

    // range of short int
    printf("range of sort:(%d, %d)\n",SHRT_MIN,SHRT_MAX);
    printf("range of unsigned sort:(%d, %d)\n",0,USHRT_MAX);

    // range of int
    printf("range of int:(%d, %d)\n", INT_MIN, INT_MAX);
    printf("range of unsigned int:(%d, %u)\n",0,UINT_MAX);

    // range of long
    printf("range of long:(%ld, %ld)\n",LONG_MIN, LONG_MAX);
    printf("range of unsigned long:(%d, %lu)\n",0,ULONG_MAX);
    
    return 0;
}