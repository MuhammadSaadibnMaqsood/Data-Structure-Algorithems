#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// -------------------- Tree Definition --------------------
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// -------------------- BSTIterator Definition --------------------
typedef struct {
    struct TreeNode **stack;
    int top;
    int size;
} BSTIterator;

// Push the entire left chain of a subtree
void pushLeft(BSTIterator *obj, struct TreeNode *node) {
    while (node != NULL) {
        obj->stack[++obj->top] = node;
        node = node->left;
    }
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator *obj = (BSTIterator*)malloc(sizeof(BSTIterator));
    obj->size = 200000;  // large enough
    obj->top = -1;
    obj->stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * obj->size);

    pushLeft(obj, root);
    return obj;
}

int bSTIteratorNext(BSTIterator* obj) {
    struct TreeNode *node = obj->stack[obj->top--];

    if (node->right)
        pushLeft(obj, node->right);

    return node->val;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->top != -1;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->stack);
    free(obj);
}


// -------------------- Helper: Create a Node --------------------
struct TreeNode* newNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}


// -------------------- BUILD SAMPLE TREE --------------------
// Tree from the example: [7,3,15,null,null,9,20]
//
//            7
//          /   \
//         3     15
//              /  \
//             9   20
//
struct TreeNode* buildSampleTree() {
    struct TreeNode* root = newNode(7);
    root->left = newNode(3);
    root->right = newNode(15);
    root->right->left = newNode(9);
    root->right->right = newNode(20);
    return root;
}


// -------------------- MAIN FUNCTION FOR TESTING --------------------
int main() {
    struct TreeNode* root = buildSampleTree();

    BSTIterator* it = bSTIteratorCreate(root);

    printf("Iterator Output:\n");
    while (bSTIteratorHasNext(it)) {
        printf("%d ", bSTIteratorNext(it));
    }

    printf("\n");

    bSTIteratorFree(it);
    return 0;
}
