#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int capacity;
    int *data;
    int top;
} MyStack;

MyStack *myStackCreate()
{
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    stack->capacity = 16;
    stack->top = -1;
    stack->data = (int *)malloc(sizeof(int) * stack->capacity);
}

void Push(MyStack *st, int val)
{
    if (st->top == st->capacity)
        return -1;
    st->data[++st->top] = val;
}

int pop(MyStack *st)
{
    return st->data[st->top--];
}

int peek(MyStack* st){
    return st->data[st->top];
}
int isEmpty(MyStack* st){
    return st->top;
}

typedef struct
{
    MyStack *stack1;
    MyStack *stack2;

} MyQueue;

MyQueue *myQueueCreate()
{
    MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
    queue->stack1 = myStackCreate();
    queue->stack2 = myStackCreate();

    return queue;
}

void myQueuePush(MyQueue *obj, int x)
{
    Push(obj->stack2, x);
    obj->stack1->top = -1;

    while (obj->stack2->top != -1)
    {
        int val = pop(obj->stack2);
        Push(obj->stack1, val);
        obj->stack2->top--;
    }
}

int myQueuePop(MyQueue *obj)
{
    return pop(obj->stack1);
}

int myQueuePeek(MyQueue *obj)
{
    return peek(obj->stack1);
}

bool myQueueEmpty(MyQueue *obj)
{
    return isEmpty(obj->stack1);
}

void myQueueFree(MyQueue *obj)
{
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
