#include<stdio.h>
#include<stdlib.h>

#define QUEUESIZE 10

typedef struct dataStruct
{
    int data;
    int priority;
} S_data;
typedef struct priQueue
{
    S_data item[QUEUESIZE];
    int size;
    int front;
    int rear;
    int count;
} S_queue;

void initQueue(S_queue* q)
{
    int size = QUEUESIZE;
    int front = 0;
    int rear = 0;
    int count = 0;
}