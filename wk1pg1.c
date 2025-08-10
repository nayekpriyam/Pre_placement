#include <stdio.h>
void main()
{
    int n;
    printf("enter the size of the array");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int ele;
    printf("Enter the element to be inserted");
    scanf("%d",&ele);
    a[n]=ele;
    printf("The elements are:");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}