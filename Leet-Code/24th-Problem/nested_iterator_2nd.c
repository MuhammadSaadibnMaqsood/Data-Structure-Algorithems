#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    struct NestedInteger **list;
    int size;
    int index;
} Frame;


struct NestedIterator
{
    Frame *stack;
    int top;
};


struct NestedIterator *nestedIterCreate(struct NestedInteger **nestedList, int nestedListSize)
{
    struct NestedIterator *iter = malloc(sizeof(struct NestedIterator));

    
    iter->stack = malloc(sizeof(Frame) * 10000);
    iter->top = 0;

    
    iter->stack[0].list = nestedList;
    iter->stack[0].size = nestedListSize;
    iter->stack[0].index = 0;

    return iter;
}


bool nestedIterHasNext(struct NestedIterator *iter)
{
    while (iter->top >= 0)
    {

        Frame *f = &iter->stack[iter->top];

        
        if (f->index >= f->size)
        {
            iter->top--;
            continue;
        }

        struct NestedInteger *curr = f->list[f->index];

        
        if (NestedIntegerIsInteger(curr))
        {
            return true;
        }

        
        f->index++;

        struct NestedInteger **subList = NestedIntegerGetList(curr);
        int subSize = NestedIntegerGetListSize(curr);

        iter->top++;
        iter->stack[iter->top].list = subList;
        iter->stack[iter->top].size = subSize;
        iter->stack[iter->top].index = 0;
    }

    return false;
}


int nestedIterNext(struct NestedIterator *iter)
{
    Frame *f = &iter->stack[iter->top];
    struct NestedInteger *curr = f->list[f->index];
    f->index++;
    return NestedIntegerGetInteger(curr);
}


void nestedIterFree(struct NestedIterator *iter)
{
    free(iter->stack);
    free(iter);
}
