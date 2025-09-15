#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 3        
#define HASH_SIZE 10     

typedef struct Node {
    int key, value;
    struct Node *prev, *next;
} Node;

typedef struct HashNode {
    int key;
    Node* page;
    struct HashNode* next;
} HashNode;

Node *head = NULL, *tail = NULL;
int size = 0;
HashNode* hashTable[HASH_SIZE];

int hash(int key) {
    return key % HASH_SIZE;
}

void hashInsert(int key, Node* page) {
    int h = hash(key);
    HashNode* newEntry = (HashNode*)malloc(sizeof(HashNode));
    newEntry->key = key;
    newEntry->page = page;
    newEntry->next = hashTable[h];
    hashTable[h] = newEntry;
}

void hashDelete(int key) {
    int h = hash(key);
    HashNode *temp = hashTable[h], *prev = NULL;
    while (temp) {
        if (temp->key == key) {
            if (prev) prev->next = temp->next;
            else hashTable[h] = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

Node* hashSearch(int key) {
    int h = hash(key);
    HashNode* temp = hashTable[h];
    while (temp) {
        if (temp->key == key) return temp->page;
        temp = temp->next;
    }
    return NULL;
}

void addToFront(Node* node) {
    node->prev = NULL;
    node->next = head;
    if (head) head->prev = node;
    head = node;
    if (!tail) tail = node;
}

void removeNode(Node* node) {
    if (node->prev) node->prev->next = node->next;
    else head = node->next;
    if (node->next) node->next->prev = node->prev;
    else tail = node->prev;
}

int get(int key) {
    Node* page = hashSearch(key);
    if (!page) return -1;

    removeNode(page);
    addToFront(page);
    return page->value;
}

void put(int key, int value) {
    Node* page = hashSearch(key);
    if (page) {
        page->value = value;
        removeNode(page);
        addToFront(page);
    } else {
        if (size == CAPACITY) {
            hashDelete(tail->key);
            removeNode(tail);
            free(tail);
            size--;
        }
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = key;
        newNode->value = value;
        newNode->prev = newNode->next = NULL;
        addToFront(newNode);
        hashInsert(key, newNode);
        size++;
    }
}
int main() {
    for (int i = 0; i < HASH_SIZE; i++) hashTable[i] = NULL;

    put(1, 10);
    put(2, 20);
    put(3, 30);
    printf("Get 2: %d\n", get(2));   
    put(4, 40);                      
    printf("Get 1: %d\n", get(1));   
    printf("Get 3: %d\n", get(3));   
    printf("Get 4: %d\n", get(4));  
    return 0;
}
