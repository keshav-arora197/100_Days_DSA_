#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

// Swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify upwards after insertion
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

// Heapify downwards after extraction
void heapifyDown(int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

// Insert into heap
void insert(int x) {
    if (size == MAX) {
        return;
    }
    heap[size] = x;
    heapifyUp(size);
    size++;
}

// Peek minimum element
void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", heap[0]);
    }
}

// Extract minimum element
void extractMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

int main() {
    int N, x;
    char op[20];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "extractMin") == 0) {
            extractMin();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}