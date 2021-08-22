// page: 48 

#include<stdio.h>
#include <stdlib.h>
#include <string.h>


#define SAPCE 5
void detab(char in[], char out[], int len)
{
    // int size =0;
    int blank =0;
    for(int i=0, j =0; i< len; i++)
    {
        if(in[i] == '\t')
        {
            blank = SAPCE;
            while(blank-- >0)
                out[j++] = ' ';
        }
        else
            out[j++] = in[i];
            // size++;
    }
    // printf("%d, %d\n", j, len);
}



void main()
{
    size_t  size;
    size_t  buffSize;
    char *buff;
    char out[100] = "\0";

// printf("%c", ' ');
    while((size = getline(&buff, &buffSize, stdin))>0)
    {
        detab(buff, out, size);
        printf("%s", out);
        // if(size > 8)
        //     
    }
    free(buff);
}