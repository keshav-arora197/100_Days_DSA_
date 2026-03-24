#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        return;
    }
    stack[++top] = value;
}

// Pop operation
void pop() {
    if (top == -1) {
        return;
    }
    top--;
}

// Display stack from top to bottom
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i != 0) {
            printf(" ");
        }
    }
}

int main() {
    int n, m, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        pop();
    }

    display();

    return 0;
}