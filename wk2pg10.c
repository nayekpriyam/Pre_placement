#include<stdio.h>
int main(){
    int r,c,count=0;
    printf("Enter rows and columns: ");
    scanf("%d %d",&r,&c);
    int mat[r][c];
    printf("Enter elements:\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&mat[i][j]);
            if(mat[i][j]==0)count++;
        }
    }
    printf("Number of zeros=%d\n",count);
    return 0;
}