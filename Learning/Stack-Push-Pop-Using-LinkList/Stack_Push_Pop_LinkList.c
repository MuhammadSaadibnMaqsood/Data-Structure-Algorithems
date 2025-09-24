#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Stack {
    struct Node *top;
    int size;       // total capacity
    int used;       // current elements
};

void LinkListTraversal(struct Node *head) {
    struct Node *ptr = head;
    while (ptr != NULL) {
        printf(" %d ->", ptr->data);
        ptr = ptr->next;
    }
    printf(" NULL\n");
}

int isFull(struct Stack *s) {
    return (s->used == s->size);
}

int isEmpty(struct Stack *s) {
    return (s->used == 0);
}

void push(struct Stack *s, int data) {
    if (isFull(s)) {
        printf("\nSTACK IS FULL, cannot push %d\n", data);
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    s->used++;
    printf("\nPushed: %d", data);
}

void pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("\nSTACK IS EMPTY, cannot pop\n");
        return;
    }
    struct Node *temp = s->top;
    printf("\nPopped: %d", temp->data);
    s->top = s->top->next;
    free(temp);
    s->used--;
}

int main() {
    struct Stack s;
    s.top = NULL;
    s.size = 6;
    s.used = 0;

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);

    printf("\nStack elements after pushes: ");
    LinkListTraversal(s.top);

    pop(&s);
    printf("\nStack elements after pop: ");
    LinkListTraversal(s.top);

    push(&s, 5);
    push(&s, 6);
    push(&s, 7);  // will show STACK IS FULL

    printf("\nFinal Stack: ");
    LinkListTraversal(s.top);

    return 0;
}
