// page: 45 

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* str, int length)
{
    char temp;
    for(int i=0; i <length/2; i++)
    {
        temp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = temp;
    }
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
        reverse(buff, size);
        printf("%s", buff);
        // if(size > 8)
        //     
    }
    free(buff);
}