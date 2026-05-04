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

int length(Node *head) {
    int len = 0;
    while (head) { len++; head = head->next; }
    return len;
}

int main() {
    int n, m;
    scanf("%d", &n);
    Node *a = buildList(n);
    scanf("%d", &m);
    Node *b = buildList(m);

    int la = length(a), lb = length(b);

    int *arr_a = malloc(la * sizeof(int));
    int *arr_b = malloc(lb * sizeof(int));

    Node *cur = a;
    for (int i = 0; i < la; i++, cur = cur->next)
        arr_a[i] = cur->data;

    cur = b;
    for (int i = 0; i < lb; i++, cur = cur->next)
        arr_b[i] = cur->data;

    int i = la - 1, j = lb - 1, result = -1;
    while (i >= 0 && j >= 0 && arr_a[i] == arr_b[j]) {
        result = arr_a[i];
        i--;
        j--;
    }

    if (result != -1)
        printf("%d\n", result);
    else
        printf("No Intersection\n");

    free(arr_a);
    free(arr_b);
    return 0;
}