#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef;
    int exp;
    struct Node *next;
} Node;

Node *newNode(int coef, int exp) {
    Node *node = malloc(sizeof(Node));
    node->coef = coef;
    node->exp = exp;
    node->next = NULL;
    return node;
}

void printTerm(int coef, int exp, int first) {
    if (!first) printf(" + ");
    if (exp == 0)
        printf("%d", coef);
    else if (exp == 1)
        printf("%dx", coef);
    else
        printf("%dx^%d", coef, exp);
}

int main() {
    int n;
    scanf("%d", &n);

    Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);
        Node *node = newNode(c, e);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }

    Node *cur = head;
    int first = 1;
    while (cur) {
        printTerm(cur->coef, cur->exp, first);
        first = 0;
        cur = cur->next;
    }
    printf("\n");

    return 0;
}