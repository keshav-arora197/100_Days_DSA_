#include <stdio.h>

#define MAX 1000

int queue[MAX], stack[MAX];
int front = 0, rear = -1, top = -1;

// Enqueue
void enqueue(int value) {
    queue[++rear] = value;
}

// Push into stack
void push(int value) {
    stack[++top] = value;
}

// Pop from stack
int pop() {
    return stack[top--];
}

int main() {
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    // Move queue elements to stack
    for (int i = front; i <= rear; i++) {
        push(queue[i]);
    }

    // Pop from stack and print
    while (top != -1) {
        printf("%d", pop());
        if (top != -1) {
            printf(" ");
        }
    }

    return 0;
}