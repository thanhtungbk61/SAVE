// page: 77

#include <stdio.h>
#include <string.h>

void expand(char source[], char des[])
{
    int min, max, index=0;
    // if(source[0] != '-')
    min = source[0];
    max = source[strlen(source)-1];
    for(int i=min; i<=max; i++)
    {
        des[index++] = i;
    }
    des[index] = '\0';

}


void expand2(char source[], char des[])
{
    int max, min, dIndex=0, sIndex=0;
    // for(int i=0; source[sIndex] == '-'; i++, sIndex++);
expandLoop:
    while(source[sIndex] == '-' )
        des[dIndex++] =source[sIndex++];
    min = source[sIndex++];
    // for(int i=0; source[sIndex] == '-'; i++, sIndex++);
    while(source[sIndex] == '-' )
        sIndex++;
    max = source[sIndex++];
expandLoop2:
    for(int i=min; i<=max; i++)
    {
        des[dIndex++] = i;
    }

    if(source[sIndex] == '\0')
        goto end;

    if(source[sIndex] =='-' && source[++sIndex] == '\0')
        des[dIndex++] = '-';
    else if(source[sIndex] =='-' && source[++sIndex] != '\0')
    {
        min = des[dIndex++];
        max = source[sIndex++];
        goto expandLoop2;
    }
    else
        goto expandLoop;
    // while(source[sIndex] == '-' )
    //     des[dIndex++] =source[sIndex++];    

end:
    des[dIndex] = '\0';

}

void main(void)
{
    char source[] = "---a---z0-90-9-";
    char des[100];

    expand2(source, des);
    printf("des:%s", des);
}
