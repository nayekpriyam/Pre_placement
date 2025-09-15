#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int prec(char c) {
    if (c=='+'||c=='-') return 1;
    if (c=='*'||c=='/') return 2;
    if (c=='^') return 3;
    return 0;
}

int isOperator(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

void infixToPostfix(const char *in, char *out) {
    int n = strlen(in), j=0;
    char *stack = malloc(n);
    int top=-1;
    for (int i=0;i<n;i++) {
        char c = in[i];
        if (isspace(c)) continue;
        if (isalnum(c)) out[j++] = c;
        else if (c=='(') stack[++top]=c;
        else if (c==')') {
            while (top!=-1 && stack[top]!='(') out[j++] = stack[top--];
            if (top!=-1 && stack[top]=='(') top--;
        } else if (isOperator(c)) {
            while (top!=-1 && ((prec(stack[top])>prec(c)) || (prec(stack[top])==prec(c) && c!='^')) && stack[top]!='(')
                out[j++] = stack[top--];
            stack[++top] = c;
        }
    }
    while (top!=-1) out[j++]=stack[top--];
    out[j] = '\0';
    free(stack);
}

int main() {
    char in[1001], out[1001];
    if (!fgets(in, sizeof(in), stdin)) return 0;
    in[strcspn(in, "\n")] = '\0';
    infixToPostfix(in, out);
    printf("%s\n", out);
    return 0;
}
