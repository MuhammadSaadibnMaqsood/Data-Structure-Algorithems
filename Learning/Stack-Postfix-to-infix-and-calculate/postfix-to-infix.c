#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char **arr;   
};

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
    {
        return 1;
    }
    return 0;
}

void push(struct Stack *stack, char *str)
{
    stack->top++;
    stack->arr[stack->top] = strdup(str);   
}

char* pop(struct Stack *stack)
{
    char *str = stack->arr[stack->top];
    stack->top--;
    return str;
}

char* postFix_to_Infix(char *postFix)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = strlen(postFix);
    stack->top = -1;
    stack->arr = (char **)malloc(stack->size * sizeof(char*));

    char *val1, *val2;
    char newEl[100];

    for (int i = 0; i < strlen(postFix); i++)
    {
        if (!isOperator(postFix[i]))
        {
            char op[2] = {postFix[i], '\0'};  
            push(stack, op);
        }
        else
        {
            val1 = pop(stack);
            val2 = pop(stack);

            sprintf(newEl, "(%s %c %s)", val2, postFix[i], val1);

            push(stack, newEl);
        }
    }

    return pop(stack);
}

int main(int argc, char const *argv[])
{
    char *postfix = "231*+9-";

    char *infix = postFix_to_Infix(postfix);

    printf("Infix: %s\n", infix);

    return 0;
}
