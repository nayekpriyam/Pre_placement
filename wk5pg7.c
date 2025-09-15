#include <stdio.h>
#include <stdlib.h>

void nextGreater(int arr[], int n, int res[]) {
    int *stack = malloc(sizeof(int)*n);
    int top = -1;
    for (int i=n-1;i>=0;i--) {
        while (top!=-1 && arr[stack[top]] <= arr[i]) top--;
        res[i] = (top==-1) ? -1 : arr[stack[top]];
        stack[++top] = i;
    }
    free(stack);
}

int main() {
    int n;
    if (scanf("%d", &n)!=1) return 0;
    int *arr = malloc(sizeof(int)*n);
    for (int i=0;i<n;i++) scanf("%d", &arr[i]);
    int *res = malloc(sizeof(int)*n);
    nextGreater(arr, n, res);
    for (int i=0;i<n;i++) printf("%d ", res[i]);
    printf("\n");
    free(arr); free(res);
    return 0;
}
