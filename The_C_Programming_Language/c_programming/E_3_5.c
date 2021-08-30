#include <string.h>
#include <stdio.h>

void itob(int n, char out[], int base)
{
    int int2CharTable[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

            // for(int i=0; n>0; i++)
            // {
            //     printf("n/base: %d\n", (n%base));
            //     out[i] = int2CharTable[(n%base)] ;
            //     n = n/base;
            //     out[i+1] ='\0';   
            // }
    int length =0;
    out[length] =0;
    out[1] ='\0';
    while(n>0)
    {
        out[length++] = int2CharTable[(n%base)] ;
        n=n/base;
    }
    out[length] = '\0';
    // swap here
    for(int i=0; i<length-1; i++)
    {
        char temp = out[i];
        out[i] = out[length-i-1];
        out[length-i-1] = temp;
    }

}


void main(void)
{
    int n =161;
    char out[100];
    for(int base=2; base<= 16; base++)
    {
        itob(n, out, base);
        printf("base:%d out:%s\n",base,out );
    }

}