#include <stdio.h>
#include <stdlib.h>

struct CircularQueue
{
    int size;
    int f;
    int b;
    int *arr;
};

int isFull(struct CircularQueue *que)
{
    if ((que->b + 1) % que->size == que->f)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct CircularQueue *que)
{
    if (que->b == que->f)
    {
        return 1;
    }
    return 0;
}

void Enque(struct CircularQueue *que, int data)
{
    if (isFull(que))
    {
        printf("\nQueue Overflow");
    }
    else
    {
        que->b = (que->b + 1) % que->size;
        que->arr[que->b] = data;
    }
}

int Deque(struct CircularQueue *que)
{
    if (isEmpty(que))
    {
        return 0;
    }
    else
    {
        que->f = (que->f + 1) % que->size;
        return que->arr[que->f];
    }
}

int main(int argc, char const *argv[])
{
    struct CircularQueue *queue = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));

    queue->size = 4;
    queue->f = 0;
    queue->b = 0;
    queue->arr = (int *)malloc(queue->size * sizeof(int));

    if (isFull(queue))
    {
        printf("\nQueue is full");
    }

    if (isEmpty(queue))
    {
        printf("\nQueue is Empty");
    }

    Enque(queue, 1);
    Enque(queue, 2);
    Enque(queue, 3);
    // Enque(queue, 5);

    printf("\nDeque element: %d", Deque(queue));
    printf("\nDeque element: %d", Deque(queue));
    Enque(queue, 4);

    if (isFull(queue))
    {
        printf("\nQueue is full");
    }

    if (isEmpty(queue))
    {
        printf("\nQueue is Empty");
    }

    return 0;
}
