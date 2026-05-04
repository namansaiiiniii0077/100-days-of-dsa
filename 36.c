#include <stdio.h>

#define MAX 1000

int queue[MAX];
int front = 0, rear = 0, size = 0;

void enqueue(int val) {
    queue[rear] = val;
    rear = (rear + 1) % MAX;
    size++;
}

int dequeue() {
    int val = queue[front];
    front = (front + 1) % MAX;
    size--;
    return val;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    int m;
    scanf("%d", &m);

    while (m-- && size > 0)
        dequeue();

    for (int i = 0; i < size; i++) {
        if (i > 0) printf(" ");
        printf("%d", queue[(front + i) % MAX]);
    }
    printf("\n");

    return 0;
}