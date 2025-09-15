#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *a; int top;
    int cap;
} Stack;
Stack* newStack(int c){ Stack*s=malloc(sizeof(Stack)); s->a=malloc(sizeof(int)*c); s->top=-1; s->cap=c; return s; }
void push(Stack *s,int v){ s->a[++s->top]=v; }
int pop(Stack*s){ if(s->top==-1) return INT_MIN; return s->a[s->top--]; }
int peek(Stack*s){ if(s->top==-1) return INT_MIN; return s->a[s->top]; }
int empty(Stack*s){ return s->top==-1; }

typedef struct {
    Stack *s1, *s2;
} MyQueue;
MyQueue* createQueue(int cap){ MyQueue*q=malloc(sizeof(MyQueue)); q->s1=newStack(cap); q->s2=newStack(cap); return q; }
void qpush(MyQueue*q,int x){ push(q->s1,x); }
int qpop(MyQueue*q){
    if(empty(q->s2)){
        while(!empty(q->s1)) push(q->s2, pop(q->s1));
    }
    return pop(q->s2);
}
int qpeek(MyQueue*q){
    if(empty(q->s2)){
        while(!empty(q->s1)) push(q->s2, pop(q->s1));
    }
    return peek(q->s2);
}

int main(){
    int Q; if(scanf("%d",&Q)!=1) return 0;
    MyQueue *q = createQueue(Q+5);
    while(Q--){
        int type; scanf("%d", &type);
        if(type==1){ int x; scanf("%d",&x); qpush(q,x); }
        else if(type==2){ qpop(q); }
        else if(type==3){ printf("%d\n", qpeek(q)); }
    }
    return 0;
}
