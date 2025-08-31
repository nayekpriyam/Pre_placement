#include <stdio.h>

int josephus(int n, int k) {
    if (n == 1)
        return 0; 
    return (josephus(n - 1, k) + k) % n;
}
int main() {
    int n, k;
    printf("Enter the number of people (n): ");
    scanf("%d", &n);
    printf("Enter the step count (k): ");
    scanf("%d", &k);

    printf("The safe position is: %d\n", josephus(n, k) + 1);
    return 0;
}