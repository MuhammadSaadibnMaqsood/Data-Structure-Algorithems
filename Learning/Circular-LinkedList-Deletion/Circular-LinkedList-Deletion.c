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

struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr1 = head->next;
    struct Node *ptr2 = head;

    do
    {
        ptr2 = ptr2->next;

    } while (ptr2->next != head);

    ptr2->next = ptr1;

    return ptr1;
}

void deletionAtIndex(struct Node *head, int index)
{

    struct Node *ptr = head;
    struct Node *ptr2 = head->next;
    int i = 0;

    while (i < index - 2)
    {
        ptr = ptr->next;
        ptr2 = ptr2->next;
        i++;
    }

    ptr->next = ptr2->next;
}

void deleteAtLast(struct Node *head)
{
    struct Node *ptr = head->next;
    struct Node *ptr2 = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    ptr2->next = ptr->next;
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

    printf("Before Deletion\n");
    circularLinkedListTraversal(head);

    printf("After Deletion First Node\n");
    head = deleteFirst(head);
    circularLinkedListTraversal(head);

    // printf("After Deletion At Index\n");
    // deletionAtIndex(head, 2);
    // circularLinkedListTraversal(head);

    printf("After Deletion Last Node\n");
    deleteAtLast(head);
    circularLinkedListTraversal(head);
    return 0;
}
