#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minReversals(const char *expr) {
    int n = strlen(expr);
    if (n % 2) return -1;
    int open = 0, close = 0;
    for (int i=0;i<n;i++) {
        if (expr[i] == '{') open++;
        else {
            if (open > 0) open--;
            else close++;
        }
    }
    int res = (open+1)/2 + (close+1)/2;
    return res;
}

int main() {
    char s[100001];
    if (!fgets(s, sizeof(s), stdin)) return 0;
    s[strcspn(s, "\n")] = '\0';
    int ans = minReversals(s);
    if (ans == -1) printf("Impossible\n");
    else printf("%d\n", ans);
    return 0;
}
