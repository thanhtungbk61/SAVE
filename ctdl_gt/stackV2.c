#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct stack
{
    int* data;
    int maxSize;
    int top;
} stack;

bool isEmpty(stack *s)
{
    if(s->top ==0)
        return true;
    return false;
}

bool isFull(stack *s)
{
    if(s->top == (s->maxSize))
        return true;
    return false;
}
int push(stack* s, int data)
{
    if(isFull(s))
        return -1;
    s->data[s->top] = data;
    s->top++;
    printf("top:%d\n", s->top);
    return 0;
}

int pop(stack* s, int* des)
{
    if(isEmpty(s))
        return -1;
    s->top --;
    *des = s->data[s->top];
    return 0;
}

int initStack(stack *s, int length)
{
    s->data = (int*)malloc(sizeof(int) *length);
    s->maxSize = length;
    s->top =0;
}
void main(void)
{
    stack s;
    initStack(&s, 10);
    int dataGet =0;
    // s.maxSize =10;
    // s.top =0;
    for(int i =0; i < s.maxSize ; i++)
    {
        int status = push(&s, i);
        if(status ==-1)
            printf("push error\n");
    }

    for(int i =0; i<s.maxSize; i++)
    {
        int status = pop(&s, &dataGet);
        if(status ==-1)
            printf("pop error\n");
        printf("data out:%d\n", dataGet);
    }
}