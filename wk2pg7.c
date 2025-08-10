#include<stdio.h>
int main(){
    int n1,n2;
    printf("Enter degree of first polynomial: ");
    scanf("%d",&n1);
    printf("Enter degree of second polynomial: ");
    scanf("%d",&n2);
    int p1[n1+1],p2[n2+1],prod[n1+n2+1];
    for(int i=0;i<=n1;i++)scanf("%d",&p1[i]);
    for(int i=0;i<=n2;i++)scanf("%d",&p2[i]);
    for(int i=0;i<=n1+n2;i++)prod[i]=0;
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            prod[i+j]+=p1[i]*p2[j];
        }
    }
    printf("Product of polynomials: ");
    for(int i=n1+n2;i>=0;i--){
        printf("%dx^%d",prod[i],i);
        if(i!=0)printf(" + ");
    }
    printf("\n");
    return 0;
}