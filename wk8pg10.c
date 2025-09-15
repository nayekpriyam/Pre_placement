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

Node* insertBST(Node* root, int key) {
    if (!root) return newNode(key);
    if (key < root->data) root->left = insertBST(root->left, key);
    else if (key > root->data) root->right = insertBST(root->right, key);
    return root;
}

Node* lcaBST(Node* root, int n1, int n2) {
    if (!root) return NULL;
    if (root->data > n1 && root->data > n2)
        return lcaBST(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return lcaBST(root->right, n1, n2);
    return root;
}

int main() {
    Node* root = NULL;
    int vals[] = {20, 8, 22, 4, 12, 10, 14};
    for (int i = 0; i < 7; ++i) root = insertBST(root, vals[i]);

    int a = 10, b = 14;
    Node* anc = lcaBST(root, a, b);
    if (anc) printf("LCA of %d and %d is %d\n", a, b, anc->data);
    else printf("LCA not found\n");

    a = 14; b = 8;
    anc = lcaBST(root, a, b);
    if (anc) printf("LCA of %d and %d is %d\n", a, b, anc->data);
    else printf("LCA not found\n");

    return 0;
}
