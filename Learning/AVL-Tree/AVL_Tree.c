#include <stdio.h>
#include <stdlib.h>

// AVL Node structure
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// Function to create a new node
struct Node *createNode(int key) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // height of leaf node = 1
    return newNode;
}

// Function to get height safely
int getHeight(struct Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get Balance Factor
int getBalanceFactor(struct Node *node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Right rotation
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + (getHeight(y->left) > getHeight(y->right)
                         ? getHeight(y->left)
                         : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right)
                         ? getHeight(x->left)
                         : getHeight(x->right));

    // Return new root
    return x;
}

// Left rotation
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + (getHeight(x->left) > getHeight(x->right)
                         ? getHeight(x->left)
                         : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right)
                         ? getHeight(y->left)
                         : getHeight(y->right));

    // Return new root
    return y;
}

// Insert function (recursively)
struct Node *insert(struct Node *node, int key) {
    // Normal BST insertion
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // no duplicates

    // Update height of current node
    node->height = 1 + (getHeight(node->left) > getHeight(node->right)
                            ? getHeight(node->left)
                            : getHeight(node->right));

    // Get the balance factor
    int balance = getBalanceFactor(node);

    // Perform rotations if unbalanced

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return unchanged node
    return node;
}

// Inorder Traversal (for testing)
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);  // This will trigger Right Rotation (LL Case)
    root = insert(root, 25);
    root = insert(root, 40);
    root = insert(root, 50);  // Might trigger rotations

    printf("Inorder traversal of AVL tree:\n");
    inorder(root);
    printf("\n");

    return 0;
}
