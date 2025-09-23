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
        return 1;
    }
    else
    {
        printf("\nSTACK IS FULL");
        return 0;
    }
}

void push(struct Stack *ptr, int el)
{
    if (isFull(ptr) == 1)
    {
        ptr->arr[ptr->top + 1] = el;
        ptr->top++;

        printf("\nElement inserted: %d", el);
    }
}

int pop(struct Stack *ptr)
{
    if (isEmpty(ptr) == 0)
    {
        int el = ptr->arr[ptr->top];
        ptr->top--;
        return el;
    }
}
void stackTraversal(struct Stack *ptr)
{

    int j = 0;
    while (j <= ptr->top)

    {
        printf("\nElement: %d", ptr->arr[j]);
        j++;
    }
}

int peek(struct Stack *ptr, int index)
{
    if (ptr->top - index + 1 < 0)
    {
        return -1;
    }

    return ptr->arr[ptr->top - index + 1];
}
int main(int argc, char const *argv[])
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * (sizeof(int)));
    int el;
    push(s, 5);
    push(s, 4);
    push(s, 2);
    push(s, 6);
    push(s, 7);
    push(s, 8);

    printf("\nSTACK TRAVERSAL");
    stackTraversal(s);
    printf("\nSTACK PEEK ELEMENT");
    printf("\nPEEK ELEMENT: %d", peek(s, 3));

    return 0;
}
