#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertAtStart(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next = head;
    newNode->data = data;
    head = newNode;
    return head;
}

void insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;
    int i = 0;

    while (i < index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    newNode->next = ptr->next;
    newNode->data = data;
    ptr->next = newNode;
}

void insertAtEnd(struct Node *head, int data)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    struct Node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    newNode->data = data;
    newNode->next = NULL;
    ptr->next = newNode;
}

void insertAfterNode(struct Node *ptr, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
    newNode->next = ptr->next;
    newNode->data = data;
    ptr->next = newNode;
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

    second->data = 7;
    second->next = third;

    third->data = 10;
    third->next = NULL;

    linkListTraversal(head);

    head = insertAtStart(head, 20);

    printf("Linked List Traversal after insertion at first\n");

    linkListTraversal(head);

    printf("Linked List Traversal after insertion at between\n");

    insertAtIndex(head, 15, 2);

    linkListTraversal(head);

    printf("Linked List Traversal after insertion at end\n");

    insertAtEnd(head, 17);

    linkListTraversal(head);

    printf("Linked List Traversal after insertion at Node\n");

    insertAfterNode(second, 77);
    linkListTraversal(head);
    return 0;
}
