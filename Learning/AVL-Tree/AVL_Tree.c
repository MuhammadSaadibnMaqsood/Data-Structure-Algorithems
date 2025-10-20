#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

struct Node *creatNode(int key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 0;

    return newNode;
}

int getHeight(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    return node->height;
}

int getBalancedFactor(struct Node *node)
{
    return node->left->height - node->right->height;
}

struct Node *leftRotation(struct Node *node)
{
    struct Node *x = node->right;
    struct Node *t2 = node->left->right;

    x->right = node;
    node->left = t2;

    node->height = 0;

    x->height = 1 + (getHeight(x) - getHeight(node));

    return x;
}
struct Node *rightRotation(struct Node *node)
{
    struct Node *y = node->right;
    struct Node *t2 = node->right->left;

    y->left = node;
    node->right = t2;

    node->height = 0;

    y->height = 1 + (getHeight(y) - getHeight(node));

    return y;
}

struct Node *insert(int key)
{
    struct Node *node = creatNode(key);
}

int main(int argc, char const *argv[])
{

    return 0;
}
