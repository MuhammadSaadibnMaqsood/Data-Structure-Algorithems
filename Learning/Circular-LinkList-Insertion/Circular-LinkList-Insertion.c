#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void circularLinkedListTraversal(struct Node *head)
{

    struct Node *ptr = head;

    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr->next != head);
    printf("Element: %d\n", ptr->data);
}

struct Node *insertionAtFirst(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;

    newNode->data = data;

    do
    {
        ptr = ptr->next;
    } while (ptr->next != head);
    ptr->next = newNode;
    newNode->next = head;

    return newNode;
}

void insertionAtIndex(struct Node *head, int data, int index)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;
    int i = 0;

    while (i < index - 1)
    {
        ptr = ptr->next;

        i++;
    }
    newNode->data = data;
    newNode->next = ptr->next;
    ptr->next = newNode;
}
void insertionAtLast(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;

    do
    {
        ptr = ptr->next;

    } while (ptr->next != head);

    newNode->data = data;
    newNode->next = head;
    ptr->next = newNode;
}

int main(int argc, char const *argv[])
{

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = head;

    printf("Before Insertion\n");
    circularLinkedListTraversal(head);

    printf("After Insertion At first\n");
    head = insertionAtFirst(head, 0);
    circularLinkedListTraversal(head);

    printf("After Insertion At Index\n");
    insertionAtIndex(head, 12, 3);
    circularLinkedListTraversal(head);

    printf("After Insertion At Last\n");
    insertionAtLast(head, 5);
    circularLinkedListTraversal(head);

    return 0;
}
