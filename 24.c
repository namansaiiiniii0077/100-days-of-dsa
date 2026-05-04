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

    Node dummy;
    Node *tail = &dummy;
    dummy.next = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        tail->next = newNode(x);
        tail = tail->next;
    }

    int key;
    scanf("%d", &key);

    Node *prev = &dummy, *cur = dummy.next;
    while (cur) {
        if (cur->data == key) {
            prev->next = cur->next;
            free(cur);
            break;
        }
        prev = cur;
        cur = cur->next;
    }

    Node *node = dummy.next;
    while (node) {
        if (node != dummy.next) printf(" ");
        printf("%d", node->data);
        node = node->next;
    }
    printf("\n");

    return 0;
}