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

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int vals[] = {20, 10, 30, 5, 15, 25, 35};
    for (int i = 0; i < 7; ++i) root = insertBST(root, vals[i]);

    printf("BST inorder: ");
    inorder(root);
    printf("\nInsert 22 and 12\n");
    root = insertBST(root, 22);
    root = insertBST(root, 12);
    printf("BST inorder: ");
    inorder(root);
    printf("\n");
    return 0;
}
