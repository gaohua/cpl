/* Write a function escape(s,t) that converts characters like newline and tab into
   visible escape sequences like \n and \t as it copies the string t to s. Use a
   switch. Write a function for the other direction as well, converting escape
   sequences into the real characters.
*/

#define MAXLEN 1000
#include<stdio.h>


void escape(char s[], char t[]);
void undoescape(char s[], char t[]);

int main()
{
    char s[MAXLEN], us[MAXLEN];
    char t[] = {"hello,\n world\t\n"};
    escape(s,t);
    undoescape(us,s); 
    printf("escaped string is : %s\n",s);
    printf("unescaped string is : %s",us);
    return 0;
}

void escape(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while(t[i] != '\0')
    {
        switch(t[i])
        {
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            default:
                s[j++] = t[i];
                break;
        }
        ++i; 
    }
    s[j] = '\0';
}

void undoescape(char s[], char t[])
{
    int i, j;

    i = j = 0;    
    while(t[i] != '\0')
    {
        switch (t[i])
        {
        case 'n':
            s[j++] = '\n';
            break;
        case 't':
            s[j++] = '\t'; 
            break;
        case '\\':
            break;
        default:
            s[j++] = t[i];
            break;
        }
        ++i;
    }
}