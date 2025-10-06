#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

char topElement(struct Stack *stack)
{
    return stack->arr[stack->top];
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    return 0;
}

void push(struct Stack *stack, char el)
{
    stack->top++;
    stack->arr[stack->top] = el;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

char pop(struct Stack *stack)
{
    if (!isEmpty(stack))
    {
        char el = stack->arr[stack->top];
        stack->top--;
        return el;
    }
    return '\0';
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '/' || ch == '*');
}

char *infixToPostfix(char *infix)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->size = strlen(infix);
    stack->arr = (char *)malloc(stack->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0;

    while (i < strlen(infix))
    {
        if (!isOperator(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(topElement(stack)))
            {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i]);
            i++;
        }
    }

    while (!isEmpty(stack))
    {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "x+y-z";
    char *postfix = infixToPostfix(infix);

    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);

    return 0;
}
