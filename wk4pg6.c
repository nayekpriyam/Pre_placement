#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* sortedInsert(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* current = head;

    if (data < head->data) {
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
        return newNode; 
    }
    while (current->next != head && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;

    return head;
}
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}
int main() {
    struct Node* head = NULL;

    head = sortedInsert(head, 30);
    head = sortedInsert(head, 20);
    head = sortedInsert(head, 40);
    head = sortedInsert(head, 10);

    printList(head);

    return 0;
}