#include <stdio.h>

struct Meeting {
    int start;
    int end;
};

void swapMeeting(struct Meeting *a, struct Meeting *b) {
    struct Meeting temp = *a;
    *a = *b;
    *b = temp;
}

void sortMeetings(struct Meeting arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].start > arr[j + 1].start) {
                swapMeeting(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(int heap[], int *size, int val) {
    heap[*size] = val;
    int i = *size;
    (*size)++;

    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

int pop(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;

    int i = 0;

    while (1) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < *size && heap[left] < heap[smallest])
            smallest = left;

        if (right < *size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Meeting meetings[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    sortMeetings(meetings, n);

    int heap[n];
    int size = 0;
    int maxRooms = 0;

    for (int i = 0; i < n; i++) {
        while (size > 0 && heap[0] <= meetings[i].start) {
            pop(heap, &size);
        }

        push(heap, &size, meetings[i].end);

        if (size > maxRooms)
            maxRooms = size;
    }

    printf("%d", maxRooms);

    return 0;
}