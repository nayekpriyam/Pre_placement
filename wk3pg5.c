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
void findNthFromEnd(struct Node* head, int n) {
    struct Node *main_ptr = head, *ref_ptr = head;
    int count = 0;
    while (count < n) {
        if (ref_ptr == NULL) {
            printf("The list has fewer than %d nodes.\n", n);
            return;
        }
        ref_ptr = ref_ptr->next;
        count++;
    }
    while (ref_ptr != NULL) {
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
    }
    printf("The %dth node from the end is: %d\n", n, main_ptr->data);
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    printf("Linked List: ");
    printList(head);
    int n = 2; 
    findNthFromEnd(head, n);
    return 0;
}