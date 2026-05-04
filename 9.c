#include <stdio.h>
#include <string.h>

void reverse(char *s, int left, int right) {
    if (left >= right) return;
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    reverse(s, left + 1, right - 1);
}

int main() {
    char s[1000];
    scanf("%s", s);
    reverse(s, 0, strlen(s) - 1);
    printf("%s\n", s);
    return 0;
}