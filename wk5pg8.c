#include <stdio.h>
#include <stdlib.h>

int knows(int **M, int a, int b) { return M[a][b]; }

int findCelebrity(int **M, int n) {
    int a = 0, b = n-1;
    while (a < b) {
        if (knows(M, a, b)) a++;
        else b--;
    }
    int cand = a;
    for (int i=0;i<n;i++) {
        if (i!=cand && (knows(M, cand, i) || !knows(M, i, cand)))
            return -1;
    }
    return cand;
}

int main() {
    int n;
    if (scanf("%d", &n)!=1) return 0;
    int **M = malloc(n*sizeof(int*));
    for (int i=0;i<n;i++) {
        M[i] = malloc(n*sizeof(int));
        for (int j=0;j<n;j++) scanf("%d", &M[i][j]);
    }
    int ans = findCelebrity(M, n);
    if (ans == -1) printf("No celebrity\n");
    else printf("Celebrity is %d\n", ans);
    for (int i=0;i<n;i++) free(M[i]);
    free(M);
    return 0;
}
