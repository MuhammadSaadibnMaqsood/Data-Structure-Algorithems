#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        printf("Duplicate not allowed: %d\n", data);
    }
}

int main()
{
    struct Node *n1 = createNode(11);
    struct Node *n2 = createNode(9);
    struct Node *n3 = createNode(13);
    struct Node *n4 = createNode(8);
    struct Node *n5 = createNode(10);
    struct Node *n6 = createNode(12);
    struct Node *n7 = createNode(15);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    struct Node * inserted = insert(n1, 14);

    if (inserted)
    {
        printf("\nElement is inserted");
    }
    else
    {
        printf("\nNot Inserted");
    }
}
