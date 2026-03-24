#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

// Enqueue operation
void enqueue(int value) {
    if (rear == MAX - 1) {
        return;
    }
    queue[++rear] = value;
}

// Display queue
void display() {
    for (int i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if (i < rear) {
            printf(" ");
        }
    }
}

int main() {
    int n, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    display();

    return 0;
}