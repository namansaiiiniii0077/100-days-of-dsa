#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index) {
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(int x) {
    if (size == MAX) return;
    heap[size] = x;
    heapifyUp(size);
    size++;
}

int peek() {
    if (size == 0) return -1;
    return heap[0];
}

int extractMin() {
    if (size == 0) return -1;

    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);

    return min;
}

int main() {
    int N;
    scanf("%d", &N);

    char op[20];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (op[0] == 'i') {
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'p') {
            printf("%d\n", peek());
        }
        else if (op[0] == 'e') {
            printf("%d\n", extractMin());
        }
    }

    return 0;
}