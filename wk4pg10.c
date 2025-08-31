#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* child;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}
Node* flattenList(Node* head) {
    if (!head) return NULL;

    Node* current = head;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    while (current) {
        if (current->child) {
            tail->next = current->child;
            Node* temp = current->child;
            while (temp->next) {
                temp = temp->next;
            }
            tail = temp;
            current->child = NULL;
        }
        current = current->next;
    }

    return head;
}
void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->child = createNode(4);
    head->next->child->next = createNode(5);
    head->next->child->child = createNode(6);

    printf("Original List:\n");
    printList(head);

    head = flattenList(head);

    printf("Flattened List:\n");
    printList(head);

    return 0;
}