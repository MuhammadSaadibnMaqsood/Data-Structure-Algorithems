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

int isBST(struct Node *root)
{
    if (root)
    {
        if (root->left < root->data && root->right > root->data)
        {
            isBST(root->left);
            isBST(root->right);
        }
        else
        {
            return 0;
        }

        return 1;
    }

    return 1;
}

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int main(int argc, char const *argv[])
{
    // ROOT NODE
    struct Node *n1 = createNode(11);

    // SECOND & THIRD CHILD
    struct Node *n2 = createNode(9);
    struct Node *n3 = createNode(13);

    n1->left = n2;
    n1->right = n3;

    // FOUTH & FIFTH CHILD
    struct Node *n4 = createNode(8);
    struct Node *n5 = createNode(10);

    n2->left = n4;
    n2->right = n5;

    // SIXTH & SEVENTH CHILD
    struct Node *n6 = createNode(12);
    struct Node *n7 = createNode(15);

    n3->left = n6;
    n3->right = n7;

    inOrderTraversal(n1);
    if (isBST(n1))
    {
        printf("Tree is BST");
    }
    else
    {
        printf("Tree is not BST");
    }

    return 0;
}
