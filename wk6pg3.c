#include <stdio.h>
#define MAX 1000

typedef struct {
    int arr[MAX];
    int front, rear, size;
} CQueue;

void initCQueue(CQueue *q) {
    q->front = q->rear = -1;
    q->size = MAX;
}

int isFull(CQueue *q) {
    return ((q->rear + 1) % q->size == q->front);
}

int isEmpty(CQueue *q) {
    return (q->front == -1);
}

void enqueue(CQueue *q, int x) {
    if (isFull(q)) {
        printf("Circular Queue Overflow\n");
        return;
    }
    if (isEmpty(q)) q->front = 0;
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = x;
}

int dequeue(CQueue *q) {
    if (isEmpty(q)) {
        printf("Circular Queue Underflow\n");
        return -1;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front = (q->front + 1) % q->size;
    return val;
}
