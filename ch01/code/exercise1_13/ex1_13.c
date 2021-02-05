/* this program to print a hitogram of the length of
   words in its input.*/

#include<stdio.h>

#define MAXWORDNUM 10
#define OUT 0
#define IN  1

int main()
{
    int c, i, j, state, wordLen, maxWordLen, wordIndex;
    int wordLens[MAXWORDNUM];

    i = j = wordLen = maxWordLen = wordIndex = 0;
    state = OUT;
    for(i = 0; i < MAXWORDNUM; ++i)
        wordLens[i] = 0;

    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\t' || c== '\n')
        {
            state = OUT;
            wordLens[wordIndex++] = wordLen;
            if(maxWordLen < wordLen)
                maxWordLen = wordLen;
            wordLen = 0;
            
            if(wordIndex >= MAXWORDNUM)
                break;
        }
        else {
            if(state == OUT) 
                state = IN;
            wordLen++;
        }
    }

    /* Print Horizontal Histogram */
    printf("print horizontal histogram:\n");
    for(i = 0; i < wordIndex; ++i)
    {
        printf("%2d|",i+1);
        for(j = 0; j < wordLens[i]; ++j)
        {
            printf(" # ");
        }
        printf("\n");
    }

    /* Print vertical histogram */
    printf("\nprintf vertical histogram\n");
    for(i = maxWordLen; i != 0; --i)
    {
        /* y axis */
        printf("%2d|",i);

        /* main histogram */
        for(j = 0; j < wordIndex; ++j)
        {
            if(wordLens[j] >= i)
            {
                printf(" # ");
            }
            else
            {
                printf("   ");
            }
            
        }
        printf("\n");
    }
    /* x axis */
    for(i = 0; i < 2; ++i)
    {
        if(i == 0)
            printf("  +");
        else
            printf("   ");
        
        for (j = 0; j < wordIndex; ++j)
        {
            if(i == 0)
                printf("---");
            else
                printf(" %d ",j + 1);
        }
        printf("\n");
    }
}