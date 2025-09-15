#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *next;
} Node;

typedef struct {
    Node **buckets;
    int capacity;
} SCHash;

int schash_hash(int key, int cap) {
    long k=key; if(k<0) k=-k;
    return (int)(k % cap);
}

SCHash* schash_create(int cap) {
    SCHash *h = malloc(sizeof(SCHash));
    h->capacity = cap;
    h->buckets = calloc(cap, sizeof(Node*));
    return h;
}

void schash_insert(SCHash *h, int key) {
    int idx = schash_hash(key, h->capacity);
    Node *cur = h->buckets[idx];
    while(cur) {
        if(cur->key == key) return; 
        cur = cur->next;
    }
    Node *n = malloc(sizeof(Node));
    n->key = key;
    n->next = h->buckets[idx];
    h->buckets[idx] = n;
}

int schash_search(SCHash *h, int key) {
    int idx = schash_hash(key, h->capacity);
    Node *cur = h->buckets[idx];
    while(cur) {
        if(cur->key == key) return 1;
        cur = cur->next;
    }
    return 0;
}

void schash_delete(SCHash *h, int key) {
    int idx = schash_hash(key, h->capacity);
    Node *cur = h->buckets[idx], *prev=NULL;
    while(cur) {
        if(cur->key == key) {
            if(prev) prev->next = cur->next;
            else h->buckets[idx] = cur->next;
            free(cur);
            return;
        }
        prev = cur; cur = cur->next;
    }
}

void schash_print(SCHash *h) {
    for(int i=0;i<h->capacity;i++) {
        printf("[%d]:", i);
        Node *cur = h->buckets[i];
        while(cur) { printf(" %d ->", cur->key); cur = cur->next; }
        printf(" NULL\n");
    }
}

int main() {
    SCHash *h = schash_create(7);
    int vals[] = {10,20,15,7,32,5,14,21};
    for(int i=0;i<8;i++) schash_insert(h, vals[i]);
    schash_print(h);
    printf("Search 15: %d\n", schash_search(h,15));
    schash_delete(h,15);
    printf("After delete 15. Search 15: %d\n", schash_search(h,15));
    schash_print(h);
    return 0;
}
