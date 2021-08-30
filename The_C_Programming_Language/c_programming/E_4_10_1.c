#include <stdio.h>
#include <string.h>

void printd(int n)
{
    if(n/10)
        printd(n/10);
    printf("%c",(n%10+ '0'));

}


void main(void)
{
    int data =123;
    printd(data);
}