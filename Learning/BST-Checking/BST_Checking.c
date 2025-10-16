#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *prev = NULL;

int isBST(struct Node *root)
{
    if (root != NULL)
    {
        if (!isBST(root->left))
            return 0;

        if (prev != NULL && root->data <= prev->data)
            return 0;

        prev = root;

        return isBST(root->right);
    }
    return 1;
}

void inOrderTraversal(struct Node *root)
{
    if (root)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
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

    printf("Inorder Traversal: ");
    inOrderTraversal(n1);

    if (isBST(n1))
        printf("\nTree is BST");
    else
        printf("\nTree is not BST");

    return 0;
}
