#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *s;
} State;

int main() {
    int q;
    if (scanf("%d\n", &q)!=1) return 0;
    State *stack = malloc(sizeof(State)*(q+5));
    int top = -1;
    char *cur = strdup(""); 
    for (int i=0;i<q;i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            char w[100005];
            scanf("%s", w);
            stack[++top].s = cur;
            int newlen = strlen(cur) + strlen(w);
            char *nxt = malloc(newlen+1);
            strcpy(nxt, cur);
            strcat(nxt, w);
            cur = nxt;
        } else if (type == 2) {
            int k; scanf("%d", &k);
            stack[++top].s = cur;
            int curLen = strlen(cur);
            int newLen = curLen - k;
            if (newLen < 0) newLen = 0;
            char *nxt = malloc(newLen+1);
            strncpy(nxt, cur, newLen);
            nxt[newLen] = '\0';
            cur = nxt;
        } else if (type == 3) {
            int k; scanf("%d", &k);
            if (k >=1 && k <= (int)strlen(cur)) printf("%c\n", cur[k-1]);
            else printf("\n");
        } else if (type == 4) {
            if (top >= 0) {
                char *prev = stack[top--].s;
                free(cur);
                cur = prev;
            }
        }
        int c = getchar();
        if (c != '\n' && c != EOF) ungetc(c, stdin);
    }
    while (top >= 0) { free(stack[top--].s); }
    free(stack);
    free(cur);
    return 0;
}
