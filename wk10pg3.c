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
    int R,C;
    if(scanf("%d %d",&R,&C)!=2) return 0;
    int **mat = malloc(sizeof(int*)*R);
    for(int i=0;i<R;i++){
        mat[i]=malloc(sizeof(int)*C);
        for(int j=0;j<C;j++) scanf("%d",&mat[i][j]);
    }
    int *h = calloc(C, sizeof(int));
    int maxRect=0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(mat[i][j]==1) h[j] += 1; else h[j]=0;
        }
        int area = largestRectangleArea(h, C);
        if(area>maxRect) maxRect=area;
    }
    printf("%d\n", maxRect);
    for(int i=0;i<R;i++) free(mat[i]);
    free(mat); free(h);
    return 0;
}
