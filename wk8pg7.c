#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x; n->left = n->right = NULL;
    return n;
}

int isBSTUtil(Node* root, long minVal, long maxVal) {
    if (!root) return 1;
    if (root->data <= minVal || root->data >= maxVal) return 0;
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

int isBST(Node* root) {
    return isBSTUtil(root, LONG_MIN, LONG_MAX);
}

int main() {
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    printf("Is BST? %s\n", isBST(root) ? "Yes" : "No");

    root->right->left = newNode(7); 
    printf("After inserting 7 at right->left, Is BST? %s\n", isBST(root) ? "Yes" : "No");
    return 0;
}
