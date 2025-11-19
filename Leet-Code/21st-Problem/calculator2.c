#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

struct Stack *createStack(int size)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (int *)malloc(size * sizeof(int));
    return stack;
}

void push(struct Stack *stack, int val)
{
    stack->arr[++stack->top] = val;
}

int pop(struct Stack *stack)
{
    return stack->arr[stack->top--];
}

int calculate(char *s)
{
    int size = strlen(s);
    struct Stack *stack = createStack(size);

    int num = 0;
    char lastOp = '+'; // MOST IMPORTANT LINE

    for (int i = 0; i < size; i++)
    {

        if (isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
        }

        if ((!isdigit(s[i]) && s[i] != ' ') || i == size - 1)
        {

            if (lastOp == '+')
                push(stack, num);

            else if (lastOp == '-')
                push(stack, -num);

            else if (lastOp == '*')
            {
                int t = pop(stack);
                push(stack, t * num);
            }
            else if (lastOp == '/')
            {
                int t = pop(stack);
                push(stack, t / num);
            }

            lastOp = s[i];
            num = 0;
        }
    }

    int result = 0;
    while (stack->top != -1)
        result += pop(stack);

    return result;
}

int main()
{
    char s[] = " 3+5 / 2 ";
    printf("Output: %d\n", calculate(s));
    return 0;
}
