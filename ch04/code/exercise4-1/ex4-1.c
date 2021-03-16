/* Write the function strrindex(s, t), which returns the position
   of the rightmost occurrent of t in s, or -1 if there is none.
*/

int strrindex(char source[], char searchfor[]);

int main()
{
    return 0;
}

int strrindex(char s[], char t[])
{
    int i, j, k;

    for(i = 0; s[i] != '\0'; ++i)
    {
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
            ;
        if(k > 0 && t[k] == '\0')
            return i+k-1;
    }
}
