/* Our binary search makes two tests inside the loop, when one would suffice (at the price
   of more tests outside). Write a version with only one test inside the loop and measure
   the difference in run-time.
*/
#include<stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
    const int n = 6;
    int v[6] = {1,3,5,7,9,11};
    int x = 7;
    int r = binsearch(x,v,n);
    printf("search result is: %d\n",r); 
    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0; 
    high = n - 1;

    while(low <= high && v[mid] != x)
    {
        mid = (high - low) / 2 + low;
        if(x > v[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    if(v[mid] == x)
        return mid;
    return -1;
}