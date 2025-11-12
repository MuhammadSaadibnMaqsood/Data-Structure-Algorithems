#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int size;
    int top;
    int *arr;
};

struct Stack *createStack(int size) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->size = size;
    stack->arr = (int *)malloc(stack->size * sizeof(int));
    return stack;
}

void push(struct Stack *stack, int data) {
    stack->arr[++stack->top] = data;
}

int pop(struct Stack *stack) {
    return stack->arr[stack->top--];
}

int evalRPN(char **tokens, int tokensSize) {
    struct Stack *stack = createStack(tokensSize);

    for (int i = 0; i < tokensSize; i++) {
        if (strcmp(tokens[i], "+") == 0 || strcmp(tokens[i], "-") == 0 ||
            strcmp(tokens[i], "*") == 0 || strcmp(tokens[i], "/") == 0) {

            int el1 = pop(stack);
            int el2 = pop(stack);
            int result;

            if (strcmp(tokens[i], "+") == 0)
                result = el2 + el1;
            else if (strcmp(tokens[i], "-") == 0)
                result = el2 - el1;
            else if (strcmp(tokens[i], "*") == 0)
                result = el2 * el1;
            else
                result = el2 / el1;

            push(stack, result);
        } else {
            push(stack, atoi(tokens[i]));
        }
    }

    int output = pop(stack);
    free(stack->arr);
    free(stack);
    return output;
}

int main() {
    char *tokens[] = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int tokensSize = sizeof(tokens) / sizeof(tokens[0]);

    int output = evalRPN(tokens, tokensSize);
    printf("\nOUTPUT: %d\n", output);
    return 0;
}
