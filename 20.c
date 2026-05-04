#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10007

typedef struct Node {
    int key;
    int count;
    struct Node *next;
} Node;

Node *table[TABLE_SIZE];

int hash(int key) {
    return abs(key) % TABLE_SIZE;
}

int get(int key) {
    int h = hash(key);
    Node *cur = table[h];
    while (cur) {
        if (cur->key == key) return cur->count;
        cur = cur->next;
    }
    return 0;
}

void put(int key, int count) {
    int h = hash(key);
    Node *cur = table[h];
    while (cur) {
        if (cur->key == key) { cur->count = count; return; }
        cur = cur->next;
    }
    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->count = count;
    node->next = table[h];
    table[h] = node;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    put(0, 1);
    int prefix = 0, count = 0;

    for (int i = 0; i < n; i++) {
        prefix += arr[i];
        count += get(prefix);
        put(prefix, get(prefix) + 1);
    }

    printf("%d\n", count);
    return 0;
}

