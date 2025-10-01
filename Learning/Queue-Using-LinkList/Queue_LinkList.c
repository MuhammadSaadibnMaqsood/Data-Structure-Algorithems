#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;

struct Node
{
    int data;
    struct Node *next;
};

int deque()
{
    int val = -1;
    struct Node *ptr = f;
    if (r == NULL && f == NULL)
    {
        printf("Queue is Empty");
    }
    else
    {
        val = f->data;
        f = f->next;
        free(ptr);
    }
    return val;
}

void enque(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (r == NULL && f == NULL)
    {
        f = r = newNode;
    }
    else
    {
        r->next = newNode;
        r = newNode;
    }
}
int main(int argc, char const *argv[])
{
    enque(10);
    enque(9);
    enque(8);
    enque(7);
    printf("\nDeque element: %d", deque());
    printf("\nDeque element: %d", deque());
    return 0;
}
