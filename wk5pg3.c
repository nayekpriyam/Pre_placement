#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isMatching(char a, char b) {
    return (a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']');
}

int isBalanced(const char *s) {
    int n = strlen(s);
    char *stack = malloc(n);
    int top = -1;
    for (int i=0;i<n;i++) {
        char c = s[i];
        if (c=='(' || c=='{' || c=='[') stack[++top] = c;
        else if (c==')' || c=='}' || c==']') {
            if (top == -1 || !isMatching(stack[top--], c)) { free(stack); return 0; }
        }
    }
    int res = (top==-1);
    free(stack);
    return res;
}

int main() {
    char s[1001];
    if (!fgets(s, sizeof(s), stdin)) return 0;
    s[strcspn(s, "\n")] = '\0';
    printf("%s\n", isBalanced(s) ? "Balanced" : "Not Balanced");
    return 0;
}
