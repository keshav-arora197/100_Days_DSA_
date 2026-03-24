#include <stdio.h>
#define MAX 100

int cq[MAX];
int front = 0, rear = -1, size = 0;

// Enqueue in circular queue
void enqueue(int value) {
    if (size == MAX) {
        return;
    }
    rear = (rear + 1) % MAX;
    cq[rear] = value;
    size++;
}

// Dequeue from circular queue
int dequeue() {
    if (size == 0) {
        return -1;
    }
    int value = cq[front];
    front = (front + 1) % MAX;
    size--;
    return value;
}

// Display queue from front to rear
void display() {
    for (int i = 0; i < size; i++) {
        printf("%d", cq[(front + i) % MAX]);
        if (i < size - 1) {
            printf(" ");
        }
    }
}

int main() {
    int n, m, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int x = dequeue();
        enqueue(x);
    }

    display();

    return 0;
}