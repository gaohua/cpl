#include<stdio.h>

/* cout blanks, tabs and newlines */
int main()
{
    int c, bn, tn, ln;
    
    bn = tn = ln = 0;
    while((c = getchar())!=EOF)
    {
        if(c == ' ')
            bn ++;
        else if(c == '\t')
            tn ++;
        else if(c == '\n')
            ln ++;
    }
    printf("blanks:%d\ttabs:%d\tnewlines:%d\n",bn,tn,ln);

    return 0;
}