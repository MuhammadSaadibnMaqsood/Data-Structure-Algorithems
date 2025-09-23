#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("STACK IS EMPTY");
        return 1;
    }
    return 0;
}

int isFull(struct Stack *ptr)
{
    if (ptr->top != ptr->size - 1)
    {
        printf("STACK IS NOT FULL");
        return 1;
    }
    else
    {

        printf("STACK IS FULL");
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * (sizeof(int)));

    isEmpty(s);
    isFull(s);

    return 0;
}
