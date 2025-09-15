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

void mirror(Node* root) {
    if (!root) return;
    Node* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    mirror(root->left);
    mirror(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Inorder before mirror: ");
    inorder(root); printf("\n");

    mirror(root);

    printf("Inorder after mirror: ");
    inorder(root); printf("\n");
    return 0;
}
