#include <stdio.h>

int canAllocate(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;

        if (sum + arr[i] > maxPages) {
            students++;
            sum = arr[i];

            if (students > m)
                return 0;
        } else {
            sum += arr[i];
        }
    }

    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] > low)
            low = arr[i];

        high += arr[i];
    }

    if (m > n) {
        printf("-1");
        return 0;
    }

    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canAllocate(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}