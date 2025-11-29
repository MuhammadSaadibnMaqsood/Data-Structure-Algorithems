#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Iterator frame (one list and its current index)
typedef struct {
    struct NestedInteger **list;
    int size;
    int index;
} Frame;

// The iterator
struct NestedIterator {
    Frame *stack;
    int top;
};

// Create iterator
struct NestedIterator* nestedIterCreate(struct NestedInteger** nestedList, int nestedListSize) {
    struct NestedIterator *iter = malloc(sizeof(struct NestedIterator));

    iter->stack = malloc(sizeof(Frame) * 10000);
    iter->top = 0;

    // push initial frame
    iter->stack[iter->top].list = nestedList;
    iter->stack[iter->top].size = nestedListSize;
    iter->stack[iter->top].index = 0;

    return iter;
}

// Move iterator to next integer frame
bool nestedIterHasNext(struct NestedIterator *iter) {
    while (iter->top >= 0) {
        Frame *f = &iter->stack[iter->top];

        // No more elements in this list, pop frame
        if (f->index >= f->size) {
            iter->top--;
            continue;
        }

        struct NestedInteger *curr = f->list[f->index];

        if (NestedIntegerIsInteger(curr)) {
            // Found next integer
            return true;
        }

        // Element is a list → expand it
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

// Return next integer
int nestedIterNext(struct NestedIterator *iter) {
    Frame *f = &iter->stack[iter->top];
    struct NestedInteger *curr = f->list[f->index];
    f->index++;
    return NestedIntegerGetInteger(curr);
}

// free iterator
void nestedIterFree(struct NestedIterator *iter) {
    free(iter->stack);
    free(iter);
}
