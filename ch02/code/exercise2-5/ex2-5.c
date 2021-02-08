/* Write the function any(s1, s2), which returns the first location in 
   the string s1 where any character from the string s2 occurs, or -1 if
   s1 contains no characters from s2.(the standard library function 
   strpbrk does the same job but returns a pointer to the location.)
*/

#include<stdio.h>

int any(char s1[], char s2[]);

int main()
{
    char s1[] = {"hello"};
    char s2[] = {"world"};
    int location = any(s1,s2);
    printf("%d\n",location);
    return 0;
}

int any(char s1[], char s2[])
{
    int i, j, location;

    i = j = 0;
    location = -1;

    for(i = 0; s2[i] != '\0' && location == -1; ++i)
    {
        for(j = 0; s1[j] != '\0'&& location == -1; ++j)
        {
            if(s2[i] == s1[j])
            {
                location = j;
            }
        }
    }
    return location;
}

