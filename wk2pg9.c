#include<stdio.h>
int main(){
    int n,flag=1;
    printf("Enter size of square matrix: ");
    scanf("%d",&n);
    int mat[n][n];
    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j && mat[i][j]!=1)flag=0;
            else if(i!=j && mat[i][j]!=0)flag=0;
        }
    }
    if(flag)printf("Matrix is identity\n");
    else printf("Matrix is not identity\n");
    return 0;
}