#include <stdio.h>
#include <stdlib.h>

#define MAPC 100003
typedef struct Node{ int key; struct Node *next; } Node;
Node *mapb[MAPC];

int h(int k){ long x=k; if(x<0) x=-x; return x%MAPC; }

int foundPair(int arr[], int n, int sum){
    for(int i=0;i<MAPC;i++) mapb[i]=NULL;
    for(int i=0;i<n;i++){
        int need = sum - arr[i];
        int idx = h(need);
        Node *cur = mapb[idx];
        while(cur){ if(cur->key==need) return 1; cur=cur->next; }
        idx = h(arr[i]); Node *nnode = malloc(sizeof(Node)); nnode->key=arr[i]; nnode->next=mapb[idx]; mapb[idx]=nnode;
    }
    return 0;
}

int main(){
    int arr[] = {1,4,45,6,10,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 16;
    printf("Pair with sum %d exists? %s\n", sum, foundPair(arr,n,sum) ? "Yes":"No");
    return 0;
}
