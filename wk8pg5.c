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

void leftViewUtil(Node* root, int level, int *maxLevel) {
    if (!root) return;
    if (level > *maxLevel) {
        printf("%d ", root->data);
        *maxLevel = level;
    }
    leftViewUtil(root->left, level + 1, maxLevel);
    leftViewUtil(root->right, level + 1, maxLevel);
}

void leftView(Node* root) {
    int maxLevel = 0;
    leftViewUtil(root, 1, &maxLevel);
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->right->right = newNode(6);

    printf("Left view: ");
    leftView(root);
    printf("\n");
    return 0;
}
