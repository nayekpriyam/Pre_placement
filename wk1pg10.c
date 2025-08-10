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
    int high=n-1;
    int low=0;
    while(low<high)
    {
        int temp=a[low];
        a[low]=a[high];
        a[high]=temp;
        low++;
        high--;
    }
    printf("The reversed array is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}