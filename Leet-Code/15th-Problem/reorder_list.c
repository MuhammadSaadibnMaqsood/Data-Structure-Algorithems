#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct Stack {
    struct ListNode **arr;
    int top;
    int size;
};

void Traversal(struct ListNode *head) {
    printf("\n");
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void push(struct Stack *stack, struct ListNode *node) {
    stack->arr[++stack->top] = node;
}

struct ListNode *pop(struct Stack *stack) {
    return stack->arr[stack->top--];
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

struct Stack *createStack(int size) {
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->arr = malloc(size * sizeof(struct ListNode *));
    stack->top = -1;
    stack->size = size;
    return stack;
}

void reorderList(struct ListNode *head) {
    if (!head || !head->next)
        return;

    struct Stack *stack = createStack(50000);
    struct ListNode *ptr = head;

    
    while (ptr) {
        push(stack, ptr);
        ptr = ptr->next;
    }

    int n = stack->top + 1;
    ptr = head;

    for (int i = 0; i < n / 2; i++) {
        struct ListNode *endNode = pop(stack);
        struct ListNode *nextNode = ptr->next;

        ptr->next = endNode;
        endNode->next = nextNode;

        ptr = nextNode;
    }
    
    ptr->next = NULL;

    Traversal(head);
}

int main() {
    struct ListNode *head = malloc(sizeof(struct ListNode));
    struct ListNode *second = malloc(sizeof(struct ListNode));
    struct ListNode *third = malloc(sizeof(struct ListNode));
    struct ListNode *fourth = malloc(sizeof(struct ListNode));
    struct ListNode *fifth = malloc(sizeof(struct ListNode));

    head->val = 1;
    head->next = second;

    second->val = 2;
    second->next = third;

    third->val = 3;
    third->next = fourth;

    fourth->val = 4;
    fourth->next = fifth;

    fifth->val = 5;
    fifth->next = NULL;

    reorderList(head);
    return 0;
}
