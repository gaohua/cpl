/* Write a function expand(s1, s2) that expands shorthand notations like a-z in the
   string s1 into the equivalent complete list abc...xyz in s2. Allow for letters
   of either case and digits, and be prepared to handle cases like a-b-c and a-z
   0-9 and -a-z. Arrange that a leading or trailing - is taken literally.
*/
#include<stdio.h>
#define MAXLEN 1000

void expand(char s1[], char s2[]);

int main()
{
    char s1[] = {"-hella-f1-8-"};
    char s2[MAXLEN];

    expand(s1,s2);

    printf("result is : %s\n",s2);
    return 0;
}
void expand(char s1[], char s2[])
{
    int i, j, prec;
    prec = '\0';
    for(i = j = 0; s1[i] != '\0'; ++i)
    {
        if(s1[i] == '-')
        {
            if(prec != '\0' && s1[i+1] != '\0')
            {
                while(++prec <= s1[i+1])
                {
                    s2[j++] = prec;
                }     
                ++i;
            }
        }
        else
        {
           s2[j++] = s1[i]; 
        }
        prec = s1[i];
    }
    s2[j] = '\0';
}