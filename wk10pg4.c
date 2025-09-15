#include <stdio.h>
#include <stdlib.h>

int largestRectangleArea(int *h, int n){
    int *stack = malloc(sizeof(int)*(n+1));
    int top = -1;
    int i=0;
    int maxA=0;
    while(i<n){
        if(top==-1 || h[stack[top]]<=h[i]) stack[++top]=i++;
        else{
            int tp = stack[top--];
            int width = (top==-1)? i : i - stack[top] - 1;
            int area = h[tp]*width;
            if(area>maxA) maxA=area;
        }
    }
    while(top!=-1){
        int tp = stack[top--];
        int width = (top==-1)? i : i - stack[top] - 1;
        int area = h[tp]*width;
        if(area>maxA) maxA=area;
    }
    free(stack);
    return maxA;
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    int *h = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) scanf("%d",&h[i]);
    printf("%d\n", largestRectangleArea(h,n));
    free(h);
    return 0;
}
