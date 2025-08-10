#include<stdio.h>
void rotate90(int n,int mat[n][n]){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int temp=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=temp;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            int temp=mat[i][j];
            mat[i][j]=mat[i][n-j-1];
            mat[i][n-j-1]=temp;
        }
    }
}
int main(){
    int n;
    printf("Enter size of square matrix: ");
    scanf("%d",&n);
    int matrix[n][n];
    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    rotate90(n,matrix);
    printf("Matrix after 90 degree rotation:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}