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

struct Node *searchIter(struct Node *root, int el)
{
    while (root != NULL)
    {
        if (root->data == el)
        {
            return root;
        }
        else if (el < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

   
    return NULL;
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

    struct Node *searchEl = searchIter(n1, 12);

    if (searchEl)
    {
        printf("\nFound: %d", searchEl->data);
    }
    else
    {
        printf("\nNot found");
    }
}
