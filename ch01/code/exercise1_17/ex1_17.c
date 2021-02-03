/* print all input lines that are longer than 80 characters. */
#include<stdio.h>
#define MAXLEN 1000
#define LIMITLEN  80
 int getline(char line[], int maxlen);

int main()
{
    char line[MAXLEN], len;
    len = 0;
    while((len = getline(line,MAXLEN)))
    {
        if(len > LIMITLEN)
            printf("%s",line);
    }
    return 0;
}

int getline(char line[],int maxlen)
{
    int i, c;

    i = 0;
    for(i = 0; i < (maxlen - 1) && ((c = getchar())!=EOF) && c != '\n'; ++i)
    {
        line[i] =  c;
    }
    
    if(c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}