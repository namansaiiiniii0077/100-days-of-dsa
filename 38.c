#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *back;
    int size;
} Deque;

Deque *createDeque() {
    Deque *dq = malloc(sizeof(Deque));
    dq->front = dq->back = NULL;
    dq->size = 0;
    return dq;
}

Node *newNode(int val) {
    Node *node = malloc(sizeof(Node));
    node->data = val;
    node->prev = node->next = NULL;
    return node;
}

void push_front(Deque *dq, int val) {
    Node *node = newNode(val);
    if (!dq->front) dq->front = dq->back = node;
    else { node->next = dq->front; dq->front->prev = node; dq->front = node; }
    dq->size++;
}

void push_back(Deque *dq, int val) {
    Node *node = newNode(val);
    if (!dq->back) dq->front = dq->back = node;
    else { node->prev = dq->back; dq->back->next = node; dq->back = node; }
    dq->size++;
}

void pop_front(Deque *dq) {
    if (!dq->front) { printf("Deque is empty\n"); return; }
    Node *tmp = dq->front;
    dq->front = dq->front->next;
    if (dq->front) dq->front->prev = NULL;
    else dq->back = NULL;
    free(tmp);
    dq->size--;
}

void pop_back(Deque *dq) {
    if (!dq->back) { printf("Deque is empty\n"); return; }
    Node *tmp = dq->back;
    dq->back = dq->back->prev;
    if (dq->back) dq->back->next = NULL;
    else dq->front = NULL;
    free(tmp);
    dq->size--;
}

void front(Deque *dq) {
    if (!dq->front) printf("-1\n");
    else printf("%d\n", dq->front->data);
}

void back(Deque *dq) {
    if (!dq->back) printf("-1\n");
    else printf("%d\n", dq->back->data);
}

void empty(Deque *dq) {
    printf("%s\n", dq->size == 0 ? "true" : "false");
}

void size_dq(Deque *dq) {
    printf("%d\n", dq->size);
}

void clear(Deque *dq) {
    while (dq->front) pop_front(dq);
}

void display(Deque *dq) {
    Node *cur = dq->front;
    while (cur) {
        if (cur != dq->front) printf(" ");
        printf("%d", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void reverse(Deque *dq) {
    Node *cur = dq->front;
    while (cur) {
        Node *tmp = cur->next;
        cur->next = cur->prev;
        cur->prev = tmp;
        cur = tmp;
    }
    Node *tmp = dq->front;
    dq->front = dq->back;
    dq->back = tmp;
}

void sort_dq(Deque *dq) {
    if (!dq->front) return;
    int arr[dq->size], i = 0;
    Node *cur = dq->front;
    while (cur) { arr[i++] = cur->data; cur = cur->next; }
    for (int a = 0; a < dq->size - 1; a++)
        for (int b = a + 1; b < dq->size; b++)
            if (arr[a] > arr[b]) { int t = arr[a]; arr[a] = arr[b]; arr[b] = t; }
    cur = dq->front; i = 0;
    while (cur) { cur->data = arr[i++]; cur = cur->next; }
}

int main() {
    Deque *dq = createDeque();
    char op[20];

    while (scanf("%s", op) == 1) {
        if      (!strcmp(op, "push_front"))  { int v; scanf("%d", &v); push_front(dq, v); }
        else if (!strcmp(op, "push_back"))   { int v; scanf("%d", &v); push_back(dq, v); }
        else if (!strcmp(op, "pop_front"))   pop_front(dq);
        else if (!strcmp(op, "pop_back"))    pop_back(dq);
        else if (!strcmp(op, "front"))       front(dq);
        else if (!strcmp(op, "back"))        back(dq);
        else if (!strcmp(op, "empty"))       empty(dq);
        else if (!strcmp(op, "size"))        size_dq(dq);
        else if (!strcmp(op, "clear"))       clear(dq);
        else if (!strcmp(op, "reverse"))     reverse(dq);
        else if (!strcmp(op, "sort"))        sort_dq(dq);
        else if (!strcmp(op, "display"))     display(dq);
    }

    return 0;
}