#include <stdio.h>
#include <string.h>

char stack[1000];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop()        { return stack[top--]; }
char peek()       { return stack[top]; }

int precedence(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int main() {
    char expr[1000];
    scanf("%s", expr);

    int len = strlen(expr);
    for (int i = 0; i < len; i++) {
        char c = expr[i];
        if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(')
                printf("%c", pop());
            if (top != -1) pop();
        } else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c))
                printf("%c", pop());
            push(c);
        } else {
            printf("%c", c);
        }
    }

    while (top != -1)
        printf("%c", pop());

    printf("\n");
    return 0;
}