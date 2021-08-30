#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    int c;
    printf("%d\n", EOF);
    while((c =getchar()) != EOF)
        printf("%d\n", c);
    printf("%d\n", c);
}