#include<stdio.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

main()
{
    char line[MAXLINE];
    int found = 0;

    while(getline(line,MAXLINE) > 0)
    {
        if(strindex(line,pattern) >= 0)
        {
            printf("%s", line);
            found++;
        }
    }
    return found;
}

int getline(char line[], int lim)
{
    int c, i;

    i = 0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        line[i++] = c;
    }

    if(c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;

    for(i = 0; s[i] != '\0'; i++)
    {
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if(k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}