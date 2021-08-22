#include <stdio.h>
#include <stdlib.h>


void main(void)
{
    float upper = 300;

    float celsius;
    for(float i= 300; i>= 0; i-=20)
    {
        celsius = (5.0/9.0)*(i -32);
        printf("%6.0f %6.1f\n", i, celsius);
    }
}