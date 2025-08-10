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
    int c=0;
    int x=a[0],y=a[1];
    if(a[0]>=a[1])
    {
        for(int i=0;i<n-1;i++)
        {
            if(a[i]>=a[i+1])
            {
                c=c+1;
            }
        }
    }
    else
    {
        for(int i=0;i<n-1;i++)
        {
            if(a[i]<=a[i+1])
            {
                c=c+1;
            }
        }
    }
    if(c==n-1)
        printf("Sorted array");
    else
        printf("Unsorted array");
}