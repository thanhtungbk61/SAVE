#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


double atof(char s[])
{
    int i, sign=1, ePow=1;
    float val=0;
    int power=1, ePower =0;
    // while(!(isspace(s[i++]))) ;
    for(i=0; isspace(s[i]); i++ );
    if(s[i] == '-' || s[i] == '+')
    {
        sign = (s[i] == '-')? -1 : 1;
        i++;
    }
    for(; isdigit(s[i]); i++)
        val = val*10+ (s[i] -'0');

    if(s[i] == '.')
        i++;

    for( ; isdigit(s[i]); i++)
    {
        val = val*10 + (s[i] -'0');
        power*=10;
    }
    // val = val/power;
    // power =1;

    if(s[i] == 'e' || s[i] == 'E')
        i++;
    else
        return sign*val/power;

    if(s[i] == '-' || s[i] == '+')
    {
        ePow = (s[i]='-')? -1 : 1;
        i++;
    }
    else
        return val = sign*val/power;

    for( ; isdigit(s[i]); i++)
    {
        ePower = ePower*10 + (s[i] -'0');
    }

    if(ePow ==1)
        return sign*val/power*pow(10,ePower);
    else
        return sign*val/power/pow(10,ePower);
    // printf("val:%f, power:%f", val, power);
    // return (sign*val/power); // + power/pow(10,j)

}


void main(void)
{
    char* dataIn;
    size_t size;

    while(getline(&dataIn, &size, stdin)!= '\0')
    {
        float dataOut = atof(dataIn);
        printf("dataOut: %f\n", dataOut);
    }
}