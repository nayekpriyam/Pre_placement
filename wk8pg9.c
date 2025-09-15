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

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return NULL;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* r = root->right;
            free(root);
            return r;
        } else if (!root->right) {
            Node* l = root->left;
            free(root);
            return l;
        } else {
            Node* succ = findMin(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
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
    int vals[] = {50, 30, 20, 40, 70, 60, 80};
    for (int i = 0; i < 7; ++i) root = insertBST(root, vals[i]);

    printf("Inorder before deletions: ");
    inorder(root); printf("\n");

    root = deleteNode(root, 20); 
    root = deleteNode(root, 30); 
    root = deleteNode(root, 50); 
    printf("Inorder after deletions: ");
    inorder(root); printf("\n");
    return 0;
}
