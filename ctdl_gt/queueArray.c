#include <stdio.h>
#include <stdbool.h>
#define QUEUESIZE 10
typedef struct queue
{
    int data[QUEUESIZE];
    int size;
    int front;
    int rear;
    int count;
} queue;

int initQueue(queue* q)
{
    q->count =0;
    q->front =0;
    q->rear =0;
    q->size = QUEUESIZE;
}

bool isEmpty(queue *q)
{
    if(q->rear == q->front)
        return true;
    return false;
}

bool isFull(queue *q)
{
    if(q->count == q->size)
        return true;
    return false;
}

int enQueue(queue* q, int data)
{
    if(isFull(q))
        return -1;
    q->data[q->rear] =data;
    q->rear = (q->rear +1)%q->size;
    q->count++;
    return 0;
}

int deQueue(queue *q, int *des)
{
    if(isEmpty(q))
        return -1;
    *des = q->data[q->front];
    q->front = (q->front +1)%q->size;;
    q->count --;
    return 0;
}

void main(void)
{
    queue q;
    int dataGet=0, status=-1;
    initQueue(&q);

    for(int i=0; i<30; i++)
    {
        status = enQueue(&q,i);
        // printf("count:%d size:%d\n", q.count, q.size);
        if(status == -1)
            printf("en queue error\n");
        if(i < 10)
        {
            status = deQueue(&q, &dataGet);
            if(status == -1)
                printf("deQueue error\n");
            printf("data get: %d\n", dataGet);
        }

    }
}