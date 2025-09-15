#include <stdio.h>
#include <string.h>

int isPalindrome(char str[], int l, int r) {
    if (l >= r) return 1;
    if (str[l] != str[r]) return 0;
    return isPalindrome(str, l + 1, r - 1);
}

int main() {
    char str[100];
    scanf("%s", str);
    if (isPalindrome(str, 0, strlen(str) - 1))
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
    return 0;
}
