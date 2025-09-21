#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node* ptr){
    while (ptr != NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
    
}

int main(int argc, char const *argv[])
{
    struct Node *first;
    struct Node *second;
    struct Node *third;

    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    first->data = 5;
    first->next=second;

    second->data = 7;
    second->next = third;

    third->data = 10;
    third->next = NULL;

    linkedListTraversal(first);

    return 0;
}
