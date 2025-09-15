#include <stdio.h>
#include <stdlib.h>

void calculateSpan(int price[], int n, int S[]) {
    int *stack = malloc(sizeof(int)*n); 
    int top = -1;
    for (int i=0;i<n;i++) {
        while (top!=-1 && price[stack[top]] <= price[i]) top--;
        S[i] = (top == -1) ? (i+1) : (i - stack[top]);
        stack[++top] = i;
    }
    free(stack);
}

int main() {
    int n;
    if (scanf("%d", &n)!=1) return 0;
    int *price = malloc(sizeof(int)*n);
    for (int i=0;i<n;i++) scanf("%d", &price[i]);
    int *S = malloc(sizeof(int)*n);
    calculateSpan(price, n, S);
    for (int i=0;i<n;i++) printf("%d ", S[i]);
    printf("\n");
    free(price); free(S);
    return 0;
}
