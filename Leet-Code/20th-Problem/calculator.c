#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Stack for integers
struct Stack {
    int size;
    int top;
    int *arr;
};

struct Stack* createStack(int size) {
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (int*)malloc(size * sizeof(int));
    return stack;
}

void push(struct Stack *stack, int val) {
    stack->arr[++stack->top] = val;
}

int pop(struct Stack *stack) {
    return stack->arr[stack->top--];
}

int calculate(char *s) {
    int n = strlen(s);
    struct Stack *stack = createStack(n);

    int num = 0;
    char op = '+';

    for (int i = 0; i < n; i++) {

        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0'); // build multi-digit number
        }

        // If operator or last character
        if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {
            if (op == '+') {
                push(stack, num);
            }
            else if (op == '-') {
                push(stack, -num);
            }
            else if (op == '*') {
                int last = pop(stack);
                push(stack, last * num);
            }
            else if (op == '/') {
                int last = pop(stack);
                push(stack, last / num);
            }

            op = s[i];   // update operator
            num = 0;     // reset num
        }
    }

    // Sum all values in the stack
    int result = 0;
    while (stack->top != -1) {
        result += pop(stack);
    }

    free(stack->arr);
    free(stack);
    return result;
}

int main() {
    char s1[] = "3+2*2";
    char s2[] = " 3/2 ";
    char s3[] = " 3+5 / 2 ";

    printf("Result 1 = %d\n", calculate(s1)); // 7
    printf("Result 2 = %d\n", calculate(s2)); // 1
    printf("Result 3 = %d\n", calculate(s3)); // 5

    return 0;
}
