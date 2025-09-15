#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} LPHash;

LPHash* lp_create(int cap) {
    LPHash *h = malloc(sizeof(LPHash));
    h->capacity = cap;
    h->size = 0;
    h->arr = malloc(sizeof(int)*cap);
    for(int i=0;i<cap;i++) h->arr[i] = INT_MIN; 
    return h;
}

int hash(int key, int cap) {
    long k = key;
    if(k<0) k = -k;
    return (int)(k % cap);
}

void lp_insert(LPHash *h, int key) {
    if(h->size >= h->capacity) {
        printf("Hash full, cannot insert %d\n", key);
        return;
    }
    int idx = hash(key, h->capacity);
    int start = idx;
    while(h->arr[idx] != INT_MIN && h->arr[idx] != INT_MIN+1 && h->arr[idx] != key) {
        idx = (idx + 1) % h->capacity;
        if(idx == start) return;
    }
    if(h->arr[idx] == key) return; 
    h->arr[idx] = key;
    h->size++;
}

int lp_search(LPHash *h, int key) {
    int idx = hash(key, h->capacity);
    int start = idx;
    while(h->arr[idx] != INT_MIN) {
        if(h->arr[idx] == key) return 1;
        idx = (idx+1) % h->capacity;
        if(idx==start) break;
    }
    return 0;
}

void lp_delete(LPHash *h, int key) {
    int idx = hash(key, h->capacity);
    int start = idx;
    while(h->arr[idx] != INT_MIN) {
        if(h->arr[idx] == key) {
            h->arr[idx] = INT_MIN+1; 
            h->size--;
            return;
        }
        idx = (idx+1) % h->capacity;
        if(idx==start) break;
    }
}

void lp_print(LPHash *h) {
    for(int i=0;i<h->capacity;i++) {
        if(h->arr[i] == INT_MIN) printf("[%d]: EMPTY\n", i);
        else if(h->arr[i] == INT_MIN+1) printf("[%d]: DELETED\n", i);
        else printf("[%d]: %d\n", i, h->arr[i]);
    }
}

int main() {
    LPHash *h = lp_create(11);
    int vals[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16};
    for(int i=0;i<10;i++) lp_insert(h, vals[i]);
    printf("Table after inserts:\n"); lp_print(h);
    printf("Search 23: %d\n", lp_search(h, 23));
    lp_delete(h, 23);
    printf("After deleting 23. Search 23: %d\n", lp_search(h, 23));
    lp_print(h);
    return 0;
}
