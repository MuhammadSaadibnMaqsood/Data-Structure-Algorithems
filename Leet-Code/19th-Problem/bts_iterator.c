#include <stdio.h>
#include <stdlib.h>

//  * Definition for a binary tree node.
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct
{
    int size;
    int top;
    int *arr;

} BSTIterator;

BSTIterator *bSTIteratorCreate(struct TreeNode *root)
{
     BSTIterator * stack = (BSTIterator*)malloc(sizeof(BSTIterator));
     stack->size = 1000;
     stack->top = 0;
     stack->arr = (BSTIterator*)malloc(stack->size * sizeof(int));
    if (!root)
    {
        return NULL;
    }
    struct TreeNode *ptr = root;
    push(stack,root);
    
    if (ptr->right)
    {
        bSTIteratorCreate(root->right);

    }

    if (ptr->right)
    {
        
    }
    
    

}

int bSTIteratorNext(BSTIterator *obj)
{
}

int bSTIteratorHasNext(BSTIterator *obj)
{
}

void bSTIteratorFree(BSTIterator *obj)
{
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
