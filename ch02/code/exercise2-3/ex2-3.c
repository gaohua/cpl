/* write the function htoi(s), which converts a string of hexadecimal
   digits (including an optional 0x or 0X) into its equivalent integer
   value. The allowable digits are 0 through 9, a through f, and A
   through F.
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

unsigned htoi(char s[]);

int main()
{
    char *endp = NULL;
    char *test[] = 
    {
        "F00",
        "bar",
        "0100",
        "0X1",
        "0xA",
        "0X0c0BE",
        "abcdef",
        "123456",
        "0x123456",
        "deadbeef",
        "zog_c"
    };

    unsigned int result;
    unsigned int check;

    size_t numtests = sizeof test / sizeof test[0];
    size_t testIdx;
    for(testIdx = 0; testIdx < numtests; testIdx++)
    {
        result = htoi(test[testIdx]);
        check = (unsigned int)strtoul(test[testIdx],&endp,16);

        if((*endp != '\0' && result == 0) || result == check)
        {
           printf("Testing %s, Correct. %u\n",test[testIdx], result); 
        }
        else
        {
            printf("Testing %s. Incorrect. %u\n", test[testIdx], result);
        }
        
    }
    return 0;
}

unsigned htoi(char s[])
{
    int i, n, lower;
    
    n = 0;
    lower = 0;
    for(i = 0; s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'f'
        || s[i] >= 'A' && s[i] <= 'F' || s[i] == 'x' || s[i] == 'X'; ++i)
    {
        if(s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))
        {
            ++i;
            continue;
        }
        if(isdigit(s[i]))
        {
            n = 16 * n + (s[i] - '0');
        }
        else if(isalpha(s[i]))
        {
            lower = tolower(s[i]);
            if(lower >= 'a' && lower <= 'f')
            {
                n = 16 * n + (lower - 'a' + 10);
            }
        }
    }
    return n;
}