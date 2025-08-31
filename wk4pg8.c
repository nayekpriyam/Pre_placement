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
struct Node* pairwiseSwap(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; 
    }
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    head = head->next; 
    while (curr != NULL && curr->next != NULL) {
        next = curr->next;
        curr->next = next->next;
        next->next = curr;
        if (prev != NULL) {
            prev->next = next;
        }
        prev = curr;
        curr = curr->next;
    }

    return head;
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List:\n");
    printList(head);
    head = pairwiseSwap(head);
    printf("List After Pairwise Swap:\n");
    printList(head);

    return 0;
}