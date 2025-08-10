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
    int x=0;
    for (int i=0; i<n;i++) {
        if(a[i]!=0)
        {   
            a[x]=a[i];
            x++;
        }
    }
    while(x<n)
    {
        a[x++]=0;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    
}