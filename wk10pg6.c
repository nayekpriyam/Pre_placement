#include <stdio.h>
#include <stdlib.h>

typedef struct { char id; int dead, profit; } Job;

int cmp(const void*a,const void*b){ return ((Job*)b)->profit - ((Job*)a)->profit; }

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Job *jobs = malloc(sizeof(Job)*n);
    int maxd=0;
    for(int i=0;i<n;i++){ scanf(" %c %d %d",&jobs[i].id, &jobs[i].dead, &jobs[i].profit); if(jobs[i].dead>maxd) maxd=jobs[i].dead; }
    qsort(jobs,n,sizeof(Job),cmp);
    int *slot = malloc(sizeof(int)*(maxd+1));
    char *res = malloc(sizeof(char)*(maxd+1));
    for(int i=0;i<=maxd;i++) slot[i]=0, res[i]=0;
    int totalProfit=0, count=0;
    for(int i=0;i<n;i++){
        for(int d = jobs[i].dead; d>0; d--){
            if(!slot[d]){ slot[d]=1; res[d]=jobs[i].id; totalProfit+=jobs[i].profit; count++; break; }
        }
    }
    printf("Jobs scheduled: ");
    for(int i=1;i<=maxd;i++) if(res[i]) printf("%c ", res[i]);
    printf("\nTotal profit: %d\n", totalProfit);
    free(jobs); free(slot); free(res);
    return 0;
}
