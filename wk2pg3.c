#include<stdio.h>
int main(){
    int n;
    printf("Enter size of square matrix: ");
    scanf("%d",&n);
    int mat[n][n],sum1=0,sum2=0;
    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        sum1+=mat[i][i];
        sum2+=mat[i][n-i-1];
    }
    printf("Primary diagonal sum=%d\n",sum1);
    printf("Secondary diagonal sum=%d\n",sum2);
    return 0;
}