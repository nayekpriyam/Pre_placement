#include <stdio.h>
#include <stdlib.h>

#define CAP 100003
typedef struct Node { int key, cnt; struct Node *next; } Node;
Node *buckets[CAP];

int hfun(int k){ long x=k; if(x<0)x=-x; return x%CAP; }

void add(int key){
    int h=hfun(key); Node *cur=buckets[h];
    while(cur){ if(cur->key==key){ cur->cnt++; return;} cur=cur->next;}
    Node *n=malloc(sizeof(Node)); n->key=key; n->cnt=1; n->next=buckets[h]; buckets[h]=n;
}

int main(){
    int arr[] = {1, 2, 3, 2, 3, 4, 5, 3, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++) add(arr[i]);
    printf("Duplicates: ");
    for(int i=0;i<CAP;i++){
        Node *cur=buckets[i];
        while(cur){
            if(cur->cnt>1) printf("%d ", cur->key);
            cur=cur->next;
        }
    }
    printf("\n");
    return 0;
}
