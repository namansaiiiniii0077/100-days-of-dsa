#include <stdio.h>

#define MAX 1000

int stack[MAX], top = -1;

void push(int val) { stack[++top] = val; }

int pop() { return stack[top--]; }

void display() {
    for (int i = top; i >= 0; i--) {
        if (i != top) printf(" ");
        printf("%d", stack[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int val;
            scanf("%d", &val);
            push(val);
        } else if (op == 2) {
            if (top == -1) printf("Stack Underflow\n");
            else printf("%d\n", pop());
        } else {
            display();
        }
    }

    return 0;
}