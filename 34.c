#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int val) {
    Node *node = malloc(sizeof(Node));
    node->data = val;
    node->next = top;
    top = node;
}

int pop() {
    int val = top->data;
    Node *tmp = top;
    top = top->next;
    free(tmp);
    return val;
}

int main() {
    char token[20];

    while (scanf("%s", token) == 1) {
        if (strlen(token) == 1 &&
            (token[0] == '+' || token[0] == '-' ||
             token[0] == '*' || token[0] == '/')) {
            int b = pop(), a = pop();
            if      (token[0] == '+') push(a + b);
            else if (token[0] == '-') push(a - b);
            else if (token[0] == '*') push(a * b);
            else                      push(a / b);
        } else {
            push(atoi(token));
        }
    }

    printf("%d\n", pop());
    return 0;
}