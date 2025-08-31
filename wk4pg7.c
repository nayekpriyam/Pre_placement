#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int isCircular(struct Node* head) {
    if (head == NULL) {
        return 1; 
    }
    struct Node* temp = head->next;

    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    return (temp == head);
}
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = head; 

    if (isCircular(head)) {
        printf("The linked list is circular.\n");
    } else {
        printf("The linked list is not circular.\n");
    }

    return 0;
}