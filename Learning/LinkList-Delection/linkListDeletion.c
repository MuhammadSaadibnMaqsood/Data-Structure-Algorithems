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

struct Node *deleteHead(struct Node *head)
{
    head = head->next;
    return head;
}

void deleteAtIndex(struct Node *head, int index)
{
    struct Node *ptr1 = head;
    struct Node *ptr2 = head;
    int i = 0;
    int j = 0;

    while (i < index - 1)

    {
        ptr1 = ptr1->next;
        i++;
    }

    while (i < index)

    {
        ptr2 = ptr2->next;
        i++;
    }

    ptr1->next = ptr2->next;
}

void delectLastNode(struct Node *head)
{

    struct Node *ptr = head;
    struct Node *ptr2 = head;
    int i = 0;
    int j = 0;

    while (ptr->next == NULL)
    {
        ptr = ptr->next;
        i++;
    }
    while (j < i - 1)
    {
        ptr2 = ptr2->next;
        j++;
    }

    ptr2->next = NULL;
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
    fourth->next = NULL;

    printf("LinkedList Before Any Deletion \n");
    linkListTraversal(head);

    head = deleteHead(head);
    printf("LinkedList After Deletion head\n");
    linkListTraversal(head);

    printf("LinkedList After Deletion At index 1\n");

    deleteAtIndex(head, 1);
    linkListTraversal(head);

    printf("LinkedList After Deletion At index 1\n");
    delectLastNode(head);
    linkListTraversal(head);
    return 0;
}
