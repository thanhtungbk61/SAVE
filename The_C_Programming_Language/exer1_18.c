// page: 45 

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
            // temp[size] = str[i]; basic version
            str[size] = str[i];
            size++;
        }
        if(str[i]==' ' || str[i]=='\n' || str[i]=='\t')
            invalid ++;
        else
            invalid =0;
    }

// basic version
    // for(int i = 0; i< size; i++)
    // {
    //     str[i] = temp[i];
    // }
    str[size] = '\0';
    // printf("format printf:%s\n", str);
}

void main()
{
    size_t  size;
    size_t  buffSize;
    char *buff;
    // buff = (char*)malloc(sizeof(char*)* 255);
    // getline will malloc and realloc 

    while((size = getline(&buff, &buffSize, stdin))>0)
    {
        format(buff, size);
        printf("%s", buff);
        // if(size > 8)
        //     
    }
    free(buff);
}