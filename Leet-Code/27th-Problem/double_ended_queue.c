#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *arr;
    int front;
    int rear;
    int size;
    int count;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k)
{
    MyCircularDeque *dq = malloc(sizeof(MyCircularDeque));
    dq->arr = malloc(sizeof(int) * k);
    dq->size = k;
    dq->front = 0;
    dq->rear = 0;
    dq->count = 0;
    return dq;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value)
{
    if (obj->count == obj->size) return false;

    obj->front = (obj->front - 1 + obj->size) % obj->size;
    obj->arr[obj->front] = value;
    obj->count++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value)
{
    if (obj->count == obj->size) return false;

    obj->arr[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->size;
    obj->count++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj)
{
    if (obj->count == 0) return false;

    obj->front = (obj->front + 1) % obj->size;
    obj->count--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj)
{
    if (obj->count == 0) return false;

    obj->rear = (obj->rear - 1 + obj->size) % obj->size;
    obj->count--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj)
{
    if (obj->count == 0) return -1;
    return obj->arr[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj)
{
    if (obj->count == 0) return -1;
    return obj->arr[(obj->rear - 1 + obj->size) % obj->size];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj)
{
    return obj->count == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj)
{
    return obj->count == obj->size;
}

void myCircularDequeFree(MyCircularDeque* obj)
{
    free(obj->arr);
    free(obj);
}
