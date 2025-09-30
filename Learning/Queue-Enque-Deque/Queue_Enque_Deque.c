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

void Enque(struct queue *que, int data)
{
    if (isFull(que))
    {
        printf("Queue OVerflow");
    }
    else
    {
        que->b++;
        que->arr[que->b] = data;
    }
}

int Deque(struct queue *que)
{
    if (isEmpty(que))
    {
        return 0;
    }
    else
    {
        que->f++;
        return que->arr[que->f];
    }
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
        printf("\nQueue is full");
    }

    if (isEmpty(queue))
    {
        printf("\nQueue is Empty");
    }

    Enque(queue, 1);
    Enque(queue, 2);
    Enque(queue, 3);

    printf("\nDeque element: %d", Deque(queue));
    printf("\nDeque element: %d", Deque(queue));

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
