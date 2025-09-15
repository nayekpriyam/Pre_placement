#include <stdio.h>
#include <string.h>

int countDistinct(char *str, int start, int end) {
    int freq[256] = {0}, count = 0;
    for (int i = start; i <= end; i++) {
        if (freq[(unsigned char)str[i]] == 0)
            count++;
        freq[(unsigned char)str[i]]++;
    }
    return count;
}

int countSubstrings(char *str, int k) {
    int n = strlen(str), result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (countDistinct(str, i, j) == k)
                result++;
        }
    }
    return result;
}

int main() {
    char str[100];
    int k;
    scanf("%s %d", str, &k);
    printf("%d\n", countSubstrings(str, k));
    return 0;
}
