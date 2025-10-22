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
    queue->size = 50;
    queue->first = 0;
    queue->last = 0;
    queue->arr = (int *)malloc(queue->size * sizeof(int));

    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int adj_Matrix[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };

    int i = 0;
    visited[i] = 1;
    printf("%d", i);
    enqueue(queue, i);
    while (!isEmpty(queue))
    {
        int node = dequeue(queue);
        for (int j = 0; j < 7; j++)
        {
            if (adj_Matrix[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = j;
                enqueue(queue, j);
            }
        }
    }

    return 0;
}
