//page 74
#include <string.h>
#include <stdio.h>

void shellSoft(char v[], int length)
{
    for(int i=0; i<length; i++)
    {
        for(int j=i; j< length; j++)
        {
            if(v[i] >  v[j])
            {
                char temp = v[i];
                v[i] = v[j];
                v[j] =temp;
            }

        }
    }
}


void main(void)
{
    char testArray[100] = "12thanhtung@123";
    shellSoft(testArray, strlen("12thanhtung@123"));

    printf("%s\n", testArray);
}