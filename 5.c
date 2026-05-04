#include <stdio.h>

int main() {
    int p;
    scanf("%d", &p);
    int a[p];
    for (int i = 0; i < p; i++)
        scanf("%d", &a[i]);

    int q;
    scanf("%d", &q);
    int b[q];
    for (int i = 0; i < q; i++)
        scanf("%d", &b[i]);

    int i = 0, j = 0, first = 1;

    while (i < p && j < q) {
        if (!first) printf(" ");
        if (a[i] <= b[j])
            printf("%d", a[i++]);
        else
            printf("%d", b[j++]);
        first = 0;
    }

    while (i < p) {
        if (!first) printf(" ");
        printf("%d", a[i++]);
        first = 0;
    }

    while (j < q) {
        if (!first) printf(" ");
        printf("%d", b[j++]);
        first = 0;
    }

    printf("\n");

    return 0;
}