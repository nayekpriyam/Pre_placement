#include<stdio.h>
int main(){
    int n1,n2,max;
    printf("Enter degree of first polynomial: ");
    scanf("%d",&n1);
    printf("Enter degree of second polynomial: ");
    scanf("%d",&n2);
    max=n1>n2?n1:n2;
    int p1[max+1],p2[max+1],sum[max+1];
    for(int i=0;i<=max;i++){p1[i]=0;p2[i]=0;}
    printf("Enter coefficients of first polynomial from highest to constant:\n");
    for(int i=n1;i>=0;i--)scanf("%d",&p1[i]);
    printf("Enter coefficients of second polynomial from highest to constant:\n");
    for(int i=n2;i>=0;i--)scanf("%d",&p2[i]);
    for(int i=0;i<=max;i++)sum[i]=p1[i]+p2[i];
    printf("Sum of polynomials: ");
    for(int i=max;i>=0;i--){
        printf("%dx^%d",sum[i],i);
        if(i!=0)printf(" + ");
    }
    printf("\n");
    return 0;
}