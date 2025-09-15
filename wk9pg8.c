#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HCAP 200003
typedef struct Node { long key; long cnt; struct Node *next; } Node;
Node *hb[HCAP];

int hfun(long k){ if(k<0) k=-k; return (int)(k % HCAP); }

void add_count(long key){
    int idx = hfun(key);
    Node *cur = hb[idx];
    while(cur){ if(cur->key==key){ cur->cnt++; return;} cur=cur->next;}
    Node *n = malloc(sizeof(Node)); n->key=key; n->cnt=1; n->next=hb[idx]; hb[idx]=n;
}

long get_count(long key){
    int idx=hfun(key);
    Node *cur=hb[idx];
    while(cur){ if(cur->key==key) return cur->cnt; cur=cur->next; }
    return 0;
}

long countZeroSumSubarrays(int arr[], int n){
    for(int i=0;i<HCAP;i++) hb[i]=NULL;
    long prefix=0;
    add_count(0); 
    long ans=0;
    for(int i=0;i<n;i++){
        prefix += arr[i];
        long c = get_count(prefix);
        ans += c;
        add_count(prefix);
    }
    return ans;
}

int main(){
    int arr[] = {0, 0, 5, 5, 0, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Zero-sum subarrays = %ld\n", countZeroSumSubarrays(arr,n));
    return 0;
}
