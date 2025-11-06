#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct Stack *stack)
{
    return stack->top == 0;
}

int isFull(struct Stack *stack)
{
    return stack->top == stack->size;
}

void push(struct Stack *stack, char data)
{
    if (!isFull(stack))
    {
        stack->arr[stack->top] = data;
        stack->top++;
    }
}

char pop(struct Stack *stack)
{
    if (!isEmpty(stack))
    {
        stack->top--;
        return stack->arr[stack->top];
    }
    return '\0';
}

int isMatching(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int isValid(char *s)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = strlen(s);
    stack->top = 0;
    stack->arr = (char *)malloc(stack->size * sizeof(char));

    for (int i = 0; i < stack->size; i++)
    {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{')
        {
            push(stack, c);
        }
        else
        {
            if (isEmpty(stack))
            {
                free(stack->arr);
                free(stack);
                return 0;
            }

            char popped = pop(stack);
            if (!isMatching(popped, c))
            {
                free(stack->arr);
                free(stack);
                return 0;
            }
        }
    }

    int valid = isEmpty(stack);
    free(stack->arr);
    free(stack);
    return valid;
}

int main()
{
    char *s = "(]";

    if (isValid(s))
        printf("\nValid\n");
    else
        printf("\nInvalid\n");

    return 0;
}
