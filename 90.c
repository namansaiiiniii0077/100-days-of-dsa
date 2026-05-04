#include <stdio.h>

int canPaint(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;

        if (sum + arr[i] > maxTime) {
            painters++;
            sum = arr[i];

            if (painters > k)
                return 0;
        } else {
            sum += arr[i];
        }
    }

    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] > low)
            low = arr[i];

        high += arr[i];
    }

    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPaint(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}