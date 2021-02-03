/* compile with 'gcc -Wall -pedantic -std=c11 filename.c' */
#include<stdio.h>
#define MAXLINE 10    /* maxinum input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = getline(line,MAXLINE)) > 0)
    {
        if(len > max){
            max = len;
            copy(longest, line);
        }
    }
    if(max > 0)
        printf("%s", longest);
    return 0;
}

/* getline: read a line into line, return length */
int getline(char line[], int maxline)
{
    int c, i;
    for(i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }
    if(c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}