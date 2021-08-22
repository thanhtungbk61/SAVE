// page: 48 

#include<stdio.h>
#include <stdlib.h>
#include <string.h>


#define SPACE 7
void detab(char in[], char out[], int len)
{
    // int size =0;
    int blank =0;
    for(int i=0, j =0; i< len; i++)
    {
        if(in[i] == '\t')
        {
            blank = SPACE;
            while(blank-- >0)
                out[j++] = ' ';
        }
        else
            out[j++] = in[i];
            // size++;
    }
    // printf("%d, %d\n", j, len);
}

void entab(char in[], char out[])
{
    int blank;
    int countBlank=0;
    for(int i=0, j =0; i< strlen(in); i++)
    {
        if(in[i] == ' ')
            countBlank++;
        else
        {
            if(countBlank > 0)
            {
                while(countBlank -- >0)
                    out[j++] = ' ';
                countBlank =0;
            }
            out[j++] = in[i];
        }
        if(countBlank == SPACE)
        {
            out[j++] = '\t';
            countBlank =0;
            // out[j] = in[i];
        }

    }
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
        entab(buff, out);
        printf("%s", out);
        // if(size > 8)
        //     
    }
    free(buff);
}