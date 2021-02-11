
#include<stdio.h>

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main()
{
    const int n = 10;
    int v[n] = {1,3,4,5,8,10,11,15,18,30};
    int r;
    int x;
    x = 1;
    r = binsearch2(x,v,n);
    printf("search %d, result is : %d\n",x,r);
    return 0;
}

/* [l,r] [l,mid-1] [mid + 1,r]*/
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;

    while(low <= high)
    {
        mid = (high - low) / 2 + low;
        if(x == v[mid])
            return mid;
        else if(x <= v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

/* [low,right), [low,mid),[mid+1,right)*/
int binsearch2(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n;

    while(low < high)
    {
        mid = (high - low) / 2 + low;

        if(x == v[mid])
            return mid;
        else if(x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return -1;
}