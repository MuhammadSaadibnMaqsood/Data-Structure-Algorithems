#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct {
    struct TreeNode **stack;
    int top;
    int size;
} BSTIterator;


void pushLeft(BSTIterator *obj, struct TreeNode *node) {
    while (node != NULL) {
        obj->stack[++obj->top] = node;
        node = node->left;
    }
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator *obj = (BSTIterator*)malloc(sizeof(BSTIterator));
    obj->size = 200000;     // enough for 1e5 height worst-case
    obj->top = -1;
    obj->stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * obj->size);

    // push leftmost path
    pushLeft(obj, root);

    return obj;
}

int bSTIteratorNext(BSTIterator* obj) {
    // pop smallest available element
    struct TreeNode *node = obj->stack[obj->top--];

    // push left path of right subtree
    if (node->right != NULL) {
        pushLeft(obj, node->right);
    }

    return node->val;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->top != -1;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->stack);
    free(obj);
}
