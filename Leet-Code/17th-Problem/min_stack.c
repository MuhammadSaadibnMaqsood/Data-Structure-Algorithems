#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int top;
    int *arr;
    int *min;
} MinStack;

MinStack *minStackCreate()
{
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    obj->size = 30000; 
    obj->top = -1;
    obj->arr = (int *)malloc(obj->size * sizeof(int));
    obj->min = (int *)malloc(obj->size * sizeof(int));
    return obj;
}

void minStackPush(MinStack *obj, int val)
{
    obj->arr[++obj->top] = val;

    if (obj->top == 0)
    {
        obj->min[obj->top] = val;
    }
    else
    {
        int currentMin = obj->min[obj->top - 1];
        obj->min[obj->top] = (val < currentMin) ? val : currentMin;
    }
}

void minStackPop(MinStack *obj)
{
    if (obj->top >= 0)
        obj->top--;
}

int minStackTop(MinStack *obj)
{
    return obj->arr[obj->top];
}

int minStackGetMin(MinStack *obj)
{
    return obj->min[obj->top];
}

void minStackFree(MinStack *obj)
{
    free(obj->arr);
    free(obj->min);
    free(obj);
}


int main()
{
    MinStack *s = minStackCreate();
    minStackPush(s, -2);
    minStackPush(s, 0);
    minStackPush(s, -3);

    printf("Min: %d\n", minStackGetMin(s)); 
    minStackPop(s);
    printf("Top: %d\n", minStackTop(s));   
    printf("Min: %d\n", minStackGetMin(s)); 

    minStackFree(s);
    return 0;
}
