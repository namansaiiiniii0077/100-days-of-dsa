#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int val) {
    Node *node = malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    if (!rear) front = rear = node;
    else { rear->next = node; rear = node; }
}

void display() {
    Node *cur = front;
    while (cur) {
        if (cur != front) printf(" ");
        printf("%d", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    display();
    return 0;
}