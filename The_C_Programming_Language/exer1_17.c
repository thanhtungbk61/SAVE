#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void format(char* str, int length)
{
    char temp[100];
    int size =0;
    int invalid =0;
    for(int i=0; i <length; i++)
    {
        if(invalid ==0 || ((str[i]!=' ' && str[i]!='\n' && str[i]!='\t')))
        {
            temp[i] = str[i];
            size++;
        }
        if(str[i]==' ' || str[i]=='\n' || str[i]=='\t')
            invalid ++;
        else
            invalid =0;
    }

    for(int i = 0; i< size; i++)
    {
        str[i] = temp[i];
    }
    str[size] = '\0';
}

void main()
{
    size_t  size;
    size_t  buffSize;
    char *buff;
    char buff2[100];
    // buff = (char*)malloc(sizeof(char*)* 255);

    while((size = getline(&buff, &buffSize, stdin))>0)
    // while((size = getline(&buff2, &buffSize, stdin))>0)
    {
        if(size > 8)
            printf("%s", buff);
    }



}