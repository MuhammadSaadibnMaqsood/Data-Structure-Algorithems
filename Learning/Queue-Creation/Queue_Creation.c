#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int b;
    int *arr;
};

int isFull(struct queue *que)
{
    if (que->b == que->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *que)
{
    if (que->b == que->f)
    {
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    struct queue *queue = (struct queue *)malloc(sizeof(struct queue));

    queue->size = 20;
    queue->f = -1;
    queue->b = -1;
    queue->arr = (int *)malloc(queue->size * sizeof(int));

    if (isFull(queue))
    {
        printf("Queue is full");
    }

    if (isEmpty(queue))
    {
        printf("Queue is Empty");
    }

    return 0;
}
