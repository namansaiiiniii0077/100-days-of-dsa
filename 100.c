#include <stdio.h>

struct Pair {
    int value;
    int index;
};

void merge(struct Pair arr[], int ans[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    struct Pair left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    int rightCount = 0;

    while (i < n1 && j < n2) {
        if (right[j].value < left[i].value) {
            rightCount++;
            arr[k++] = right[j++];
        } else {
            ans[left[i].index] += rightCount;
            arr[k++] = left[i++];
        }
    }

    while (i < n1) {
        ans[left[i].index] += rightCount;
        arr[k++] = left[i++];
    }

    while (j < n2) {
        arr[k++] = right[j++];
    }
}

void mergeSort(struct Pair arr[], int ans[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        mergeSort(arr, ans, l, m);
        mergeSort(arr, ans, m + 1, r);

        merge(arr, ans, l, m, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Pair arr[n];
    int ans[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
        ans[i] = 0;
    }

    mergeSort(arr, ans, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    return 0;
}