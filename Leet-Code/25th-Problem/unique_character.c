#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int front;
    int rear;
    int arr[100000];
} Queue;

void push(Queue *q, int value)
{
    q->arr[q->rear++] = value;
}

void pop(Queue *q)
{
    q->front++;
}

int front(Queue *q)
{
    return q->arr[q->front];
}

int empty(Queue *q)
{
    return q->front == q->rear;
}

int firstUniqChar(char *s)
{
    int freq[26] = {0};

    Queue q = {.front = 0, .rear = 0};

    for (int i = 0; s[i] != '\0'; i++)
    {
        freq[s[i] - 'a']++;
        push(&q, i);
    }

    while (!empty(&q))
    {
        int idx = front(&q);
        if (freq[s[idx] - 'a'] == 1)
        {
            return idx;
        }
        pop(&q);
    }
    return -1;
}


