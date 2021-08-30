// page 72

#include <stdio.h>
#include <string.h>

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low =0;
    high = n -1;
    
    while(low < high)
    {
        mid = (high+low)/2;
        if(x <mid)
            high = mid;
        else
            low = mid; 
    }
    if(x >= low && x <= high)
        return mid;
    else
        return -1;
}


int binsearch2(int x, int v[], int n)
{
    int low, high, mid;
    low =0;
    high = n -1;

    
    if(x < v[0] || x > v[n-1])
        return -1;
    while(low < high)
    {
        mid = (high+low)/2;
        if(x <=v[mid])
            high = mid;
        else
            low = mid+1; 
    }
    return low;
}

void main(void)
{
    int data[11];
    int x =6;

    for(int i =0; i<11; i++)
        data[i] = i +1;
    int status = binsearch2(x, data, 10);

    printf("status: %d\n", status);
}

