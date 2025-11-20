#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *data;
    int capacity;
    int size;
    int front;
    int back;
} Queue;

Queue *queueCreate(int capacity)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->capacity = capacity > 0 ? capacity : 16;
    q->data = (int *)malloc(q->capacity * sizeof(int));
    q->size = 0;
    q->front = 0;
    q->back = 0;
    return q;
}

void queueFree(Queue *q)
{
    if (!q)
        return;
    free(q->data);
    free(q);
}

bool queueEmpty(Queue *q)
{
    return q->size == 0;
}

int queueSize(Queue *q)
{
    return q->size;
}

void queueEnqueue(Queue *q, int val)
{
    if (q->size == q->capacity)
    {
        int newCap = q->capacity * 2;
        int *newData = (int *)malloc(newCap * sizeof(int));

        for (int i = 0; i < q->size; ++i)
        {
            newData[i] = q->data[(q->front + i) % q->capacity];
        }
        free(q->data);
        q->data = newData;
        q->capacity = newCap;
        q->front = 0;
        q->back = q->size;
    }
    q->data[q->back] = val;
    q->back = (q->back + 1) % q->capacity;
    q->size++;
}

int queueDequeue(Queue *q)
{
    if (q->size == 0)
    {
        return -1;
    }
    int val = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return val;
}

int queueFront(Queue *q)
{
    if (q->size == 0)
        return -1;
    return q->data[q->front];
}

typedef struct
{
    Queue *q1;
    Queue *q2;
} MyStack;

MyStack *myStackCreate()
{
    MyStack *st = (MyStack *)malloc(sizeof(MyStack));
    st->q1 = queueCreate(16);
    st->q2 = queueCreate(16);
    return st;
}

void myStackPush(MyStack *obj, int x)
{
    queueEnqueue(obj->q2, x);
    while (!queueEmpty(obj->q1))
    {
        int v = queueDequeue(obj->q1);
        queueEnqueue(obj->q2, v);
    }

    Queue *tmp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = tmp;
}

int myStackPop(MyStack *obj)
{
    return queueDequeue(obj->q1);
}

int myStackTop(MyStack *obj)
{
    return queueFront(obj->q1);
}

bool myStackEmpty(MyStack *obj)
{
    return queueEmpty(obj->q1);
}

void myStackFree(MyStack *obj)
{
    if (!obj)
        return;
    queueFree(obj->q1);
    queueFree(obj->q2);
    free(obj);
}

int main(void)
{
    MyStack *myStack = myStackCreate();
    myStackPush(myStack, 1);
    myStackPush(myStack, 2);
    printf("top: %d (expected 2)\n", myStackTop(myStack));
    printf("pop: %d (expected 2)\n", myStackPop(myStack));
    printf("empty: %s (expected false)\n", myStackEmpty(myStack) ? "true" : "false");

    myStackPush(myStack, 3);
    myStackPush(myStack, 4);
    printf("top: %d (expected 4)\n", myStackTop(myStack));
    printf("pop: %d (expected 4)\n", myStackPop(myStack));
    printf("pop: %d (expected 3)\n", myStackPop(myStack));
    printf("pop: %d (expected 1)\n", myStackPop(myStack));
    printf("empty: %s (expected true)\n", myStackEmpty(myStack) ? "true" : "false");

    myStackFree(myStack);
    return 0;
}
