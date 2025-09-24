#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkListTraversal(struct Node *head)
{
    struct Node *ptr = head;

    while (ptr != NULL)
    {
        printf("\nElement in Linked List: %d", ptr->data);
        ptr = ptr->next;
    }
}

int isFull(int stackSize, int stackUsed)
{
    if (stackSize > stackUsed)
    {
        printf("STACK IS NOT FULL");
        return 0;
    }
    printf("STACK IS FULL");
    return 1;
}

int isEmpty(int stackSize, int stackUsed)
{
    if (stackUsed == 0)
    {
        printf("STACK IS EMPTY");
        return 0;
    }
    printf("STACK IS NOT EMPTY");
    return 1;
}

int main(int argc, char const *argv[])
{

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *thrid = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    int stack_size = 6;
    int stackUsed = 0;

    head->data = 1;
    head->next = second;
    stackUsed++;

    second->data = 2;
    second->next = thrid;
    stackUsed++;

    thrid->data = 3;
    thrid->next = fourth;
    stackUsed++;

    fourth->data = 4;
    fourth->next = NULL;
    stackUsed++;

    LinkListTraversal(head);
    isEmpty(stack_size, stackUsed);
    isFull(stack_size, stackUsed);

       return 0;
}
