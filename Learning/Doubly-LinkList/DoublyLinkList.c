#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void linkListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        printf("\nElement: %d", ptr->data);
        ptr = ptr->next;
    }
    printf("\nElement: %d", ptr->data);

    printf("\n Now reverse");

    while (ptr->prev != NULL)
    {
        printf("\nElement: %d", ptr->data);
        ptr = ptr->prev;
    }
    printf("\nElement: %d", ptr->data);
}

int main(int argc, char const *argv[])
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 4;
    head->next = second;
    head->prev = NULL;

    second->data = 7;
    second->next = third;
    second->prev = head;

    third->data = 10;
    third->next = NULL;
    third->prev = second;

    linkListTraversal(head);

    return 0;
}
