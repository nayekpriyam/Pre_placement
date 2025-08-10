#include<stdio.h>
#include<stdlib.h>
int main(){
    int *arr,n,choice,pos,val;
    printf("Enter size of array: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);

    printf("\n1.Display\n2.Insert\n3.Delete\nEnter choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            for(int i=0;i<n;i++)printf("%d ",arr[i]);
            printf("\n");
            break;
        case 2:
            printf("Enter position and value: ");
            scanf("%d%d",&pos,&val);
            if(pos<0||pos>n)printf("Invalid position\n");
            else{
                arr=(int*)realloc(arr,(n+1)*sizeof(int));
                for(int i=n;i>pos;i--)arr[i]=arr[i-1];
                arr[pos]=val;
                n++;
                for(int i=0;i<n;i++)printf("%d ",arr[i]);
                printf("\n");
            }
            break;
        case 3:
            printf("Enter position to delete: ");
            scanf("%d",&pos);
            if(pos<0||pos>=n)printf("Invalid position\n");
            else{
                for(int i=pos;i<n-1;i++)arr[i]=arr[i+1];
                n--;
                arr=(int*)realloc(arr,n*sizeof(int));
                for(int i=0;i<n;i++)printf("%d ",arr[i]);
                printf("\n");
            }
            break;
        default:
            printf("Invalid choice\n");
    }
    free(arr);
    return 0;
}