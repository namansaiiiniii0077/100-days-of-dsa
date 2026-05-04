#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int sum = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            if (i == j) sum += x;
        }

    printf("%d\n", sum);
    return 0;
}