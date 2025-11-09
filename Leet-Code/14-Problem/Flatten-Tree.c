#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct Stack
{
    int size;
    int top;
    struct TreeNode **arr;
};


struct Stack *createStack(int size)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (struct TreeNode **)malloc(size * sizeof(struct TreeNode *));
    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, struct TreeNode *node)
{
    stack->arr[++stack->top] = node;
}

struct TreeNode *pop(struct Stack *stack)
{
    return stack->arr[stack->top--];
}


void flatten(struct TreeNode *root)
{
    if (!root)
        return;

    struct Stack *stack = createStack(2000);

    push(stack, root);

    while (!isEmpty(stack))
    {
        struct TreeNode *curr = pop(stack);

        
        if (curr->right)
        {
            push(stack, curr->right);
        }

        if (curr->left)
        {
            push(stack, curr->left);
        }

        if (!isEmpty(stack))
        {
            curr->right = stack->arr[stack->top];
        }

        curr->left = NULL;
    }
}


void printFlattened(struct TreeNode *root)
{
    while (root)
    {
        printf("%d ", root->val);
        root = root->right;
    }
    printf("\n");
}


int main()
{
    
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node5 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node4 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node6 = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    root->val = 1;
    node2->val = 2;
    node5->val = 5;
    node3->val = 3;
    node4->val = 4;
    node6->val = 6;

    root->left = node2;
    root->right = node5;
    node2->left = node3;
    node2->right = node4;
    node5->left = NULL;
    node5->right = node6;
    node3->left = node3->right = NULL;
    node4->left = node4->right = NULL;
    node6->left = node6->right = NULL;

    flatten(root);
    printFlattened(root);

    return 0;
}
