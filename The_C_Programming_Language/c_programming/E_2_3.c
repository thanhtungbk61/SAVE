// page 60
// need to change 'A' to 'a' value

//
#include <stdio.h>
#include <string.h>
#include <math.h>

int htoi(char in[])
{
    int temp  =0;
    int length = strlen(in);

    if( !((in[0] == '0')&&(in[1] == 'x' || in[1] == 'X')) )
        return -1;
    for(int i =0; i< length -2; i++)
    {
        if(in[length-1-i] >= '0' && in[length-1-i] <= '9')
        {
            temp += (in[length-1-i] - '0') *(pow(16,i));
        }
        else if(in[length-1-i] >= 'a' && in[length-1-i] <= 'f')
        {
            temp += (in[length-1-i] - 87) *(pow(16,i));
        }
        else if(in[length-1-i] >= 'A' && in[length-1-i] <= 'F')
        {
            temp += (in[length-1-i] - 55) *(pow(16,i));
        }  
        else 
            return -1;      
    }
    return temp;

}


void main(void)
{
    char dataIn[] = "0xA1";
    int dataOut;
    dataOut = htoi(dataIn);
    printf("dataOut:%d\n", dataOut);
}