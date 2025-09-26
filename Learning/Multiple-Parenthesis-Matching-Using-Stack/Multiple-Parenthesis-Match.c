#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack
{
    char data;
    int top;
    char *arr;
};

int matchParenthesis(char *exp)
{
    int size = strlen(exp);
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

    stack->top = -1;
    stack->arr = (char *)malloc(sizeof(char));

    for (int i = 0; i < size; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(stack, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(stack))
            {
                return 0;
            }

            pop(stack, exp[i]);
        }
    }
    if (isEmpty(stack))
    {
        return 1;
    }
}

int main(int argc, char const *argv[])
{
    char *exp = "1*(3+2){]";

    if (matchParenthesis(exp))
    {
        printf("\nParenthesis Balanced");
    }
    else
    {
        printf("\nParenthesis Not Balanced");
    }

    return 0;
}
