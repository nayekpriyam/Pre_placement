#include <stdio.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) { q->front=q->rear=-1; }
int isEmpty(Queue *q){ return q->front==-1; }
void enqueue(Queue *q,int x){ if(q->front==-1) q->front=0; q->arr[++q->rear]=x; }
int dequeue(Queue *q){ return q->arr[q->front++]; }

void reverseK(Queue *q,int k){
    int stack[MAX],top=-1;
    for(int i=0;i<k;i++) stack[++top]=dequeue(q);
    while(top>=0) enqueue(q,stack[top--]);
    int size=q->rear-q->front+1;
    for(int i=0;i<size-k;i++) enqueue(q,dequeue(q));
}

int main(){
    Queue q; initQueue(&q);
    for(int i=1;i<=6;i++) enqueue(&q,i);
    reverseK(&q,3);
    while(!isEmpty(&q)) printf("%d ",dequeue(&q));
    return 0;
}
