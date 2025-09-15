#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestValidParentheses(char *s){
    int n = strlen(s);
    int *stack = malloc(sizeof(int)*(n+1));
    int top = -1;
    int maxlen = 0;
    stack[++top] = -1;
    for(int i=0;i<n;i++){
        if(s[i]=='(') stack[++top]=i;
        else {
            top--;
            if(top==-1) stack[++top]=i;
            else {
                int len = i - stack[top];
                if(len>maxlen) maxlen=len;
            }
        }
    }
    free(stack);
    return maxlen;
}

int main(){
    char s[100005];
    if(scanf("%s", s)!=1) return 0;
    printf("%d\n", longestValidParentheses(s));
    return 0;
}
