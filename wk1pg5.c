#include <stdio.h>
void main()
{
    int n;
    printf("enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int x=a[n-1];
    for(int i=n-1;i>0;i--)
    {
        a[i]=a[i-1];
    }    
    a[0]=x;
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    
}