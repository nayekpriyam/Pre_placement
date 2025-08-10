#include <stdio.h>
#include <string.h>
void main()
{
    char ch[100];
    printf("Enter a string");
    scanf("%s",&ch);
    int l=strlen(ch);
    for(int i=0;i<=l/2;i++)
    {
        char c=ch[i];
        ch[i]=ch[l-i-1];
        ch[l-i-1]=c;
    }
    printf("Reversed string is:%s",ch);
}