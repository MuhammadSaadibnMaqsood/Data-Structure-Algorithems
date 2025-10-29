#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *addTwoNumbers(struct Node *last1, struct Node *last2)
{
    struct Node *head = NULL, *tail = NULL;

    int carry = 0;

    
    while (last1 != NULL || last2 != NULL || carry != 0)
    {
        int x = (last1 != NULL) ? last1->data : 0;
        int y = (last2 != NULL) ? last2->data : 0;

        int sum = x + y + carry;
        carry = sum / 10;
        int digit = sum % 10;

        
        struct Node *newNode = createNode(digit);

        
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        if (last1)
            last1 = last1->prev;
        if (last2)
            last2 = last2->prev;
    }

    return head;
}

int main()
{
    
    struct Node *head1 = createNode(2);
    struct Node *n2 = createNode(4);
    struct Node *n3 = createNode(3);
    head1->next = n2;
    n2->prev = head1;
    n2->next = n3;
    n3->prev = n2;

    
    struct Node *head2 = createNode(5);
    struct Node *m2 = createNode(6);
    struct Node *m3 = createNode(4);
    head2->next = m2;
    m2->prev = head2;
    m2->next = m3;
    m3->prev = m2;

    
    struct Node *last1 = n3;
    struct Node *last2 = m3;

    struct Node *result = addTwoNumbers(last1, last2);

    printf("Sum: ");
    linkedListTraversal(result);
    printf("\n");

    return 0;
}
