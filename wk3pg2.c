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
void insertInMiddle(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *slow = *head, *fast = *head;
    struct Node* prev = NULL;
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    newNode->next = slow;
    if (prev != NULL) {
        prev->next = newNode;
    } else {
        *head = newNode;
    }
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(4);
    printf("Original List: ");
    printList(head);
    insertInMiddle(&head, 3);
    printf("Updated List: ");
    printList(head);
    return 0;
}