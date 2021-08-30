#include <string.h>
#include <stdio.h>

int strrindex(char s[], char t[])
{
    int sLen = strlen(s), tLen = strlen(t);
    int count;
    int sIndex, tIndex;
    for(int i =sLen-1; i >0; i--)
    {
        for(count =0, sIndex =i, tIndex =(tLen-1); t[tIndex] == s[sIndex] &&  tIndex >=0 && sIndex >=0; count++, sIndex--, tIndex--);
        if(count == tLen)
            return sIndex+1;
        // V1
            // if(t[tLen-1] == s[i])
            // {
            //     sIndex = i;
            //     tIndex = tLen-1;
            //     for(count =0;(t[tIndex] == s[sIndex] && tIndex >=0 && sIndex >=0) ; count++, sIndex--, tIndex--);
            //     if(count == tLen)
            //         return (sIndex+1);
            // }
    }
    return -1;
}

void main(void)
{
    char s[] = "thanhtung@123";
    char t[] = "thanhtung";
    printf("index:%d\n", strrindex(s,t));
}