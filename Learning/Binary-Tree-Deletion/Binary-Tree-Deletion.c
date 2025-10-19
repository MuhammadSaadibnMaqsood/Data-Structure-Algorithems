#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

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

// ✅ Do NOT free here — only return the node (used for swapping)
struct Node *inOrderPredecessor(struct Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct Node *deleteNode(struct Node *root, int el)
{
    if (root == NULL)
        return NULL;

    if (el < root->data)
        root->left = deleteNode(root->left, el);
    else if (el > root->data)
        root->right = deleteNode(root->right, el);
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // Case 2: One child (right only)
        else if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        // Case 3: One child (left only)
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 4: Two children
        else
        {
            struct Node *iPre = inOrderPredecessor(root);
            root->data = iPre->data;
            root->left = deleteNode(root->left, iPre->data);
        }
    }

    return root;
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

    printf("\nBefore deletion: ");
    inOrderTraversal(n1);

    n1 = deleteNode(n1, 10);

    printf("\nAfter deletion: ");
    inOrderTraversal(n1);
}
