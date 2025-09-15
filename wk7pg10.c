#include <stdio.h>
#include <string.h>

long long digitSum(char *n, long long k) {
    long long sum = 0;
    for (int i = 0; i < strlen(n); i++)
        sum += (n[i] - '0');
    sum *= k;

    if (sum < 10) return sum;

    char buffer[50];
    sprintf(buffer, "%lld", sum);
    return digitSum(buffer, 1);
}

int main() {
    char n[1000];
    long long k;
    scanf("%s %lld", n, &k);
    printf("%lld\n", digitSum(n, k));
    return 0;
}
