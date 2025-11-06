#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int size;
    int top;
    char **arr;
};

int isEmpty(struct Stack *stack) {
    return stack->top == 0;
}

void push(struct Stack *stack, char *dir) {
    if (stack->top < stack->size) {
        stack->arr[stack->top] = strdup(dir);
        stack->top++;
    }
}

void pop(struct Stack *stack) {
    if (!isEmpty(stack)) {
        stack->top--;
        free(stack->arr[stack->top]);
    }
}

char *simplifyPath(char *path) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = strlen(path);
    stack->top = 0;
    stack->arr = (char **)malloc(stack->size * sizeof(char *));

    // Make a copy because strtok modifies the string
    char *copy = strdup(path);
    char *token = strtok(copy, "/");

    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            if (!isEmpty(stack)) pop(stack);
        } else if (strcmp(token, ".") != 0 && strlen(token) > 0) {
            push(stack, token);
        }
        token = strtok(NULL, "/");
    }

    // If stack empty → root "/"
    if (isEmpty(stack)) {
        free(stack->arr);
        free(stack);
        free(copy);
        return strdup("/");
    }

    // Calculate required memory size dynamically
    int totalLen = 0;
    for (int i = 0; i < stack->top; i++) {
        totalLen += strlen(stack->arr[i]) + 1; // +1 for '/'
    }

    char *result = (char *)malloc(totalLen + 1); // +1 for '\0'
    result[0] = '\0';

    for (int i = 0; i < stack->top; i++) {
        strcat(result, "/");
        strcat(result, stack->arr[i]);
    }

    // Free stack memory
    for (int i = 0; i < stack->top; i++) {
        free(stack->arr[i]);
    }
    free(stack->arr);
    free(stack);
    free(copy);

    return result;
}

int main() {
    char path[] = "/.../a/../b/c/../d/./";
    char *newPath = simplifyPath(path);
    printf("Simplified Path: %s\n", newPath);
    free(newPath);
    return 0;
}
