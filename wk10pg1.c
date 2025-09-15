#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key, val;
    int prev, next; 
    int used;
} Node;

typedef struct {
    int cap, size;
    Node *nodes;
    int head, tail; 
    int *hash_keys; 
    int *hash_vals; 
    int hash_size;
    int *free_list;
    int free_top;
} LRUCache;

int next_pow2(int v){ int p=1; while(p<v) p<<=1; return p; }
int hash_idx(LRUCache *c, int key){
    int h = (key*2654435761u) & (c->hash_size-1);
    while(c->hash_keys[h]!=INT_MIN && c->hash_keys[h]!=key) h=(h+1)&(c->hash_size-1);
    return h;
}

LRUCache* lRUCacheCreate(int capacity){
    LRUCache *c = malloc(sizeof(*c));
    c->cap = capacity;
    c->size = 0;
    c->nodes = calloc(capacity, sizeof(Node));
    for(int i=0;i<capacity;i++){ c->nodes[i].used = 0; c->nodes[i].prev = c->nodes[i].next = -1; }
    c->head = c->tail = -1;
    c->hash_size = next_pow2(capacity*4);
    c->hash_keys = malloc(sizeof(int)*c->hash_size);
    c->hash_vals = malloc(sizeof(int)*c->hash_size);
    for(int i=0;i<c->hash_size;i++){ c->hash_keys[i]=INT_MIN; c->hash_vals[i]=-1; }
    c->free_list = malloc(sizeof(int)*capacity);
    for(int i=0;i<capacity;i++) c->free_list[i]=capacity-1-i;
    c->free_top = capacity-1;
    return c;
}

void detach(LRUCache *c, int idx){
    if(idx==-1) return;
    int p = c->nodes[idx].prev, n = c->nodes[idx].next;
    if(p!=-1) c->nodes[p].next = n; else c->head = n;
    if(n!=-1) c->nodes[n].prev = p; else c->tail = p;
    c->nodes[idx].prev = c->nodes[idx].next = -1;
}

void attach_head(LRUCache *c, int idx){
    c->nodes[idx].prev = -1;
    c->nodes[idx].next = c->head;
    if(c->head!=-1) c->nodes[c->head].prev = idx;
    c->head = idx;
    if(c->tail==-1) c->tail = idx;
}

int lRUCacheGet(LRUCache* c, int key){
    int h = hash_idx(c,key);
    if(c->hash_keys[h]==INT_MIN) return -1;
    int nodei = c->hash_vals[h];
    if(nodei==-1) return -1;
    detach(c,nodei);
    attach_head(c,nodei);
    return c->nodes[nodei].val;
}

void lRUCachePut(LRUCache* c, int key, int value){
    int h = hash_idx(c,key);
    if(c->hash_keys[h]!=INT_MIN){
        int nodei = c->hash_vals[h];
        if(nodei!=-1){
            c->nodes[nodei].val = value;
            detach(c,nodei);
            attach_head(c,nodei);
            return;
        }
    }
    int use;
    if(c->size < c->cap){
        use = c->free_list[c->free_top--];
        c->size++;
    } else {
        int ev = c->tail;
        int eh = hash_idx(c, c->nodes[ev].key);
        c->hash_keys[eh]=INT_MIN;
        c->hash_vals[eh]=-1;
        int j = (eh+1)&(c->hash_size-1);
        while(c->hash_keys[j]!=INT_MIN){
            int kkey = c->hash_keys[j];
            int kval = c->hash_vals[j];
            c->hash_keys[j]=INT_MIN; c->hash_vals[j]=-1;
            int nh = hash_idx(c,kkey);
            c->hash_keys[nh]=kkey; c->hash_vals[nh]=kval;
            j = (j+1)&(c->hash_size-1);
        }
        use = ev;
        detach(c,use);
    }
    c->nodes[use].key = key;
    c->nodes[use].val = value;
    c->nodes[use].used = 1;
    c->nodes[use].prev = c->nodes[use].next = -1;
    attach_head(c,use);
    int nh = hash_idx(c,key);
    c->hash_keys[nh] = key;
    c->hash_vals[nh] = use;
}

void lRUCacheFree(LRUCache* c){
    free(c->nodes);
    free(c->hash_keys);
    free(c->hash_vals);
    free(c->free_list);
    free(c);
}

int main(){
    LRUCache *cache = lRUCacheCreate(2);
    lRUCachePut(cache,1,1);
    lRUCachePut(cache,2,2);
    printf("%d\n", lRUCacheGet(cache,1)); 1
    lRUCachePut(cache,3,3); ,
    printf("%d\n", lRUCacheGet(cache2)); 
    lRUCachePut(cache,4,4); 
    printf("%d\n", lRUCacheGet(cache,1)); 
    printf("%d\n", lRUCacheGet(cache,3)); 
    printf("%d\n", lRUCacheGet(cache,4)); 
    lRUCacheFree(cache);
    return 0;
}
