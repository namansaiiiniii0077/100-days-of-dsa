#include <stdio.h>

#define MAX 1000

int stack[MAX], top = -1;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        stack[++top] = x;
    }

    int m;
    scanf("%d", &m);

    while (m-- && top >= 0)
        top--;

    for (int i = top; i >= 0; i--) {
        if (i != top) printf(" ");
        printf("%d", stack[i]);
    }
    printf("\n");

    return 0;
}