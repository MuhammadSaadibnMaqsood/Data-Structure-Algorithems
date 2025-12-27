#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->data = (int*)malloc(capacity * sizeof(int));
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    return q;
}

void enqueue(Queue *q, int value) {
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

int dequeue(Queue *q) {
    int val = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return val;
}

void freeQueue(Queue *q) {
    free(q->data);
    free(q);
}

void sort(int *deck, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (deck[j] < deck[min])
                min = j;
        }
        int temp = deck[i];
        deck[i] = deck[min];
        deck[min] = temp;
    }
}

int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) {
    *returnSize = deckSize;

    sort(deck, deckSize);

    Queue *q = createQueue(deckSize);
    int *result = (int*)malloc(deckSize * sizeof(int));

    // push indices
    for (int i = 0; i < deckSize; i++)
        enqueue(q, i);

    for (int i = 0; i < deckSize; i++) {
        int idx = dequeue(q);
        result[idx] = deck[i];

        if (q->size > 0) {
            enqueue(q, dequeue(q));
        }
    }

    freeQueue(q);
    return result;
}
