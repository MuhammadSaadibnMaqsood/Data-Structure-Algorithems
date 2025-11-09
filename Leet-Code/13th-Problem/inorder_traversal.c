#include <stdio.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int isEmpty(struct Stack *stack)
{
    return stack->top == 0;
}

void push(struct Stack *stack, int *data)
{
    if (stack->top < stack->size)
    {
        stack->arr[stack->top] = data;
        stack->top++;
    }
}

int pop(struct Stack *stack)
{
    if (!isEmpty(stack))
    {
        int data = stack->arr[stack->top - 1];
        stack->top--;

        free(stack->arr[stack->top]);
        return data;
    }
}

int *inorderTraversal(struct Node *root, int *returnSize)
{

}

int main(int argc, char const *argv[])
{
    int root = {1, NULL, 2, 3};
    int returnSize;

    int *result = inorderTraversal(root, &returnSize);

    return 0;
}
