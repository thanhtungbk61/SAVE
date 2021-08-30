// page 74

#include <string.h>
#include <stdio.h>

void escape(char s[], char t[])
{
    int  j=0;
    for(int i =0; t[i] != '\0'; i++)
    {
        switch(t[i])
        {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}


void main(void)
{
    char* data;
    char dataOut[100];
    size_t size, sizeIn;
    while(1)
    {
        size = getline(&data, &sizeIn, stdin);
        escape(dataOut,data );
        printf("dataOut:%s\n", dataOut);
    }
}