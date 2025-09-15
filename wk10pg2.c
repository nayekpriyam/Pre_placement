#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct { int key, cnt; } Pair;

int cmp_pair(const void *a, const void *b){
    Pair *pa = (Pair*)a, *pb=(Pair*)b;
    if(pa->cnt!=pb->cnt) return pb->cnt - pa->cnt;
    return pa->key - pb->key;
}

int next_pow2(int v){ int p=1; while(p<v) p<<=1; return p; }

int main(){
    int n;
    if(scanf("%d",&n)!=1) return 0;
    int *a = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int k; scanf("%d",&k);
    int hsz = next_pow2(n*4+10);
    int *hk = malloc(sizeof(int)*hsz), *hv = malloc(sizeof(int)*hsz);
    for(int i=0;i<hsz;i++){ hk[i]=INT_MIN; hv[i]=0; }
    for(int i=0;i<n;i++){
        int key = a[i];
        int h = (key*2654435761u) & (hsz-1);
        while(hk[h]!=INT_MIN && hk[h]!=key) h=(h+1)&(hsz-1);
        if(hk[h]==INT_MIN) hk[h]=key;
        hv[h]++;
    }
    Pair *pairs = malloc(sizeof(Pair)*hsz);
    int pc=0;
    for(int i=0;i<hsz;i++) if(hk[i]!=INT_MIN) { pairs[pc].key=hk[i]; pairs[pc].cnt=hv[i]; pc++; }
    qsort(pairs, pc, sizeof(Pair), cmp_pair);
    for(int i=0;i<k && i<pc;i++){
        if(i) printf(" ");
        printf("%d", pairs[i].key);
    }
    printf("\n");
    free(a); free(hk); free(hv); free(pairs);
    return 0;
}
