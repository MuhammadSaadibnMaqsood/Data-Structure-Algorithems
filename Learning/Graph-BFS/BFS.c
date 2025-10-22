#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int first;
    int last;
    int *arr;
};

int isEmpty(struct Queue *queue)
{
    return queue->first == queue->last;
}

int isFull(struct Queue *queue)
{
    return queue->last == queue->size;
}

void enqueue(struct Queue *queue, int data)
{
    if (isFull(queue))
    {
        printf("Queue is Full\n");
        return;
    }

    queue->arr[queue->last] = data;
    queue->last++;
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty\n");
        return -1;
    }

    int val = queue->arr[queue->first];
    queue->first++;
    return val;
}

int main()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->size = 5;
    queue->first = 0;
    queue->last = 0;
    queue->arr = (int *)malloc(queue->size * sizeof(int));

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    enqueue(queue, 40);

    printf("Current queue elements:\n");
    for (int i = queue->first; i < queue->last; i++)
    {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");

    return 0;
}
