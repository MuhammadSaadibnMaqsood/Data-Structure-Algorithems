#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {

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

        return 0;
    }
}

void push(struct Stack *ptr, char el)
{
    if (isFull(ptr) == 1)
    {
        ptr->arr[ptr->top + 1] = el;
        ptr->top++;
    }
}

int pop(struct Stack *ptr)
{
    if (isEmpty(ptr) == 0)
    {
        ptr->top--;
    }
}

int parenthesisMatch(char *exp)
{

    int size = strlen(exp);

    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

    stack->size = size;
    stack->top = -1;
    stack->arr = (char *)malloc(size * sizeof(char));

    for (int i = 0; i < size; i++)
    {
        if (exp[i] == '(')
        {
            push(stack, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(stack))
            {
                return 0;
            }

            pop(stack);
        }
    }

    return isEmpty(stack);
}

int main(int argc, char const *argv[])
{

    // CHECK PARENTHESIS

    char *exp = "(8)*3(4)";

    if (parenthesisMatch(exp))
    {
        printf("Paranthesis Match");
    }
    else
    {
        printf("Parenthesis Not match");
    }

    return 0;
}
