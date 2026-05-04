#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    int table[m];

    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    char op[20];
    int key;

    for (int j = 0; j < n; j++) {
        scanf("%s %d", op, &key);

        int h = key % m;

        if (strcmp(op, "INSERT") == 0) {
            for (int i = 0; i < m; i++) {
                int index = (h + i * i) % m;

                if (table[index] == EMPTY || table[index] == key) {
                    table[index] = key;
                    break;
                }
            }
        }
        else if (strcmp(op, "SEARCH") == 0) {
            int found = 0;

            for (int i = 0; i < m; i++) {
                int index = (h + i * i) % m;

                if (table[index] == key) {
                    found = 1;
                    break;
                }

                if (table[index] == EMPTY)
                    break;
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}