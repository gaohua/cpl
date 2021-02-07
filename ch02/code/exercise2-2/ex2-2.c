/* write a loop equivalent to the for loop above without using && or ||

    for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
*/

for (i = 0; i < lim - 1)
{
    if((c = getchar()) != '\n')
        if(c != EOF)
            s[i] = c;
}