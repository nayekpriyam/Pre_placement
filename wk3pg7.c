#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void detectAndRemoveLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { 
            removeLoop(head, slow);
            return;
        }
    }
}
void removeLoop(struct Node* head, struct Node* loopNode) {
    struct Node* ptr1 = head;
    struct Node* ptr2;
    while (1) {
        ptr2 = loopNode;
        while (ptr2->next != loopNode && ptr2->next != ptr1) {
            ptr2 = ptr2->next;
        }

        if (ptr2->next == ptr1) {
            break;
        }
        ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
}
struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}
void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = head->next;
    detectAndRemoveLoop(head);
    printf("Linked List after removing loop: \n");
    printList(head);
    return 0;
}