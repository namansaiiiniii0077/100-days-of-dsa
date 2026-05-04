#include <stdio.h>

struct Interval {
    int start;
    int end;
};

void swap(struct Interval *a, struct Interval *b) {
    struct Interval temp = *a;
    *a = *b;
    *b = temp;
}

void sortIntervals(struct Interval arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].start > arr[j + 1].start) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Interval arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    sortIntervals(arr, n);

    int currentStart = arr[0].start;
    int currentEnd = arr[0].end;

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= currentEnd) {
            if (arr[i].end > currentEnd)
                currentEnd = arr[i].end;
        } else {
            printf("%d %d\n", currentStart, currentEnd);
            currentStart = arr[i].start;
            currentEnd = arr[i].end;
        }
    }

    printf("%d %d", currentStart, currentEnd);

    return 0;
}