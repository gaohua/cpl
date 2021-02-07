/* write an alternate version of squeeze(s1,s2) that deletes
   each character in s1 that matches any character in the string s2.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char *s1[]=
    {
        "this is a test",
        "hello world",
        ""
    };
    char *s2[]=
    {
        "a s",
        "ld",
        "a b c"
    };
    char *expect[]=
    {
        "thiitet",
        "heo wor",
        ""
    };

    int i ;
    for (i = 0; i < sizeof(s1)/sizeof(s1[0]); i++)
    {
        char f1[sizeof(*s1[i])/sizeof(char)];
        strcpy(f1,s1[i]);
        squeeze(f1,s2[i]); 
        if(s1[i] == expect[i])
        {
            printf("correct. %s",s1[i]);
        }
        else
        {
            printf("incorrect. %s",s1[i]);
        }
        
    }
    return 0;
}
void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for(i = j = 0; s1[i] != '\0'; i++)
    {
        for(k = 0; s2[k] != '\0'; k++)
        {
            if(s1[i] != s2[k])
            {
                s1[j++] = s1[i];
            }
        }
    }
}