#include <stdio.h>
#include <string.h>
void main()
{
    char ch[100],st[100];
    printf("Enter a string");
    scanf("%s",&ch);
    strcpy(st,ch);
    int l=strlen(ch);
    for(int i=0;i<=l/2;i++)
    {
        char c=ch[i];
        ch[i]=ch[l-i-1];
        ch[l-i-1]=c;
    }
    if(strcmp(ch,st)==0)
        printf("Palindrome String");
    else
        printf("Not a Palindrome String");
}