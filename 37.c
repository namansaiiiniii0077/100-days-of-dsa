#include <stdio.h>

#define MAX 1000

int pq[MAX], size = 0;

void insert(int val) {
    pq[size++] = val;
}

int findMin() {
    int idx = 0;
    for (int i = 1; i < size; i++)
        if (pq[i] < pq[idx]) idx = i;
    return idx;
}

int delete() {
    if (size == 0) return -1;
    int idx = findMin();
    int val = pq[idx];
    pq[idx] = pq[--size];
    return val;
}

int peek() {
    if (size == 0) return -1;
    return pq[findMin()];
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[10];
        scanf("%s", op);
        if (op[0] == 'i') {
            int val;
            scanf("%d", &val);
            insert(val);
        } else if (op[0] == 'd') {
            printf("%d\n", delete());
        } else {
            printf("%d\n", peek());
        }
    }

    return 0;
}