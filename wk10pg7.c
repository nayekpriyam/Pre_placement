#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void*a,const void*b){ return (*(int*)a) - (*(int*)b); }

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    int *arr = malloc(sizeof(int)*n);
    int *dep = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<n;i++) scanf("%d",&dep[i]);
    qsort(arr,n,sizeof(int),cmp_int);
    qsort(dep,n,sizeof(int),cmp_int);
    int i=0,j=0, plat=0, maxp=0;
    while(i<n && j<n){
        if(arr[i] <= dep[j]){ plat++; if(plat>maxp) maxp=plat; i++; }
        else { plat--; j++; }
    }
    printf("%d\n", maxp);
    free(arr); free(dep);
    return 0;
}
