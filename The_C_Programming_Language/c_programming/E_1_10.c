#include<stdio.h>

// printf in per word to per line

void main(void)
{
    char c;
    int nw =0,nc=0;
    int invalid =0;


    while((c = getchar()) != EOF)
    {
        if(invalid ==0 ||( c != ' ' && c !='\t' && c != '\n' && c != '\r'))
        {
            printf("%c",c);
        }
        if(c == ' ' || c =='\t' || c == '\n' || c == '\r')
        {
            invalid++;
            if(invalid == 1)
                printf("\n");
        }
        else
        {
            invalid =0;
        }
    }
}