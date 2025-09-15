#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int evaluatePostfix(char *expr) {
    int n = strlen(expr);
    int *stack = malloc(sizeof(int)*n);
    int top = -1;
    char *token = strtok(expr, " ");
    while (token) {
        if (isdigit(token[0]) || (token[0]=='-' && isdigit(token[1]))) {
            stack[++top] = atoi(token);
        } else {
            int b = stack[top--];
            int a = stack[top--];
            switch(token[0]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
                case '^': {
                    int res=1;
                    for(int i=0;i<b;i++) res *= a;
                    stack[++top] = res;
                } break;
                default: break;
            }
        }
        token = strtok(NULL, " ");
    }
    int res = (top>=0) ? stack[top] : 0;
    free(stack);
    return res;
}

int main() {
    char line[2000];
    if (!fgets(line, sizeof(line), stdin)) return 0;
    line[strcspn(line, "\n")] = '\0';
    char *copy = strdup(line);
    int ans = evaluatePostfix(copy);
    printf("%d\n", ans);
    free(copy);
    return 0;
}
