#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
void push(Stack *s, int x) { s->arr[++s->top] = x; }
int pop(Stack *s) { return s->arr[s->top--]; }

typedef struct {
    Stack s1, s2;
} Queue;

void initQueue(Queue *q) {
    initStack(&q->s1);
    initStack(&q->s2);
}

void enqueue(Queue *q, int x) {
    push(&q->s1, x);
}

int dequeue(Queue *q) {
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    if (isEmpty(&q->s2)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return pop(&q->s2);
}
