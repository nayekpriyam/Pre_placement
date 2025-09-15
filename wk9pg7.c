#include <stdio.h>
#include <stdlib.h>

#define M 100003
typedef struct Node{ int key, cnt; struct Node *next; } Node;
Node *b[M];

int h(int k){ long x=k; if(x<0) x=-x; return x%M; }

void incCount(int key){
    int idx = h(key); Node *cur = b[idx];
    while(cur){ if(cur->key==key){ cur->cnt++; return;} cur=cur->next; }
    Node *n = malloc(sizeof(Node)); n->key=key; n->cnt=1; n->next=b[idx]; b[idx]=n;
}

int getCount(int key){
    int idx=h(key); Node *cur=b[idx];
    while(cur){ if(cur->key==key) return cur->cnt; cur=cur->next; }
    return 0;
}

int countPairs(int arr[], int n, int sum){
    for(int i=0;i<M;i++) b[i]=NULL;
    int count=0;
    for(int i=0;i<n;i++){
        int complement = sum - arr[i];
        count += getCount(complement);
        incCount(arr[i]);
    }
    return count;
}

int main(){
    int arr[] = {1,5,7,-1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 6;
    printf("Number of pairs = %d\n", countPairs(arr,n,sum));
    return 0;
}
