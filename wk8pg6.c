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

int heightAndUpdateDiameter(Node* root, int *diameter) {
    if (!root) return 0;
    int lh = heightAndUpdateDiameter(root->left, diameter);
    int rh = heightAndUpdateDiameter(root->right, diameter);
    int through = lh + rh + 1;
    if (through > *diameter) *diameter = through;
    return (lh > rh ? lh : rh) + 1;
}

int diameter(Node* root) {
    int dia = 0;
    heightAndUpdateDiameter(root, &dia);
    return dia;
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(6);

    printf("Diameter (in nodes): %d\n", diameter(root));
    return 0;
}
