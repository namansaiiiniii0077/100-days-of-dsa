#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *newNode(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    int n;
    scanf("%d", &n);

    Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        Node *node = newNode(x);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }

    tail->next = head;

    Node *cur = head;
    do {
        if (cur != head) printf(" ");
        printf("%d", cur->data);
        cur = cur->next;
    } while (cur != head);
    printf("\n");

    return 0;
}