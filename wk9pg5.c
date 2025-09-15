#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){ return (*(int*)a) - (*(int*)b); }

int longestConsecutive(int *arr, int n){
    if(n==0) return 0;
    qsort(arr,n,sizeof(int),cmp);
    int best=1, cur=1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]) continue; 
        else if(arr[i]==arr[i-1]+1) cur++;
        else { if(cur>best) best=cur; cur=1; }
    }
    if(cur>best) best=cur;
    return best;
}

int main(){
    int arr[] = {100, 4, 200, 1, 3, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Longest consecutive length = %d\n", longestConsecutive(arr,n));
    return 0;
}
