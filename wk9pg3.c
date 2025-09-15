#include <stdio.h>
#include <stdlib.h>

#define MAP_CAP 100003

typedef struct MNode {
    int key, val;
    struct MNode *next;
} MNode;

MNode *map_bucket[MAP_CAP];

int map_hash(int key) {
    long k = key; if(k<0) k=-k;
    return (int)(k % MAP_CAP);
}

void map_put_inc(int key) {
    int h = map_hash(key);
    MNode *cur = map_bucket[h];
    while(cur) {
        if(cur->key == key) { cur->val++; return; }
        cur = cur->next;
    }
    MNode *n = malloc(sizeof(MNode)); n->key = key; n->val = 1;
    n->next = map_bucket[h]; map_bucket[h] = n;
}

void map_dec_remove_if_zero(int key) {
    int h = map_hash(key);
    MNode *cur = map_bucket[h], *prev=NULL;
    while(cur) {
        if(cur->key == key) {
            cur->val--;
            if(cur->val == 0) {
                if(prev) prev->next = cur->next; else map_bucket[h] = cur->next;
                free(cur);
            }
            return;
        }
        prev = cur; cur = cur->next;
    }
}

int map_get(int key) {
    int h = map_hash(key);
    MNode *cur = map_bucket[h];
    while(cur) {
        if(cur->key == key) return cur->val;
        cur = cur->next;
    }
    return 0;
}

void clear_map() {
    for(int i=0;i<MAP_CAP;i++) {
        MNode *cur = map_bucket[i];
        while(cur) { MNode *t = cur; cur = cur->next; free(t); }
        map_bucket[i] = NULL;
    }
}

void countDistinct(int arr[], int n, int k) {
    if(k>n) return;
    for(int i=0;i<k;i++) map_put_inc(arr[i]);
    int distinct = 0;
    for(int i=0;i<MAP_CAP;i++) {
        MNode *cur = map_bucket[i];
        while(cur) { distinct++; cur = cur->next; }
    }
    printf("%d ", distinct);
    for(int i=k;i<n;i++) {
        map_put_inc(arr[i]);
        map_dec_remove_if_zero(arr[i-k]);
        distinct = 0;
        for(int j=0;j<MAP_CAP;j++) { MNode *cur = map_bucket[j]; while(cur) { distinct++; cur = cur->next; } }
        printf("%d ", distinct);
    }
    printf("\n");
}

int main() {
    int arr[] = {1,2,1,3,4,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    countDistinct(arr,n,k);
    clear_map();
    return 0;
}
