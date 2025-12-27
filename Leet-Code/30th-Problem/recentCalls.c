#include <stdlib.h>

typedef struct {
    int *queue;
    int front;
    int rear;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter *rc = (RecentCounter *)malloc(sizeof(RecentCounter));
    rc->queue = (int *)malloc(sizeof(int) * 10000);
    rc->front = 0;
    rc->rear = 0;
    return rc;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->queue[obj->rear++] = t;

    while (obj->queue[obj->front] < t - 3000) {
        obj->front++;
    }

    return obj->rear - obj->front;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->queue);
    free(obj);
}
