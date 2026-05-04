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

    int k = 0;
    scanf("%d", &k);
    k = k % n;

    if (k == 0) {
        Node *cur = head;
        while (cur) {
            if (cur != head) printf(" ");
            printf("%d", cur->data);
            cur = cur->next;
        }
        printf("\n");
        return 0;
    }

    tail->next = head;

    Node *cur = head;
    for (int i = 0; i < n - k - 1; i++)
        cur = cur->next;

    head = cur->next;
    cur->next = NULL;

    cur = head;
    while (cur) {
        if (cur != head) printf(" ");
        printf("%d", cur->data);
        cur = cur->next;
    }
    printf("\n");

    return 0;
}