#include <stdio.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

void init(Queue *q){q->front=q->rear=-1;}
int empty(Queue *q){return q->front==-1;}
void enq(Queue *q,int x){if(q->front==-1) q->front=0; q->arr[++q->rear]=x;}
int deq(Queue *q){return q->arr[q->front++];}

void interleave(Queue *q){
    int n=q->rear-q->front+1;
    int half=n/2;
    Queue q1;init(&q1);
    for(int i=0;i<half;i++) enq(&q1,deq(q));
    while(!empty(&q1)){
        enq(q,deq(&q1));
        enq(q,deq(q));
    }
}

int main(){
    Queue q;init(&q);
    for(int i=1;i<=6;i++) enq(&q,i);
    interleave(&q);
    while(!empty(&q)) printf("%d ",deq(&q));
    return 0;
}
