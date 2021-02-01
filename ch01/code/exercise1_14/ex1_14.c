/* this program to print a histogram of the 
   frequencies of different characters in its input.*/
#include<stdio.h>

#define CHARACTERSIZE  256 

int main()
{
    int c, i, j;
    int characters[CHARACTERSIZE];
    
    i = j = 0;
    for(i = 0; i < CHARACTERSIZE; ++i)
    {
        characters[i] = 0;
    }

    while((c = getchar())!=EOF)
    {
        characters[c]++;
    }

    /* print histogram */
    for(i = 0; i < CHARACTERSIZE; ++i)
    {
        if(characters[i] != 0)
        {
            printf("%2c:",i);
            for(j = 0; j < characters[i]; ++j)
            {
                printf(" # ");
            }
            printf("\n");
        }
    }
    return 0;
}

