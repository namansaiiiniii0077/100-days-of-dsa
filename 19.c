#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), cmp);

    int left = 0, right = n - 1;
    int best_left = left, best_right = right;
    int best_sum = abs(arr[left] + arr[right]);

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (abs(sum) < best_sum) {
            best_sum = abs(sum);
            best_left = left;
            best_right = right;
        }
        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d\n", arr[best_left], arr[best_right]);
    return 0;
}


