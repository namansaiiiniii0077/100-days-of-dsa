#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int expected = (i == j) ? 1 : 0;
            if (a[i][j] != expected) {
                printf("Not an Identity Matrix\n");
                return 0;
            }
        }
    }

    printf("Identity Matrix\n");
    return 0;
}