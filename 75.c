#include <stdio.h>

int main() {
    int arr[1000];
    int n = 0;

    while (scanf("%d", &arr[n]) != EOF) {
        n++;
    }

    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == 0) {
                int len = j - i + 1;
                if (len > maxLen)
                    maxLen = len;
            }
        }
    }

    printf("%d", maxLen);

    return 0;
}