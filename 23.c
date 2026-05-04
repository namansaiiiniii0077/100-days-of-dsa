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

Node *buildList(int n) {
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        Node *node = newNode(x);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    return head;
}

int main() {
    int n, m;
    scanf("%d", &n);
    Node *a = buildList(n);
    scanf("%d", &m);
    Node *b = buildList(m);

    Node dummy;
    Node *tail = &dummy;
    dummy.next = NULL;

    while (a && b) {
        if (a->data <= b->data) { tail->next = a; a = a->next; }
        else                    { tail->next = b; b = b->next; }
        tail = tail->next;
    }
    tail->next = a ? a : b;

    Node *cur = dummy.next;
    while (cur) {
        if (cur != dummy.next) printf(" ");
        printf("%d", cur->data);
        cur = cur->next;
    }
    printf("\n");

    return 0;
}