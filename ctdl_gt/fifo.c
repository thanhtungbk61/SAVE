#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define FIFO_SIZE    10
typedef struct fifo
{
    int rdIndex;
    int wrIndex;
    int count;
    // int size;
    int data[FIFO_SIZE];
} fifo;


void userPrintf(int* data, int length)
{
    printf("printf data: ");
    for(int i = 0; i< length; i ++)
    {
        printf("%d ",data[i]);
    }
    printf(" :end\n");
}

void prinFifo(fifo f)
{
    for(int i =0; i <FIFO_SIZE; i++)
    {
        printf("%d ",f.data[i]);
    }
    printf("\n\n");
}
void initFifo(fifo* f)
{
    f->count =0;
    f->rdIndex = 0;
    f->wrIndex =0;
    memset(f->data, 0, FIFO_SIZE);
}
int isEmpty(fifo *f)
{
    if(f->count ==0)
        return true;
    return false;
}

int isFull(fifo *f)
{
    if(f->count >= FIFO_SIZE)
        return true;
    return false;
}
int isInvalidLength(fifo *f, int length)
{
    if((length<=0) || ((FIFO_SIZE - f->count) <length ))
        return true;
    return false;
}

// case Fifo not empty but length > remain size of fifo
int pushFifo(fifo* f, int* dataIn, int length)
{
    if(isFull(f) || isInvalidLength(f, length))
        return -1;
    for(int i =0; i<length; i++)
    {
        // if(f->wrIndex )
        f->data[f->wrIndex] = dataIn[i];
        f->wrIndex= (f->wrIndex+1)%FIFO_SIZE;
    }
    
    // memcpy(&(f->data[f->wrIndex]), dataIn, length);
    // f->wrIndex= (f->wrIndex +length)%FIFO_SIZE;
    f->count += length;
    return length; 
}

// int pushFifo(fifo* f, int* dataIn, int length)
// {
//     if(isFull(f) || (length> FIFO_SIZE) || (length<= 0))
//         return -1;
//     for(int i =0; i<length; i++)
//     {
//         if(f->wrIndex )
//         f->data[f->wrIndex+i] = dataIn[i];
//     }
    
//     // memcpy(&(f->data[f->wrIndex]), dataIn, length);
//     f->wrIndex= (f->wrIndex +length)%FIFO_SIZE;
//     f->count += length;
//     return length; 
// }

int popFifo(fifo* f, int* dataOut, int length)
{
    if(isEmpty(f) || (length> FIFO_SIZE) || (length<= 0))
        return -1;
    for(int i =0; i<length; i++)
    {
        dataOut[i] = f->data[f->rdIndex];
        f->rdIndex = (f->rdIndex +1)%FIFO_SIZE;
    }
    // memcpy(dataOut, (f->data[f->rdIndex]), length);
    // f->rdIndex = (f->rdIndex +length)%FIFO_SIZE;
    f->count -= length;
    return length;
}

void setUpData(int* data, int length)
{
    for(int i =0; i<length; i++)
    {
        data[i] = i;
    }
}

 
void main (void)
{
    fifo test;
    int dataIn[FIFO_SIZE +10] = {0,};
    int dataOut[FIFO_SIZE + 10];
    int status;
    initFifo(&test);
    printf("count:%d, read:%d, write:%d\n", test.count, test.rdIndex, test.wrIndex);

    setUpData(dataIn, FIFO_SIZE +10);

    for(int i = 1; i< FIFO_SIZE +10; i++)
    {
        // memset(dataIn, 0, 15);
        // memset(dataOut, 0, (FIFO_SIZE +10));
        // memset(test.data,0, FIFO_SIZE);
        setUpData(dataOut, i);
        // userPrintf(dataIn,(FIFO_SIZE +10));
        status = pushFifo(&test, dataIn, i);
        // if(status < 0)
        // {
        //     printf("push error index: %d\n",i);
        //     return;
        // }
        status = popFifo(&test,dataOut, i);
        // if(status < 0)
        // {
        //     printf("popFifo error\n");
        //     return;
        // }
        userPrintf(dataOut, i);
        // printf("popFifo__ count:%d, read:%d, write:%d\n\n", test.count, test.rdIndex, test.wrIndex);
    }
    printf("\ncount:%d, read:%d, write:%d", test.count, test.rdIndex, test.wrIndex);
}


