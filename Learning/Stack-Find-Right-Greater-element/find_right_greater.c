#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

int isFull(struct Stack *stack)
{
    return stack->top == stack->size - 1;
}

int pop(struct Stack *stack)
{
    if (!isEmpty(stack))
    {
        int val = stack->arr[stack->top];
        stack->top--;
        return val;
    }
    return -1; 
}

void push(struct Stack *stack, int val)
{
    if (!isFull(stack))
    {
        stack->top++;
        stack->arr[stack->top] = val;
    }
}

struct Stack *findRightGreater(int *arr, int n)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = n;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->size * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                push(stack, arr[j]);
                break;
            }
            if (j == n - 1) 
            {
                push(stack, -1);
            }
        }
        if (i == n - 1) 
        {
            push(stack, -1);
        }
    }

    return stack;
}

int main()
{
    int arr[4] = {4, 5, 2, 25};

    struct Stack* stack = findRightGreater(arr, 4);

    printf("\n%d", pop(stack));
    printf("\n%d", pop(stack));
    printf("\n%d", pop(stack));
    printf("\n%d", pop(stack));

    return 0;
}
