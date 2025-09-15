#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* push(Node *top, int x) {
    Node *n = malloc(sizeof(Node));
    n->data = x;
    n->next = top;
    return n;
}
Node* pop(Node *top, int *ret) {
    if (!top) { *ret = -1; return NULL; }
    Node *next = top->next;
    *ret = top->data;
    free(top);
    return next;
}
int peek(Node *top) {
    if (!top) { printf("Stack empty\n"); return -1; }
    return top->data;
}

int main() {
    Node *top = NULL;
    int x;
    top = push(top, 5);
    top = push(top, 15);
    printf("Peek: %d\n", peek(top)); 
    top = pop(top, &x); printf("Popped: %d\n", x);
    top = pop(top, &x); printf("Popped: %d\n", x);
    top = pop(top, &x);
    return 0;
}
