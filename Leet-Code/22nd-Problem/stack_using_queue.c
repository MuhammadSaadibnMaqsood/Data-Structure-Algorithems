#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int capacity;
    int front;  // index of current front
    int back;   // index for next insert
    int size;
} Queue;

Queue *queueCreate(int capacity) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * capacity);
    q->capacity = capacity;
    q->front = 0;
    q->back = 0;
    q->size = 0;
    return q;
}

void queueFree(Queue *q) {
    free(q->data);
    free(q);
}

bool queueEmpty(Queue *q) {
    return q->size == 0;
}

int queueSize(Queue *q) {
    return q->size;
}

void queueEnqueue(Queue *q, int x) {
    if (q->size == q->capacity) {
        // simple resize if needed (shouldn't be necessary for small constraints,
        // but useful to avoid overflow): double capacity
        int newCap = q->capacity * 2;
        int *newData = malloc(sizeof(int) * newCap);
        // copy in order
        for (int i = 0; i < q->size; ++i) {
            newData[i] = q->data[(q->front + i) % q->capacity];
        }
        free(q->data);
        q->data = newData;
        q->capacity = newCap;
        q->front = 0;
        q->back = q->size;
    }
    q->data[q->back] = x;
    q->back = (q->back + 1) % q->capacity;
    q->size++;
}

int queueDequeue(Queue *q) {
    if (q->size == 0) return -1; // invalid, but per problem calls will be valid
    int val = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return val;
}

int queueFront(Queue *q) {
    if (q->size == 0) return -1;
    return q->data[q->front];
}

/* MyStack implemented using two queues */
typedef struct {
    Queue *q1;
    Queue *q2;
    int capacity; // initial capacity for queues
} MyStack;

MyStack* myStackCreate() {
    MyStack *st = (MyStack *)malloc(sizeof(MyStack));
    st->capacity = 16; // small default, will auto-resize as needed
    st->q1 = queueCreate(st->capacity);
    st->q2 = queueCreate(st->capacity);
    return st;
}

void myStackPush(MyStack* obj, int x) {
    // enqueue x to q2
    queueEnqueue(obj->q2, x);
    // move all from q1 to q2
    while (!queueEmpty(obj->q1)) {
        int v = queueDequeue(obj->q1);
        queueEnqueue(obj->q2, v);
    }
    // swap q1 and q2
    Queue *tmp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = tmp;
}

int myStackPop(MyStack* obj) {
    // pop from q1's front
    return queueDequeue(obj->q1);
}

int myStackTop(MyStack* obj) {
    return queueFront(obj->q1);
}

bool myStackEmpty(MyStack* obj) {
    return queueEmpty(obj->q1);
}

void myStackFree(MyStack* obj) {
    queueFree(obj->q1);
    queueFree(obj->q2);
    free(obj);
}

/* Example main to test */
int main(void) {
    MyStack *myStack = myStackCreate();
    myStackPush(myStack, 1);
    myStackPush(myStack, 2);
    printf("top: %d (expected 2)\n", myStackTop(myStack));
    printf("pop: %d (expected 2)\n", myStackPop(myStack));
    printf("empty: %s (expected false)\n", myStackEmpty(myStack) ? "true" : "false");

    // More tests
    myStackPush(myStack, 3);
    myStackPush(myStack, 4);
    printf("top: %d (expected 4)\n", myStackTop(myStack));
    printf("pop: %d (expected 4)\n", myStackPop(myStack));
    printf("pop: %d (expected 3)\n", myStackPop(myStack));
    printf("pop: %d (expected 1)\n", myStackPop(myStack));
    printf("empty: %s (expected true)\n", myStackEmpty(myStack) ? "true" : "false");

    myStackFree(myStack);
    return 0;
}
