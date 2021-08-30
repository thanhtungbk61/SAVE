#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_BUFFER  128
typedef struct stack
{
    int data[MAX_BUFFER];
    int maxSize;
    int top;
} stack;

void stackInit(stack* s)
{
    s->maxSize =MAX_BUFFER;
    s->top     =0;
}
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


// this main for test stack
// void main(void)
// {
//     stack s;
//     int dataGet =0;
//     stackInit(&s);
//     // s.maxSize =10;
//     // s.top =0;
//     for(int i =0; i < s.maxSize ; i++)
//     {
//         int status = push(&s, i);
//         if(status ==-1)
//             printf("push error\n");
//     }

//     for(int i =0; i<s.maxSize; i++)
//     {
//         int status = pop(&s, &dataGet);
//         if(status ==-1)
//             printf("pop error\n");
//         printf("data out:%d\n", dataGet);
//     }
// }

// this main for caculate biểu thức hậu tố: 2 3 4 + * 5 – 2 2 * + có giá trị là 13.
int caculate(int para1, int para2, char operator)
{
    switch (operator)
    {
    case '-':
        return (para1 - para2);
        break;
    case '+':
        return (para1 + para2);
    case '*':
        return (para1 * para2);
    case '/':
        return (para1 / para2);
    default:
        break;
    }
}
void main(void)
{
    int nextNUmber =0, inputNumber, oldNum;
    stack s;
    stackInit(&s);
    char *inputChar;
    size_t size= 100;
    getline(&inputChar, &size, stdin);
    for(int i=0; i<strlen(inputChar) -1; i++)
    {
        if(inputChar[i] >= '0' && inputChar[i] <= '9')
        {
            if(nextNUmber ==1)
            {
                pop(&s, &oldNum);
                oldNum = oldNum*10 + (inputChar[i] -'0');
                push(&s, oldNum);
            }
            else
                push(&s,(inputChar[i] -'0'));
            nextNUmber =1;
        }
        else if(inputChar[i] == ' ')
            nextNUmber =0;
        else
        {
            int para1, para2;
            pop(&s, &para2);
            pop(&s, &para1);
            push(&s, caculate(para1, para2, inputChar[i]));
            printf("caculate(para1, para2, inputChar[i]) :%d\n", caculate(para1, para2, inputChar[i]));
        }
            
    }
    int dataOut;
    pop(&s, &dataOut);
    printf("dataOut:%d", dataOut);
}