#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int getCount(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}
int getIntersectionPoint(struct Node* head1, struct Node* head2) {
    int count1 = getCount(head1);
    int count2 = getCount(head2);
    int diff = abs(count1 - count2);

    if (count1 > count2) {
        for (int i = 0; i < diff; i++) {
            head1 = head1->next;
        }
    } else {
        for (int i = 0; i < diff; i++) {
            head2 = head2->next;
        }
    }
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1->data;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;
}
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
int main() {
    struct Node* newNode;
    struct Node* head1 = newNode(10);
    struct Node* head2 = newNode(3);

    head2->next = newNode(6);
    head2->next->next = newNode(9);

    newNode = newNode(15);
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode->next = newNode(30);

    printf("The intersection point is: %d\n", getIntersectionPoint(head1, head2));

    return 0;
}