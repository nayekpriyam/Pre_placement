#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x; n->left = n->right = NULL;
    return n;
}

typedef struct Q {
    Node **arr;
    int front, rear, capacity;
} Q;

Q* createQ(int cap) {
    Q* q = (Q*)malloc(sizeof(Q));
    q->arr = (Node**)malloc(sizeof(Node*) * cap);
    q->front = 0; q->rear = 0; q->capacity = cap;
    return q;
}

int empty(Q* q) { return q->front == q->rear; }
void push(Q* q, Node* x) {
    if (q->rear == q->capacity) { 
        int newcap = q->capacity * 2;
        q->arr = (Node**)realloc(q->arr, sizeof(Node*) * newcap);
        q->capacity = newcap;
    }
    q->arr[q->rear++] = x;
}
Node* pop(Q* q) {
    if (empty(q)) return NULL;
    return q->arr[q->front++];
}

void levelOrder(Node* root) {
    if (!root) return;
    Q* q = createQ(8);
    push(q, root);
    while (!empty(q)) {
        Node* cur = pop(q);
        printf("%d ", cur->data);
        if (cur->left) push(q, cur->left);
        if (cur->right) push(q, cur->right);
    }
    free(q->arr); free(q);
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level order: ");
    levelOrder(root);
    printf("\n");
    return 0;
}
